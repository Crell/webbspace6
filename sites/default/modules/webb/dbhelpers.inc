<?php

/**
 * @file
 * This is a library of useful database functions and methods.
 * 
 * Shamelessly copied from helpers module, which has no real Drupal 5 release.
 * 
 */

/**
 * Database functions
 */

/**
 * Run an insert query on the active database.
 *
 * @param $table
 *   The database table on which to run the insert query.
 * @param $fields
 *   An associative array of the values to insert.  The keys are the
 *   fields, and the corresponding values are the values to insert.
 * @return
 *   A   database query result resource, or FALSE if the query was not
 * executed correctly.
 *
 */
function db_insert($table, $fields) {

  $insert_fields = array_keys($fields);
  $insert_values = array_values($fields);

  $params = array();
  foreach ($insert_values as $value) {
    switch(gettype($value)) {
      case 'double':
        $escape = '%f';
        break;
      case 'integer':
        $escape = '%d';
        break;
      case 'string':
        $escape = "'%s'";
        break;
      case 'NULL':
        $escape = 'NULL';
        break;
      default:
        continue;
    }
    $params[] = $escape;
  }

  $sql = 'INSERT INTO {' . $table . '} (' . implode(',', $insert_fields) . ') VALUES (' . implode(',', $params) . ')';

  return db_query($sql, $insert_values);
}

/**
 * Run an update query on the active database.
 *
 * @param $table
 *   The database table on which to run the update query.
 * @param $fields
 *   An associative array of the values to update.  The keys are the
 *   fields, and the corresponding values are the values to update to.
 * @param $where
 *   The where rules for this update query.
 * @param $where_type
 *   Whether to AND or OR the where rules together.
 * @return
 *   A database query result resource, or FALSE if the query was not
 *   executed correctly.
 *
 */
function db_update($table, $fields, $where, $where_type='AND') {

  $update_values = array_values($fields);

  $flat_fields = array();
  foreach ($fields as $field => $value) {
    switch(gettype($value)) {
      case 'integer':
        $escape = '%d';
        break;
      case 'double':
        $escape = '%f';
        break;
      case 'string':
        $escape = "'%s'";
        break;
      case 'NULL':
        $escape = 'NULL';
        break;
      default:
        continue;
    }
    $flat_fields[] = $field . '=' . $escape;
  }

  list($where_string, $where_values) = db_where_clause($where, $where_type);

  $sql = 'UPDATE ' . $table . ' SET ' . implode(',', $flat_fields) . $where_string;

  return db_query($sql, array_merge($update_values, $where_values));
}

/**
 * Run a delete query on the active database.
 *
 * @param $table
 *   The database table on which to run the delete query.
 * @param $where
 *   The where rules for this delete query.
 * @param $where_type
 *   Whether to AND or OR the where rules together.
 * @return
 *   A database query result resource, or FALSE if the query was not
 *   executed correctly.
 *
 */
function db_delete($table, $where, $where_type='AND') {

  list($where_string, $where_values) = db_where_clause($where, $where_type);

  $sql = 'DELETE FROM ' . $table . $where_string;

  return db_query($sql, $where_values);
}

/**
 * Build the WHERE portion of an SQL query, based on the specified values.
 *
 * @param $where
 *   Associative array of rules in the WHERE clause.  If a key in the array
 *   is numeric, the value is taken as a literal rule.  If it is non-numeric,
 *   then it is assumed to be a field name and the corresponding value is the
 *   value that it must hold.
 * @param $where_type
 *   Whether the values of the WHERE clause should be ANDed or ORed together.
 *
 *   As an example, this $where clause would be translated as follows:
 *   $where = array('name'=>'foo', 'type'=>'page', 'created < 1147567877')
 *
 *   WHERE (name='foo') AND ('type'='page') AND (created < 1147567877')
 * @return
 *   An array containing the where clause with sprintf() markers, and
 *   an array of values to substitute for them.
 */
function db_where_clause($where, $where_type='AND', $where_keyword=TRUE) {
  $params = array();
  $args = array();
  foreach ($where as $key => $value) {
    if (is_numeric($key)) {
      $params[] = ' (' . $value . ') ';
    }
    else {
      switch(gettype($value)) {
        case 'double':
          $escape = '%f';
          break;
        case 'integer':
          $escape = '%d';
          break;
        case 'string':
          $escape = "'%s'";
          break;
        case 'NULL':
          $escape = 'NULL';
          break;
        default:
          continue;
      }
      $params[] = ' (' . $key . '=' . $escape . ') ';
      $args[] = $value;
    }
  }

  $return = '';
  if (sizeof($params)) {
    $return = ($where_keyword ? ' WHERE ' : ' ') . implode($where_type, $params);
  }

  return array($return, $args);
}

/**
 * Returns an array with all objects from a query
 * Does not do a rewrite sql for you!
 * Call similar to db_query.
 */
function db_fetch_all_as_objects($query) {
  $results = array();
  $args = func_get_args();
  array_shift($args);
  if (isset($args[0]) and is_array($args[0])) { // 'All arguments in one array' syntax
    $args = $args[0];
  }
  $res = db_query($query, $args);

  while ($row = db_fetch_object($res)) {
    $results[] = $row;
  }
  return $results;
}

/**
 * Returns an array with all arrays from a query
 * Does not do a rewrite sql for you!
 * Call similar to db_query.
 */
function db_fetch_all_as_arrays($query) {
  $results = array();
  $args = func_get_args();
  array_shift($args);
  if (isset($args[0]) and is_array($args[0])) { // 'All arguments in one array' syntax
    $args = $args[0];
  }
  $res = db_query($query, $args);

  while ($row = db_fetch_array($res)) {
    $results[] = $row;
  }
  return $results;
}

/**
 * Returns the first column of a query result as an array.
 * Does not do a rewrite sql for you!
 * Call similar to db_query().
 */
function db_fetch_column($query) {
  $results = array();
  $args = func_get_args();
  array_shift($args);
  if (isset($args[0]) and is_array($args[0])) { // 'All arguments in one array' syntax
    $args = $args[0];
  }
  $res = db_query($query, $args);

  while ($row = db_fetch_array($res)) {
    $results[] = current($row);
  }

  return $results;
}

/**
 * Returns an associative array, with the first column of the result set
 * as the key and the second as the value.
 * Does not do a rewrite sql for you!
 * Call similar to db_query().
 */
function db_fetch_assoc($query) {
  $results = array();
  $args = func_get_args();
  array_shift($args);
  if (isset($args[0]) and is_array($args[0])) { // 'All arguments in one array' syntax
    $args = $args[0];
  }
  $res = db_query($query, $args);

  while ($row = db_fetch_array($res)) {
    $keys = array_keys($row);
    $results[$row[$keys[0]]] = $row[$keys[1]];
  }

  return $results;
}
