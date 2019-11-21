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
/* SERONG */
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
/* BUAT KUDA */
BOARD_INDEX Knight1(BIDAK K){
    return K.posisi+21;
}
BOARD_INDEX Knight2(BIDAK K){
    return K.posisi+12;
}
BOARD_INDEX Knight3(BIDAK K){
    return K.posisi-8;
}
BOARD_INDEX Knight4(BIDAK K){
    return K.posisi-19;
}
BOARD_INDEX Knight5(BIDAK K){
    return K.posisi-21;
}
BOARD_INDEX Knight6(BIDAK K){
    return K.posisi-12;
}
BOARD_INDEX Knight7(BIDAK K){
    return K.posisi+8;
}
BOARD_INDEX Knight8(BIDAK K){
    return K.posisi+19;
}
/***** MAIN FUNCTION *****/

Queue_Move AvailableMove(List_Bidak B);
BOARD_INDEX GetKingPos(List_Bidak B);
boolean IsMove(BIDAK B, BOARD_INDEX KingPos){

    if (B.tipe==PAWN){

    }else if (B.tipe==KNIGHT){

    }else{

    }

}
boolean KingCheck(BIDAK B, BOARD_INDEX KingPos);
List_Move GenerateMove(BIDAK B);