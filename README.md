## Tugas Besar IF2111 Alstrukdat
Repo isinya tubes catur buat IF2111
Direktori dibagi jadi 2 di src ada engine sama adt. Adt isinya adt yang dibuat di kelas, kalau engine code yang mau kita buat di engine chessnya. Cara include file ADT di engine:
``` c
#include "../adt/<fileadt.h>"
```

### List Gawean yang udah mulai dikerjain
* Board di file `board.h`
* Bidak di file `bidak.h`


### Basic Mechanism for Move-Generation
1. Jadi kita punya board yang direpresentasikan sebagai array[120] of elemen.
2. Nah setiap array ini isinya integer yang merepresentasikan objek yang sebenarnya yang ada di setiap *tile* catur.
3. Kita juga punya linked-list yang isinya adalah setiap bidak yang ada di papan catur *which is* jumlahnya adalah 16 node yang artinya total ada 2 list.
4. State awalnya adalah setiap giliran tuh memiliki kondisi yang spesifik di arraynya untuk *representing* kondisi aktual tentang posisi, nah linked list tuh merepresentasikan setiap bidak yang isinya ada jenis bidak dan posisi:
   ```c
    typedef struct{
    PAWN_TYPE tipe;
    BOARD_SQUARES posisi;
    }BIDAK;
   ```
    Nah isi dari linked-list ini kita akan pakai untuk meng-generate possible move dari setiap bidak (node linked-list)
5. Ide umum generate move:
   1. Kita generate semua move dari setiap bidak spesifik sesuai aturan catur kita panggil aja **Illegal-move** dengan cara mengiterasi setiap node nanti akan dihasilkan sekumpulan opsi, termasuk makan memakan juga.
   2. Setelah itu akan difiliter move itu dengan melihat kondisi aktual yang ada di array, seperti apakah *tile* yang akan dituju legal atau engga (ga masuk *bad_square*) apakah di tile yang dituju ada isinya atau engga, apakah mungkin juga di *tile* yang dituju ada yang bisa dimakan atau engga. Intinya kita akan saring dari illegal-move buat nyampe pada *tile* yang isinya '0' atau lawan. Kita sebut saja setelah disaring namanya **Legal-move**

6. Nah algoritma umum untuk move-generation:
   1. Iterasi awal **(pre_move)** setiap node di linked-list 
   2. Generate **Illegal move** dari setiap node, dengan ketentuan:
      1. Posisi yang mungkin untuk berpindah
      2. atau posisi yang mungkin untuk makan (terutama buat pion karena makan sama geraknya beda)
   3. Filter **Illegal move** dengan ketentuan:
      1. Eliminasi Kalau *tile* tujuan *bad_square* 
      2. Eliminasi kalau *tile* tujuan isinya kawan
      3. Eliminasi kalau *tile* tujuan terpotong (kecuali kuda) oleh apapun
   4. Didapatlah **Legal move** dengan ketentuan:
      1. Aksi berpindah
      2. Aksi makan (spesifik sesuai ketentuan tiap bidak)
   5. User *prompt* input
   6. Eksekusi aksi dengan ketentuan:
      1. Posisi yang digerakan berubah (kondisi array berubah)
      2. Kalau makan lawan, artinya ada kondisi satu elemen array yang *ditimpa* jadi nanti akan dicheck setelah ini 
      3. Setelah aksi dilakukan kita push ke stack untuk ngisi mengenai info move baru aja dilakukan dengan isi stack
      ```c
      typedef struct{
          BOARD_SQUARE prev_position;
          BOARD_SQUARE now_position;
          boolean is_makan;
      }ELEMEN_STACK;
      ```
   7. Iterasi akhir **post_move**, dengan ketentuan:
      1. Check di setiap posisi bidak (BIDAK.POSISI yang belum dialter) yang ada di linked-list apakah sesuai dengan kondisi yang ada di elemen array atau engga
      2. Kalau ga sesuai, ada dua kemungkinan: *kosong* atau *ditimpa* oleh lawannya
      3. Nanti info yang masuk ke stack, dipake buat nge-update node bidak yang di linked-list
   8. Kalau dia dimakan, node yang berkesesuaian di dealokasi dan score pemain lawan ditambah



### List Gawean
* Board di file `board.h` :
* Bidak di file `bidak.h`
* Cara bergerak bidak di board
* Linked list buat info bidak
* Stack buat undo 
* Queue isinya apa



