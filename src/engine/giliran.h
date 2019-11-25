#ifndef GILIRAN_H
#define GILIRAN_H

#include "chess.h"
#include "../adt/listbidak.h"
#include "../adt/queuegiliran.h"

/*inisialisasi queue ketika game dimulai*/
void InitGiliran(Queue_Giliran *Q, infotypeturn *currPlayerInfo);
//dipanggil sebelum game loop (saat inisialisasi)
// I.S.: currPlayerInfo sembarang, Q sembarang
// F.S.: Player WHITE (yang pertama main) sudah ada dalam currPlayerInfo
//		Sehingga InitGiliran cukup menginisiasi giliran selanjutnya yaitu pemain BLACK.

/*proses pergantian giliran*/
void changeTurnMove(Queue_Giliran *Q, infotypeturn *currPlayerInfo, MOVE *M);
/*I.S. 	: 	Q terdefinisi, currPlayerInfo terdefinisi, M terdefinisi
F.S. 	: 	Melakukan Del terhadap elemen Q yang sedang bermain, kemudian melakukan Add 
			terhadap elemen tersebut ke dalam Q setelah pemain melakukan move
			serta mengupdate counter dan poin pemain*/

void changeTurnUndo(Queue_Giliran *Q, infotypeturn *currPlayerInfo, MOVE *M);
/*I.S. 	: 	Q terdefinisi, currPlayerInfo terdefinisi, M terdefinisi
F.S. 	: 	Melakukan Add terhadap elemen Q yang sedang mengUndo, kemudian melakukan Del 
			terhadap elemen tersebut dari Q setelah pemain melakukan undo
			serta mengupdate counter dan poin pemain*/

int Poin(MOVE *M);
/*I.S. : M terdefinisi
F.S. : Menghasilkan poin yang bersesuaian berdasarkan type bidak yang dimakan (M.victim.id.type)*/

boolean Is50Turn(Queue_Giliran *Q);
/* I.S. : Q terdefinisi
F.S. : Menghasilkan true apabila InfoHeadT(Q).counter dan InfoTailT(Q).counter keduanya bernilai 50*/

#endif