#ifndef _ACC_
#define _ACC_

#include "leader.h"
#include "board.h"
#include "giliran.h"
#include "SaveLoad.h"
#include "core.h"


void Welcome();

void Menu();

void keluar();

void RunNewGame(LeaderBoard *B);

void RunSavedGame(LeaderBoard *B);

void RunGame(BOARD D, Queue_Giliran *Q,boolean *done);

int getIdent(Queue_Giliran Q);

int getNum(char *cmd);

#endif