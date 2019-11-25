/* File : List_Bidakbidak.h */
/* contoh ADT List_Bidak berkait dengan representasi fisik pointer  */
/* Representasi address_bidak dengan pointer */
/* infotypelb adalah integer */
/* ini isinya buat linked List_Bidak isi bidak*/
#ifndef List_bidak_H
#define List_bidak_H

#include "boolean.h"
#include "../engine/chess.h"

#define Nil NULL

typedef BIDAK infotypelb;
typedef struct tElmtListb *address_bidak;
typedef struct tElmtListb { 
	infotypelb infob;
	address_bidak next;
} ElmtListb;

typedef struct {
	address_bidak First;
} List_Bidak;


/* Definisi List_Bidak : */
/* List_Bidak kosong : FirstBidak(L) = Nil */
/* Setiap elemen dengan address_bidak P dapat diacu Info(P), NextBidak(P) */
/* Elemen terakhir List_Bidak : jika address_bidaknya Last, maka NextBidak(Last)=Nil */
#define InfoBidak(P) (P)->infob
#define NextBidak(P) (P)->next
#define FirstBidak(L) ((L).First)

/* PROTOTYPE */
/****************** TEST List_Bidak KOSONG ******************/
boolean IsEmptyBidak (List_Bidak L);
/* Mengirim true jika List_Bidak kosong */

/****************** PEMBUATAN List_Bidak KOSONG ******************/
void CreateEmptyBidak (List_Bidak *L);
/* I.S. sembarang             */
/* F.S. Terbentuk List_Bidak kosong */

/****************** Manajemen Memori ******************/
address_bidak AlokasiB (infotypelb X);
/* Mengirimkan address_bidak hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_bidak tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, NextBidak(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiB (address_bidak *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_bidak P */

/****************** PENCARIAN SEBUAH ELEMEN List_Bidak ******************/
address_bidak SearchB (List_Bidak L, infotypelb X);
/* Mencari apakah ada elemen List_Bidak dengan info(P)= X */
/* Jika ada, mengirimkan address_bidak elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
address_bidak SearchId (List_Bidak L, LIST_ID X);
/* Buat cari id tertentu gan */
address_bidak SearchCustom(List_Bidak L, BOARD_INDEX idx, BOARD_TILE type);


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List_Bidak *L, infotypelb X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List_Bidak *L, infotypelb X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen List_Bidak di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List_Bidak *L, infotypelb *X);
/* I.S. List_Bidak L tidak kosong  */
/* F.S. Elemen pertama List_Bidak dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List_Bidak *L, infotypelb *X);
/* I.S. List_Bidak tidak kosong */
/* F.S. Elemen terakhir List_Bidak dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List_Bidak *L, address_bidak P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_bidak P sebagai elemen pertama */
void InsertAfter (List_Bidak *L, address_bidak P, address_bidak Prec);
/* I.S. Prec pastilah elemen List_Bidak dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List_Bidak *L, address_bidak P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List_Bidak *L, address_bidak *P);
/* I.S. List_Bidak tidak kosong */
/* F.S. P adalah alamat elemen pertama List_Bidak sebelum penghapusan */
/*      Elemen List_Bidak berkurang satu (mungkin menjadi kosong) */
/* FirstBidak element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List_Bidak *L, infotypelb X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen List_Bidak beraddress_bidak P, dengan info(P)=X  */
/* Maka P dihapus dari List_Bidak dan di-dealokasi */
/* Jika tidak ada elemen List_Bidak dengan info(P)=X, maka List_Bidak tetap */
/* List_Bidak mungkin menjadi kosong karena penghapusan */
void DelLast (List_Bidak *L, address_bidak *P);
/* I.S. List_Bidak tidak kosong */
/* F.S. P adalah alamat elemen terakhir List_Bidak sebelum penghapusan  */
/*      Elemen List_Bidak berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List_Bidak *L, address_bidak *Pdel, address_bidak Prec);
/* I.S. List_Bidak tidak kosong. Prec adalah anggota List_Bidak  */
/* F.S. Menghapus NextBidak(Prec): */
/*      Pdel adalah alamat elemen List_Bidak yang dihapus  */

/****************** PROSES SEMUA ELEMEN List_Bidak ******************/
void PrintInfo (List_Bidak L);
/* I.S. List_Bidak mungkin kosong */
/* F.S. Jika List_Bidak tidak kosong, iai List_Bidak dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List_Bidak kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List_Bidak L);
/* Mengirimkan banyaknya elemen List_Bidak; mengirimkan 0 jika List_Bidak kosong */

// /*** Prekondisi untuk Max/Min/rata-rata : List_Bidak tidak kosong ***/
// infotypelb Max (List_Bidak L);
// /* Mengirimkan nilai info(P) yang maksimum */
// address_bidak AdrMax (List_Bidak L);
// /* Mengirimkan address_bidak P, dengan info(P) yang bernilai maksimum */
// infotypelb Min (List_Bidak L);
// /* Mengirimkan nilai info(P) yang minimum */
// address_bidak AdrMin (List_Bidak L);
// /* Mengirimkan address_bidak P, dengan info(P) yang bernilai minimum */
// float Average (List_Bidak L);
// /* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP List_Bidak ******************/

void InversList_Bidak (List_Bidak *L);
/* I.S. sembarang. */
/* F.S. elemen List_Bidak dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen List_Bidak, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List_Bidak *L1, List_Bidak *L2, List_Bidak *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah List_Bidak : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen List_Bidak L1 dan L2) */
/* dan L1 serta L2 menjadi List_Bidak kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif
