
// for engine
#include "leader.h"


int main(){
    int pil;
    LeaderBoard B;
    boolean exit = false;
    ReadLeaderBoard(&B);
    Welcome();
    while (! exit){
        Menu();
        scanf("%d",&pil);
        switch (pil) {
                case 1 : RunNewGame(&B); /* init board,init bidak, start game until exit or done*/
                        break;
                case 2 : RunSavedGame(&B); /* read file from external, continue game until exit or done*/
                        break;
                case 3 : PrintLeaderboard(B);
                        break;
                case 4 : exit = true;
                        break;
                default : printf("Input salah !\n");
                        break;
        }
    }
    SaveLeaderBoard(B);
    keluar();
    return 0;
}