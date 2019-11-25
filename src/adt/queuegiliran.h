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
typedef struct tElmtQueueTurn * address;
typedef struct tElmtQueueTurn { 
  infotypeturn InfoT;
  address Next; 
} ElmtQueueTurn; 

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct { 
  address HEAD;  /* alamat penghapusan */
  address TAIL;  /* alamat penambahan */
} Queue_Giliran;

typedef Queue_Giliran Queue;

/* Selektor */
#define HeadT(Q) (Q).HEAD
#define TailT(Q) (Q).TAIL
#define InfoHeadT(Q) (Q).HEAD->Info
#define InfoTailT(Q) (Q).TAIL->Info
#define NextT(P) (P)->Next
#define InfoT(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiTurn (address *P, infotypeturn X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(TP)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiTurn (address  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyTurn (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmtTurn(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyTurn(Queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif AddTurn/DelTurnete ***/
void AddTurn (Queue * Q, infotypeturn X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DelTurn(Queue * Q, infotypeturn * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

#endif