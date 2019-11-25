#include "undo.h"
#include "board.h"


//prosedur swap
//prosedur isundopossible -> cek udh 2 langkah apa blm

/****HELPER FUNCTION USING STACK***/
void SwapTile(BOARD *B, BOARD_INDEX curpos, BOARD_INDEX newpos){
    BOARD_TILE tmp = SetBoard(*B, curpos);
    SetBoard(*B, curpos) = SetBoard(*B, newpos);
    SetBoard(*B, newpos) = tmp;
}
void MakanTile(BOARD *B, BOARD_INDEX prey, BOARD_INDEX victim){
    BOARD_TILE tmp = SetBoard(*B, prey);
    SetBoard(*B, victim) = tmp;
    SetBoard(*B, prey) = EMPTY_SQUARE;
}
void UpdateStack(Stack *S, MOVE M){
    Push(S, M);
}
void UpdateList(List_Bidak *LSelf, MOVE M){
    LIST_ID id = M.id;
    address P = SearchId(*LSelf, id);
    Info(P).posisi = M.new_position;
}
void UpdateMakan(List_Bidak *LEnemy, MOVE M){
    BIDAK Victim = M.victim;
    //Karena dia dimakan jadi di dealokasiin dari list musuh
    DelP(LEnemy, Victim);
}

void UndoBoard(BOARD *B, Stack *S, List_Bidak *Acu, List_Bidak *Lawanacu)
{
    /*kamus lokal*/
    MOVE StepLawan, Stepku;


    /*Algoritma*/
    POP(S, &StepLawan);

    if (!StepLawan.is_makan) //kalo dia ga abis makan
    {
        UpdateList(&Lawanacu, StepLawan);
        SwapTile(B, StepLawan.new_position, StepLawan.cur_position);
    }

    else //dia abis makan
    {

    }

    POP(S, &Stepku);

    if (Stepku.is_makan) //kalo aku ga abis makan
    {
        UpdateList(&Acu, Stepku);
        SwapTile(B,Stepku.new_position, Stepku.cur_position);
    }
    else //aku abis makan
    {
        
    }
    
}

void UpdateBoard(BOARD *B, MOVE M){
    List_Bidak LPutih = (*B).LPutih;
    List_Bidak LHitam = (*B).LHitam;
    //Yang ga makan dulu
    
    if (!M.is_makan){

        if (M.warna==WHITE)
            UpdateList(&LPutih, M);
        else/*Black*/
            UpdateList(&LHitam, M);
        
        //Karna ga makan, kita cuman swap nilai di cur pos
        //sama new pos di board

        SwapTile(B, M.cur_position, M.new_position);

    }else{
        if (M.warna==WHITE){
            UpdateList(&LPutih, M);
            UpdateMakan(&LHitam, M);
        }else{
            UpdateList(&LHitam, M);
            UpdateMakan(&LPutih, M); 
        }
        MakanTile(B, M.cur_position, M.new_position);
    }
    
//jika makan kembaliin bidak yang lama
    //push lagi apa kaga sih
    //kalo undo berkali-kali swapnya gimana
    PrintBoard(B);
}


