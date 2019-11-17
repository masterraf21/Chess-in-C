#ifndef BIDAK_H
#define BIDAK_H

#include "chess.h"
#include "../adt/listbidak.h"


/******KONSTRUKTOR*******/

//Fungsi Konstruktor tiap bidak
BIDAK InitBidak(PAWN_TYPE Tipe, BOARD_SQUARE Posisi, COLOR Warna);
//Konstruktor List buat nyimpen bidak
//langsung diisi sama bidak 16 biji 
void InitGenerate(List_Bidak *L);







#endif