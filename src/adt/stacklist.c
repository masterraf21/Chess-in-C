#include <stdlib.h>
#include <stdio.h>
#include "stacklist.h"

/* Prototype manajemen memori */
void AlokasiStack (address_stack *P, infotypestack X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoStack(P)=X dan 
        NextStack(P)=Nil */
/*      P=Nil jika alokasi gagal */{
	*P = (address_stack) malloc(sizeof(ElmtStack));
	if(*P!=Nil){
		InfoStack(*P) = X;
		NextStack(*P) = Nil;
	}
}
void DealokasiStack (address_stack P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 
{
	free(P);
}
/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
	return (Top(S)==Nil);
}
void CreateEmptyStack (Stack * S)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stackS yang kosong */
{
	Top(*S) = Nil;
}
void Push (Stack * S, infotypestack X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
	address_stack P;
	AlokasiStack(&P,X);

	if(P!=Nil){
		//add the current top to next of
		//our allocated P
		NextStack(P) = Top(*S);
		//then assign the actual top to the p
		Top(*S) = P;
	}
}
void Pop (Stack * S, infotypestack * X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
	address_stack P = Top(*S);
	//kalo kosong
	if (NextStack(Top(*S))==Nil)
		CreateEmptyStack(S);
	else
		Top(*S) = NextStack(Top(*S));

	*X = InfoStack(P);
	DealokasiStack(P);
}