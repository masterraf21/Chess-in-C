#ifndef BOARD_H
#define BOARD_H

#include "chess.h"
#include "bidak.h"
#include "../adt/stacklist.h"


/** TYPEDEF KHUSUS **/
typedef struct {
    TabInt Tab; //Table of int[120]
    List_Bidak LPutih; //List bidak yang berkorespondensi
    List_Bidak LHitam; //buat yang item
}BOARD;

/****** MACRO *******/
#define Tab(L) (L).Tab
#define LPutih(L) (L).LPutih
#define LHitam(L) (L).LHitam
#define SetBoard(B,X) Tab(B).TI[X]

/****HELPER FUNCTION USING STACK***/
void SwapTile(BOARD *B, BOARD_INDEX x, BOARD_INDEX y);
void MakanTile(BOARD *B, BOARD_INDEX pemangsa, BOARD_INDEX korban);
void UpdateStack(Stack *S, MOVE M);
void UpdateList(List_Bidak *L, MOVE M);
void UpdateUndoList(List_Bidak *LSelf, MOVE M);
void UpdateMakan(List_Bidak *LEnemy, MOVE M);
void UpdateBoard(BOARD *B, MOVE M);
// void UndoBoard(BOARD *B, Stack *S, List_Bidak *Acu, List_Bidak *Lawanacu);

/******* KONSTRUKTOR ******/
// Init
void init_board(BOARD *B);

/****** DRAW ******/
// Pra- Draw procedure
char IntToCharBidak(int n);
int NoBarisToTileIndex(int m);
void IsiTile(int nobaris, BOARD B);
void AtasTile();
void BawahTile();
// Draw procedure
void PrintBoard(BOARD B);

#endif
