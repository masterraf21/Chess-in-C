
#include "mesin_kata.h"
#include "mesin_kar.h"
#include <stdio.h>
#include <stdlib.h>

/* State Mesin Kata */
boolean EndKata;
Kata CKata;
//{ ***** Primitif-Primitif Mesin Kata ***** }
void STARTKATA(char* filename){
    START(filename);
    if (CC == MARK) {
		EndKata=true;
	} else {
		EndKata=false;
		SalinKata();
	}
}

void ADVKATA() {
	Ignore_Separator();
	if (IsEOP()) {
		EndKata=true;
	} else {
		SalinKata();
	}
}
void SalinKata() {
    int i=0;
	/*	Algoritma */
	while (( CC != MARK) && (CC != TERM) && (CC != NEXT)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
	} 
	CKata.Length=i;
}

void Ignore_Separator() {
while (((CC == NEXT) || (CC == TERM)) && (CC != MARK)) {
    ADV();
    } 
} 

void TulisKata(Kata kat){
	for (int i = 0; i< kat.Length;i++){
		printf("%c",kat.TabKata[i]);
	}
	printf("\n");
}