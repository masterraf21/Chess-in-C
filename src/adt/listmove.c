#include "listmove.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST List_Move KOSONG ******************/
boolean IsEmpty (List_Move L)
/* Mengirim true jika List_Move kosong */
{
	return (First(L)==Nil);
}

/****************** PEMBUATAN List_Move KOSONG ******************/
void CreateEmpty (List_Move *L)
/* I.S. sembarang             */
/* F.S. Terbentuk List_Move kosong */
{
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address_move Alokasi (infotype X)
/* Mengirimkan address_move hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_move tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	ElmtList_Move *P = (ElmtList_Move *) malloc(sizeof(ElmtList_Move));

	if (P != Nil){
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}else{
		return Nil;
	}
}
void Dealokasi (address_move *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_move P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN List_Move ******************/
address_move Search (List_Move L, infotype X)
/* Mencari apakah ada elemen List_Move dengan Info(P)= X */
/* Jika ada, mengirimkan address_move elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address_move P_nil = Nil;
	address_move P_next = First(L);
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
void InsVFirst (List_Move *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address_move P = Alokasi(X);
	if (P!=Nil){
		InsertFirst(L, P);
	}
}
void InsVLast (List_Move *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen List_Move di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address_move P = Alokasi(X);
	if (P!=Nil){
		InsertLast(L, P);
	}

}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List_Move *L, infotype *X)
/* I.S. List_Move L tidak kosong  */
/* F.S. Elemen pertama List_Move dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address_move P;
	DelFirst(L, &P);
	*X = Info(P);
	Dealokasi(&P);
}
void DelVLast (List_Move *L, infotype *X)
/* I.S. List_Move tidak kosong */
/* F.S. Elemen terakhir List_Move dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address_move P;
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List_Move *L, address_move P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_move P sebagai elemen pertama */
{
	//elemen "kedua" diassign dengan address_move
	Next(P) = First(*L);
	First(*L) = P;

}
void InsertAfter (List_Move *L, address_move P, address_move Prec)
/* I.S. Prec pastilah elemen List_Move dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//P Inputan
	//Prec tuh addr sebelum P nantinya 
	Next(P) = Next(Prec);
	Next(Prec) = P;

}
void InsertLast (List_Move *L, address_move P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	

	if(IsEmpty(*L)){
		Next(P) = Nil;
		First(*L) = P;
		
	}else/*Traversal*/{
		//Traversal sampe ujung gan, berhenti sebelum Nil
		address_move Last = First(*L);
		while(Next(Last)!=Nil){
			Last = Next(Last);
		}
		InsertAfter(L,P,Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List_Move *L, address_move *P)
/* I.S. List_Move tidak kosong */
/* F.S. P adalah alamat elemen pertama List_Move sebelum penghapusan */
/*      Elemen List_Move berkurang satu (mungkin menjadi kosong) */
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
void DelP (List_Move *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen List_Move beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari List_Move dan di-dealokasi */
/* Jika tidak ada elemen List_Move dengan Info(P)=X, maka List_Move tetap */
/* List_Move mungkin menjadi kosong karena penghapusan */
{
	address_move P = Search(*L, X); //P bakal jadi output
	if (P!=Nil){
		address_move Prec = First(*L);

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
void DelLast (List_Move *L, address_move *P)
/* I.S. List_Move tidak kosong */
/* F.S. P adalah alamat elemen terakhir List_Move sebelum penghapusan  */
/*      Elemen List_Move berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
{
	address_move Last, PrecLast;
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
void DelAfter (List_Move *L, address_move *Pdel, address_move Prec)
/* I.S. List_Move tidak kosong. Prec adalah anggota List_Move  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen List_Move yang dihapus  */
{
	*Pdel = Next(Prec);
	if (*Pdel != Nil)
		Next(Prec) = Next(Next(Prec));
}

/****************** PROSES SEMUA ELEMEN List_Move ******************/
void PrintInfo (List_Move L)
/* I.S. List_Move mungkin kosong */
/* F.S. Jika List_Move tidak kosong, iai List_Move dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List_Move kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	if (!IsEmpty(L)){
		address_move P = First(L);

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
int NbElmt (List_Move L)
/* Mengirimkan banyaknya elemen List_Move; mengirimkan 0 jika List_Move kosong */
{
	address_move P = First(L);
	int count = 0;
	while(P!=Nil){
		count +=1 ;
		P = Next(P);
	}
	return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : List_Move tidak kosong ***/
infotype Max (List_Move L)
/* Mengirimkan nilai Info(P) yang maksimum */{
	address_move P = First(L);
	infotype Max = Info(P);

	while(P!=Nil){
		if(Info(P)>Max){
			Max = Info(P);
		}

		P = Next(P);
	}

	return Max;
}

address_move AdrMax (List_Move L)
/* Mengirimkan address_move P, dengan info(P) yang bernilai maksimum */
{
	address_move P = First(L);
	address_move Max = First(L);

	while(P!=Nil){
		if(Info(P)>Info(Max)){
			Max = P;
		}

		P = Next(P);
	}

	return Max;
}
infotype Min (List_Move L)
/* Mengirimkan nilai info(P) yang minimum */
{
	address_move P = First(L);
	infotype Min = Info(P);

	while(P!=Nil){
		if(Info(P)<Min){
			Min = Info(P);
		}

		P = Next(P);
	}

	return Min;

}
address_move AdrMin (List_Move L)
/* Mengirimkan address_move P, dengan info(P) yang bernilai minimum */
{
	address_move P = First(L);
	address_move Min = First(L);

	while(P!=Nil){
		if(Info(P)<Info(Min)){
			Min = P;
		}

		P = Next(P);
	}

	return Min;
}

float Average (List_Move L)
/* Mengirimkan nilai rata-rata info(P) */
{
	int nb = NbElmt(L);
	int jml = 0;
	address_move P  = First(L);

	while(P!=Nil){
		jml += Info(P);
		P = Next(P);
	}

	float rat = (float) jml / (float) nb;
	return rat;
}

/****************** PROSES TERHADAP List_Move ******************/

void InversList_Move (List_Move *L)
/* I.S. sembarang. */
/* F.S. elemen List_Move dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen List_Move, tanpa melakukan alokasi/dealokasi. */
{

	// address_move prev = Nil;
	// address_move curr = First(*L);
	// address_move next = Nil;

	// while(curr != Nil){
	// 	next = Next(curr);
	// 	Next(curr) = prev;

	// 	prev = curr;
	// 	curr = next;
	// }

	address_move P,Q;
	address_move First = First(*L);

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
void Konkat1 (List_Move *L1, List_Move *L2, List_Move *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah List_Move : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen List_Move L1 dan L2) */
/* dan L1 serta L2 menjadi List_Move kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	CreateEmpty(L3);

    if (!(IsEmpty(*L1))){
        First(*L3) = First(*L1);

        address_move last1 = First(*L1);

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