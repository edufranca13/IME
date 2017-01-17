/* $Id: profiling\040in\040Edit\040menu.j,v 1.4 2004/05/27 09:42:45 richard Exp $ */

MENU Edit IS
  SEPARATOR
  CHECKBOX profiling "Collect execution profile" INITIALLY false
  BUTTON "Reset execution profile"  IS profile reset
  BUTTON "Save profile report"      IS profile report
END
