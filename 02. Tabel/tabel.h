#ifndef tabel_H
#define tabel_H 

/* Program   : tabel.h */
/* Deskripsi : header file modul Tabel */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah */
/* Tanggal   : 5 September 2022 */
/***********************************/

#include <stdio.h>
#include "boolean.h"

/* type Tabel = < wadah : array[1..10] of integer,
                   size : integer > */
/* asumsi: indeks 0 tidak digunakan */
typedef	struct { int wadah[11];
                 int size; } Tabel;
/* Soal 1 */                 
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T); 

/* Soal 2 */
/* procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T);

/* Soal 3 */
/* procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T);

/* Soal 4 */                 
/*function getSize ( T: Tabel ) -> integer
	{mengembalikan banyak elemen pengisi T} */
int getSize (Tabel T);

/* Soal 5 */
/* function countEmpty ( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi} */
int countEmpty (Tabel T);

/* Soal 6 */
/* function isEmptyTable ( T: Tabel ) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T);

/* Soal 7 */
/* function isFullTable ( T: Tabel ) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T);

/* Soal 8 */
/* procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 } */
void populate1 (Tabel *T, int N);

/* Soal 9 */
/* procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah} */
void searchX1 (Tabel T, int X, int *Pos);

/* Soal 10 */
/* procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah} */
void countX (Tabel T, int X, int *Byk);

/* Soal 11 */
/* function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T} */
int SumEl (Tabel T);

/* Soal 12 */
/* function AverageEl ( T:Tabel ) -> integer 
	{mengembalikan nilai rata-rata elemen pengisi T} */
int AverageEl (Tabel T);
float AverageE2 (Tabel T);

/* Soal 13 */
/* function getMaxEl ( T: Tabel ) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T);

/* Soal 14 */
/* function getMinEl ( T: Tabel ) -> integer
	{mengembalikan nilai elemen terkecil} */
int getMinEl (Tabel T);

/* Soal 15 */
/* procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0} */
void populate2 (Tabel *T);

/* Soal 16 */
/* procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X} */
void addXTable (Tabel *T, int X);

/* Soal 17 */
/* procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa} */
void delXTable (Tabel *T, int X);

/* Soal 18 */
/* procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa} */
void delAllXTable (Tabel *T, int X);

/* Soal 19 */
/* function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/* asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama */
int Modus (Tabel T);
                 
#endif