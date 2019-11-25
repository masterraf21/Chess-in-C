#ifndef SAVE__LOAD__H 
#define SAVE__LOAD__H 

// #include "chess.h
#include "chess.h"
#include "../adt/listbidak.h"
#include "../adt/queuegiliran.h"
#include "../adt/mesin_kata.h"

char AmbilWarna(COLOR c);

COLOR getcolor (char c);

void ReadFile(List_Bidak *W, List_Bidak *B,Queue_Giliran *Q);
	
void SaveFile(List_Bidak W, List_Bidak B, Queue_Giliran Q);
			 	

#endif



 