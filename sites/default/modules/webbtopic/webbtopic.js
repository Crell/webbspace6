if (Drupal.jsEnabled) {
  $(document).ready(function() {
    // get all attributes of span tag
    $('span.webbtopic-topic').each ( function() {
      var a = $("<a>" + $(this).text() + "</a>")
      .attr('href', '#')
      .addClass($(this).attr('class'))
      .bind('click', function(event) {
        event.preventDefault();
        var input = $(this).parent().siblings('input');
        input.val($(this).text());
      }); // end bind
      $(this).before(a).remove();
    }); // end span.webbtopic-topic
  });
}
