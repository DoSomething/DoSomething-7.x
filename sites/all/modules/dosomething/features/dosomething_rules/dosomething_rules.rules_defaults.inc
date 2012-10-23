<?php
/**
 * @file
 * dosomething_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dosomething_rules_default_rules_configuration() {
  $items = array();
  $items['rules_club_og_member_approved'] = entity_import('rules_config', '{ "rules_club_og_member_approved" : {
      "LABEL" : "Club - OG member approved",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "rules", "og" ],
      "ON" : [ "og_user_approved" ],
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "og-membership:group:entity" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "og-membership:group:entity" ],
            "type" : { "value" : { "club" : "club" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your Request Has Been Granted...",
            "message" : "... to officially become a member of [og_membership:group:label]. Check out http:\\/\\/www.dosomething.org\\/user to see your DoSomething.org profile which now lists your DoSomething Club. \\r\\n\\r\\nAnd make sure to get your DoSomething Club involved in one of our easy DoSomething.org national cause campaigns: http:\\/\\/www.dosomething.org\\/campaigns. They are really fun and easy to run, plus they can make a huge impact in your community.\\r\\n\\r\\nIf you have any questions, email us at clubs@dosomething.org.\\r\\n\\r\\n--  Thanks\\r\\nThe DoSomething.org Clubs Team",
            "from" : "clubs@dosomething.org",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_club_og_member_denied'] = entity_import('rules_config', '{ "rules_club_og_member_denied" : {
      "LABEL" : "Club - OG member denied",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "rules", "og" ],
      "ON" : [ "og_user_delete" ],
      "DO" : [
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your Request Has Been Denied...",
            "message" : "... to officially become a member of [og_membership:group:label]. Think this was a mistake? Email clubs@dosomething.org and we\\u0027ll get to the bottom of it.\\r\\n\\r\\n--  Thanks\\r\\nThe DoSomething.org Clubs Team\\r\\n",
            "from" : "clubs@dosomething.org",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_club_og_member_subscribe_pending'] = entity_import('rules_config', '{ "rules_club_og_member_subscribe_pending" : {
      "LABEL" : "Club - OG member subscribe (Pending)",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "rules", "og" ],
      "ON" : [ "og_user_insert" ],
      "IF" : [
        { "data_is" : { "data" : [ "og-membership:state" ], "value" : "2" } },
        { "entity_is_of_type" : { "entity" : [ "og-membership:group:entity" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "og-membership:group:entity" ],
            "type" : { "value" : { "club" : "club" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "og-membership:group:manager:mail" ],
            "subject" : "[account:ds_member_name] has requested to join your Do Something Club",
            "message" : "[account:ds_member_name] requested to join [og_membership:group:label].\\r\\n\\r\\nIn order to grant or deny this request go to [site:url]\\/group\\/node\\/[og_membership:group:etid]\\/admin\\/people.\\r\\n\\r\\nGranting membership will link [account:ds_member_name] to [og_membership:group:label], showing off just how strong your DoSomething Club is!\\r\\n\\r\\nIf you have any questions, email us at clubs@dosomething.org.\\r\\n\\r\\n--  Thanks\\r\\nThe DoSomething.org Clubs Team",
            "from" : "clubs@dosomething.org",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : { "message" : "A message has been sent to the club administrator requesting membership to this club. You will be notified once your request has been accepted or denied." } }
      ]
    }
  }');
  return $items;
}
