#include "listmove.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST List_Move KOSONG ******************/
boolean IsEmptyM (List_Move L)
/* Mengirim true jika List_Move kosong */
{
	return (FirstMove(L)==Nil);
}
boolean IsMoveSama(MOVE a, MOVE b){
	return (a.cur_position==b.cur_position)&&(a.id.number==b.id.number)
	&&(a.id.type==b.id.type)&&(a.is_makan==b.is_makan)&&
	(a.warna==b.warna)&&(IsBidakSama(a.victim,b.victim));
}

/****************** PEMBUATAN List_Move KOSONG ******************/
void CreateEmptyM (List_Move *L)
/* I.S. sembarang             */
/* F.S. Terbentuk List_Move kosong */
{
	FirstMove(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address_move AlokasiMove (infotypelm X)
/* Mengirimkan address_move hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_move tidak nil, dan misalnya */
/* menghasilkan P, maka InfoMove(P)=X, NextMove(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	ElmtListm *P = (ElmtListm *) malloc(sizeof(ElmtListm));

	if (P != Nil){
		InfoMove(P) = X;
		NextMove(P) = Nil;
		return P;
	}else{
		return Nil;
	}
}
void DealokasiMove (address_move *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_move P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN List_Move ******************/
address_move SearchMove (List_Move L, infotypelm X)
/* Mencari apakah ada elemen List_Move dengan InfoMove(P)= X */
/* Jika ada, mengirimkan address_move elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address_move P_nil = Nil;
	address_move P_next = FirstMove(L);
	boolean found = false;

	//cek kosong gak
	//kalau ga kosong di proses
	//kalau kosong langsung return nil
	if(!IsEmptyM(L)){
		//cek dulu elemen pertama apapun isinya
		do{
			if(IsMoveSama(InfoMove(P_next),X)){
				P_nil = P_next;
				found = true;
			}else{
				P_next = NextMove(P_next);
			}

		}while ((P_next!=Nil)&&(!found)); //berhenti pas dia udah diujung atau uda ketemu
	}

	return P_nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstM (List_Move *L, infotypelm X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address_move P = AlokasiMove(X);
	if (P!=Nil){
		InsertFirstM(L, P);
	}
}
void InsVLastM (List_Move *L, infotypelm X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen List_Move di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address_move P = AlokasiMove(X);
	if (P!=Nil){
		InsertLastM(L, P);
	}

}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstM (List_Move *L, infotypelm *X)
/* I.S. List_Move L tidak kosong  */
/* F.S. Elemen pertama List_Move dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address_move P;
	DelFirstM(L, &P);
	*X = InfoMove(P);
	DealokasiMove(&P);
}
void DelVLastM (List_Move *L, infotypelm *X)
/* I.S. List_Move tidak kosong */
/* F.S. Elemen terakhir List_Move dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address_move P;
	DelLastM(L, &P);
	*X = InfoMove(P);
	DealokasiMove(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstM (List_Move *L, address_move P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_move P sebagai elemen pertama */
{
	//elemen "kedua" diassign dengan address_move
	NextMove(P) = FirstMove(*L);
	FirstMove(*L) = P;

}
void InsertAfterM (List_Move *L, address_move P, address_move Prec)
/* I.S. Prec pastilah elemen List_Move dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//P Inputan
	//Prec tuh addr sebelum P nantinya 
	NextMove(P) = NextMove(Prec);
	NextMove(Prec) = P;

}
void InsertLastM (List_Move *L, address_move P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	

	if(IsEmptyM(*L)){
		NextMove(P) = Nil;
		FirstMove(*L) = P;
		
	}else/*Traversal*/{
		//Traversal sampe ujung gan, berhenti sebelum Nil
		address_move Last = FirstMove(*L);
		while(NextMove(Last)!=Nil){
			Last = NextMove(Last);
		}
		InsertAfterM(L,P,Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstM (List_Move *L, address_move *P)
/* I.S. List_Move tidak kosong */
/* F.S. P adalah alamat elemen pertama List_Move sebelum penghapusan */
/*      Elemen List_Move berkurang satu (mungkin menjadi kosong) */
/* FirstMove element yg baru adalah suksesor elemen pertama yang lama */
{
	(*P) = FirstMove(*L);
	if(NextMove(FirstMove(*L))==Nil){ //cuman ada satu
		CreateEmptyM(L);
	}
	else{
		FirstMove(*L) = NextMove(FirstMove(*L));
	}
}
void DelPM (List_Move *L, infotypelm X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen List_Move beraddress P, dengan InfoMove(P)=X  */
/* Maka P dihapus dari List_Move dan di-dealokasi */
/* Jika tidak ada elemen List_Move dengan InfoMove(P)=X, maka List_Move tetap */
/* List_Move mungkin menjadi kosong karena penghapusan */
{
	address_move P = SearchMove(*L, X); //P bakal jadi output
	if (P!=Nil){
		address_move Prec = FirstMove(*L);

		if (Prec==P)/*yang pertama*/{
			DelFirstM(L, &P);
		}else/*cari sebelumnya*/{
			while (NextMove(Prec)!=P){
				Prec = NextMove(Prec);
			}
			DelAfterM(L, &P, Prec);
		}
	}

	DealokasiMove(&P); //udah ketemu gan

}
void DelLastM (List_Move *L, address_move *P)
/* I.S. List_Move tidak kosong */
/* F.S. P adalah alamat elemen terakhir List_Move sebelum penghapusan  */
/*      Elemen List_Move berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
{
	address_move Last, PrecLast;
	Last = FirstMove(*L);
	PrecLast = Nil;

	while(NextMove(Last)!=Nil){
		//Traversal sampe ujung
		PrecLast = Last;
		Last = NextMove(Last);
	}

	*P = Last;
	if (PrecLast==Nil){
		FirstMove(*L) = Nil;
	}else{
		NextMove(PrecLast) = Nil;
		//jadinya preclast tuh element terakhir gan
	}

}
/* jika ada */
void DelAfterM (List_Move *L, address_move *Pdel, address_move Prec)
/* I.S. List_Move tidak kosong. Prec adalah anggota List_Move  */
/* F.S. Menghapus NextMove(Prec): */
/*      Pdel adalah alamat elemen List_Move yang dihapus  */
{
	*Pdel = NextMove(Prec);
	if (*Pdel != Nil)
		NextMove(Prec) = NextMove(NextMove(Prec));
}

/****************** PROSES SEMUA ELEMEN List_Move ******************/
// void PrintInfoM (List_Move L)
// /* I.S. List_Move mungkin kosong */
// /* F.S. Jika List_Move tidak kosong, iai List_Move dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika List_Move kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
// {
// 	printf("[");
// 	if (!IsEmptyM(L)){
// 		address_move P = FirstMove(L);

// 		do{
// 			printf("%d", InfoMove(P));
// 			P = NextMove(P);

// 			if (P!=Nil){
// 				printf(",");
// 			}

// 		}while(P!=Nil);


// 	}
// 	printf("]");

// }
int NbElmtM (List_Move L)
/* Mengirimkan banyaknya elemen List_Move; mengirimkan 0 jika List_Move kosong */
{
	address_move P = FirstMove(L);
	int count = 0;
	while(P!=Nil){
		count +=1 ;
		P = NextMove(P);
	}
	return count;
}
// /*** Prekondisi untuk Max/Min/rata-rata : List_Move tidak kosong ***/
// infotypelm MaxM (List_Move L)
// /* Mengirimkan nilai InfoMove(P) yang maksimum */{
// 	address_move P = FirstMove(L);
// 	infotypelm Max = InfoMove(P);

// 	while(P!=Nil){
// 		if(InfoMove(P)>Max){
// 			Max = InfoMove(P);
// 		}

// 		P = NextMove(P);
// 	}

// 	return Max;
// }

// address_move AdrMaxM (List_Move L)
// /* Mengirimkan address_move P, dengan info(P) yang bernilai maksimum */
// {
// 	address_move P = FirstMove(L);
// 	address_move Max = FirstMove(L);

// 	while(P!=Nil){
// 		if(InfoMove(P)>InfoMove(Max)){
// 			Max = P;
// 		}

// 		P = NextMove(P);
// 	}

// 	return Max;
// }
// infotypelm MinM (List_Move L)
// /* Mengirimkan nilai info(P) yang minimum */
// {
// 	address_move P = FirstMove(L);
// 	infotypelm Min = InfoMove(P);

// 	while(P!=Nil){
// 		if(InfoMove(P)<Min){
// 			Min = InfoMove(P);
// 		}

// 		P = NextMove(P);
// 	}

// 	return Min;

// }
// address_move AdrMinM (List_Move L)
// /* Mengirimkan address_move P, dengan info(P) yang bernilai minimum */
// {
// 	address_move P = FirstMove(L);
// 	address_move Min = FirstMove(L);

// 	while(P!=Nil){
// 		if(InfoMove(P)<InfoMove(Min)){
// 			Min = P;
// 		}

// 		P = NextMove(P);
// 	}

// 	return Min;
// }

// float AverageM (List_Move L)
// /* Mengirimkan nilai rata-rata info(P) */
// {
// 	int nb = NbElmt(L);
// 	int jml = 0;
// 	address_move P  = FirstMove(L);

// 	while(P!=Nil){
// 		jml += InfoMove(P);
// 		P = NextMove(P);
// 	}

// 	float rat = (float) jml / (float) nb;
// 	return rat;
// }

/****************** PROSES TERHADAP List_Move ******************/

// void InversList_Move (List_Move *L)
// /* I.S. sembarang. */
// /* F.S. elemen List_Move dibalik : */
// /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
// /* Membalik elemen List_Move, tanpa melakukan alokasi/dealokasi. */
// {

// 	address_move P,Q;
// 	address_move FirstMove = FirstMove(*L);

// 	P = FirstMove(*L);
// 	Q = NextMove(P);

// 	while(Q != Nil){

// 		P = Q;
// 		Q = NextMove(Q);

// 		P;
// 		InsertFirstM(L, P);
// 		NextMove(FirstMove) = Q;
// 	}

// }
void Konkat1M (List_Move *L1, List_Move *L2, List_Move *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah List_Move : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen List_Move L1 dan L2) */
/* dan L1 serta L2 menjadi List_Move kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	CreateEmptyM(L3);

    if (!(IsEmptyM(*L1))){
        FirstMove(*L3) = FirstMove(*L1);

        address_move last1 = FirstMove(*L1);

        while(NextMove(last1) != Nil) {
            last1 = NextMove(last1);
        }

        NextMove(last1) = FirstMove(*L2);
    }
    else{
        FirstMove(*L3) = FirstMove(*L2);
    }


    CreateEmptyM(L1);
    CreateEmptyM(L2);

}