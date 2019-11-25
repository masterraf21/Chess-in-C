#include "undo.h"
#include "board.h"
//#include ""
void CreateEmptyElmtStack(ELMT_STACK S)
{

}

//prosedur swap
//prosedur isundopossible -> cek udh 2 langkah apa blm

void Undo(BOARD B, Stack *S, List_Bidak *Acu, List_Bidak *Lawanacu)
{
    /*Kamus Lokal*/
    ELMT_STACK UndoStack;
    MOVE StepLawan;
    MOVE Stepku;
    BOARD_INDEX temp, temp1;

    /*Algoritma*/
    CreateEmptyElmtStack(UndoStack);

    Pop(S, &StepLawan);
    Pop(S, &Stepku);

    //swap cur pos dengan prev pos
    temp = StepLawan.cur_position;
    StepLawan.cur_position = StepLawan.new_position;
    StepLawan.new_position = temp;
    UpdateList(Lawanacu,StepLawan);
    UpdateBoard(&B,StepLawan);


    temp1 = Stepku.cur_position;
    Stepku.cur_position = Stepku.new_position;
    Stepku.new_position = temp;
    UpdateList(Acu,Stepku);
    UpdateBoard(&B,Stepku);

    //jika makan kembaliin bidak yang lama
    //push lagi apa kaga sih
   
    PrintBoard(B);



}

