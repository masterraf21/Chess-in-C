#include <stdlib.h>
#include "move.h"

/**** HELPER FUNCTION *****/
BOARD_INDEX Neighbor(BIDAK B);
BOARD_INDEX Up(BIDAK B){
    return B.posisi+10;
}
BOARD_INDEX Up_i(BIDAK B, int i){
    if (i==1)
        return Up(B);
    else 
        return B.posisi+10*i;
}
BOARD_INDEX Down(BIDAK B){
    return B.posisi-10;
}
BOARD_INDEX Down_i(BIDAK B, int i){
    if (i==1)
        return Down(B);
    else
        return B.posisi-10*i;
}
BOARD_INDEX Left(BIDAK B){
    return B.posisi-1;
}
BOARD_INDEX Left_i(BIDAK B, int i){
    if (i==1)
        return Left(B);
    else 
        return B.posisi-1*i;
}
BOARD_INDEX Right(BIDAK B){
    return B.posisi+1;
}
BOARD_INDEX Right_i(BIDAK B, int i){
    if (i==1)
        return Right(B);
    else 
        return B.posisi+1*i;
}
/* SERONG */
BOARD_INDEX SerongKananAtas(BIDAK B){
    return B.posisi+11;
}
BOARD_INDEX SerongKananAtas_i(BIDAK B, int i){
    if (i==1)
        return SerongKananAtas(B);
    else 
        return B.posisi+11*i;
}
BOARD_INDEX SerongKananBawah(BIDAK B){
    return B.posisi-9;
}
BOARD_INDEX SerongKananBawah_i(BIDAK B, int i){
    if (i==1)
        return SerongKananBawah(B);
    else 
        return B.posisi-9;
}
BOARD_INDEX SerongKiriAtas(BIDAK B){
    return B.posisi+9;
}
BOARD_INDEX SerongKiriAtas_i(BIDAK B, int i){
    if (i==1)
        return SerongKiriAtas(B);
    else 
        return B.posisi+9;
}
BOARD_INDEX SerongKiriBawah(BIDAK B){
    return B.posisi-11;
}
BOARD_INDEX SerongKiriBawah_i(BIDAK B, int i){
    if (i==1)
        return SerongKiriBawah(B);
    else 
        return B.posisi-11;
}
/* BUAT KUDA */
BOARD_INDEX Knight1(BIDAK K){
    return K.posisi+21;
}
BOARD_INDEX Knight2(BIDAK K){
    return K.posisi+12;
}
BOARD_INDEX Knight3(BIDAK K){
    return K.posisi-8;
}
BOARD_INDEX Knight4(BIDAK K){
    return K.posisi-19;
}
BOARD_INDEX Knight5(BIDAK K){
    return K.posisi-21;
}
BOARD_INDEX Knight6(BIDAK K){
    return K.posisi-12;
}
BOARD_INDEX Knight7(BIDAK K){
    return K.posisi+8;
}
BOARD_INDEX Knight8(BIDAK K){
    return K.posisi+19;
}

/***** MAIN FUNCTION *****/

//dipake buat nampilin mana aja yang bisa gerak
//pake queue biar enak ngeluarinnya
Queue_Move AvailableMove(List_Bidak B){
    //siapin Output bray
    Queue_Move Q;
    CreateEmpty(&Q);


}
List_Move GenerateMove(BIDAK B){
    List_Move L;
    CreateEmpty(&L);
    
    if((B.tipe==PAWN)&&(B.warna==WHITE)){
        GenWPawn(B, &L);
    }else if(B.tipe==PAWN&&B.warna==BLACK){
        GenBPawn(B, &L);
    }else{
        if (B.tipe==ROOK){
            GenRook(B, &L);
        }else if(B.tipe==BISHOP){
            GenBishop(B, &L);
        }else if(B.tipe==KNIGHT){
            GenKnight(B, &L);
        }else if(B.tipe==QUEEN){
            GenQueen(B, &L);
        }else if(B.tipe==KING){
            GenKing(B, &L);
        }
    }
}

//helper functions
boolean IsMoveLegal(MOVE M);
BOARD_INDEX GetKingPos(List_Bidak B){
    address P = SearchId(B, KINGX);
    if(P!=Nil)
        return Info(P).id;

}
boolean IsKingCheck(BIDAK B, BOARD_INDEX KingPos, int *ray){

}
boolean IsKingSafe(BOARD_INDEX KingPos, int *ray, int *dummyboard){

}
int * CreateDummyBoard(BOARD B){
    int dummy[64];
    DUMMY_INDEX j = A1x;
    for (BOARD_INDEX i = A1; i <= H8; i++)
    {
        dummy[j] = SetBoard(B, i);
        j++;        
    }

    return dummy;
}
void DummytoRay(int *dummy, int **ray, DUMMY_INDEX i){
    i

}
int * CreateRay(BOARD B){
    enum PawnBlack {KingB=-6,QueenB,RookB,BishopB,KnightB,PawnB};
    enum PawnWhite {PawnW=1,KnightW,BishopW,RookW,QueenW,KingW};

    int dummy[64] = CreateDummyBoard(B);
    int ray[64];
    //init the ray with 0s
    for (DUMMY_INDEX i = A1x; i <= H8x; i++)
    {
        ray[i] = 0;
    }
    
    for (DUMMY_INDEX i = A1x; i <= H8x; i++){




    }
}
int * CheckRay(BOARD B, COLOR C){

}

//Move generator perbidak
void GenWPawn(BOARD B, BIDAK WPawn, List_Move *L){
    BOARD_INDEX pos = WPawn.posisi;

}
void GenBPawn(BOARD B, BIDAK BPAWN, List_Move *L){
    BOARD_INDEX pos = BPAWN.posisi;
    
}
void GenRook(BOARD B, BIDAK R, List_Move *L){
    
    BOARD_INDEX pos = R.posisi;

    /*CHECK ALL SIDES*/
    //upper side first
    if(SetBoard(B,Up(R))!=BAD_SQUARE){
        int i = 1; //iterator tile
        do
        {
            BOARD_TILE nt = SetBoard(B, Up_i(R,i));
            
            if(Enemy(R,nt)){
                
            }else if(Friend(R,nt)){

            }else/*EMPTY_SQUARE*/{
                
            }
            
        } while(SetBoard(B,Up_i(R,i))==EMPTY_SQUARE);
        
        
        


    }

    if(SetBoard(B,Left(R))!=BAD_SQUARE){
        int i = 1;


    }

    if(SetBoard(B,Right(R))!=BAD_SQUARE){
        int i = 1;

    }

    if(SetBoard(B,Down(R))!=BAD_SQUARE){
        int i = 1;

    }
}
void GenBishop(BOARD B, BIDAK Bi, List_Move *L){

}
void GenKnight(BOARD B, BIDAK K, List_Move *L){

}
void GenQueen(BOARD B, BIDAK Q, List_Move *L){

}
void GenKing(BOARD B, BIDAK K, List_Move *L){

}
