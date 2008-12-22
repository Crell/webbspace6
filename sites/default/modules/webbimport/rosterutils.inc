<?php

/*
This library includes assorted functions for parsing and managing the account
and character files throughout the system.  It exists mainly to support the census
and similar scripts.
*/

function parse_user_file($userfile) {

  $accounts = array();

  $account_file = file($userfile);
  foreach($account_file as $line) {
    $a = array();
    $line = trim($line);
    list($a['user'], $a['name'], $a['email'], $a['level']) = explode(':', $line);
    $accounts[] = $a;
  }
  return $accounts;
}


function get_all_characters($dir) {

  $chars = array();

  //if(DEBUG) print "Parsing '$dir'\n";
  if (is_dir($dir)) {
    if ($dh = opendir($dir)) {
      if (file_exists("$dir/.chars")) {
        $path = split('/', $dir);
        $extra = array('ship' => $path[sizeof($path)-1], 'fleet' => $path[sizeof($path)-2]);
        $chars = parse_character_file("$dir/.chars", $extra);
      }
      while (($file = readdir($dh)) !== false) {
        if ($file == '.') { continue;}
        elseif ($file == '..') { continue;}
        // There are some dangling symbolic links in the messages directory that will
        // print errors on the next line.  The solution is to delete the symlinks.
        elseif (is_dir("$dir/$file")) {
          $chars = array_merge($chars, get_all_characters("$dir/$file"));
        }
      }
      closedir($dh);
    }
  }
  return $chars;
}


/**
 * Parse a characters file into an array of objects
 *
 * @param $files
 *  The full path name of the file to parse
 *
 * @param $extra
 *  Associative array of additional values to attach to every object (such as ship name)
 *
 * @param $status
 *  Whether or not to also parse the associated ctouch file for each character
 *  
 * @param $full
 *  Whether or not to expand each object to include string versions of rank and position values
 *
 */
function parse_character_file($file, $extra = array(), $status = TRUE, $expand = TRUE) {

  $characters = array();

  // The directory where the file is, so that we can access other files in the same directory
  $dir = dirname(realpath($file));

  if (file_exists($file)) {
    //if (DEBUG === TRUE) print "Parsing {$file}\n";
    $chars = file($file);
    foreach ($chars as $char) {
      $c = array();
      if ('' == trim($char)) continue;
//       if (sizeof(split(':', $char)) != 7) continue; // For some reason, some ships have HTML in their .chars file.  We ignore that...
       list($c['user'], $c['name'], $c['rankcode'], $c['positioncode'], $c['species'], $c['age'], $c['height'], $c['weight'])  = split(':', $char);

      if ($status) {
        $ctouch_file = $dir . '/.ctouch-' . $c['user'];
        $c['lastpost'] = file_exists($ctouch_file) ? filemtime($ctouch_file) : 0;
      }
      if ($expand) {
        $c['rank'] = rank_map($c['rankcode']);
        $c['position'] = position_map($c['positioncode'], file_exists($dir . '/.starbase'));
        $c['rostered'] = in_array($c['rankcode'], array(10, 18)) ? FALSE : TRUE; // Sloppy way, but works.  10, 18 are the non-rostered ranks
      }
      $character = array_merge($c, $extra);
      $characters[] = array2object($character);
    }
  }

  return $characters;
}

function rank_map($rankcode) {
  static $ranks = array(
            10 => '(no title)',
            11 => 'Gamemaster',
            12 => 'Civilian',
            18 => 'AWOL',
            19 => 'Crewman',
            20 => 'Cadet',
            21 => 'Ensign',
            22 => 'Lieut (j.g.)',
            23 => 'Lieutenant',
            24 => 'Lt. Cmdr.',
            25 => 'Commander',
            26 => 'Captain',
            27 => 'Fleet Captain',
            28 => 'Commodore',
            29 => 'Admiral',
          );
  return $ranks[$rankcode];
}


function position_map($positioncode, $is_starbase = FALSE) {

  // If it's a string, just return it as is since it's a custom position
  if (! is_numeric($positioncode))return $positioncode;

  $position = array();

  // These are what is defined by effWeBB, not what makes any logical sense
  static $security = array(0 => 'COS', 1 => 'Sec');
  static $engineering = array(0 => 'CE', 1 => 'Eng');
  static $medical = array(0 => 'CMO', 1 => 'Med');
  static $science = array(0 => 'CSO', 1 => 'Sci');
  static $co = array(0 => 'CO', 1 => 'GM /');
  static $xo = array(0 => 'XO', 1 => 'GM /');
  static $counselor = array(0 => 'CNS', 1 => 'Cns');
  static $gamemaster = array(0 => 'Gamemaster', 1 => 'GM Alpha');
  static $tactical = array(0 => 'CTO', 1 => 'Tac');
  static $operations = array(0 => 'COO', 1 => 'Ops');

  $ship = array(1 => $gamemaster,
                2 => $co,
                3 => $xo,
                4 => $counselor,
                5 => $engineering,
                6 => $medical,
                7 => $science,
                8 => $security,
                9 => $tactical
           );

  $starbase = array(1 => $gamemaster,
                2 => $co,
                3 => $xo,
                4 => $counselor,
                5 => $operations,
                6 => $medical,
                7 => $science,
                8 => $security,
                9 => $tactical
           );


  $deptcode = (int)($positioncode / 10);
  $levelcode = $positioncode % 10;

  if ($is_starbase) {
    return $starbase[$deptcode][$levelcode];
  }
  else {
    return $ship[$deptcode][$levelcode];
  }

}


function status_map($lastpost, $username) {
  // This function is sort of a hack for legacy data.  We'll actually use
  // the LastPost field for most calculations, but this is for consistency
  // as well as to flag LOA users.

  global $config_dir;
  $user_dir = "$config_dir/users";

  $loa = array();

  if (! isset($loa[$username])) {
    $userfile = file("$user_dir/$username");
    // I'm not certain what all of these fields are, but we only care about $loa_time
    list($username2, $passwd_crypt, $crap, $crap, $loa_reason, $loa_time) = explode(':', $userfile[0]);
    $loa_time = trim($loa_time);
    $loa[$username] = ($loa_time < time() || $loa_time == 0) ? FALSE : TRUE;
    //print "$username: $loa_time: {$loa[$username]}\n";
  }

  if ($loa[$username]) {
    return 'LOA';
  }

  if (0 == $lastpost) return "ok(new)";

  // 60*60*24 = 86400
  $offset = (int)((time()-$lastpost)/(86400)); // time in seconds, convert to days
  return "ok({$offset})";

}

function map_user_array($accounts) {

  $mapped = array();

  foreach ($accounts as $account) {
    $mapped[$account['user']] = $account;
  }

  return $mapped;
}


// This function borrowed from Drupal under the GPL
function array2object($array) { 
  if (is_array($array)) {
    $object = new StdClass();
    foreach ($array as $key => $value) {
      $object->$key = $value;
    }
  }
  else {
    $object = $array;
  }

  return $object;
}
