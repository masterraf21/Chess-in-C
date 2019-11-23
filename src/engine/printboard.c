#include "printboard.h"

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
        IsiTile((8-i),2,b);
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