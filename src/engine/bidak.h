#include "../adt/listlinier.h"

#ifndef BIDAK_H
#define BIDAK_H

//WHITE=0, BLACK=1
enum COLOR {WHITE,BLACK};


//enum pawns
enum PAWN_TYPE{PAWNS=1, KNIGHT, BISHOP, ROOK, QUEEN, KING};

//struct ini dipake buat nanti di linked list, bisa buat generate move juga
typedef struct{
    int tipe;
    int posisi;
    //bisa diisi apa aja



}BIDAK;


#endif