#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "move.h"

/**** HELPER FUNCTION *****/
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
/* PAWN FIRST INDEX(s) */
boolean PawnWFirst(BOARD B, BIDAK P){
    PAWN_ID num = P.id.number;
    PAWN_TYPE typ = P.id.type;
    BOARD_INDEX pos = P.posisi;

    if((num==ONE)&&(typ==PAWN)&&(pos==A2)){
        return true;
    }else if((num==TWO)&&(typ==PAWN)&&(pos==B2)){
        return true;
    }else if((num==THREE)&&(typ==PAWN)&&(pos==C2)){
        return true;
    }else if((num==FOUR)&&(typ==PAWN)&&(pos==D2)){
        return true;
    }else if((num==FIVE)&&(typ==PAWN)&&(pos==E2)){
        return true;
    }else if((num==SIX)&&(typ==PAWN)&&(pos==F2)){
        return true;
    }else if((num==SEVEN)&&(typ==PAWN)&&(pos==G2)){
        return true;
    }else if((num==EIGHT)&&(typ==PAWN)&&(pos==H2)){
        return true;
    }else{
        return false;
    }

}
boolean PawnBFirst(BOARD B, BIDAK P){
    PAWN_ID num = P.id.number;
    PAWN_TYPE typ = P.id.type;
    BOARD_INDEX pos = P.posisi;

    if((num==ONE)&&(typ==PAWN)&&(pos==A7)){
        return true;
    }else if((num==TWO)&&(typ==PAWN)&&(pos==B7)){
        return true;
    }else if((num==THREE)&&(typ==PAWN)&&(pos==C7)){
        return true;
    }else if((num==FOUR)&&(typ==PAWN)&&(pos==D7)){
        return true;
    }else if((num==FIVE)&&(typ==PAWN)&&(pos==E7)){
        return true;
    }else if((num==SIX)&&(typ==PAWN)&&(pos==F7)){
        return true;
    }else if((num==SEVEN)&&(typ==PAWN)&&(pos==G7)){
        return true;
    }else if((num==EIGHT)&&(typ==PAWN)&&(pos==H7)){
        return true;
    }else{
        return false;
    }

}
boolean IsUpKosong(BOARD B, BIDAK P){
    return (SetBoard(B, Up(P))==EMPTY_SQUARE);
}
boolean IsDownKosong(BOARD B, BIDAK P){
    return (SetBoard(B, Down(P))==EMPTY_SQUARE);
}

/***** SEARCH FUNCTION ******/
boolean IsNeighbor(BOARD B, BIDAK Bi){
    BOARD_TILE up,down,left,right,skat,skab,skit,skib;
    up=SetBoard(B,Up(Bi));down=SetBoard(B,Down(Bi));left=SetBoard(B,Left(Bi));right=SetBoard(B,Right(Bi));
    skat=SetBoard(B,SerongKananAtas(Bi));skab=SetBoard(B,SerongKananBawah(Bi));
    skit=SetBoard(B,SerongKiriAtas(Bi));skib=SetBoard(B,SerongKiriBawah(Bi));

    if((Bi.id.type==KING)||(Bi.id.type==QUEEN)){
        return ((up==EMPTY_SQUARE)||(Enemy(Bi,up))||(down==EMPTY_SQUARE)||(Enemy(Bi,down))
        ||(left==EMPTY_SQUARE)||(Enemy(Bi,left))||(right==EMPTY_SQUARE)||(Enemy(Bi,right))
        ||(skat==EMPTY_SQUARE)||(Enemy(Bi,skat))||(skab==EMPTY_SQUARE)||(Enemy(Bi,skab))
        ||(skit==EMPTY_SQUARE)||(Enemy(Bi,skit))||(skib==EMPTY_SQUARE)||(Enemy(Bi,skib)));
    }else if(Bi.id.type==ROOK){
        return ((up==EMPTY_SQUARE)||(Enemy(Bi,up))||(down==EMPTY_SQUARE)||(Enemy(Bi,down))
        ||(left==EMPTY_SQUARE)||(Enemy(Bi,left))||(right==EMPTY_SQUARE)||(Enemy(Bi,right)));
    }else if((Bi.id.type==PAWN)&&(Bi.warna==WHITE)){
        return (up==EMPTY_SQUARE)||(Enemy(Bi,skat))||(Enemy(Bi,skit));
    }
    else if ((Bi.id.type==PAWN)&&(Bi.warna==BLACK)){
        return (down==EMPTY_SQUARE)||(Enemy(Bi,skab))||(Enemy(Bi,skib));
    }else/*BISHOP*/{
        return ((skat==EMPTY_SQUARE)||(Enemy(Bi,skat))||(skab==EMPTY_SQUARE)||(Enemy(Bi,skab))
        ||(skit==EMPTY_SQUARE)||(Enemy(Bi,skit))||(skib==EMPTY_SQUARE)||(Enemy(Bi,skib)));
    }
}

