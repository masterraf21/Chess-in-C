#ifndef MOVE_H
#define MOVE_H

#include "chess.h"
#include "board.h"
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
List_Move GenerateMove(BIDAK B);

//helper functions conerning ray function
//and check checking
boolean IsMoveLegal(MOVE M);
BOARD_INDEX GetKingPos(List_Bidak B);
boolean IsKingCheck(BIDAK B, BOARD_INDEX KingPos);
boolean IsKingSafe(BOARD_INDEX KingPos, int *ray, int *dummyboard);
int * CreateDummyBoard(BOARD B);
void DummytoRay(int *dummy, int **ray);
int * CreateRay(BOARD B);
int * CheckRay(BOARD B, COLOR C);


//Move generator perbidak
void GenWPawn(BOARD B, BIDAK WPawn, List_Move *L);
void GenBPawn(BOARD B, BIDAK BPAWN, List_Move *L);
void GenRook(BOARD B, BIDAK R, List_Move *L);
void GenBishop(BOARD B, BIDAK Bi, List_Move *L);
void GenKnight(BOARD B, BIDAK K, List_Move *L);
void GenQueen(BOARD B, BIDAK Q, List_Move *L);
void GenKing(BOARD B, BIDAK K, List_Move *L);

//interface penghubung list sama move
void AddMove(List_Move *L, BIDAK Mover, BOARD_INDEX Target_Index);
void AddMakan(List_Move *L, BIDAK Mover, BOARD_INDEX Target_Index, BIDAK Victim);




#endif