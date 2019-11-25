#include <stdlib.h>
#include <stdio.h>
#include "queuegiliran.h"

/* Prototype manajemen memori */
void AlokasiTurn (address *P, infotypeturn X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
	*P = (address) malloc(sizeof(ElmtQueueTurn));

	if(*P!=Nil){
		Info(*P) = X;
		Next(*P) = Nil;
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
	return ((Head(Q)==Nil)&&(Tail(Q)==Nil));
}
int NbElmtTurn(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
	int count = 0;
	address P = Head(Q);

	while(P!=Nil){
		P = Next(P);
		count++;
	}
	
	return count;
}
/*** Kreator ***/
void CreateEmptyTurn(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
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
			Head(*Q) = P;
			Tail(*Q) = P;
		}else{
			//next the current tail with P
			Next(Tail(*Q)) = P;
			//now that the current tail is p assign with p
			Tail(*Q) = P;
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
	address P = Head(*Q);

	if(Next(Head(*Q))==Nil)
		//only one element, then create empty
		CreateEmptyTurn(Q);
	else
		//get the next one
		Head(*Q) = Next(Head(*Q));

	//get the info then deallocate
	*X = Info(P);
	DealokasiTurn(P);
}