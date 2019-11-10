#include "../adt/array.h"
#include "../adt/listlinier.h"

#ifndef BOARD_H
#define BOARD_H

//enum board place starting from 21
enum {A1=21,A2,A3,A4,A5,A6,A7,A8};

typedef struct {
    TabInt Tabel;
    boolean is_checkmate;
    boolean is_en_passan;
    boolean is

    
}BOARD;

// Konstruktor
void init_board(BOARD *B);
// Draw function
void draw_board(BOARD B);







#endif
