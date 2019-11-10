#include "../adt/array.h"
#include "../adt/listlinier.h"

#ifndef BOARD_H
#define BOARD_H

//enum board place starting from 21
enum POSISI_BOARD {A1=21,A2,A3,A4,A5,A6,A7,A8};

typedef struct CHESS_BOARD{
    TabInt Tabel; //Table of int[120]
    boolean is_checkmate;
    boolean is_en_passan;

    
}BOARD;

// Konstruktor
void init_board(BOARD *B);
// Update
void update_board(BOARD *B);
// Move generator
void generate_move(BOARD B);
// Draw procedure
void draw_board(BOARD B);
// Checkmate check
boolean is_check(BOARD B);
// En passant check
boolean is_enpassant(BOARD B);
// Testing illegal board
boolean is_illegal(ElType T);








#endif
