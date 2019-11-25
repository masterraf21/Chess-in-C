#include <stdlib.h>
#include <stdio.h>
#include "queuegiliran.h"

/* Prototype manajemen memori */
void AlokasiTurn (address *P, infotypeturn X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoT(P)=X dan 
        NextT(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
	*P = (address) malloc(sizeof(ElmtQueueTurn));

	if(*P!=Nil){
		InfoT(*P) = X;
		NextT(*P) = Nil;
	}
}
void DealokasiTurn (address  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
	free(P);
}
boolean IsEmptyTurn (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
	return ((HeadT(Q)==Nil)&&(TailT(Q)==Nil));
}
int NbElmtTurn(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
	int count = 0;
	address P = HeadT(Q);

	while(P!=Nil){
		P = NextT(P);
		count++;
	}
	
	return count;
}
/*** Kreator ***/
void CreateEmptyTurn(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
	HeadT(*Q) = Nil;
	TailT(*Q) = Nil;
}
/*** Primitif AddTurn/DelTurnete ***/
void AddTurn (Queue * Q, infotypeturn X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
	address P;
	AlokasiTurn(&P, X);

	if (P!=Nil){
		if (IsEmptyTurn(*Q)){
			HeadT(*Q) = P;
			TailT(*Q) = P;
		}else{
			//next the current tail with P
			NextT(TailT(*Q)) = P;
			//now that the current tail is p assign with p
			TailT(*Q) = P;
		}
	}
}
void DelTurn(Queue * Q, infotypeturn * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
	address P = HeadT(*Q);

	if(NextT(HeadT(*Q))==Nil)
		//only one element, then create empty
		CreateEmptyTurn(Q);
	else
		//get the next one
		HeadT(*Q) = NextT(HeadT(*Q));

	//get the info then deallocate
	*X = InfoT(P);
	DealokasiTurn(P);
}