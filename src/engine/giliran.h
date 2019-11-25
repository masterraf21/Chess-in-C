#ifndef GILIRAN_H
#define GILIRAN_H

#include "chess.h"
#include "../adt/listbidak.h"
#include "../adt/queuegiliran.h"



/*inisialisasi queue ketika game dimulai*/
void InitGiliran(Queue_Giliran *Q, infotypeturn *currPlayerInfo);
// I.S: Player White (yang pertama main) itu udah langsung dimasukin ke currPlayerInfo
// Jadi InitGiliran cukup menginisiasi giliran selanjutnya yaitu BLACK.

/*proses pergantian giliran*/
void changeTurn(Queue_Giliran *Q, infotypeturn *currPlayerInfo);
/*intinya disini nanti bakal nge Del elemen Q yang lg giliran, terus setelah melakukan move si 
	elemennya di Add lagi kedalem Q*/
/*Sekaligus nge-update counter giliran + poin kalo terjadi makan memakan*/

boolean Is50Turn(Queue_Giliran *Q);
/* I.S. : Q terdefinisi
F.S. : Menghasilkan true apabila InfoHeadT(Q).counter dan InfoTailT(Q).counter keduanya bernilai 50*/

#endif