

/*
void Welcome() -> print welcome
void Menu() -> print menu 
void keluar() -> display exit message

void RunNewGame(Leaderboard *B) -> prosedur mulai game baru, leaderboard digunakan untuk menambah score jika game selesai
void RunSavedGame(Leaderboard *B) -> prosedur mulai game dari saveffie, read savefile dulu baru ngejalanin game  
*/

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
        }
    }
    SaveLeaderBoard(B);
    keluar();
    return 0;
}