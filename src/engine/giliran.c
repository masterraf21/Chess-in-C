#include "giliran.h"
#include <stdlib.h>

void InitGiliran(Queue_Giliran *Q)
{
	/*KAMUS*/
	infotypeturn B, W;
	B.player = BLACK;
	B.counter = 0;
	B.poin = 0;
	W.player = WHITE;
	W.counter = 0;
	W.poin = 0;
	/*ALGORITMA*/
	CreateEmptyTurn(Q);
	AddTurn(Q,W);
	AddTurn(Q,B);
}

int Poin(MOVE M)
{
	switch (M.victim.id.type) {
            case PAWN : return 1;
                    break;
            case KNIGHT : return 2;
                    break;
            case ROOK : return 4;
                    break;
            case BISHOP : return 4;
                    break;     
            case QUEEN : return 8;
            		break;
           	case KING : return 10;
           			break;
        }
}

// void changeTurnMove(Queue_Giliran *Q, infotypeturn *currPlayerInfo, MOVE *M)
// {
// 	if ((*M).is_makan) {
// 		(*currPlayerInfo).poin = (*currPlayerInfo).poin + Poin(M);
// 	}
// 	(*currPlayerInfo).counter ++;
// 	AddTurn(Q, (*currPlayerInfo));
// 	DelTurn(Q, (currPlayerInfo));
// }

// void changeTurnUndo(Queue_Giliran *Q, infotypeturn *currPlayerInfo, MOVE *M)
// {
// 	if ((*M).is_makan) {
// 		(*currPlayerInfo).poin = (*currPlayerInfo).poin - Poin(M);
// 	}
// 	(*currPlayerInfo).counter --;
// 	DelTurn(Q, currPlayerInfo);
// 	AddTurn(Q, (*currPlayerInfo));
// }


boolean Is50Turn(Queue_Giliran Q)
{
	return (((InfoHeadT(Q).counter) == 50) && ((InfoTailT(Q).counter) == 50));
}