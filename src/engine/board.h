#ifndef BOARD_H
#define BOARD_H

#include "chess.h"
#include "bidak.h"

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


/******* KONSTRUKTOR ******/
// Init
void init_board(BOARD *B);
// Update
void update_board(BOARD *B, List_Bidak L, COLOR C);
// Draw procedure
void draw_board(BOARD B);

#endif
