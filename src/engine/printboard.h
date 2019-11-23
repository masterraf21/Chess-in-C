#ifndef PRINTBOARD_H
#define PRINTBOARD_H

#include "chess.h"
#include "bidak.h"

void IsiTile(int nobaris, int nokolom, char bidak);
//bakal berhubungan sama array posisi bidak

void AtasTile();
//framing atas

void BawahTile();
//framing bawah

void PrintBoard();
//main board


#endif