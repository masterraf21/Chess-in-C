#ifndef UNDO_H
#define UNDO_H

#include "chess.h"
#include "../adt/listbidak.h"
#include "../adt/stacklist.h"

void Undo(BOARD B, Stack *S, List_Bidak *Acu, List_Bidak *Lawanacu);

#endif