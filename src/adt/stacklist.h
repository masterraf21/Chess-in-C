/* File : stacklist.h */
#ifndef _STACKLIST_H
#define _STACKLIST_H

#include "boolean.h"
#include "../engine/chess.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotypestack */
typedef MOVE infotypestack;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * address_stack;
typedef struct tElmtStack { 
  infotypestack Info;
  address_stack Next; 
} ElmtStack; 

/* Type stack dengan ciri TOP : */
typedef struct { 
  address_stack TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info 
#define NextStack(P) (P)->Next
#define InfoStack(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiStack (address_stack *P, infotypestack X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiStack (address_stack P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmptyStack (Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyStack (Stack * S);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack * S, infotypestack X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack * S, infotypestack * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

#endif