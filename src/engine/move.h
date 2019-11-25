#ifndef MOVE_H
#define MOVE_H

#include "chess.h"
#include "board.h"
#include "../adt/listmove.h"
#include "../adt/listbidak.h"
#include "../adt/queuemove.h"

/**** HELPER FUNCTION *****/
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
/* PAWN FIRST INDEX(s) */
boolean PawnWFirst(BOARD B, BIDAK P);
boolean PawnBFirst(BOARD B, BIDAK P);
boolean IsUpKosong(BOARD B, BIDAK P);
boolean IsDownKosong(BOARD B, BIDAK P);

/***** SEARCH FUNCTION ******/
boolean IsNeighbor(BOARD B, BIDAK Bi);
boolean IsNeighborKnight(BOARD B, BIDAK Bi);
//Fungsi ini bakal ngeluarin mid yang diprompt oleh user
//setelah printing, index diarray selalu -1 dengan yang diprompt
MOVE_ID GetQueueIdx(Queue_Move Q, int IdxPrompt);
MOVE GetListIdx(List_Move L, int IdxPrompt);
BIDAK GetBidakId(List_Bidak L, MOVE_ID Mid);


/***** MAIN FUNCTION *****/
//dipake buat nampilin mana aja yang bisa gerak
//pake queue biar enak ngeluarinnya
Queue_Move AvailableMove(BOARD B, List_Bidak L);
List_Move GenerateMove(BIDAK B, BOARD BO);

//helper functions conerning ray function
//and check checking
// boolean IsMoveLegal(MOVE M);
// BOARD_INDEX GetKingPos(List_Bidak B);
// boolean IsKingCheck(BIDAK B, BOARD_INDEX KingPos);
// boolean IsKingSafe(BOARD_INDEX KingPos, int *ray, int *dummyboard);
// int * CreateDummyBoard(BOARD B);
// void DummytoRay(int *dummy, int **ray, DUMMY_INDEX i);
// int * CreateRay(BOARD B);
// int * CheckRay(BOARD B, COLOR C);


//Move generator perbidak
void GenWPawn(BOARD B, BIDAK WPawn, List_Move *L);
void GenBPawn(BOARD B, BIDAK BPAWN, List_Move *L);
void GenRook(BOARD B, BIDAK R, List_Move *L);
void GenBishop(BOARD B, BIDAK Bi, List_Move *L);
void GenKnight(BOARD B, BIDAK K, List_Move *L);
void GenQueen(BOARD B, BIDAK Q, List_Move *L);
void GenKing(BOARD B, BIDAK K, List_Move *L);

/*** INTERFACE BETWEEN MOVE AND LIST ******/
//color dirinya sendiri
BIDAK SearchMakan(BOARD_INDEX bi, BOARD_TILE bt, BOARD B, COLOR SelfColor);
void AddMove(List_Move *L, BIDAK Mover, BOARD_INDEX Target_Index);
void AddMakan(BOARD B, List_Move *L, BIDAK Mover, BOARD_INDEX VictimIdx, BOARD_TILE VictimTile);

/*** PRINTING FUNCTION ****/
char* IdxtoStr(BOARD_INDEX Idx);
char* TypetoStr(PAWN_TYPE type);
void PrintIdxPos(MOVE_ID Mid, int idx);
void PrintIdxMove(MOVE M, int idx);
void PrintAvailableMove(Queue_Move Q);
void PrintMoveBidak(List_Move L);

#endif