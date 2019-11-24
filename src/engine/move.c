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

/***** MAIN FUNCTION *****/

//dipake buat nampilin mana aja yang bisa gerak
//pake queue biar enak ngeluarinnya
Queue_Move AvailableMove(List_Bidak B){
    //siapin Output bray
    Queue_Move Q;
    CreateEmpty(&Q);


}
List_Move GenerateMove(BIDAK B, BOARD BO){
    List_Move L;
    CreateEmpty(&L);
    
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

//helper functions
boolean IsMoveLegal(MOVE M);
BOARD_INDEX GetKingPos(List_Bidak B){
    address P = SearchId(B, KING);
    if(P!=Nil)
        return Info(P).id.type;

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

    if(IsUpKosong(B,WPawn)){
        if(PawnWFirst(B,WPawn)){
            //jalan satu
            AddMove(L, WPawn, Up(WPawn));
            //jalan satu
            AddMove(L, WPawn, Up_i(WPawn, 2));

            //makan
            if(Enemy(WPawn, SerongKananAtas(WPawn))){
                BOARD_INDEX vid = SerongKananAtas(WPawn);
                BOARD_TILE vtile = SetBoard(B, vid);
                AddMakan(B, L, WPawn, vid, vtile);

            }
            if(Enemy(WPawn, SerongKiriAtas(WPawn))){
                BOARD_INDEX vid = SerongKiriAtas(WPawn);
                BOARD_TILE vtile = SetBoard(B, vid);
                AddMakan(B, L, WPawn, vid, vtile);

            }
        }else{
            //cuman jalan satu aja
            AddMove(L, WPawn, Up(WPawn));

            //makan
            if(Enemy(WPawn, SerongKananAtas(WPawn))){
                BOARD_INDEX vid = SerongKananAtas(WPawn);
                BOARD_TILE vtile = SetBoard(B, vid);
                AddMakan(B, L, WPawn, vid, vtile);

            }
            if(Enemy(WPawn, SerongKiriAtas(WPawn))){
                BOARD_INDEX vid = SerongKiriAtas(WPawn);
                BOARD_TILE vtile = SetBoard(B, vid);
                AddMakan(B, L, WPawn, vid, vtile);

            }

        }

    }
    //kalau gak kosong cek dia bisa makan ga di serongnya
    else{        
        if(Enemy(WPawn, SerongKananAtas(WPawn))){

            BOARD_INDEX vid = SerongKananAtas(WPawn);
            BOARD_TILE vtile = SetBoard(B, vid);
            AddMakan(B, L, WPawn, vid, vtile);

        }
        if(Enemy(WPawn, SerongKiriAtas(WPawn))){

            BOARD_INDEX vid = SerongKiriAtas(WPawn);
            BOARD_TILE vtile = SetBoard(B, vid);
            AddMakan(B, L, WPawn, vid, vtile);

        }
    }

}
void GenBPawn(BOARD B, BIDAK BPawn, List_Move *L){
    
    if(IsDownKosong(B,BPawn)){
        if(PawnWFirst(B,BPawn)){
            //jalan dua



            //jalan satu


            //makan
            if(Enemy(BPawn, SerongKananBawah(BPawn))){

            }
            if(Enemy(BPawn, SerongKiriBawah(BPawn))){

            }

            

        }else{
            //cuman jalan satu aja



            //makan
            if(Enemy(BPawn, SerongKananBawah(BPawn))){

            }
            if(Enemy(BPawn, SerongKiriBawah(BPawn))){

            }

        }

    }
    //kalau gak kosong cek dia bisa makan ga di serongnya
    else{
        //makan
        if(Enemy(BPawn, SerongKananBawah(BPawn))){

        }
        if(Enemy(BPawn, SerongKiriBawah(BPawn))){

        }
    }

   
    
}

void GenRook(BOARD B, BIDAK R, List_Move *L){

    /*CHECK ALL SIDES*/
    //upper side first
    if(SetBoard(B,Up(R))!=BAD_SQUARE){
        int i = 1; //iterator tile
        do
        {
            BOARD_TILE nt = SetBoard(B, Up_i(R,i));
            
            if(Enemy(R,nt))/*Makan*/{



            }else if(Friend(R,nt))/*Terhalang*/{
                //kalau terhalang yaudah gausah jalan lagi kedepan
                break;
            }else/*Kosong*/{
                
            }   

            i++;
        } while(SetBoard(B,Up_i(R,i))!=BAD_SQUARE);
    
    }

    if(SetBoard(B,Left(R))!=BAD_SQUARE){
        int i = 1;
        do
        {
            BOARD_TILE nt = SetBoard(B, Left_i(R,i));
            
            if(Enemy(R,nt))/*Makan*/{



            }else if(Friend(R,nt))/*Terhalang*/{
                //kalau terhalang yaudah gausah jalan lagi kedepan
                break;
            }else/*Kosong*/{
                
            }   

            i++;
        } while(SetBoard(B,Left_i(R,i))!=BAD_SQUARE);


    }

    if(SetBoard(B,Right(R))!=BAD_SQUARE){
        int i = 1;
        do
        {
            BOARD_TILE nt = SetBoard(B, Right_i(R,i));
            
            if(Enemy(R,nt))/*Makan*/{



            }else if(Friend(R,nt))/*Terhalang*/{
                //kalau terhalang yaudah gausah jalan lagi kedepan
                break;
            }else/*Kosong*/{
                
            }   

            i++;
        } while(SetBoard(B,Right_i(R,i))!=BAD_SQUARE);

    }

    if(SetBoard(B,Down(R))!=BAD_SQUARE){
        int i = 1;
        do
        {
            BOARD_TILE nt = SetBoard(B, Down_i(R,i));
            
            if(Enemy(R,nt))/*Makan*/{


            }else if(Friend(R,nt))/*Terhalang*/{
                //kalau terhalang yaudah gausah jalan lagi kedepan
                break;
            }else/*Kosong*/{
                
            }   

            i++;
        } while(SetBoard(B,Down_i(R,i))!=BAD_SQUARE);

    }
}
void GenBishop(BOARD B, BIDAK Bi, List_Move *L){

    if(SetBoard(B,SerongKananAtas(Bi))!=BAD_SQUARE){
        int i = 1;
        do
        {
            BOARD_TILE nt = SetBoard(B,SerongKananAtas_i(Bi,i));
            if (Friend(Bi, nt)){
                break;
            }else if(Enemy(Bi,nt)){

            }else{

            }
        } while (SetBoard(B, SerongKananAtas_i(Bi,i))!=BAD_SQUARE);
        
    }

    if(SetBoard(B,SerongKiriAtas(Bi))!=BAD_SQUARE){
        int i = 1;
        do
        {
            BOARD_TILE nt = SetBoard(B,SerongKiriAtas_i(Bi,i));
            if (Friend(Bi, nt)){
                break;
            }else if(Enemy(Bi,nt)){

            }else{
                
            }
            
        } while (SetBoard(B, SerongKiriAtas_i(Bi,i))!=BAD_SQUARE);
    }    


    if(SetBoard(B,SerongKananBawah(Bi))!=BAD_SQUARE){
        int i = 1;
        do
        {
            BOARD_TILE nt = SetBoard(B,SerongKananBawah_i(Bi,i));
            if (Friend(Bi, nt)){
                break;
            }else if(Enemy(Bi,nt)){

            }else{
                
            }
            
        } while (SetBoard(B, SerongKananBawah_i(Bi,i))!=BAD_SQUARE);
    }  

    
    if(SetBoard(B,SerongKiriBawah(Bi))!=BAD_SQUARE){
        int i = 1;
        do
        {
            BOARD_TILE nt = SetBoard(B,SerongKiriBawah_i(Bi,i));
            if (Friend(Bi, nt)){
                break;
            }else if(Enemy(Bi,nt)){

            }else{
                
            }
            
        } while (SetBoard(B, SerongKiriBawah_i(Bi,i))!=BAD_SQUARE);
    }  
}
void GenKnight(BOARD B, BIDAK K, List_Move *L){

    if(SetBoard(B,Knight1(K))!=BAD_SQUARE){

        BOARD_TILE kn = SetBoard(B,Knight1(K));
        if(Friend(K,kn)){

        }else if(Enemy(K,kn)){

        }else/*kosong*/{

        }

    }
    if(SetBoard(B,Knight2(K))!=BAD_SQUARE){
        
        BOARD_TILE kn = SetBoard(B,Knight2(K));
        if(Friend(K,kn)){

        }else if(Enemy(K,kn)){

        }else/*kosong*/{

        }
    }
    if(SetBoard(B,Knight3(K))!=BAD_SQUARE){

        BOARD_TILE kn = SetBoard(B,Knight3(K));
        if(Friend(K,kn)){

        }else if(Enemy(K,kn)){

        }else/*kosong*/{

        }

    }
    if(SetBoard(B,Knight4(K))!=BAD_SQUARE){

        BOARD_TILE kn = SetBoard(B,Knight4(K));
        if(Friend(K,kn)){

        }else if(Enemy(K,kn)){

        }else/*kosong*/{

        }

    }
    if(SetBoard(B,Knight5(K))!=BAD_SQUARE){

        BOARD_TILE kn = SetBoard(B,Knight5(K));
        if(Friend(K,kn)){

        }else if(Enemy(K,kn)){

        }else/*kosong*/{

        }
    } 
    if(SetBoard(B,Knight6(K))!=BAD_SQUARE){


        BOARD_TILE kn = SetBoard(B,Knight6(K));
        if(Friend(K,kn)){

        }else if(Enemy(K,kn)){

        }else/*kosong*/{

        }
    } 
    if(SetBoard(B,Knight7(K))!=BAD_SQUARE){


        BOARD_TILE kn = SetBoard(B,Knight7(K));
        if(Friend(K,kn)){

        }else if(Enemy(K,kn)){

        }else/*kosong*/{

        }

    }
    if(SetBoard(B,Knight8(K))!=BAD_SQUARE){


        BOARD_TILE kn = SetBoard(B,Knight8(K));
        if(Friend(K,kn)){

        }else if(Enemy(K,kn)){

        }else/*kosong*/{

        }
    }  

}
void GenQueen(BOARD B, BIDAK Q, List_Move *L){

    if(SetBoard(B,Up(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_TILE qt = SetBoard(B,Up_i(Q,i));
        do
        {
            if(Friend(Q,qt)){

            }else if(Enemy(Q,qt)){

            }else/*kosong*/{

            }
        } while (SetBoard(B,Up_i(Q,i))!=BAD_SQUARE);
    }
    if(SetBoard(B,Down(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_TILE qt = SetBoard(B,Down_i(Q,i));
        do
        {
            if(Friend(Q,qt)){

            }else if(Enemy(Q,qt)){

            }else/*kosong*/{

            }

        } while (SetBoard(B,Up_i(Q,i))!=BAD_SQUARE);
    }
    if(SetBoard(B,Left(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_TILE qt = SetBoard(B,Left_i(Q,i));
        do
        {
            if(Friend(Q,qt)){

            }else if(Enemy(Q,qt)){

            }else/*kosong*/{

            }
        } while (SetBoard(B,Up_i(Q,i))!=BAD_SQUARE);
        
    }
    if(SetBoard(B,Right(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_TILE qt = SetBoard(B,Right_i(Q,i));
        do
        {
            if(Friend(Q,qt)){

            }else if(Enemy(Q,qt)){

            }else/*kosong*/{

            }
        } while (SetBoard(B,Up_i(Q,i))!=BAD_SQUARE);
        
    }
    if(SetBoard(B,SerongKananAtas(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_TILE qt = SetBoard(B,SerongKananAtas_i(Q,i));
        do
        {
            if(Friend(Q,qt)){

            }else if(Enemy(Q,qt)){

            }else/*kosong*/{

            }
        } while (SetBoard(B,Up_i(Q,i))!=BAD_SQUARE);
        
    }
    if(SetBoard(B,SerongKananBawah(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_TILE qt = SetBoard(B,SerongKananBawah_i(Q,i));
        do
        {
            if(Friend(Q,qt)){

            }else if(Enemy(Q,qt)){

            }else/*kosong*/{

            }
        } while (SetBoard(B,Up_i(Q,i))!=BAD_SQUARE);
        
    }
    if(SetBoard(B,SerongKiriAtas(Q))!=BAD_SQUARE){
       int i = 1;
        BOARD_TILE qt = SetBoard(B,SerongKiriAtas_i(Q,i));
        do
        {
            if(Friend(Q,qt)){

            }else if(Enemy(Q,qt)){

            }else/*kosong*/{

            }
        } while (SetBoard(B,Up_i(Q,i))!=BAD_SQUARE); 
        
    }
    if(SetBoard(B,SerongKiriBawah(Q))!=BAD_SQUARE){
        int i = 1;
        BOARD_TILE qt = SetBoard(B,SerongKiriBawah_i(Q,i));
        do
        {
            if(Friend(Q,qt)){

            }else if(Enemy(Q,qt)){

            }else/*kosong*/{

            }
        } while (SetBoard(B,Up_i(Q,i))!=BAD_SQUARE);
        
    }

}
void GenKing(BOARD B, BIDAK K, List_Move *L){

    if (SetBoard(B,Up(K))!=BAD_SQUARE){
        BOARD_TILE kt = SetBoard(B,Up(K));
        if(Friend(K,kt)){

        }else if(Enemy(K,kt)){

        }else{

        }

    }
    if (SetBoard(B,Down(K))!=BAD_SQUARE){
        BOARD_TILE kt = SetBoard(B,Down(K));
        if(Friend(K,kt)){

        }else if(Enemy(K,kt)){

        }else{
            
        }
        
    }
    if (SetBoard(B,Left(K))!=BAD_SQUARE){
        BOARD_TILE kt = SetBoard(B,Left(K));
        if(Friend(K,kt)){

        }else if(Enemy(K,kt)){

        }else{
            
        }
        
    }
    if (SetBoard(B,Right(K))!=BAD_SQUARE){
        BOARD_TILE kt = SetBoard(B,Right(K));
        if(Friend(K,kt)){

        }else if(Enemy(K,kt)){

        }else{
            
        }
    }
    if (SetBoard(B,SerongKananAtas(K))!=BAD_SQUARE){
        BOARD_TILE kt = SetBoard(B,SerongKananAtas(K));
        if(Friend(K,kt)){

        }else if(Enemy(K,kt)){

        }else{
            
        }
        
    }
    if (SetBoard(B,SerongKananBawah(K))!=BAD_SQUARE){
        BOARD_TILE kt = SetBoard(B,SerongKananBawah(K));
        if(Friend(K,kt)){

        }else if(Enemy(K,kt)){

        }else{
            
        }
        
    }
    if (SetBoard(B,SerongKiriAtas(K))!=BAD_SQUARE){
        BOARD_TILE kt = SetBoard(B,SerongKiriAtas(K));
        if(Friend(K,kt)){

        }else if(Enemy(K,kt)){

        }else{
            
        }
        
    }
    if (SetBoard(B,SerongKiriBawah(K))!=BAD_SQUARE){
        BOARD_TILE kt = SetBoard(B,SerongKiriBawah(K));
        if(Friend(K,kt)){

        }else if(Enemy(K,kt)){

        }else{
            
        }
        
    }

}

//interface

//Implementation of search custom 
BIDAK SearchMakan(BOARD_INDEX idx, BOARD_TILE type, BOARD B, COLOR SelfColor){
    
    //ambil list bidak lawan
    if (SelfColor==WHITE){
        List_Bidak LMusuh;
        LMusuh = B.LHitam;
    }else{
        List_Bidak LMusuh;
        LMusuh = B.LPutih;
    }

    address P = SearchCustom(LMusuh,idx,type);
    BIDAK B = Info(P);

    return B;
}
void AddMove(List_Move *L, BIDAK Mover, BOARD_INDEX Target_Index){
    MOVE M;
    M.cur_position = Mover.posisi;
    M.id.type = Mover.id.type;
    M.id.number = Mover.id.number;
    M.new_position = Target_Index;
    M.is_makan = false;

    InsVFirst(L, M);
}

void AddMakan(BOARD B, List_Move *L, BIDAK Mover, BOARD_INDEX VictimIdx, BOARD_TILE VictimTile){
    MOVE M;
    M.cur_position = Mover.posisi;
    M.id.type = Mover.id.type;
    M.id.number = Mover.id.number;
    M.new_position = VictimIdx;
    M.is_makan = true;

    BIDAK Victim = SearchMakan(VictimIdx, VictimTile, B, Mover.warna);
    M.victim = Victim;

    InsVFirst(L, M);

}
