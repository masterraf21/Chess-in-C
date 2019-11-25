#include "giliran.h"
#include "undo.h"
#include <stdlib.h>

void InitGiliran(Queue_Giliran *Q, infotypeturn *currPlayerInfo)
//dipanggil sebelum game loop (pas inisialisasi)
// I.S.: currPlayerInfo sembarang, Q sembarang
// F.S.:Player WHITE (yang pertama main) itu udah langsung dimasukin ke currPlayerInfo
//		Jadi InitGiliran cukup menginisiasi giliran selanjutnya yaitu BLACK.
{
	/*KAMUS*/
	infotypeturn B;
	B.player = BLACK;
	B.counter = 0;
	B.poin = 0;
	/*ALGORITMA*/
	CreateEmpty(Q);
	Add(Q,B);
	// ngasih tau giliran pertama siapa
	(*currPlayerInfo).player = WHITE;
	(*currPlayerInfo).counter = 0;
	(*currPlayerInfo).poin = 0;
}

void changeTurn(Queue_Giliran *Q, infotypeturn *currPlayerInfo) /* parameternya mungkin ditambahin: 'Queue_Giliran *stateCurrQueue' yang I.S. nya sembarang
(awalnya sembarang, isinya bakal jadi Queue_Giliran yang bakal masuk ke stack undo),
ada atau nggaknya si parameter ini tergantung undo yang dibikin yumna. Yumnanya mau ngepush current game statenya dimana?
kalo misalnya yumna mau ngepush di dalam changeTurn : letakkan pushnya kek kode dibawah ini (setelah add, tp sebelum del)
tapi kalo misalnya yumna mau ngepushnya di main program atau bikin prosedur sendiri,
berarti gaperlu ngePush current game state di dalem changeTurn.
current game state itu disini maksudnya posisi bidak ada dimana aja, dsb*/


// changeTurn dipanggil di akhir game loop
/*intinya disini nanti bakal nge Del elemen Q yang lg giliran, terus setelah melakukan move si 
	elemennya di Add lagi kedalem Q*/
/*Sekaligus nge-update counter giliran + poin kalo terjadi makan memakan*/
{
	//infotypeturn X,Y;
	(*currPlayerInfo).counter ++;
	Add(Q, currPlayerInfo);
	// CreateEmpty(stateCurrQueue);
	// Del(Q, X);
	// Del(Q, Y);
	// Add(stateCurrQueue, X); Add(Q,X);
	// Add(stateCurrQueue, Y); Add(Q,Y);
	// vvv ini kalau yumnaa ngepushnya dalem changeTurn
	// Push(S, Q) -> masukin state ini ke dalam Stack utk di Undo
	Del(Q, currPlayerInfo);
}

boolean Is50Turn(Queue_Giliran *Q)
{
	return (((InfoHeadT(Q).counter) == 50) && ((InfoTailT(Q).counter) == 50));
}