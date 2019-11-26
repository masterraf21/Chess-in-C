#include <stdlib.h>
#include <stdio.h>
#include "queuemove.h"

/* Prototype manajemen memori */
void AlokasiQ (addressQ *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoQM(P)=X dan 
        NextQM(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
	*P = (addressQ) malloc(sizeof(ElmtQueue));

	if(*P!=Nil){
		InfoQM(*P) = X;
		NextQM(*P) = Nil;
	}
}
void DealokasiQ (addressQ P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
	free(P);
}
boolean IsEmptyQ (Queue_Move Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
	return ((Head(Q)==Nil)&&(Tail(Q)==Nil));
}
int NbElmtQ(Queue_Move Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
	int count = 0;
	addressQ P = Head(Q);

	while(P!=Nil){
		P = NextQM(P);
		count++;
	}
	
	return count;
}
/*** Kreator ***/
void CreateEmptyQ(Queue_Move * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}
/*** Primitif Add/Delete ***/
void AddQ (Queue_Move * Q, infotype X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
	addressQ P;
	AlokasiQ(&P, X);

	if (P!=Nil){
		if (IsEmptyQ(*Q)){
			Head(*Q) = P;
			Tail(*Q) = P;
		}else{
			//NextQM the current tail with P
			NextQM(Tail(*Q)) = P;
			//now that the current tail is p assign with p
			Tail(*Q) = P;
		}
	}
}
void DelQ(Queue_Move * Q, infotype * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
	addressQ P = Head(*Q);

	if(NextQM(Head(*Q))==Nil)
		//only one element, then create empty
		CreateEmptyQ(Q);
	else
		//get the NextQM one
		Head(*Q) = NextQM(Head(*Q));

	//get the info then deallocate
	*X = InfoQM(P);
	DealokasiQ(P);
}