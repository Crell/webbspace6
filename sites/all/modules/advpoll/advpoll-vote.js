// $Id: advpoll-vote.js,v 1.1.2.11 2007/12/08 18:37:33 fajerstarter Exp $

if (typeof(Drupal) == "undefined" || !Drupal.advpoll) {
  Drupal.advpoll = {};
}

/*
* Submit advpoll forms with ajax
*/
Drupal.advpoll.attachVoteAjax = function() {
  $("form.advpoll-vote").each(function() {
    var thisForm = this;
    var options = {
      dataType: "json",
      after: function(data) {
        // Remove previous messages
        $("div.messages").remove(); 
        
        // Insert response
        if (data.errors) {
          $(data.errors).insertBefore(thisForm).fadeIn();
        }
        else {
          $(thisForm).hide(); 
          $(data.statusMsgs).insertBefore(thisForm).fadeIn();
          $(data.response).insertBefore(thisForm);
        }

        // Re-enable the Vote button, in case there was an error message.
        $(".form-submit", thisForm).removeAttr("disabled");

      },
      before: function() {
        // Disable the Vote button.
        $(".form-submit", thisForm).attr("disabled", "disabled");
      }
    };
    // Tell the server we are passing the form values with ajax and attach the function
    $("input.ajax", thisForm).val(true);
    $(this).ajaxForm(options);
  });
};

Drupal.advpoll.nodeVoteAutoAttach = function() {
  Drupal.advpoll.attachVoteAjax();
};

Drupal.advpoll.handleWriteins = function() {
  $("div.poll").each(function() {
    var poll = this;
    if ($(".writein-choice", poll).length == 0) {
      // No write-ins in this poll.
      return;
    }
    var ranOnce = false;
    // Toggle display of the write-in text box for radios/checkboxes.
    $(".vote-choices input[@type=radio], .vote-choices input[@type=checkbox]", poll).click(function() {
      var isLast = $(this).val() == $(".vote-choices input[@type=radio]:last, .vote-choices input[@type=checkbox]:last", poll).val();
      var type = $(this).attr("type"); 
      // The logic here is tricky but intentional.
      if (isLast || type == "radio") {
        var showChoice = isLast && (type == "radio" || $(this).attr("checked"));
        if (!ranOnce && showChoice) {
          // If this is our first time, clone the Drupal-added write-in element
          // and add a new one next to the checkbox, then delete the old one.
          $(".writein-choice input", poll).clone().addClass("writein-choice").insertAfter($(this).parent()).end().parent().parent().remove();
          ranOnce = true;
        }
        $(".writein-choice", poll).css("display", showChoice ? "inline" : "none");
        if (showChoice) {
          $(".writein-choice", poll)[0].focus();
        }
        else {
          $(".writein-choice", poll).val("");
        }
      }
    });
  
    // Toggle display of the write-in text box for select boxes.
    // Fire on change() rather than click(), for Safari compatibility.
    $(".vote-choices select:last", poll).change(function() {
      if (!ranOnce) {
        // If this is our first time, clone the Drupal-added write-in element
        // and add a new one next to the checkbox, then delete the old one.
        $(".writein-choice input", poll).clone().addClass("writein-choice").insertAfter($(this)).end().parent().parent().remove();
        ranOnce = true;
      }
      var showChoice = $(this).val() > 0;
      var alreadyVisible = $(".writein-choice", poll).css("display") == "inline";
      $(".writein-choice", poll).css("display", showChoice ? "inline" : "none");
      if (!showChoice) {
        $(".writein-choice", poll).val("");
      }
      else if (!alreadyVisible) {
        $(".writein-choice", poll)[0].focus();
      }
    });
  });
};

if (Drupal.jsEnabled) {
  $(document).ready(function(){  
    Drupal.advpoll.nodeVoteAutoAttach();
    Drupal.advpoll.handleWriteins();
  });
};
