/* File : queuelist.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _QUEUEMOVE_H
#define _QUEUEMOVE_H
#include "boolean.h"
#include "../engine/chess.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

typedef struct {
	COLOR player;
	int counter;
	int poin;
} infotypeturn;


/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueueTurn * address_turn;
typedef struct tElmtQueueTurn { 
  infotypeturn InfoT;
  address_turn NextT; 
} ElmtQueueTurn; 

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct { 
  address_turn HEADT;  /* alamat penghapusan */
  address_turn TAILT;  /* alamat penambahan */
} Queue_Giliran;

/* Selektor */
#define HeadT(Q) (Q).HEADT
#define TailT(Q) (Q).TAILT
#define InfoHeadT(Q) (Q).HEAD->InfoT
#define InfoTailT(Q) (Q).TAIL->InfoT
#define NextT(P) (P)->NextT
#define InfoT(P) (P)->InfoT

/* Prototype manajemen memori */
void AlokasiTurn (address_turn *P, infotypeturn X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoT(P)=X dan 
        NextT(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiTurn (address_turn  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyTurn (Queue_Giliran Q);
/* Mengirim true jika Q kosong: HEADT(Q)=Nil and TAILT(Q)=Nil */
int NbElmtTurn(Queue_Giliran Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyTurn(Queue_Giliran * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif AddTurn/Delete ***/
void AddTurn (Queue_Giliran * Q, infotypeturn X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAILT dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAILT, TAILT "maju" */
void DelTurn(Queue_Giliran * Q, infotypeturn * X);
/* Proses: Menghapus X pada bagian HEADT dari Q dan mendealokasi
   elemen HEADT */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEADT pd I.S., HEADT "mundur" */

#endif