#include <stdlib.h>
#include <stdio.h>
#include "queuegiliran.h"

void AlokasiTurn (address *P, infotypeturn X)
{
	*P = (address) malloc(sizeof(ElmtQueueTurn));

	if(*P!=Nil){
		InfoT(*P) = X;
		NextT(*P) = Nil;
	}
}
void DealokasiTurn (address  P)
{
	free(P);
}
boolean IsEmptyTurn (Queue Q)
{
	return ((HeadT(Q)==Nil)&&(TailT(Q)==Nil));
}
int NbElmtTurn(Queue Q)
{
	int count = 0;
	address P = HeadT(Q);

	while(P!=Nil){
		P = NextT(P);
		count++;
	}
	
	return count;
}

void CreateEmptyTurn(Queue * Q)
{
	HeadT(*Q) = Nil;
	TailT(*Q) = Nil;
}
void AddTurn (Queue * Q, infotypeturn X)
{
	address P;
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
void DelTurn(Queue * Q, infotypeturn * X)
{
	address P = HeadT(*Q);

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