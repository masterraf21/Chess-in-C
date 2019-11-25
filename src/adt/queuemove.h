/* File : queuelist.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _QUEUEMOVE_H
#define _QUEUEMOVE_H
#include "boolean.h"
#include "../engine/chess.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef LIST_ID infotype;

/* Queue_Move dengan representasi berkait dengan pointer */
typedef struct tElmtQueueM * addressQ;
typedef struct tElmtQueueM { 
  infotype Info;
  addressQ Next; 
} ElmtQueue; 

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct { 
  addressQ HEAD;  /* alamat penghapusan */
  addressQ TAIL;  /* alamat penambahan */
} Queue_Move;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define NextQM(P) (P)->Next
#define InfoQM(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiQ (addressQ *P, infotype X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiQ (addressQ  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyQ (Queue_Move Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmtQ(Queue_Move Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyQ(Queue_Move * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void AddQ (Queue_Move * Q, infotype X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DelQ(Queue_Move * Q, infotype * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

#endif