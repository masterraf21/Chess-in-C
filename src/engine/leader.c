#include "leader.h"

int StrToInt(Kata kat){
	int res = 0; 
    for (int i = 0;i < kat.Length ; ++i) 
        res = res * 10 + kat.TabKata[i] - '0'; 
    return res;
}

void ReadLeaderBoard(LeaderBoard *B){
int count = 0;
Score temp;
STARTKATA("Leaderboard.txt");
while (! IsEOP()) {
	temp.Nama[0]= CKata.TabKata[0];
	temp.Nama[1]= CKata.TabKata[1];
	temp.Nama[2]= CKata.TabKata[2];
	temp.Nama[3]='\0';

	ADVKATA();
	temp.Nilai = StrToInt(CKata);

	(*B).Tab[count] = temp;
	count++;

	ADVKATA();
}

(*B).Neff = count;
}
	
void PrintLeaderboard(LeaderBoard *B) {
	int count = (*B).Neff;
	int nomor = 1;
	if (count == 0) {
		printf("Belum ada Leaderboard !\n");
	} else {

		printf("---------LEADERBOARD--------- \n");
		printf("+-----+----------+----------+ \n");
		printf("| No. |   Nama   |   Score  | \n");
		printf("+-----+----------+----------+ \n");

		while (count != 0) {
			printf("|  %d  |   %s    |    %d   | \n",nomor,(*B).Tab[nomor-1].Nama,(*B).Tab[nomor-1].Nilai);
			nomor++;
			count--;
		}
		printf("+-----+----------+----------+ \n");

	}
}
			 	
void SwapScore(Score *a, Score *b){
	Score temp;
	CopyNama(temp.Nama,(*a).Nama);
	temp.Nilai = (*a).Nilai;

	CopyNama((*a).Nama,(*b).Nama);
	(*a).Nilai = (*b).Nilai;

	CopyNama((*b).Nama,temp.Nama);
	(*b).Nilai = temp.Nilai;
}

void CopyNama(char *a, char *b){
	for (int i = 0; i<=3;i++){
		a[i] = b[i];
	}
}

void SaveLeaderBoard(LeaderBoard B){
	FILE *lead;
	lead = fopen("Leaderboard.txt","w");
	for(int i = 0;i<B.Neff;i++){
		fprintf(lead,"%c%c%c;%d\n",B.Tab[i].Nama[0],B.Tab[i].Nama[1],B.Tab[i].Nama[2],B.Tab[i].Nilai);
	}
	fprintf(lead,".");
	fclose(lead);
}

void AddScore(LeaderBoard *B,Score S){
	if ((*B).Neff == 0){
		(*B).Tab[(*B).Neff] = S;
	} else {
		int idx = (*B).Neff;
		boolean found = false;
		while((!found) && (idx != 0)){
			if ((*B).Tab[idx-1].Nilai < S.Nilai) {
			(*B).Tab[idx] = (*B).Tab[idx-1];
			idx--;
			} else if ((*B).Tab[idx-1].Nilai == S.Nilai){
				if((*B).Tab[idx-1].Nama[0] > S.Nama[0]){
					(*B).Tab[idx] = (*B).Tab[idx-1];
					idx--;
				} else if ((*B).Tab[idx-1].Nama[0] == S.Nama[0]){
					if((*B).Tab[idx-1].Nama[1] > S.Nama[1]){
						(*B).Tab[idx] = (*B).Tab[idx-1];
						idx--;
					} else if ((*B).Tab[idx-1].Nama[1] == S.Nama[1]){
						if((*B).Tab[idx-1].Nama[2] > S.Nama[2]){
							(*B).Tab[idx] = (*B).Tab[idx-1];
							idx--;
						}  else {
							found = true;
						}
					} else {
						found = true;
					}
				} else {
					found = true;
				}		
			} else {
				found = true;
			}
		}
		(*B).Tab[idx] = S;
	}
	(*B).Neff = (*B).Neff +1;
}





 