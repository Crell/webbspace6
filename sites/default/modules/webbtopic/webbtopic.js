Drupal.behaviors.webbtopic = function (context) {
  $('.webbtopic-topic:not(.webbtopic-processed)', context).addClass('webbtopic-processed').each(function () {
    var a = $("<a>" + $(this).text() + "</a>")
    .attr('href', '#')
    .addClass($(this).attr('class'))
    .bind('click', function(event) {
      event.preventDefault();
      var input = $(this).parent().siblings('input');
      input.val($(this).text());
    }); // end bind
    $(this).before(a).remove();
  });
};
