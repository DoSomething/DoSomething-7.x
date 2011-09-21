<?php

// Campaign Report Back

abstract class DSCampaignReportBackMigration extends DSJsonWebformMigration {
  public function __construct($node_type) {
    parent::__construct(MigrateGroup::getInstance('CampaignReportBack'), $node_type);
    $this->addUnmigratedSources(array('changed', 'status'));
  }
}

/*
class DSCampaignReportBackBotbMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('botb');
    $this->description = 'Battle of the Bands submission';

    # $this->addFieldMapping('', '');

  }
}
*/

class DSCampaignReportBackCampaignBfb2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_bfb_2011');
    $this->description = 'Campaign Project - Battle for the Bands 2011';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackCampaignEbd2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_ebd_2011');
    $this->description = 'Campaign Project - Epic Book Drive 2011';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackCampaignGys2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_gys_2011');
    $this->description = 'Campaign Project - Green Your School 2011';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackCampaignHunt2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_hunt_2011');
    $this->description = 'Campaign Project - Scavenger Hunt 2011';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackCannedFoodMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('canned_food');
    $this->description = 'Canned Food Drive Report (Tackle Hunger)';

    # $this->addFieldMapping('', '');

  }
}

/*
class DSCampaignReportBackFeedTheNeedMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('feed_the_need');
    $this->description = 'Feed the Need Drive';

    # $this->addFieldMapping('', '');

  }
}
*/

class DSCampaignReportBackHealthySchoolsReportMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('healthy_schools_report');
    $this->description = 'Healthy Schools Report Back';

    # $this->addFieldMapping('', '');

  }
}

/*
class DSCampaignReportBackHpArtMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('hp_art');
    $this->description = 'HP Art';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackIncreaseyourgreenReportMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('increaseyourgreen_report');
    $this->description = 'Increase Your Green Report';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackIyg2010Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('iyg_2010');
    $this->description = 'Increase Your Green 2010';

    # $this->addFieldMapping('', '');

  }
}
*/

class DSCampaignReportBackSaveOurMusicMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('save_our_music');
    $this->description = 'Save Our Music';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackSfsReportGalleryMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('sfs_report_gallery');
    $this->description = 'Staples for Students Image Submission';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackStaplesReasonMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('staples_reason');
    $this->description = 'Staples Reason for Helping';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackTfjContestSignupMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('tfj_contest_signup');
    $this->description = 'Teens for Jeans Contest Signup';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackTroopLetterMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('troop_letter');
    $this->description = 'Support Our Troops Letter';

    # $this->addFieldMapping('', '');

  }
}
