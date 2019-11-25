#ifndef _CORE_
#define _CORE_

#include "leader.h"
#include "move.h"
#include "bidak.h"
#include "board.h"
#include "giliran.h"
#include "SaveLoad.h"


void MoveCore(BOARD *B, Stack *S, infotypeturn *R, boolean *done);

void UndoCore(BOARD *D, Stack *S, infotypeturn *R);

#endif