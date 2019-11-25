#ifndef _ACC_
#define _ACC_

#include "leader.h"
#include "move.h"
#include "bidak.h"
#include "board.h"
#include "giliran.h"
#include "SaveLoad.h"


void Welcome();

void Menu();

void keluar();

void RunNewGame(LeaderBoard *B);

void RunSavedGame(LeaderBoard *B);

void RunGame(BOARD D,List_Bidak W, List_Bidak B, Queue_Giliran *Q,boolean *done);

int getIdent(Queue_Giliran Q);

int getnum(char *cmd);

#endif