#include "board.h"
#include <stdlib.h>


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
    InitTab(B);
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
// Update
void update_board(BOARD *B, List_Bidak L){

}
// Draw procedure
void draw_board(BOARD B)
{
    
}

void IsiTile(int nobaris, int nokolom, char bidak)
{
  printf("%d", nobaris);
   int i, last;
   last = 9;
   for (i=1; i <=9; ++i)
   {
       if (i!=nokolom)
       {
           if (i!=9)
           {
           printf("|     ");
           } 
           else
           {
               printf("|%d", nobaris);
           }
           
       }
        else if (i=nokolom) {
           printf("|  %c  ",bidak);
       }
        
        
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

//misal karakter bidaknya pake h
b = 'h';

void PrintBoard()
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

    for (i=0;i<=7;i++)
    {
        AtasTile();
        IsiTile((i),2,b);
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

;