boolean IsNeighborKnight(BOARD B, BIDAK Bi){
    BOARD_TILE k1,k2,k3,k4,k5,k6,k7,k8;
    k1=SetBoard(B, Knight1(Bi));k1=SetBoard(B, Knight2(Bi));k1=SetBoard(B, Knight3(Bi));k1=SetBoard(B, Knight4(Bi));
    k1=SetBoard(B, Knight5(Bi));k1=SetBoard(B, Knight6(Bi));k1=SetBoard(B, Knight7(Bi));k1=SetBoard(B, Knight8(Bi));

    return ((k1==EMPTY_SQUARE)||(Enemy(Bi,k1))||(k2==EMPTY_SQUARE)||(Enemy(Bi,k2))||(k3==EMPTY_SQUARE)||(Enemy(Bi,k3))
    ||(k4==EMPTY_SQUARE)||(Enemy(Bi,k4))||(k5==EMPTY_SQUARE)||(Enemy(Bi,k5))||(k6==EMPTY_SQUARE)||(Enemy(Bi,k6))
    ||(k7==EMPTY_SQUARE)||(Enemy(Bi,k7))||(k8==EMPTY_SQUARE)||(Enemy(Bi,k8)));
}

MOVE_ID GetQueueIdx(Queue_Move Q, int IdxPrompt){
    int elmt = NbElmtQ(Q);
    Queue_Move Qb = Q;
    MOVE_ID move[elmt];//buat nyimpen

    //Ambil element queue jadiin array biasa
    MOVE_ID tmp;
    for (int i = 0; i < elmt; i++)
    {
        DelQ(&Qb, &tmp);
        move[i] = tmp;
    }

    return move[IdxPrompt-1];
}

MOVE GetListIdx(List_Move L, int IdxPrompt){
    int elmt = NbElmtM(L);
    MOVE mov[elmt];
    //masukin ke array biar mudah sis
    address_move P = FirstMove(L);
    int i=0;
    MOVE M;
    while(P!=Nil){
        M = InfoMove(P);
        mov[i] = M;
        P = NextMove(P);
        i++;
    }

    return mov[IdxPrompt-1];
}

BIDAK GetBidakId(List_Bidak L, MOVE_ID Mid){
    address_bidak P = SearchId(L, Mid.id);
    return InfoBidak(P);
}

/***** MAIN FUNCTION *****/
//dipake buat nampilin mana aja yang bisa gerak
//pake queue biar enak ngeluarinnya
Queue_Move AvailableMove(BOARD B, List_Bidak L){
    //siapin Output bray
    Queue_Move Q;
    CreateEmptyQ(&Q);
    //Iterate inside the list
    BIDAK Bi;
    MOVE_ID Mid;
    address_bidak P = FirstBidak(L);
    while(P!=Nil){
        Bi = InfoBidak(P);
        if(Bi.id.type==KNIGHT){
            Mid.id = Bi.id;
            Mid.posisi = Bi.posisi;
            if(IsNeighborKnight(B,Bi)){
                AddQ(&Q,Mid);
            }
        }else/*selain knight*/{
            if(IsNeighbor(B,Bi)){
                AddQ(&Q,Mid);
            }
        }
        P = NextBidak(P);
    }


    return Q;
}
List_Move GenerateMove(BIDAK B, BOARD BO){
    List_Move L;
    CreateEmptyM(&L);
    
    if((B.id.type==PAWN)&&(B.warna==WHITE)){
        GenWPawn(BO, B, &L);
    }else if(B.id.type==PAWN&&B.warna==BLACK){
        GenBPawn(BO, B, &L);
    }else{
        if (B.id.type==ROOK){
            GenRook(BO, B, &L);
        }else if(B.id.type==BISHOP){
            GenBishop(BO, B, &L);
        }else if(B.id.type==KNIGHT){
            GenKnight(BO, B, &L);
        }else if(B.id.type==QUEEN){
            GenQueen(BO, B, &L);
        }else if(B.id.type==KING){
            GenKing(BO, B, &L);
        }
    }

    return L;
}

//ray checking kayaknya gaakan diimplement
// boolean IsMoveLegal(MOVE M);
// BOARD_INDEX GetKingPos(List_Bidak B){
//     address P = SearchId(B, KING);
//     if(P!=Nil)
//         return InfoQM(P).id.type;

// }
// boolean IsKingCheck(BIDAK B, BOARD_INDEX KingPos, int *ray){

