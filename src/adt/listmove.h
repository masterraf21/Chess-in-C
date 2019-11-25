/* File : List_Movelinier.h */
/* contoh ADT List_Move berkait dengan representasi fisik pointer  */
/* Representasi address_move dengan pointer */
/* infotypelm adalah integer */
/* ini isinya buat linked List_Move isi bidak*/
#ifndef List_move_H
#define List_move_H

#include "boolean.h"
#include "../engine/chess.h"
#include "listbidak.h"

#define Nil NULL

typedef MOVE infotypelm;
typedef struct tElmtListm *address_move;
typedef struct tElmtListm { 
	infotypelm info;
	address_move next;
} ElmtListm;

typedef struct {
	address_move FirstMove;
} List_Move;


/* Definisi List_Move : */
/* List_Move kosong : FirstMove(L) = Nil */
/* Setiap elemen dengan address_move P dapat diacu Info(P), NextMove(P) */
/* Elemen terakhir List_Move : jika address_movenya Last, maka NextMove(Last)=Nil */
#define InfoMove(P) (P)->info
#define NextMove(P) (P)->next
#define FirstMove(L) ((L).FirstMove)

/* PROTOTYPE */
/****************** TEST List_Move KOSONG ******************/
boolean IsEmptyM (List_Move L);
/* Mengirim true jika List_Move kosong */

/****************** PEMBUATAN List_Move KOSONG ******************/
void CreateEmptyM (List_Move *L);
/* I.S. sembarang             */
/* F.S. Terbentuk List_Move kosong */

/****************** Manajemen Memori ******************/
address_move AlokasiMove (infotypelm X);
/* Mengirimkan address_move hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_move tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, NextMove(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiMove (address_move *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_move P */

/****************** PENCARIAN SEBUAH ELEMEN List_Move ******************/
address_move SearchMove (List_Move L, infotypelm X);
/* Mencari apakah ada elemen List_Move dengan info(P)= X */
/* Jika ada, mengirimkan address_move elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstM (List_Move *L, infotypelm X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastM (List_Move *L, infotypelm X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen List_Move di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstM (List_Move *L, infotypelm *X);
/* I.S. List_Move L tidak kosong  */
/* F.S. Elemen pertama List_Move dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastM (List_Move *L, infotypelm *X);
/* I.S. List_Move tidak kosong */
/* F.S. Elemen terakhir List_Move dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstM (List_Move *L, address_move P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_move P sebagai elemen pertama */
void InsertAfterM (List_Move *L, address_move P, address_move Prec);
/* I.S. Prec pastilah elemen List_Move dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastM (List_Move *L, address_move P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstM (List_Move *L, address_move *P);
/* I.S. List_Move tidak kosong */
/* F.S. P adalah alamat elemen pertama List_Move sebelum penghapusan */
/*      Elemen List_Move berkurang satu (mungkin menjadi kosong) */
/* FirstMove element yg baru adalah suksesor elemen pertama yang lama */
void DelPM (List_Move *L, infotypelm X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen List_Move beraddress_move P, dengan info(P)=X  */
/* Maka P dihapus dari List_Move dan di-dealokasi */
/* Jika tidak ada elemen List_Move dengan info(P)=X, maka List_Move tetap */
/* List_Move mungkin menjadi kosong karena penghapusan */
void DelLastM (List_Move *L, address_move *P);
/* I.S. List_Move tidak kosong */
/* F.S. P adalah alamat elemen terakhir List_Move sebelum penghapusan  */
/*      Elemen List_Move berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterM (List_Move *L, address_move *Pdel, address_move Prec);
/* I.S. List_Move tidak kosong. Prec adalah anggota List_Move  */
/* F.S. Menghapus NextMove(Prec): */
/*      Pdel adalah alamat elemen List_Move yang dihapus  */

/****************** PROSES SEMUA ELEMEN List_Move ******************/
void PrintInfoM (List_Move L);
/* I.S. List_Move mungkin kosong */
/* F.S. Jika List_Move tidak kosong, iai List_Move dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List_Move kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtM (List_Move L);
/* Mengirimkan banyaknya elemen List_Move; mengirimkan 0 jika List_Move kosong */

// /*** Prekondisi untuk Max/Min/rata-rata : List_Move tidak kosong ***/
// infotypelm MaxM (List_Move L);
// /* Mengirimkan nilai info(P) yang maksimum */
// address_move AdrMaxM (List_Move L);
// /* Mengirimkan address_move P, dengan info(P) yang bernilai maksimum */
// infotypelm MinM (List_Move L);
// /* Mengirimkan nilai info(P) yang minimum */
// address_move AdrMinM (List_Move L);
// /* Mengirimkan address_move P, dengan info(P) yang bernilai minimum */
// float AverageM (List_Move L);
// /* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP List_Move ******************/

void InversList_Move (List_Move *L);
/* I.S. sembarang. */
/* F.S. elemen List_Move dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen List_Move, tanpa melakukan alokasi/dealokasi. */

void Konkat1M (List_Move *L1, List_Move *L2, List_Move *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah List_Move : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen List_Move L1 dan L2) */
/* dan L1 serta L2 menjadi List_Move kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif
