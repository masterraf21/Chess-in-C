#include "giliran.h"
#include "undo.h"
#include <stdlib.h>

void InitGiliran(Queue *Q, infotype *currPlayerInfo)
//dipanggil sebelum game loop (pas inisialisasi)
// I.S.: currPlayerInfo sembarang, Queue sembarang
// F.S.:Player White (yang pertama main) itu udah langsung dimasukin ke currPlayerInfo
//		Jadi InitGiliran cukup menginisiasi giliran selanjutnya yaitu BLACK.
{
	/*KAMUS*/
	infotype B;
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

void changeTurn(Queue *Q, infotype *currPlayerInfo) /* parameternya boleh jadi ditambahin: Queue *stateCurrQueue yang I.S. nya sembarang
(awalnya sembarang, isinya bakal jadi Queue yang bakal masuk ke stack undo),
ada atau nggaknya si parameter ini tergantung undo yang dibikin yumna. Yumnanya mau ngepush current game statenya dimana?
kalo misalnya yumna mau ngepush di dalam changeTurn : letakkan pushnya kek kode dibawah ini (setelah add, tp sebelum del)
tapi kalo misalnya yumna mau ngepushnya di main program atau bikin prosedur sendiri
berarti gaperlu ngePush current game state di dalem changeTurn
current game state itu disini maksudnya posisi bidak ada dimana aja, dsb*/


// changeTurn ini dipanggil di akhir game loop
/*intinya disini nanti bakal nge Del elemen Q yang lg giliran, terus setelah melakukan move si 
	elemennya di Add lagi kedalem Q*/
/*Sekaligus nge-update counter giliran + poin kalo terjadi makan memakan*/
{
	//infotype X,Y;
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

/* ini abaikan aja nanti shafa hapus
setup: init, currPlayerInfo->WHITE,0,0
main: maingame, endturn: Turn->currPlayerInfo

W B
B W'
W' B'

mekanisme undo:
sekarang kita di W' B'
hasil pop-> Q(W B)
Del Queue -> X yang isinya W -> currPlayerInfo dan Q(B)
yang harus di update setelah undo (pada konteks ini): currPlayerInfo dan Q yang sudah di Del
mekanisme undo: Queue yang udah disimpen di Stack bakalan di Del,
infotype Xnya bakal jadi info siapa yang main pada giliran turn itu*/