#include "board.h"
#include <stdlib.h>
#include <stdio.h>

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
    address_bidak P = SearchId(*LSelf, id);
    InfoBidak(P).posisi = M.new_position;
}
void UpdateMakan(List_Bidak *LEnemy, MOVE M){
    BIDAK Victim = M.victim;
    //Karena dia dimakan jadi di dealokasiin dari list musuh
    DelP(LEnemy, Victim);
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
    

}

/***** KONSTRUKTOR *******/
// Init board kita kondisikan
// agar dia seperti kondisi awal chess
void init_board(BOARD *B)
{

    //Buat dulu ListW dan List B nya
    List_Bidak ListW;InitListBidak(&ListW, WHITE);
    List_Bidak ListB;InitListBidak(&ListB, BLACK);
    //Assign ke structnya
    LPutih(*B) = ListW;
    LHitam(*B) = ListB;

    //Assign Array dengan kondisi awal chess
    //InitTab((&B)->Tab);
    /*Bidak*/
    //Pawn dulu 
    for (BOARD_INDEX i = A2; i <= H2; i++)
        SetBoard(*B,i) = WHITE*PAWN;
    for (BOARD_INDEX i = A7; i <= H7; i++)
        SetBoard(*B,i) = BLACK*PAWN;
    //Rook
    SetBoard(*B,A1) = WHITE*ROOK;SetBoard(*B,H1) = WHITE*ROOK;
    SetBoard(*B,A8) = BLACK*ROOK;SetBoard(*B,H8) = BLACK*ROOK;
    //Knight
    SetBoard(*B,B1) = WHITE*KNIGHT;SetBoard(*B,G1) = WHITE*KNIGHT;
    SetBoard(*B,B8) = BLACK*KNIGHT;SetBoard(*B,G8) = BLACK*KNIGHT;
    //Bishop
    SetBoard(*B,C1) = WHITE*BISHOP;SetBoard(*B,F1) = WHITE*BISHOP;
    SetBoard(*B,C8) = BLACK*BISHOP;SetBoard(*B,F8) = BLACK*BISHOP;
    //King
    SetBoard(*B,D1) = WHITE*KING;SetBoard(*B,D8) = BLACK*KING;
    //Queen
    SetBoard(*B,E1) = WHITE*QUEEN;SetBoard(*B,E8) = BLACK*QUEEN;
   
    /* Empty Squares */
    for (BOARD_INDEX i = A3; i <= H3; i++)
        SetBoard(*B,i) = EMPTY_SQUARE;
    for (BOARD_INDEX i = A4; i <= H4; i++)
        SetBoard(*B,i) = EMPTY_SQUARE;
    for (BOARD_INDEX i = A5; i <= H5; i++)
        SetBoard(*B,i) = EMPTY_SQUARE;
    for (BOARD_INDEX i = A6; i <= H6; i++)
        SetBoard(*B,i) = EMPTY_SQUARE;

    /* Off-Board */
    for (BAD_INDEX i = 0; i <= 19; i++)
        SetBoard(*B,i) = BAD_SQUARE;
    for (BAD_INDEX i = 100; i <= 119; i++)
        SetBoard(*B,i) = BAD_SQUARE;
    for (BAD_INDEX i = 20; i <= 90; i+=10)
        SetBoard(*B,i) = BAD_SQUARE;
    for (BAD_INDEX i = 29; i <= 99; i += 10)
        SetBoard(*B,i) = BAD_SQUARE;
}


