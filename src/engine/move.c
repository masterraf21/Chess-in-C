#include <stdlib.h>
#include "move.h"

/**** HELPER FUNCTION *****/
BOARD_INDEX Neighbor(BIDAK B);
BOARD_INDEX Up(BIDAK B){
    return B.posisi+10;
}
BOARD_INDEX Up_i(BIDAK B, int i){
    if (i==1)
        return Up(B);
    else 
        return B.posisi+10*i;
}
BOARD_INDEX Down(BIDAK B){
    return B.posisi-10;
}
BOARD_INDEX Down_i(BIDAK B, int i){
    if (i==1)
        return Down(B);
    else
        return B.posisi-10*i;
}
BOARD_INDEX Left(BIDAK B){
    return B.posisi-1;
}
BOARD_INDEX Left_i(BIDAK B, int i){
    if (i==1)
        return Left(i);
    else 
        return B.posisi-1*i;
}
BOARD_INDEX Right(BIDAK B){
    return B.posisi+1;
}
BOARD_INDEX Right_i(BIDAK B, int i){
    if (i==1)
        return Right(B);
    else 
        return B.posisi+1*i;
}

BOARD_INDEX SerongKananAtas(BIDAK B){
    return B.posisi+11;
}
BOARD_INDEX SerongKananAtas_i(BIDAK B, int i){
    if (i==1)
        return SerongKananAtas(B);
    else 
        return B.posisi+11*i;
}
BOARD_INDEX SerongKananBawah(BIDAK B){
    return B.posisi-9;
}
BOARD_INDEX SerongKananBawah_i(BIDAK B, int i){
    if (i==1)
        return SerongKananBawah(B);
    else 
        return B.posisi-9;
}
BOARD_INDEX SerongKiriAtas(BIDAK B){
    return B.posisi+9;
}
BOARD_INDEX SerongKiriAtas_i(BIDAK B, int i){
    if (i==1)
        return SerongKiriAtas(B);
    else 
        return B.posisi+9;
}
BOARD_INDEX SerongKiriBawah(BIDAK B){
    return B.posisi-11;
}
BOARD_INDEX SerongKiriBawah_i(BIDAK B, int i){
    if (i==1)
        return SerongKiriBawah(B);
    else 
        return B.posisi-11;
}

/***** MAIN FUNCTION *****/
List_Move MoveGenerator(List_Bidak L);
List_Move GenerateWPawn(BIDAK B);
List_Move GenerateBPawn(BIDAK B);
List_Move GenerateRook(BIDAK B);
List_Move GenerateKnight(BIDAK B);
List_Move GenerateBishop(BIDAK B);
List_Move GenerateQueen(BIDAK B);
List_Move GenerateKing(BIDAK B);