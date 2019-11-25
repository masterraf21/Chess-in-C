#include <stdlib.h>
#include <stdio.h>
#include "queuegiliran.h"

void AlokasiTurn (address_turn *P, infotypeturn X)
{
	*P = (address_turn) malloc(sizeof(ElmtQueueTurn));

	if(*P!=Nil){
		InfoT(*P) = X;
		NextT(*P) = Nil;
	}
}
void DealokasiTurn (address_turn  P)
{
	free(P);
}
boolean IsEmptyTurn (Queue_Giliran Q)
{
	return ((HeadT(Q)==Nil)&&(TailT(Q)==Nil));
}
int NbElmtTurn(Queue_Giliran Q)
{
	int count = 0;
	address_turn P = HeadT(Q);

	while(P!=Nil){
		P = NextT(P);
		count++;
	}
	
	return count;
}

void CreateEmptyTurn(Queue_Giliran * Q)
{
	HeadT(*Q) = Nil;
	TailT(*Q) = Nil;
}
void AddTurn (Queue_Giliran * Q, infotypeturn X)
{
	address_turn P;
	AlokasiTurn(&P, X);

	if (P!=Nil){
		if (IsEmptyTurn(*Q)){
			HeadT(*Q) = P;
			TailT(*Q) = P;
		}else{
			//next the current tail with P
			NextT(TailT(*Q)) = P;
			//now that the current tail is p assign with p
			TailT(*Q) = P;
		}
	}
}
void DelTurn(Queue_Giliran * Q, infotypeturn * X)
{
	address_turn P = HeadT(*Q);

	if(NextT(HeadT(*Q))==Nil)
		//only one element, then create empty
		CreateEmptyTurn(Q);
	else
		//get the next one
		HeadT(*Q) = NextT(HeadT(*Q));

	//get the info then deallocate
	*X = InfoT(P);
	DealokasiTurn(P);
}