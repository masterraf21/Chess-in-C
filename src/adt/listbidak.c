#include "listbidak.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyBidak (List_Bidak L)
/* Mengirim true jika list kosong */
{
	return (FirstBidak(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyBidak (List_Bidak *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	FirstBidak(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address_bidak AlokasiB (infotypelb X)
/* Mengirimkan address_bidak hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_bidak tidak nil, dan misalnya */
/* menghasilkan P, maka InfoBidak(P)=X, NextBidak(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	ElmtListb *P = (ElmtListb *) malloc(sizeof(ElmtListb));

	if (P != Nil){
		InfoBidak(P) = X;
		NextBidak(P) = Nil;
		return P;
	}else{
		return Nil;
	}
}
void DealokasiB (address_bidak *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_bidak P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address_bidak SearchB (List_Bidak L, infotypelb X)
/* Mencari apakah ada elemen list dengan InfoBidak(P)= X */
/* Jika ada, mengirimkan address_bidak elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address_bidak P_nil = Nil;
	address_bidak P_next = FirstBidak(L);
	boolean found = false;

	//cek kosong gak
	//kalau ga kosong di proses
	//kalau kosong langsung return nil
	if(!IsEmpty(L)){
		//cek dulu elemen pertama apapun isinya
		do{
			if(InfoBidak(P_next)==X){
				P_nil = P_next;
				found = true;
			}else{
				P_next = NextBidak(P_next);
			}

		}while ((P_next!=Nil)&&(!found)); //berhenti pas dia udah diujung atau uda ketemu
	}

	return P_nil;
}

address_bidak SearchId (List_Bidak L, LIST_ID X){
	address_bidak P_nil = Nil;
	address_bidak P_next = FirstBidak(L);
	boolean found = false;

	//cek kosong gak
	//kalau ga kosong di proses
	//kalau kosong langsung return nil
	if(!IsEmpty(L)){
		//cek dulu elemen pertama apapun isinya
		do{
			if(InfoBidak(P_next).id==X){
				P_nil = P_next;
				found = true;
			}else{
				P_next = NextBidak(P_next);
			}

		}while ((P_next!=Nil)&&(!found)); //berhenti pas dia udah diujung atau uda ketemu
	}

	return P_nil;

}

address_bidak SearchCustom(List_Bidak L, BOARD_INDEX idx, BOARD_TILE type){
	address_bidak P_nil = Nil;
	address_bidak P_next = FirstBidak(L);
	boolean found = false;

	//cek kosong gak
	//kalau ga kosong di proses
	//kalau kosong langsung return nil
	if(!IsEmpty(L)){
		//cek dulu elemen pertama apapun isinya
		do{
			BOARD_INDEX idxp = InfoBidak(P_next).posisi;
			BOARD_TILE tilep = InfoBidak(P_next).warna*InfoBidak(P_next).id.type;
			if((idxp==idx)&&(tilep==type)){
				P_nil = P_next;
				found = true;
			}else{
				P_next = NextBidak(P_next);
			}

		}while ((P_next!=Nil)&&(!found)); //berhenti pas dia udah diujung atau uda ketemu
	}

	return P_nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List_Bidak *L, infotypelb X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address_bidak P = AlokasiB(X);
	if (P!=Nil){
		InsertFirst(L, P);
	}
}
void InsVLast (List_Bidak *L, infotypelb X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address_bidak P = AlokasiB(X);
	if (P!=Nil){
		InsertLast(L, P);
	}

}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List_Bidak *L, infotypelb *X)
/* I.S. List_Bidak L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address_bidak P;
	DelFirst(L, &P);
	*X = InfoBidak(P);
	DealokasiB(&P);
}
void DelVLast (List_Bidak *L, infotypelb *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address_bidak P;
	DelLast(L, &P);
	*X = InfoBidak(P);
	DealokasiB(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List_Bidak *L, address_bidak P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_bidak P sebagai elemen pertama */
{
	//elemen "kedua" diassign dengan address_bidak
	NextBidak(P) = FirstBidak(*L);
	FirstBidak(*L) = P;

}
void InsertAfter (List_Bidak *L, address_bidak P, address_bidak Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//P Inputan
	//Prec tuh addr sebelum P nantinya 
	NextBidak(P) = NextBidak(Prec);
	NextBidak(Prec) = P;

}
void InsertLast (List_Bidak *L, address_bidak P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	

	if(IsEmpty(*L)){
		NextBidak(P) = Nil;
		FirstBidak(*L) = P;
		
	}else/*Traversal*/{
		//Traversal sampe ujung gan, berhenti sebelum Nil
		address_bidak Last = FirstBidak(*L);
		while(NextBidak(Last)!=Nil){
			Last = NextBidak(Last);
		}
		InsertAfter(L,P,Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List_Bidak *L, address_bidak *P)
/* I.S. List_Bidak tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* FirstBidak element yg baru adalah suksesor elemen pertama yang lama */
{
	(*P) = FirstBidak(*L);
	if(NextBidak(FirstBidak(*L))==Nil){ //cuman ada satu
		CreateEmpty(L);
	}
	else{
		FirstBidak(*L) = NextBidak(FirstBidak(*L));
	}
}
void DelP (List_Bidak *L, infotypelb X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan InfoBidak(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan InfoBidak(P)=X, maka list tetap */
/* List_Bidak mungkin menjadi kosong karena penghapusan */
{
	address_bidak P = SearchB(*L, X); //P bakal jadi output
	if (P!=Nil){
		address_bidak Prec = FirstBidak(*L);

		if (Prec==P)/*yang pertama*/{
			DelFirst(L, &P);
		}else/*cari sebelumnya*/{
			while (NextBidak(Prec)!=P){
				Prec = NextBidak(Prec);
			}
			DelAfter(L, &P, Prec);
		}
	}

	DealokasiB(&P); //udah ketemu gan

}
void DelLast (List_Bidak *L, address_bidak *P)
/* I.S. List_Bidak tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
{
	address_bidak Last, PrecLast;
	Last = FirstBidak(*L);
	PrecLast = Nil;

	while(NextBidak(Last)!=Nil){
		//Traversal sampe ujung
		PrecLast = Last;
		Last = NextBidak(Last);
	}

	*P = Last;
	if (PrecLast==Nil){
		FirstBidak(*L) = Nil;
	}else{
		NextBidak(PrecLast) = Nil;
		//jadinya preclast tuh element terakhir gan
	}

}
/* jika ada */
void DelAfter (List_Bidak *L, address_bidak *Pdel, address_bidak Prec)
/* I.S. List_Bidak tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus NextBidak(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = NextBidak(Prec);
	if (*Pdel != Nil)
		NextBidak(Prec) = NextBidak(NextBidak(Prec));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List_Bidak L)
/* I.S. List_Bidak mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	if (!IsEmpty(L)){
		address_bidak P = FirstBidak(L);

		do{
			printf("%d", InfoBidak(P));
			P = NextBidak(P);

			if (P!=Nil){
				printf(",");
			}

		}while(P!=Nil);


	}
	printf("]");

}
int NbElmt (List_Bidak L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	address_bidak P = FirstBidak(L);
	int count = 0;
	while(P!=Nil){
		count +=1 ;
		P = NextBidak(P);
	}
	return count;
}

// /*** Prekondisi untuk Max/Min/rata-rata : List_Bidak tidak kosong ***/
// infotypelb Max (List_Bidak L)
// /* Mengirimkan nilai InfoBidak(P) yang maksimum */{
// 	address_bidak P = FirstBidak(L);
// 	infotypelb Max = InfoBidak(P);

// 	while(P!=Nil){
// 		if(InfoBidak(P)>Max){
// 			Max = InfoBidak(P);
// 		}

// 		P = NextBidak(P);
// 	}

// 	return Max;
// }

// address_bidak AdrMax (List_Bidak L)
// /* Mengirimkan address_bidak P, dengan info(P) yang bernilai maksimum */
// {
// 	address_bidak P = FirstBidak(L);
// 	address_bidak Max = FirstBidak(L);

// 	while(P!=Nil){
// 		if(InfoBidak(P)>InfoBidak(Max)){
// 			Max = P;
// 		}

// 		P = NextBidak(P);
// 	}

// 	return Max;
// }
// infotypelb Min (List_Bidak L)
// /* Mengirimkan nilai info(P) yang minimum */
// {
// 	address_bidak P = FirstBidak(L);
// 	infotypelb Min = InfoBidak(P);

// 	while(P!=Nil){
// 		if(InfoBidak(P)<Min){
// 			Min = InfoBidak(P);
// 		}

// 		P = NextBidak(P);
// 	}

// 	return Min;

// }
// address_bidak AdrMin (List_Bidak L)
// /* Mengirimkan address_bidak P, dengan info(P) yang bernilai minimum */
// {
// 	address_bidak P = FirstBidak(L);
// 	address_bidak Min = FirstBidak(L);

// 	while(P!=Nil){
// 		if(InfoBidak(P)<InfoBidak(Min)){
// 			Min = P;
// 		}

// 		P = NextBidak(P);
// 	}

// 	return Min;
// }

// float Average (List_Bidak L)
// /* Mengirimkan nilai rata-rata info(P) */
// {
// 	int nb = NbElmt(L);
// 	int jml = 0;
// 	address_bidak P  = FirstBidak(L);

// 	while(P!=Nil){
// 		jml += InfoBidak(P);
// 		P = NextBidak(P);
// 	}

// 	float rat = (float) jml / (float) nb;
// 	return rat;
// }

/****************** PROSES TERHADAP LIST ******************/

void InversList (List_Bidak *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{

	// address_bidak prev = Nil;
	// address_bidak curr = FirstBidak(*L);
	// address_bidak next = Nil;

	// while(curr != Nil){
	// 	next = NextBidak(curr);
	// 	NextBidak(curr) = prev;

	// 	prev = curr;
	// 	curr = next;
	// }

	address_bidak P,Q;
	address_bidak FirstBidak = FirstBidak(*L);

	P = FirstBidak(*L);
	Q = NextBidak(P);

	while(Q != Nil){

		P = Q;
		Q = NextBidak(Q);

		P;
		InsertFirst(L, P);
		NextBidak(FirstBidak) = Q;
	}

}
void Konkat1 (List_Bidak *L1, List_Bidak *L2, List_Bidak *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	CreateEmpty(L3);

    if (!(IsEmpty(*L1))){
        FirstBidak(*L3) = FirstBidak(*L1);

        address_bidak last1 = FirstBidak(*L1);

        while(NextBidak(last1) != Nil) {
            last1 = NextBidak(last1);
        }

        NextBidak(last1) = FirstBidak(*L2);
    }
    else{
        FirstBidak(*L3) = FirstBidak(*L2);
    }


    CreateEmpty(L1);
    CreateEmpty(L2);

}