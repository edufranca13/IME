/* $Id: IMCS.j,v 1.7 2004/05/27 09:42:07 richard Exp $ */

/*
    The _intuitionistic_ multiple-conclusion sequent calculus!! (add after MCS.jt)
*/

/* the differences */
RULE    "⊢¬"        FROM Γ,A ⊢                  INFER Γ ⊢ ¬A,∆
RULE    "¬⊢"        FROM Γ ⊢ A                  INFER Γ,¬A ⊢ ∆
RULE    "⊢→"        FROM Γ,A ⊢ B                INFER Γ ⊢ A→B,∆
RULE    "→⊢"        FROM Γ ⊢ A AND Γ,B ⊢ ∆   INFER Γ,A→B ⊢ ∆
