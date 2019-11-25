#include "acc.h"
#include "leader.h"
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

}

void RunSavedGame(LeaderBoard *B){
// -> prosedur mulai game dari saveffie, read savefile dulu baru ngejalanin game  
}
