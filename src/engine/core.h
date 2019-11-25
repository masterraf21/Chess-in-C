#ifndef _CORE_
#define _CORE_

#include "leader.h"
#include "move.h"
#include "bidak.h"
#include "board.h"
#include "giliran.h"
//#include "undo.h"
#include "SaveLoad.h"


void MoveCore(BOARD *D, Stack *S, Queue_Giliran *Q, boolean *done);

void UndoCore(BOARD *D, Stack *S, Queue_Giliran *Q, boolean *done);

#endif