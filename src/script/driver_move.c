#include "../engine/move.h"
#include <stdio.h>

void Move(BOARD *B, Stack *S, COLOR C){
    List_Bidak LPutih = (*B).LPutih;
    List_Bidak LHitam = (*B).LHitam;
    List_Bidak L;
    if (C==WHITE){
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

    //Saatnya updet mengupdate
    UpdateStack(&S, Mov);
    UpdateBoard(&B, Mov);

}

int main(){
    BOARD B;
     //init board dulu slurr
    init_board(&B);
    //Let's simulate something to generate move
    //Init stack lur
    Stack S;
    CreateEmptyStack(&S);

    //the real deal slur
    Move(&B, &S, WHITE);
    Move(&B, &S, BLACK);
    
}

