/* $Id: set_hits.j,v 1.4 2004/04/02 13:21:58 richard Exp $ */

USE "../Barwise_n_Etchemendy/BnE-Fprime_hits.j"

HYPHIT A∈{y|P} ⊢ B IS "abstraction-E tac"
HYPHIT A∈{<y,z>|P} ⊢ B IS "abstraction-E tac"
HYPHIT A⊆B ⊢ C IS "⊆-E tac"

CONCHIT A∈{y|P} IS "abstraction-I tac"
CONCHIT A∈{<y,z>|P} IS "abstraction-I tac"
CONCHIT A=B IS "=-I"
