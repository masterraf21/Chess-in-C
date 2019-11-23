#ifndef LEADERBOARD_H 
#define LEADERBOARD_H

// #include "chess.h"
#include "../adt/mesin_kata.h"
#include "chess.h"

int StrToInt(Kata kat); 

void ReadLeaderBoard(LeaderBoard *B);
	
void PrintLeaderboard(LeaderBoard B);
			 	
void SwapScore(Score *a, Score *b);

void CopyNama(char *a, char *b);

void SaveLeaderBoard(LeaderBoard B);

void AddScore(LeaderBoard *B,Score S);
#endif



 