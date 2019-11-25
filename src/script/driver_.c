#include "../engine/board.h"
#include "../engine/bidak.h"
#include <stdio.h>

int main(){
    BOARD B;
    //init board dulu slurr
    init_board(&B);
    //init masing masing list;
    InitListBidak(&B.LHitam, BLACK);
    InitListBidak(&B.LPutih, WHITE);
    






}