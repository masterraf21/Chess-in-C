#ifndef MOVE_H
#define MOVE_H

#include "../engine/bidak.h"
#include "../engine/board.h"


typedef struct {
    BOARD_SQUARE prev_position;
    BOARD_SQUARE new_position;
    boolean is_makan;
    BIDAK victim;
}MOVE;



typedef struct{
    BOARD_SQUARE cur_position;
    BOARD_SQUARE victim_position;
    BIDAK victim;
}EATING_MOVE;

typedef List MOVE_LIST;

void generate_pawn(BIDAK Pawn, MOVE_LIST *ML);




#endif