// }
// boolean IsKingSafe(BOARD_INDEX KingPos, int *ray, int *dummyboard){

// }
// int * CreateDummyBoard(BOARD B){
//     int dummy[64];
//     DUMMY_INDEX j = A1x;
//     for (BOARD_INDEX i = A1; i <= H8; i++)
//     {
//         dummy[j] = SetBoard(B, i);
//         j++;        
//     }

//     return dummy;
// }
// void DummytoRay(int *dummy, int **ray, DUMMY_INDEX i){
    

// }
// int * CreateRay(BOARD B){
//     enum PawnBlack {KingB=-6,QueenB,RookB,BishopB,KnightB,PawnB};
//     enum PawnWhite {PawnW=1,KnightW,BishopW,RookW,QueenW,KingW};

//     int dummy[64] = CreateDummyBoard(B);
//     int ray[64];
//     //init the ray with 0s
//     for (DUMMY_INDEX i = A1x; i <= H8x; i++)
//     {
//         ray[i] = 0;
//     }
    
//     for (DUMMY_INDEX i = A1x; i <= H8x; i++){




//     }
// }
// int * CheckRay(BOARD B, COLOR C){

// }

//Move generator perbidak

void GenWPawn(BOARD B, BIDAK WPawn, List_Move *L){

    BOARD_INDEX IdxKanan = SerongKananAtas(WPawn);
    BOARD_TILE TKanan = SetBoard(B, IdxKanan);
    BOARD_INDEX IdxKiri = SerongKiriAtas(WPawn);
    BOARD_TILE TKiri = SetBoard(B, IdxKiri);

    if(IsUpKosong(B,WPawn)){
        if(PawnWFirst(B,WPawn)){
            //jalan satu
            AddMove(L, WPawn, Up(WPawn));
            //jalan dua
            AddMove(L, WPawn, Up_i(WPawn, 2));

            //makan
            if(Enemy(WPawn, TKanan)){
                AddMakan(B, L, WPawn, IdxKanan, TKanan);
            }
            if(Enemy(WPawn, TKiri)){;
                AddMakan(B, L, WPawn, IdxKiri, TKiri);
            }
        }else{
            //cuman jalan satu aja
            AddMove(L, WPawn, Up(WPawn));

            //makan
            if(Enemy(WPawn, TKanan)){
                AddMakan(B, L, WPawn, IdxKanan, TKanan);
            }
            if(Enemy(WPawn, TKiri)){;
                AddMakan(B, L, WPawn, IdxKiri, TKiri);
            }

        }

    }
    //kalau gak kosong cek dia bisa makan ga di serongnya
    else{        
        if(Enemy(WPawn, TKanan)){
            AddMakan(B, L, WPawn, IdxKanan, TKanan);
        }
        if(Enemy(WPawn, TKiri)){
            AddMakan(B, L, WPawn, IdxKiri, TKiri);
        }
    }

}
void GenBPawn(BOARD B, BIDAK BPawn, List_Move *L){

    BOARD_INDEX IdxKanan = SerongKananBawah(BPawn);
    BOARD_TILE TKanan = SetBoard(B, IdxKanan);
    BOARD_INDEX IdxKiri = SerongKiriBawah(BPawn);
    BOARD_TILE TKiri = SetBoard(B, IdxKiri);

    
    if(IsDownKosong(B,BPawn)){
       
        if(PawnWFirst(B,BPawn)){
            //jalan satu
            AddMove(L, BPawn, Down(BPawn));
            //jalan dua
            AddMove(L, BPawn, Down_i(BPawn,2));

            //makan
            if(Enemy(BPawn, TKanan)){
                AddMakan(B, L, BPawn, IdxKanan, TKanan);
            }
            if(Enemy(BPawn, TKiri)){
                AddMakan(B, L, BPawn, IdxKiri, TKiri);
            }

            
        }else{
            //cuman jalan satu aja
            AddMove(L, BPawn, Down(BPawn));

            //makan
            if(Enemy(BPawn, TKanan)){
                AddMakan(B, L, BPawn, IdxKanan, TKanan);
            }
            if(Enemy(BPawn, TKiri)){
                AddMakan(B, L, BPawn, IdxKiri, TKiri);
            }
        }
    }
    //kalau gak kosong cek dia bisa makan ga di serongnya
    else{
        //makan
       if(Enemy(BPawn, TKanan)){
            AddMakan(B, L, BPawn, IdxKanan, TKanan);
        }
        if(Enemy(BPawn, TKiri)){
            AddMakan(B, L, BPawn, IdxKiri, TKiri);
        }
    }
}