// Pra-Draw procedure
char IntToCharBidak(int n)
{
    char c;
    if (n== -1)
    {
        c = 'P'; //black pawn
    }
    else if (n == (-2))
    {
        c = 'H'; //black knight
    }
    else if (n == (-3))
    {
        c = 'B'; //black bishop
    }
    else if (n == (-4))
    {
        c = 'R'; //black rook
    }
    else if (n== (-5))
    {
        c = 'Q'; //black queen
    }
    else if (n== (-6))
    {
        c = 'K';  //black king
    }
    else if (n == (1))
    {
        c = 'p'; //white pawn
    }
    else if (n == (2))
    {
        c = 'h'; //white knight
    }
    else if (n == (3))
    {
        c = 'b'; //white bishop
    }
    else if (n == (4))
    {
        c = 'r'; //white rook
    }
    else if (n== (5))
    {
        c = 'q'; //white queen
    }
    else if (n== 6)
    {
        c = 'k';  //white king
    }
    
    return c;
}

int NoBarisToTileIndex(int m)
{
    int Idx;
    Idx = 10+(m*10);
    return Idx;
}

void IsiTile(int nobaris, BOARD B)
{
  printf("%d", nobaris);
   int i;

   for (i=1; i <=9; ++i)
   {
       //if (i!=nokolom)
       //{
           if (i!=9)
           {
                if (i==1)
                {
                printf("|  ");
                printf("%c",IntToCharBidak(SetBoard(B,(NoBarisToTileIndex(nobaris)+i))));
                printf("  ");
                }
                else if (i ==2)
                {
                printf("|  ");
                printf("%c",IntToCharBidak(SetBoard(B,(NoBarisToTileIndex(nobaris)+i))));
                printf("  ");
                }
                else if (i == 3)
                {
                printf("|  ");
                printf("%c",IntToCharBidak(SetBoard(B,(NoBarisToTileIndex(nobaris)+i))));
                printf("  ");
                }
                else if (i == 4)
                {
                printf("|  ");
                printf("%c",IntToCharBidak(SetBoard(B,(NoBarisToTileIndex(nobaris)+i))));
                printf("  "); 
                }
                else if (i == 5)
                {
                printf("|  ");
                printf("%c",IntToCharBidak(SetBoard(B,(NoBarisToTileIndex(nobaris)+i))));
                printf("  ");
                }
                else if (i == 6)
                {
                printf("|  ");
                printf("%c",IntToCharBidak(SetBoard(B,(NoBarisToTileIndex(nobaris)+i))));
                printf("  ");
                }
                else if (i == 7)
                {
                printf("|  ");
                printf("%c",IntToCharBidak(SetBoard(B,(NoBarisToTileIndex(nobaris)+i))));
                printf("  ");
                }
                else if (i == 8)
                {
                printf("|  ");
                printf("%c",IntToCharBidak(SetBoard(B,(NoBarisToTileIndex(nobaris)+i))));
                printf("  ");
                }
           } 
           else
           {
               printf("|%d", nobaris);
           }
           
       //}   GAJADI KAYA GINI TAR MO DIAPUS HEHE MAAP
        //else if (i=nokolom) {
           //printf("|  %c  ",bidak);
       //}
        
        
        }
       
       printf("\n");
   }

   
void AtasTile()
{
    int i;
    printf(" ");
    for (i= 1; i <=9; i++)
            {
                printf("|     ");
                
            }
    printf("\n");
}


void BawahTile()
{
    printf(" ");
    int i;
    for (i=1; i<=9;i++)
    {
        if (i!=9)
        {
            printf("|_____");
        }
        else
        {
            printf("|");
        }
        
    }   
    printf("\n");
}

// Draw - procedure

void PrintBoard(BOARD B)
{
    printf("  __A__ ");
    printf("__B__ ");
    printf("__C__ ");
    printf("__D__ ");
    printf("__E__ ");
    printf("__F__ ");
    printf("__G__ ");
    printf("__H__\n");

    int i;

    for (i=1;i<=8;i++)
    {
        AtasTile();
        IsiTile(i,B);
        BawahTile();
    }

    printf("    A   ");
    printf("  B   ");
    printf("  C   ");
    printf("  D   ");
    printf("  E   ");
    printf("  F   ");
    printf("  G   ");
    printf("  H   \n");

}

