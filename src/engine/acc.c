#include "acc.h"
#include "string.h"
#include <stdio.h>


void Welcome(){
//  -> print welcome
        printf("----WELCOME TO CATUR AVATAR----\n");
        // printf('logo catur ');
}
void Menu(){
// -> print menu 
        printf("Menu : \n");
        printf("1. New Game\n");
        printf("2. Load Game\n");
        printf("3. Leaderboard\n");
        printf("4. Exit\n");
        printf("Masukkan pilihan : ");
}
void keluar(){
// -> display exit message
        printf("Terimaksih telah bermain Catur Avatar \n");
        printf("Sampai Jumpa !\n");
}

void RunNewGame(LeaderBoard *B){
// -> prosedur mulai game baru, leaderboard digunakan untuk menambah score jika game selesai  
        BOARD D;
        char namput[4];
        char namhit[4];
        int idx;
        Score temps;
        boolean done = false;
        printf("Masukkan nama pemain putih : ");
        scanf("%s",namput);
        printf("Masukkan nama pemain hitam : ");
        scanf("%s",namhit);
        List_Bidak Putih;
        List_Bidak Hitam;
        Queue_Giliran Q;
        init_board(&D);
        InitListBidak(&Putih,WHITE);
        InitListBidak(&Hitam,BLACK);
        RunGame(D,Putih,Hitam,&Q,&done);
        if (done) {
                idx = getIdent(Q);
                if (idx == 1){
                        if (InfoHeadT(Q).player == WHITE){
                                strcpy(temps.Nama,namput);
                        } else {
                                strcpy(temps.Nama,namhit);
                        }
                        temps.Nilai = InfoHeadT(Q).poin;
                        AddScore(B,temps);
                } else if ( idx == 2 ){
                        if (InfoTailT(Q).player == WHITE){
                                strcpy(temps.Nama,namput);
                        } else {
                                strcpy(temps.Nama,namhit);
                        }
                        temps.Nilai = InfoTailT(Q).poin;
                        AddScore(B,temps);
                }
        }
        
}

void RunSavedGame(LeaderBoard *B){ /* belum mempertimbangkan nama */
// -> prosedur mulai game dari saveffie, read savefile dulu baru ngejalanin game 
        
}

void RunGame(BOARD D,List_Bidak W, List_Bidak B, Queue_Giliran *Q,boolean *done){
        boolean exit = false;
        char cmd[15];
        int x;
        while((! exit) && (! Is50Turn(*Q)) && !(*done)) {
                PrintBoard(D);
                printf("Masukkan command : ");
                scanf("%s",cmd);
                x = getNum(cmd);
                switch (x){
                        case 1 : Move(); /* -> kondisi game selesai ada di done */
                                break;
                        case 2 : specialmove();
                                break;
                        case 3 : undo();
                                break;
                        case 4 : exit = true;
                                break;
                }
        }
        // if (/* cek penuh */){
        //         *done = true;
        //         boolean simpan;
        //         char s;
        //         printf("Apakah anda ingin menyimpan kondisi permainan ? (Y/N) ");
        //         scanf("%c",&s);
        //         if (s == 'Y'){
        //                 SaveFile(W,B,Q);
        //         }
        //}
}

int getIdent(Queue_Giliran Q){
        if (InfoHeadT(Q).poin == InfoTailT(Q).poin){
                return 0;
        } else if (InfoHeadT(Q).poin > InfoTailT(Q).poin){
                return 1;
        } else {
                return 2;
        }
}