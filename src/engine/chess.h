//Jadi di file ini bakal didefinisiin primitif semua buat chess
//terutama buat board, bidak, sama move
//agar menghindari header saling include satu sama lain intinya sebenernya
#ifndef CHESS_H
#define CHESS_H

#include "../adt/array.h"


/*For Board*/

//index of the board itself
typedef enum {
  A1=21, B1, C1, D1, E1, F1, G1, H1,
  A2=31, B2, C2, D2, E2, F2, G2, H2,
  A3=41, B3, C3, D3, E3, F3, G3, H3,
  A4=51, B4, C4, D4, E4, F4, G4, H4,
  A5=61, B5, C5, D5, E5, F5, G5, H5,
  A6=71, B6, C6, D6, E6, F6, G6, H6,
  A7=81, B7, C7, D7, E7, F7, G7, H7,
  A8=91, B8, C8, D8, E8, F8, G8, H8,
}BOARD_INDEX;

typedef enum{
  A1x, B1x, C1x, D1x, E1x, F1x, G1x, H1x,
  A2x, B2x, C2x, D2x, E2x, F2x, G2x, H2x,
  A3x, B3x, C3x, D3x, E3x, F3x, G3x, H3x,
  A4x, B4x, C4x, D4x, E4x, F4x, G4x, H4x,
  A5x, B5x, C5x, D5x, E5x, F5x, G5x, H5x,
  A6x, B6x, C6x, D6x, E6x, F6x, G6x, H6x,
  A7x, B7x, C7x, D7x, E7x, F7x, G7x, H7x,
  A8x, B8x, C8x, D8x, E8x, F8x, G8x, H8x,

}DUMMY_INDEX;
//condition of the board aside from pawns
typedef enum
{
   EMPTY_SQUARE = 0, BAD_SQUARE = 99
}BOARD_CONDITION;
//the bad square index
typedef int BAD_INDEX;

typedef struct {
    TabInt Tab; //Table of int[120]
    List_Bidak LPutih; //List bidak yang berkorespondensi
    List_Bidak LHitam; //buat yang item
} BOARD;



/*For Bidak*/

//enum tipe warna
typedef enum
{
    WHITE = 1,BLACK=-1
} COLOR;

//enum pawns
typedef enum
{
    PAWN=1, KNIGHT, BISHOP, ROOK,  QUEEN, KING
}PAWN_TYPE;

//typedef list-infotype ids
//works both for white and black lists
typedef enum
{
    PAWN1, PAWN2, PAWN3, PAWN4,
    PAWN5, PAWN6, PAWN7, PAWN8,
    ROOK1, ROOK2,
    KNIGHT1, KNIGHT2,
    BISHOP1, BISHOP2,
    QUEENX, KINGX
}LIST_ID;

//struct ini dipake buat nanti di linked list, bisa buat generate move juga
typedef struct{
    LIST_ID id;
    PAWN_TYPE tipe;
    BOARD_INDEX posisi;
    COLOR warna;
}BIDAK;


/*For Move*/
typedef LIST_ID ELMT_QUEUE;

typedef struct {
    LIST_ID id;
    BOARD_INDEX cur_position;
    BOARD_INDEX new_position;
    boolean is_makan;
    BIDAK victim;
}MOVE;

/* Elemen move bakal ngeupdate linked list setelah ngeupdate stack */


//for done moves
typedef MOVE ELMT_STACK;







#endif