Feature: Admin tests
  As a site user
  I have access denied or granted to admin things based on my role


  # Test for admin toolbar visibility

  Scenario: Anon cannot see the admin toolbar
    Given I am on the homepage
    Then I should not see an "#admin-menu" element

  Scenario: Regular user cannot see the admin toolbar
    Given I am logged in as a regular user
    Given I am on the homepage
    Then I should not see an "#admin-menu" element

  Scenario: Staff can see the admin toolbar
    Given I am logged in as a staff
    And I am on the homepage
    Then I should see an "#admin-menu" element


  # Test for general /admin access

  Scenario: Anon cannot see the admin page
    Given I am on "/admin"
    Then I should see "Access denied"

  Scenario: Regular user cannot see the admin page
    Given I am logged in as a regular user
    And I am on "/admin"
    Then I should see "Access denied"

  Scenario: Staff can see the admin page
    Given I am logged in as a staff
    And I am on "/admin"
    Then I should see "Administration" in the ".page-title" element

  
  # Begin tests per path.  Listed alphabetically:

  # Test for /admin/appearance

  Scenario: Staff cannot see the admin appearance page
    Given I am logged in as a staff
    And I am on "/admin/appearance"
    Then I should see "Access denied"

  Scenario: Product team cannot see the admin appearance page
    Given I am logged in as a product team
    And I am on "/admin/appearance"
    Then I should see "Access denied"


  # Test for /admin/config/system/optimizely

  Scenario: Staff cannot see the admin optimizely page
    Given I am logged in as a staff
    And I am on "/admin/config/system/optimizely"
    Then I should see "Access denied"

  Scenario: Product team can see the admin optimizely page
    Given I am logged in as a product team
    And I am on "/admin/config/system/optimizely"
    Then I should see "Optimizely" in the ".page-title" element


  # Test for /admin/content

  Scenario: Staff can see the admin content overview page
    Given I am logged in as a staff
    And I am on "/admin/content"
    Then I should see "Content" in the ".page-title" element


  # Test for /admin/content/banners

  Scenario: Staff can see the admin content/banners page
    Given I am logged in as a staff
    And I am on "/admin/content/banners"
    Then I should see "Banners" in the ".page-title" element


  # Test for /admin/content/webform

  Scenario: Staff can see the admin content/webform page
    Given I am logged in as a staff
    And I am on "/admin/content/webform"
    Then I should see "Content" in the ".page-title" element


  # Test for /admin/lookup/submission

  Scenario: Anon cannot see the admin lookup submission page
    Given I am on "/admin/lookup/submission"
    Then I should see "Access denied"

  Scenario: Regular user cannot see the admin lookup submission page
    Given I am logged in as a regular user
    And I am on "/admin/lookup/submission"
    Then I should see "Access denied"

  Scenario: Staff can see the admin lookup submission page
    Given I am logged in as a staff
    And I am on "/admin/lookup/submission"
    Then I should see "E-mail"
    And I should see "Last Name"


  # Test for /admin/lookup/user

  Scenario: Anon cannot see the admin lookup user page
    Given I am on "/admin/lookup/user"
    Then I should see "Access denied"

  Scenario: Regular user cannot see the admin lookup user page
    Given I am logged in as a regular user
    And I am on "/admin/lookup/user"
    Then I should see "Access denied"

  Scenario: Staff can see the admin lookup user page
    Given I am logged in as a staff
    And I am on "/admin/lookup/user"
    Then I should see "User Lookup" in the ".page-title" element


  # Test for /admin/modules

  Scenario: Staff cannot see the admin modules page
    Given I am logged in as a staff
    And I am on "/admin/modules"
    Then I should see "Access denied"

  Scenario: Product team cannot see the admin modules page
    Given I am logged in as a product team
    And I am on "/admin/modules"
    Then I should see "Access denied"


  # Test for /admin/people

  Scenario: Staff cannot see the admin people page
    Given I am logged in as a staff
    And I am on "/admin/people"
    Then I should see "Access denied"

  Scenario: Product team cannot see the admin people page
    Given I am logged in as a product team
    And I am on "/admin/people"
    Then I should see "Access denied"


  # Test for /admin/reports

  Scenario: Staff cannot see the admin reports page
    Given I am logged in as a staff
    And I am on "/admin/reports"
    Then I should see "Access denied"

  Scenario: Product team cannot see the admin reports page
    Given I am logged in as a product team
    And I am on "/admin/reports"
    Then I should see "Access denied"

  
  # Test for /admin/structure/entityqueue

  Scenario: Staff cannot see the admin entityqueue page
    Given I am logged in as a staff
    And I am on "/admin/structure/entityqueue"
    Then I should see "Access denied"

  Scenario: Product team can see the admin entityqueue page
    Given I am logged in as a product team
    And I am on "/admin/structure/entityqueue"
    Then I should see "Entityqueues" in the ".page-title" element


  # Test for /admin/structure/nodequeue

  Scenario: Staff cannot see the admin nodequeue page
    Given I am logged in as a staff
    And I am on "/admin/structure/nodequeue"
    Then I should see "Access denied"

  Scenario: Product team can see the admin nodequeue page
    Given I am logged in as a product team
    And I am on "/admin/structure/nodequeue"
    Then I should see "Nodequeues"


  # Test for /admin/structure/taxonomy

  Scenario: Staff cannot see the admin taxonomy page
    Given I am logged in as a staff
    And I am on "/admin/structure/taxonomy"
    Then I should see "Access denied"

  Scenario: Product team can see the admin taxonomy page
    Given I am logged in as a product team
    And I am on "/admin/structure/taxonomy"
    Then I should see "Taxonomy" in the ".page-title" element


  # Test for /user/[user-name]

  Scenario: Anon cannot see a user profile
    Given I am on "/users/aaron-schachter"
    Then I should see "Access denied"

  Scenario: Regular user cannot see a user profile
    Given I am logged in as a regular user
    And I am on "/users/aaron-schachter"
    Then I should see "Access denied"

  Scenario: Staff can see a user profile
    Given I am logged in as a staff
    And I am on "/users/aaron-schachter"
    Then I should see "Member Profile"
