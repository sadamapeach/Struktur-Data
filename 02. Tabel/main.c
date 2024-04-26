#include <stdio.h>
#include "tabel.h"

int main ()
{
  /*kamus */
  Tabel P;
  int Pos;
  int Byk;
  int ave1;
  float ave2;

  /*algoritma */
  printf ("========== OPERASI TABEL ==========\n");

  /*Try and Error */
  printf("\nTry and Error\n");
  P.size = 0;
  printf ("Size = %d\n", P.size);

  /*Soal 1 */
  printf("\nCreate Table\n");
  createTable (&P);
  printf ("Size = %d\n", P.size);

  /*Soal 2 */
  printf("\nPrint Table\n");
  printTable (P);

  /*Soal 3 */
  P.wadah[1] = 17;
  P.wadah[2] = 10;
  P.wadah[3] = 02;
  P.size = 3;
  printf ("\n\nView Table\n");
  viewTable (P);

  /*Soal 4 */
  printf("\n\nGet Size\n");
  printf ("Size = %d\n", getSize(P));

  /*Soal 5 */
  printf ("\nJumlah tabel kosong = %d\n", countEmpty(P));

  printf("\nBoolean! 0 means false and 1 means true :)\n");
  /*Soal 6 */
  printf ("Apakah tabel kosong? %d\n", isEmptyTable(P));

  /*Soal 7 */
  printf ("Apakah tabel penuh? %d\n", isFullTable(P));

  /*Soal 8 */
  printf("\nPopulate 1: Mengisi elemen sebanyak N kali\n");
  printf("Masukkan 5 elemen!\n");
  populate1 (&P, 5);
  printf ("View Table\n");
  viewTable (P);

  /*Soal 9 */
  printf("\n\nSearch\n");
  printf("Mencari posisi elemen yang bernilai 3 nih..\n");
  searchX1 (P, 3, &Pos);

  /*Soal 10 */
  printf("\nCount\n");
  printf("Kira-kira elemen bernilai 3 ada berapa ya di tabel??\n");
  countX (P, 3, &Byk);

  /*Soal 11 */
  printf("\nSum\n");
  printf("Berapa ya jumlah elemen tabel kalo ditambahkan??\n");
  printf("Wow, jumlahnya ada %d!\n", SumEl(P));

  /*Soal 12 */
  printf("\nAverage\n");
  
  ave1 = AverageEl(P);
  printf("- Karena tipe datanya int maka jadi bilangan bulat..\n");
  printf("  Rata-rata bulatnya jadi %d\n", ave1);
  
  ave2 = AverageE2(P);
  printf("- Ini versi aslinya ^^\n");
  printf("  Rata-rata aslinya, yaitu %.2f\n", ave2);
  
  /*Soal 13 */
  printf("\nMax\n");
  printf("Elemen terbesar tabel ini adalah %d!\n", getMaxEl(P));
  
  /*Soal 14 */
  printf("\nMin\n");
  printf("%d adalah elemen terkecil dalam tabel..\n", getMinEl(P));
  
  /*Soal 15 */
  printf("\nPopulate 2: Mengisi elemen secara berulang, input 0 berhenti!\n");
  printf("Masukkan Nilai..\n");
  populate2(&P);
  printf("View Tabel\n");
  viewTable(P);

  /*Soal 16 */
  printf("\n\nAdd Table\n");
  printf("Kalo wadah tabel masih ada yang kosong then diisi 18.\n");
  addXTable (&P, 18);
  printf("View Tabel\n");
  viewTable(P);
  
  /*Soal 17 */
  printf("\n\nDelete X\n");
  printf("Menghapus elemen 3 'pertama' dalam tabel.\n");
  delXTable (&P, 3);
  printf("View Tabel\n");
  viewTable (P);
  
  /*Soal 18 */
  printf("\n\nDelete All X\n");
  printf("Menghapus semua elemen 3 dalam tabel.\n");
  delAllXTable (&P, 3);
  printf("View Tabel\n");
  viewTable (P);
  
  /*Soal 19*/
  printf("\n\nModus\n");
  printf("Elemen %d paling sering muncul dalam tabel!", Modus (P));

  return 0;
}
