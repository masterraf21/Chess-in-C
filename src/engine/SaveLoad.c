#include "SaveLoad.h"
#include <stdio.h>


char AmbilWarna(COLOR c){
    if (c == WHITE){
        return 'P';
    } else {
        return 'H';
    }
}

COLOR getcolor (char c){
    if(c == 'P'){
        return 1;
    } else {
        return -1;
    }
}

void ReadFile(List_Bidak *W, List_Bidak *B,Queue_Giliran *Q){
     /* 
     NOTE : BELUM MEMPERTIMBANGKAN GILIRAN QUEUE    
    Bidak -> List_ID, Posisi, Warna
    tiap kata yang diakuisisi terdiri dari 5 karakter
    contoh : 0137P
    tiap kata merepresentasikan 1 bidak
    1 karakter pertama (chr[0] dan chr[1]) menunjukkan number bidak (konversi dulu ke integer)
        0 -> 0 
        1 -> 1
        dst sampai 8 
    1 karakter chr[3] selanjutnya menunjukkan pawn type (konversi dulu ke integer)
        1 -> pawn
        2 -> knight dst
    2  karakter selanjutnya chr[4] dan chr[5] menunjukkan posisi bidak (konversi dulu ke integer)
        37 -> G2
    1 karakter selanjutnya menunjukkan warna bidak
        W -> Putih -> 1
        B -> Hitam -> -1
    */
    char* Namfile;
    BIDAK tempB;
    LIST_ID tempL;
    infotypeturn tempQ;
    printf("Masukkan nama save file : ");
    scanf("%s",Namfile);
    STARTKATA(Namfile);
    while (! IsEOP()){
        while(CKata.TabKata[0] != '|'){
            tempL.number = CKata.TabKata[0] - '0';
            tempL.type = CKata.TabKata[1] - '0';
            tempB.id = tempL;
            tempB.posisi = (CKata.TabKata[2] - '0')*10 + (CKata.TabKata[3] - '0');
            tempB.warna = getcolor(CKata.TabKata[4]);
            if (tempB.warna == 1){
                InsVFirst (W, tempB);
            } else {
                InsVFirst (B, tempB);
            }
            ADVKATA();
        }
        ADVKATA();
        for(int i =1;i<= 1;i++){
            tempQ.player = getcolor(CKata.TabKata[0]);
            ADVKATA();
            tempQ.counter = StrToInt(CKata);
            ADVKATA();
            tempQ.poin = StrToInt(CKata);
            AddTurn(Q,tempQ);
            ADVKATA();
        }  
    }   
}

void SaveFile(List_Bidak W, List_Bidak B, Queue_Giliran Q){
    /* 
    reverse engineer ReadFile
    per bidak diseparate semicolon(;)
    diakhir file dikasi mark (.)
    */
    char *Namfile;
    FILE *catur;
    address_bidak PB;
    address_turn PR;
    BIDAK BD;
    infotypeturn R;
    char warna;
    printf("Masukkan nama save file : ");
    scanf("%s",Namfile);
    catur = fopen(Namfile,"w");
    PB = FirstBidak(W);
    while (PB != Nil){
        BD = InfoBidak(PB);
        fprintf(catur,"%d%d%dP;",BD.id.number,BD.id.type,BD.posisi);
        PB = NextBidak(PB);
    }
    fprintf(catur,"\n");
    PB = FirstBidak(B);
    while (PB != Nil){
        BD = InfoBidak(PB);
        fprintf(catur,"%d%d%dH;",BD.id.number,BD.id.type,BD.posisi);
        PB = NextBidak(PB);
    }
    fprintf(catur,"\n|\n");
    PR = HeadT(Q);
    while(PR != Nil){
        R = InfoT(PR);
        warna = AmbilWarna(R.player);
        fprintf(catur,"%c;%d;%d\n",warna,R.counter,R.poin);
        PR = NextT(PR);
    }
    //Print ke file isi queue giliran dengan format <warna><count>;<score>
    //contoh P;XXX30;105
    fprintf(catur,".");
    fclose(catur);
}
			
