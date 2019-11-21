#ifndef BIDAK_H
#define BIDAK_H

#include "chess.h"
#include "../adt/listbidak.h"


/******KONSTRUKTOR*******/

//Fungsi Konstruktor tiap bidak
BIDAK InitBidak(LIST_ID Id, PAWN_TYPE Tipe, BOARD_INDEX Posisi, COLOR Warna);
//Konstruktor List buat nyimpen bidak
//langsung diisi sama bidak 16 biji 
void InitListBidak(List_Bidak *L, COLOR Warna);







#endif