/* $Id: set_russell.j,v 1.4 2005/06/09 08:48:47 rbornat Exp $ */

CONJECTUREPANEL "Set Conjectures" IS
  THEOREMS "Russell" ARE
        {x|x∉x}∈{x|x∉x}↔{x|x∉x}∉{x|x∉x}
    AND A∨¬A
    AND ¬(A∨B) ⊢ ¬A∧¬B
    AND ⊥
  END
END
