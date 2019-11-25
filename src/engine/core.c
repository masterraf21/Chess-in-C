#include "core.h"

void MoveCore(BOARD *B, Stack *S, infotypeturn *R, boolean *done){
        List_Bidak LPutih = (*B).LPutih;
        List_Bidak LHitam = (*B).LHitam;
        List_Bidak L;
        if ((*R).player==WHITE){
                L = LPutih;
        }else{
                L = LHitam;
        }

        //Generate Possible move of all bidaks
        //and print
        Queue_Move Q = AvailableMove(*B, L);
        PrintAvailableMove(Q);
        printf("Pilih bidak yang ingin digerakkan: ");
        int idx;
        scanf("%d\n", &idx);
        MOVE_ID Mid = GetQueueIdx(Q, idx);
        BIDAK Bi = GetBidakId(L, Mid);//we get bidak here

        //Next move is to generate the list move from the one bidak we have
        List_Move Lm = GenerateMove(Bi, *B);
        //Print the mtf
        PrintMoveBidak(Lm);
        printf("Pilih posisi tujuan bidak: ");
        scanf("%d\n", &idx);
        MOVE Mov = GetListIdx(Lm, idx);
        //udah dapet move nih gan
        PrintBerpindah(Mov);
        if (Mov.is_makan) {
		(*R).poin = (*R).poin + Poin(Mov);
	}
        (*R).counter++;
        //Saatnya updet mengupdate
        UpdateStack(S, Mov);
        UpdateBoard(B, Mov);
        // if ((*R).player==WHITE){
        //         (*done) = checkmate(LHitam);
        // }else{
        //         (*done) = checkmate(LPutih);
        // }
}

void UndoCore(BOARD *D, Stack *S, infotypeturn *R){
        MOVE step;
        Pop(S,&step);
        List_Bidak Put = (*D).LPutih;
        List_Bidak Hit = (*D).LHitam;
        List_Bidak aku ;
        List_Bidak lawan ;
        if (step.warna == WHITE){
                aku = Put;
                lawan = Hit;
        } else{
                aku = Hit;
                lawan = Put;
        }
        if (step.is_makan){
                InsVFirst( &lawan, step.victim); //realokasi bidak victim
                (*R).poin = (*R).poin - Poin(step);
        }
        UpdateUndoList (&aku,step);
        SwapTile(D,step.new_position,step.cur_position);
        (*R).counter--;

        if (step.warna == WHITE){
                Put = aku;
                Hit = lawan;
        } else{
                Hit = aku;
                Put = lawan;
        }
        (*D).LPutih = Put;
        (*D).LHitam = Hit;
}
