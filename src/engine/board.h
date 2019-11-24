#ifndef BOARD_H
#define BOARD_H

#include "chess.h"
#include "bidak.h"
#include "../adt/stacklist.h"
#include "move.h"

/** TYPEDEF KHUSUS **/
typedef struct {
    TabInt Tab; //Table of int[120]
    List_Bidak LPutih; //List bidak yang berkorespondensi
    List_Bidak LHitam; //buat yang item
} BOARD;

/****** MACRO *******/
#define Tab(L) (L).Tab
#define LPutih(L) (L).LPutih
#define LHitam(L) (L).LHitam
#define SetBoard(B,X) Tab(B).TI[X]

/****HELPER FUNCTION USING STACK***/
void UpdateStack(Stack *S, MOVE M);
void UpdateList(List_Bidak *L, MOVE M);
void UpdateBoard(BOARD *B, List_Bidak L, COLOR C);


/******* KONSTRUKTOR ******/
// Init
void init_board(BOARD *B);

/****** DRAW ******/
// Draw procedure
void IsiTile(int nobaris, int nokolom, char bidak);
void AtasTile();
void BawahTile();
void PrintBoard();

#endif