void GenRook(BOARD B, BIDAK R, List_Move *L){

    /*CHECK ALL SIDES*/
    //upper side first
    if(SetBoard(B,Up(R))!=BAD_SQUARE){
        int i = 1; //iterator tile
        BOARD_INDEX ni = Up_i(R,i);
        BOARD_TILE nt = SetBoard(B, ni);    
        do
        {
            ni = Up_i(R,i);
            nt = SetBoard(B, ni);
            
            if(Enemy(R,nt))/*Makan*/{
                AddMakan(B, L, R, ni, nt);
            }else if(Friend(R,nt))/*Terhalang*/{
                //kalau terhalang yaudah gausah jalan lagi kedepan
                break;
            }else/*Kosong*/{
                //maju kesana gan
                AddMove(L, R, ni);
            }   
            i++;
        }while(nt!=BAD_SQUARE);
    
    }

    if(SetBoard(B,Left(R))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX ni = Left_i(R,i);
        BOARD_TILE nt = SetBoard(B, ni);    
        do
        {
            ni = Left_i(R,i);
            nt = SetBoard(B,ni);
            
            if(Enemy(R,nt))/*Makan*/{
                AddMakan(B, L, R, ni, nt);
            }else if(Friend(R,nt))/*Terhalang*/{
                //kalau terhalang yaudah gausah jalan lagi kedepan
                break;
            }else/*Kosong*/{
                AddMove(L, R, ni);
            }   
            i++;
        } while(nt!=BAD_SQUARE);


    }

    if(SetBoard(B,Right(R))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX ni = Right_i(R,i);
        BOARD_TILE nt = SetBoard(B, ni);  
        do
        {
            ni = Right_i(R,i);
            nt = SetBoard(B,ni);
            
            if(Enemy(R,nt))/*Makan*/{
                AddMakan(B, L, R, ni, nt);
            }else if(Friend(R,nt))/*Terhalang*/{
                //kalau terhalang yaudah gausah jalan lagi kedepan
                break;
            }else/*Kosong*/{
                AddMove(L, R, ni);
            }   

            i++;
        } while(nt!=BAD_SQUARE);

    }

    if(SetBoard(B,Down(R))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX ni = Down_i(R,i);
        BOARD_TILE nt = SetBoard(B, ni); 
        do
        {
            ni = Down_i(R,i);
            nt = SetBoard(B,ni);
            
            if(Enemy(R,nt))/*Makan*/{
                AddMakan(B, L, R, ni, nt);
            }else if(Friend(R,nt))/*Terhalang*/{
                //kalau terhalang yaudah gausah jalan lagi kedepan
                break;
            }else/*Kosong*/{
                AddMove(L, R, ni);
            }   

            i++;
        } while(nt!=BAD_SQUARE);

    }
}
void GenBishop(BOARD B, BIDAK Bi, List_Move *L){

    if(SetBoard(B,SerongKananAtas(Bi))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX ni = SerongKananAtas_i(Bi,i);
        BOARD_TILE nt = SetBoard(B, ni); 
        do
        {
            ni = SerongKananAtas_i(Bi,i);
            nt = SetBoard(B, ni); 
            if (Friend(Bi, nt)){
                break;
            }else if(Enemy(Bi,nt)){
                AddMakan(B, L, Bi, ni, nt);
            }else{
                AddMove(L, Bi, ni); 
            }
            i++;
        } while (nt!=BAD_SQUARE);
        
    }

    if(SetBoard(B,SerongKiriAtas(Bi))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX ni = SerongKiriAtas_i(Bi,i);
        BOARD_TILE nt = SetBoard(B, ni); 
        do
        {
            ni = SerongKiriAtas_i(Bi,i);
            nt = SetBoard(B, ni); 
            if(Friend(Bi, nt)){
                break;
            }else if(Enemy(Bi,nt)){
                AddMakan(B, L, Bi, ni, nt);
            }else{
                AddMove(L, Bi, ni);
            }
            i++;
        } while (nt!=BAD_SQUARE);
    }    


    if(SetBoard(B,SerongKananBawah(Bi))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX ni = SerongKananBawah_i(Bi,i);
        BOARD_TILE nt = SetBoard(B, ni); 
        do
        {
            ni = SerongKananBawah_i(Bi,i);
            nt = SetBoard(B, ni); 
            if (Friend(Bi, nt)){
                break;
            }else if(Enemy(Bi,nt)){
                AddMakan(B, L, Bi, ni, nt);
            }else{
                AddMove(L, Bi, ni); 
            }
            i++;
        } while (nt!=BAD_SQUARE);
        
    }
  
    if(SetBoard(B,SerongKiriBawah(Bi))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX ni = SerongKiriBawah_i(Bi,i);
        BOARD_TILE nt = SetBoard(B, ni); 
        do
        {
            ni = SerongKiriBawah_i(Bi,i);
            nt = SetBoard(B, ni); 
            if (Friend(Bi, nt)){
                break;
            }else if(Enemy(Bi,nt)){
                AddMakan(B, L, Bi, ni, nt);
            }else{
                AddMove(L, Bi, ni); 
            }
            i++;
        } while (nt!=BAD_SQUARE);
        
    }
}

