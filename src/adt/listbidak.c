#include "listbidak.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return (First(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));

	if (P != Nil){
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}else{
		return Nil;
	}
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P_nil = Nil;
	address P_next = First(L);
	boolean found = false;

	//cek kosong gak
	//kalau ga kosong di proses
	//kalau kosong langsung return nil
	if(!IsEmpty(L)){
		//cek dulu elemen pertama apapun isinya
		do{
			if(Info(P_next)==X){
				P_nil = P_next;
				found = true;
			}else{
				P_next = Next(P_next);
			}

		}while ((P_next!=Nil)&&(!found)); //berhenti pas dia udah diujung atau uda ketemu
	}

	return P_nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P = Alokasi(X);
	if (P!=Nil){
		InsertFirst(L, P);
	}
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P = Alokasi(X);
	if (P!=Nil){
		InsertLast(L, P);
	}

}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P;
	DelFirst(L, &P);
	*X = Info(P);
	Dealokasi(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P;
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	//elemen "kedua" diassign dengan address
	Next(P) = First(*L);
	First(*L) = P;

}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//P Inputan
	//Prec tuh addr sebelum P nantinya 
	Next(P) = Next(Prec);
	Next(Prec) = P;

}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	

	if(IsEmpty(*L)){
		Next(P) = Nil;
		First(*L) = P;
		
	}else/*Traversal*/{
		//Traversal sampe ujung gan, berhenti sebelum Nil
		address Last = First(*L);
		while(Next(Last)!=Nil){
			Last = Next(Last);
		}
		InsertAfter(L,P,Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	(*P) = First(*L);
	if(Next(First(*L))==Nil){ //cuman ada satu
		CreateEmpty(L);
	}
	else{
		First(*L) = Next(First(*L));
	}
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P = Search(*L, X); //P bakal jadi output
	if (P!=Nil){
		address Prec = First(*L);

		if (Prec==P)/*yang pertama*/{
			DelFirst(L, &P);
		}else/*cari sebelumnya*/{
			while (Next(Prec)!=P){
				Prec = Next(Prec);
			}
			DelAfter(L, &P, Prec);
		}
	}

	Dealokasi(&P); //udah ketemu gan

}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
{
	address Last, PrecLast;
	Last = First(*L);
	PrecLast = Nil;

	while(Next(Last)!=Nil){
		//Traversal sampe ujung
		PrecLast = Last;
		Last = Next(Last);
	}

	*P = Last;
	if (PrecLast==Nil){
		First(*L) = Nil;
	}else{
		Next(PrecLast) = Nil;
		//jadinya preclast tuh element terakhir gan
	}

}
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	if (*Pdel != Nil)
		Next(Prec) = Next(Next(Prec));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	if (!IsEmpty(L)){
		address P = First(L);

		do{
			printf("%d", Info(P));
			P = Next(P);

			if (P!=Nil){
				printf(",");
			}

		}while(P!=Nil);


	}
	printf("]");

}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	address P = First(L);
	int count = 0;
	while(P!=Nil){
		count +=1 ;
		P = Next(P);
	}
	return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */{
	address P = First(L);
	infotype Max = Info(P);

	while(P!=Nil){
		if(Info(P)>Max){
			Max = Info(P);
		}

		P = Next(P);
	}

	return Max;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
	address P = First(L);
	address Max = First(L);

	while(P!=Nil){
		if(Info(P)>Info(Max)){
			Max = P;
		}

		P = Next(P);
	}

	return Max;
}
infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
	address P = First(L);
	infotype Min = Info(P);

	while(P!=Nil){
		if(Info(P)<Min){
			Min = Info(P);
		}

		P = Next(P);
	}

	return Min;

}
address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
	address P = First(L);
	address Min = First(L);

	while(P!=Nil){
		if(Info(P)<Info(Min)){
			Min = P;
		}

		P = Next(P);
	}

	return Min;
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
	int nb = NbElmt(L);
	int jml = 0;
	address P  = First(L);

	while(P!=Nil){
		jml += Info(P);
		P = Next(P);
	}

	float rat = (float) jml / (float) nb;
	return rat;
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{

	// address prev = Nil;
	// address curr = First(*L);
	// address next = Nil;

	// while(curr != Nil){
	// 	next = Next(curr);
	// 	Next(curr) = prev;

	// 	prev = curr;
	// 	curr = next;
	// }

	address P,Q;
	address First = First(*L);

	P = First(*L);
	Q = Next(P);

	while(Q != Nil){

		P = Q;
		Q = Next(Q);

		P;
		InsertFirst(L, P);
		Next(First) = Q;
	}

}
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	CreateEmpty(L3);

    if (!(IsEmpty(*L1))){
        First(*L3) = First(*L1);

        address last1 = First(*L1);

        while(Next(last1) != Nil) {
            last1 = Next(last1);
        }

        Next(last1) = First(*L2);
    }
    else{
        First(*L3) = First(*L2);
    }


    CreateEmpty(L1);
    CreateEmpty(L2);

}