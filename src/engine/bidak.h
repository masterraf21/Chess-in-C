#include "../adt/listlinier.h"
#include "../engine/board.h"

#ifndef BIDAK_H
#define BIDAK_H

//WHITE=0, BLACK=1
enum COLOR {WHITE=1,BLACK=-1};
//enum pawns
enum PAWN_TYPE{PAWNS=1, KNIGHT, BISHOP, ROOK, QUEEN, KING};


//struct ini dipake buat nanti di linked list, bisa buat generate move juga
typedef struct{
    PAWN_TYPE tipe;
    BOARD_SQUARES posisi;
    //bisa diisi apa aja
}BIDAK;

//PION1-A1
//PION2-B1


#endif