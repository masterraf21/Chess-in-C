#ifndef BIDAK_H
#define BIDAK_H

#include "chess.h"
#include "../adt/listbidak.h"


/****HELPER FUNCTION******/
boolean Enemy(BIDAK B, BOARD_TILE T);
boolean Friend(BIDAK B, BOARD_TILE T);

/******KONSTRUKTOR*******/
//Fungsi Konstruktor tiap bidak
BIDAK InitBidak(PAWN_ID num,PAWN_TYPE Tipe, BOARD_INDEX Posisi, COLOR Warna);
//Konstruktor List buat nyimpen bidak
//langsung diisi sama bidak 16 biji 
void InitListBidak(List_Bidak *L, COLOR Warna);
void UpdateList(List_Bidak *L, MOVE M);







#endif