#include "../adt/array.h"
#include "../adt/listlinier.h"

#ifndef BOARD_H
#define BOARD_H

//enum board place starting from 21
enum BOARD_SQUARES{
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
    BAD_SQUARE = 99};

typedef struct {
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
