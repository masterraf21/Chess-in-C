#ifndef MOVE_H
#define MOVE_H

#include "chess.h"
#include "../adt/listmove.h"
#include "../adt/listbidak.h"
#include "../adt/queuemove.h"

/**** HELPER FUNCTION *****/
BOARD_INDEX Neighbor(BIDAK B);
BOARD_INDEX Up(BIDAK B);
BOARD_INDEX Up_i(BIDAK B, int i);
BOARD_INDEX Down(BIDAK B);
BOARD_INDEX Down_i(BIDAK B, int i);
BOARD_INDEX Left(BIDAK B);
BOARD_INDEX Left_i(BIDAK B, int i);
BOARD_INDEX Right(BIDAK B);
BOARD_INDEX Right_i(BIDAK B, int i);
/* SERONG */
BOARD_INDEX SerongKananAtas(BIDAK B);
BOARD_INDEX SerongKananAtas_i(BIDAK B, int i);
BOARD_INDEX SerongKananBawah(BIDAK B);
BOARD_INDEX SerongKananBawah_i(BIDAK B, int i);
BOARD_INDEX SerongKiriAtas(BIDAK B);
BOARD_INDEX SerongKiriAtas_i(BIDAK B, int i);
BOARD_INDEX SerongKiriBawah(BIDAK B);
BOARD_INDEX SerongKiriBawah_i(BIDAK B, int i);
/* BUAT KUDA */
BOARD_INDEX Knight1(BIDAK K);
BOARD_INDEX Knight2(BIDAK K);
BOARD_INDEX Knight3(BIDAK K);
BOARD_INDEX Knight4(BIDAK K);
BOARD_INDEX Knight5(BIDAK K);
BOARD_INDEX Knight6(BIDAK K);
BOARD_INDEX Knight7(BIDAK K);
BOARD_INDEX Knight8(BIDAK K);


/***** SEARCH FUNCTION ******/

/***** MAIN FUNCTION *****/
//dipake buat nampilin mana aja yang bisa gerak
//pake queue biar enak ngeluarinnya
Queue_Move AvailableMove(List_Bidak B);
//helper function buat generate legal move
//3 fungsi dibawah nyambung
void GeneratePseudo()
BOARD_INDEX GetKingPos(List_Bidak B);
boolean IsMove(BIDAK B, BOARD_INDEX KingPos);
boolean KingCheck(BIDAK B, BOARD_INDEX KingPos);
//Generate move beneran
List_Move GenerateMove(BIDAK B);













#endif