void GenKnight(BOARD B, BIDAK K, List_Move *L){

    if(SetBoard(B,Knight1(K))!=BAD_SQUARE){

        BOARD_INDEX ki = Knight1(K);
        BOARD_TILE kn = SetBoard(B,ki);
        if(Enemy(K,kn)){
            AddMakan(B, L, K, ki, kn);
        }else/*kosong*/{
            AddMove(L, K, ki);
        }
    }
    if(SetBoard(B,Knight2(K))!=BAD_SQUARE){
        
        BOARD_INDEX ki = Knight2(K);
        BOARD_TILE kn = SetBoard(B,ki);
        if(Enemy(K,kn)){
            AddMakan(B, L, K, ki, kn);
        }else/*kosong*/{
            AddMove(L, K, ki);
        }
    }
    if(SetBoard(B,Knight3(K))!=BAD_SQUARE){

        BOARD_INDEX ki = Knight3(K);
        BOARD_TILE kn = SetBoard(B,ki);
        if(Enemy(K,kn)){
            AddMakan(B, L, K, ki, kn);
        }else/*kosong*/{
            AddMove(L, K, ki);
        }

    }
    if(SetBoard(B,Knight4(K))!=BAD_SQUARE){

        BOARD_INDEX ki = Knight4(K);
        BOARD_TILE kn = SetBoard(B,ki);
        if(Enemy(K,kn)){
            AddMakan(B, L, K, ki, kn);
        }else/*kosong*/{
            AddMove(L, K, ki);
        }

    }
    if(SetBoard(B,Knight5(K))!=BAD_SQUARE){

        BOARD_INDEX ki = Knight5(K);
        BOARD_TILE kn = SetBoard(B,ki);
        if(Enemy(K,kn)){
            AddMakan(B, L, K, ki, kn);
        }else/*kosong*/{
            AddMove(L, K, ki);
        }
    } 
    if(SetBoard(B,Knight6(K))!=BAD_SQUARE){

        BOARD_INDEX ki = Knight6(K);
        BOARD_TILE kn = SetBoard(B,ki);
        if(Enemy(K,kn)){
            AddMakan(B, L, K, ki, kn);
        }else/*kosong*/{
            AddMove(L, K, ki);
        }
    } 
    if(SetBoard(B,Knight7(K))!=BAD_SQUARE){


        BOARD_INDEX ki = Knight7(K);
        BOARD_TILE kn = SetBoard(B,ki);
        if(Enemy(K,kn)){
            AddMakan(B, L, K, ki, kn);
        }else/*kosong*/{
            AddMove(L, K, ki);
        }

    }
    if(SetBoard(B,Knight8(K))!=BAD_SQUARE){


        BOARD_INDEX ki = Knight8(K);
        BOARD_TILE kn = SetBoard(B,ki);
        if(Enemy(K,kn)){
            AddMakan(B, L, K, ki, kn);
        }else/*kosong*/{
            AddMove(L, K, ki);
        }
    }  

}
void GenQueen(BOARD B, BIDAK Q, List_Move *L){

    if(SetBoard(B,Up(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX qi = Up_i(Q,i);
        BOARD_TILE qt = SetBoard(B, qi);
        do
        {
            if(Friend(Q,qt)){
                break;
            }else if(Enemy(Q,qt)){
                AddMakan(B, L, Q, qi, qt);
            }else/*kosong*/{
                AddMove(L, Q, qi);
            }
            i++;
        } while (qt!=BAD_SQUARE);
    }
    if(SetBoard(B,Down(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX qi = Down_i(Q,i);
        BOARD_TILE qt = SetBoard(B, qi);
        do
        {
            if(Friend(Q,qt)){
                break;
            }else if(Enemy(Q,qt)){
                AddMakan(B, L, Q, qi, qt);
            }else/*kosong*/{
                AddMove(L, Q, qi);
            }
            i++;
        } while (qt!=BAD_SQUARE);
    }
    if(SetBoard(B,Left(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX qi = Left_i(Q,i);
        BOARD_TILE qt = SetBoard(B, qi);
        do
        {
            if(Friend(Q,qt)){
                break;
            }else if(Enemy(Q,qt)){
                AddMakan(B, L, Q, qi, qt);
            }else/*kosong*/{
                AddMove(L, Q, qi);
            }
            i++;
        } while (qt!=BAD_SQUARE);
        
    }
    if(SetBoard(B,Right(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX qi = Right_i(Q,i);
        BOARD_TILE qt = SetBoard(B, qi);
        do
        {
            if(Friend(Q,qt)){
                break;
            }else if(Enemy(Q,qt)){
                AddMakan(B, L, Q, qi, qt);
            }else/*kosong*/{
                AddMove(L, Q, qi);/* code */
            }
            i++;
        } while (qt!=BAD_SQUARE);
        
    }
    if(SetBoard(B,SerongKananAtas(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX qi = SerongKananAtas_i(Q,i);
        BOARD_TILE qt = SetBoard(B, qi);
        do
        {
            if(Friend(Q,qt)){
                break;
            }else if(Enemy(Q,qt)){
                AddMakan(B, L, Q, qi, qt);
            }else/*kosong*/{
                AddMove(L, Q, qi);
            }
            i++;
        } while (qt!=BAD_SQUARE);
        
    }
    if(SetBoard(B,SerongKananBawah(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX qi = SerongKananBawah_i(Q,i);
        BOARD_TILE qt = SetBoard(B, qi);
        do
        {
            if(Friend(Q,qt)){
                break;
            }else if(Enemy(Q,qt)){
                AddMakan(B, L, Q, qi, qt);
            }else/*kosong*/{
                AddMove(L, Q, qi);
            }
            i++;
        } while (qt!=BAD_SQUARE);
        
    }
    if(SetBoard(B,SerongKiriAtas(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX qi = SerongKiriAtas_i(Q,i);
        BOARD_TILE qt = SetBoard(B, qi);
        do
        {
            if(Friend(Q,qt)){
                break;
            }else if(Enemy(Q,qt)){
                AddMakan(B, L, Q, qi, qt);
            }else/*kosong*/{/* code */
                AddMove(L, Q, qi);
            }
            i++;
        } while (qt!=BAD_SQUARE); 
        
    }
    if(SetBoard(B,SerongKiriBawah(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_INDEX qi = SerongKiriBawah_i(Q,i);
        BOARD_TILE qt = SetBoard(B, qi);
        do
        {
            if(Friend(Q,qt)){
                break;
            }else if(Enemy(Q,qt)){
                AddMakan(B, L, Q, qi, qt);
            }else/*kosong*/{
                AddMove(L, Q, qi);
            }
            i++;
        } while (qt!=BAD_SQUARE);
        
    }

}
void GenKing(BOARD B, BIDAK K, List_Move *L){

    if (SetBoard(B,Up(K))!=BAD_SQUARE){
        BOARD_INDEX ki = Up(K);
        BOARD_TILE kt = SetBoard(B,ki);
        if(Enemy(K,kt)){
            AddMakan(B, L, K, ki, kt);
        }else{
            AddMove(L,K,ki);
        }
    }
    if (SetBoard(B,Down(K))!=BAD_SQUARE){
        BOARD_INDEX ki = Down(K);
        BOARD_TILE kt = SetBoard(B,ki);
        if(Enemy(K,kt)){
            AddMakan(B, L, K, ki, kt);
        }else{
            AddMove(L,K,ki);
        }
        
    }
    if (SetBoard(B,Left(K))!=BAD_SQUARE){
        BOARD_INDEX ki = Left(K);
        BOARD_TILE kt = SetBoard(B,ki);
        if(Enemy(K,kt)){
            AddMakan(B, L, K, ki, kt);
        }else{
            AddMove(L,K,ki);
        }
        
    }
    if (SetBoard(B,Right(K))!=BAD_SQUARE){
        BOARD_INDEX ki = Right(K);
        BOARD_TILE kt = SetBoard(B,ki);
        if(Enemy(K,kt)){
            AddMakan(B, L, K, ki, kt);
        }else{
            AddMove(L,K,ki);
        }
    }
    if (SetBoard(B,SerongKananAtas(K))!=BAD_SQUARE){
        BOARD_INDEX ki = SerongKiriAtas(K);
        BOARD_TILE kt = SetBoard(B,ki);
        if(Enemy(K,kt)){
            AddMakan(B, L, K, ki, kt);
        }else{
            AddMove(L,K,ki);
        }
    }
    if (SetBoard(B,SerongKananBawah(K))!=BAD_SQUARE){
        BOARD_INDEX ki = SerongKananBawah(K);
        BOARD_TILE kt = SetBoard(B,ki);
        if(Enemy(K,kt)){
            AddMakan(B, L, K, ki, kt);
        }else{
            AddMove(L,K,ki);
        }  
    }
    if (SetBoard(B,SerongKiriAtas(K))!=BAD_SQUARE){
        BOARD_INDEX ki = SerongKiriAtas(K);
        BOARD_TILE kt = SetBoard(B,ki);
        if(Enemy(K,kt)){
            AddMakan(B, L, K, ki, kt);
        }else{
            AddMove(L,K,ki);
        } 
        
    }
    if (SetBoard(B,SerongKiriBawah(K))!=BAD_SQUARE){
        BOARD_INDEX ki = SerongKiriBawah(K);
        BOARD_TILE kt = SetBoard(B,ki);
        if(Enemy(K,kt)){
            AddMakan(B, L, K, ki, kt);
        }else{
            AddMove(L,K,ki);
        } 
    }
}

//interface

//Implementation of search custom 
BIDAK SearchMakan(BOARD_INDEX idx, BOARD_TILE type, BOARD B, COLOR SelfColor){
    
    List_Bidak LPutih = (B).LPutih;
    List_Bidak LHitam = (B).LHitam;

    //ambil list bidak lawan
    address_bidak Phitam = SearchCustom(LHitam,idx,type); 
    address_bidak Pputih = SearchCustom(LPutih,idx,type);
    
    BIDAK Bh = InfoBidak(Phitam);
    BIDAK Bp = InfoBidak(Pputih);

    if(SelfColor==WHITE)
        return Bh;
    else
        return Bp;
}
void AddMove(List_Move *L, BIDAK Mover, BOARD_INDEX Target_Index){
    MOVE M;
    M.warna = Mover.warna;
    M.cur_position = Mover.posisi;
    M.id = Mover.id;
    M.new_position = Target_Index;
    M.is_makan = false;

    InsVFirstM(L, M);
}

void AddMakan(BOARD B, List_Move *L, BIDAK Mover, BOARD_INDEX VictimIdx, BOARD_TILE VictimTile){
    MOVE M;
    M.cur_position = Mover.posisi;
    M.warna = Mover.warna;
    M.id = Mover.id;
    M.new_position = VictimIdx;
    M.is_makan = true;

    BIDAK Victim = SearchMakan(VictimIdx, VictimTile, B, Mover.warna);
    M.victim = Victim;

    InsVFirstM(L, M);
}/*** PRINTING FUNCTION ****/
char* IdxtoStr(BOARD_INDEX Idx){
    char *index = (char *) malloc(sizeof(char)*8);

    switch (Idx)
    {
    case A1:
        strcpy(index, "(a,1)");
        break;
    case A2:
        strcpy(index, "(a,2)");
        break;
    case A3:
        strcpy(index, "(a,3)");
        break;
    case A4:
        strcpy(index, "(a,4)");
        break;
    case A5:
        strcpy(index, "(a,5)");
        break;
    case A6:
        strcpy(index, "(a,6)");
        break;
    case A7:
        strcpy(index, "(a,7)");
        break;
    case A8:
        strcpy(index, "(a,8)");
        break;
    case B1:
        strcpy(index, "(b,1)");
        break;
    case B2:
        strcpy(index, "(b,2)");
        break;
    case B3:
        strcpy(index, "(b,3)");
        break; 
    case B4:
        strcpy(index, "(b,4)");
        break; 
    case B5:
        strcpy(index, "(b,5)");
        break; 
    case B6:
        strcpy(index, "(b,1)");
        break; 
    case B7:
        strcpy(index, "(b,7)");
        break; 
    case B8:
        strcpy(index, "(b,8)");
        break;
    case C1:
        strcpy(index, "(c,1)");
        break;  
    case C2:
        strcpy(index, "(c,2)");
        break;        
    case C3:
        strcpy(index, "(c,3)");
        break;
    case C4:
        strcpy(index, "(c,4)");
        break;
    case C5:
        strcpy(index, "(c,5)");
        break;
    case C6:
        strcpy(index, "(c,6)");
        break;
    case C7:
        strcpy(index, "(c,7)");
        break;
    case C8:
        strcpy(index, "(c,8)");
        break;
    case D1:
        strcpy(index, "(d,1)");
        break;
    case D2:
        strcpy(index, "(d,2)");
        break;
    case D3:
        strcpy(index, "(d,3)");
        break;             
    case D4:
        strcpy(index, "(d,4)");
        break; 
    case D5:
        strcpy(index, "(d,5)");
        break;
    case D6:
        strcpy(index, "(d,7)");
        break; 
    case D7:
        strcpy(index, "(d,7)");
        break;
    case D8:
        strcpy(index, "(d,8)");
        break;
    case E1:
        strcpy(index, "(e,1)");
        break; 
    case E2:
        strcpy(index, "(e,2)");
        break;
    case E3:
        strcpy(index, "(e,3)");
        break;
    case E4:
        strcpy(index, "(e,4)");
        break;
    case E5:
        strcpy(index, "(e,5)");
        break;
    case E6:
        strcpy(index, "(e,7)");
        break;
    case E7:
        strcpy(index, "(e,7)");
        break;
    case E8:
        strcpy(index, "(e,8)");
        break;
    case F1:
        strcpy(index, "(f,1)");
        break; 
    case F2:
        strcpy(index, "(f,2)");
        break;
    case F3:
        strcpy(index, "(f,3)");
        break;
    case F4:
        strcpy(index, "(f,4)");
        break;
    case F5:
        strcpy(index, "(f,5)");
        break;
    case F6:
        strcpy(index, "(f,7)");
        break;
    case F7:
        strcpy(index, "(f,7)");
        break;
    case F8:
        strcpy(index, "(f,8)");
        break;
    case G1:
        strcpy(index, "(g,1)");
        break; 
    case G2:
        strcpy(index, "(g,2)");
        break;
    case G3:
        strcpy(index, "(g,3)");
        break;
    case G4:
        strcpy(index, "(g,4)");
        break;
    case G5:
        strcpy(index, "(g,5)");
        break;
    case G6:
        strcpy(index, "(g,7)");
        break;
    case G7:
        strcpy(index, "(g,7)");
        break;
    case G8:
        strcpy(index, "(g,8)");
        break;
    case H1:
        strcpy(index, "(h,1)");
        break; 
    case H2:
        strcpy(index, "(h,2)");
        break;
    case H3:
        strcpy(index, "(h,3)");
        break;
    case H4:
        strcpy(index, "(h,4)");
        break;
    case H5:
        strcpy(index, "(h,5)");
        break;
    case H6:
        strcpy(index, "(h,7)");
        break;
    case H7:
        strcpy(index, "(h,7)");
        break;
    case H8:
        strcpy(index, "(h,8)");
        break;
    }

    return index;
}

char* TypetoStr(PAWN_TYPE type){
    char *typ = (char *) malloc(sizeof(char)*8);

    switch (type)
    {
    case PAWN:
        strcpy(typ, "Pion");
        break;
    case KNIGHT:
        strcpy(typ, "Kuda");
        break;
    case BISHOP:
        strcpy(typ, "Mentri");
        break;
    case ROOK:
        strcpy(typ, "Benteng");
        break;
    case QUEEN:
        strcpy(typ, "Ratu");
        break;
    case KING:
        strcpy(typ, "Raja");
        break;
    }

    return typ;
}
void PrintIdxPos(MOVE_ID Mid, int idx){
    char* type = TypetoStr(Mid.id.type);
    char* idxstr = IdxtoStr(Mid.posisi);
    printf("%d. %s %s\n", idx, type, idxstr);
}

void PrintIdxMove(MOVE M, int idx){
    char* idxstr = IdxtoStr(M.new_position);
    char* type = TypetoStr(M.id.type);
    printf("%d. %s\n", idx, idxstr);
}

void PrintAvailableMove(Queue_Move Q){
    int elmt = NbElmtQ(Q);
    Queue_Move Qb = Q;
    MOVE_ID move[elmt];//buat nyimpen

    //Ambil element queue jadiin array biasa
    MOVE_ID tmp;
    for (int i = 0; i < elmt; i++)
    {
        DelQ(&Qb, &tmp);
        move[i] = tmp;
    }
    
    //print gan
    int nomer;//index printnya
    printf("Daftar bidak yang bisa bergerak:\n");
    for (int i = 0; i < elmt; i++)
    {
        nomer = i+1;
        PrintIdxPos(move[i],nomer);
    }
}



void PrintMoveBidak(List_Move L){
    int elmt = NbElmtM(L);
    MOVE mov[elmt];
    //masukin ke array biar mudah sis
    address_move P = FirstMove(L);
    int i=0;
    MOVE M;
    while(P!=Nil){
        M = InfoMove(P);
        mov[i] = M;
        P = NextMove(P);
        i++;
    }
    //printing gans
    printf("Daftar posisi tujuan yang mungkin:\n");
    int nomer;//index
    for (int i = 0; i < elmt; i++)
    {
        nomer = i+1;
        PrintIdxMove(mov[i],nomer);
    }

}

void PrintBerpindah (MOVE M){
    char* type = TypetoStr(M.id.type);
    char* curpos =  IdxtoStr(M.cur_position);
    char* newpos = IdxtoStr(M.new_position);

    printf("Bidak %s telah berpindah dari %s ke %s\n", type, curpos, newpos);
}

