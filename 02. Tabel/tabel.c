#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
#include "boolean.h"

/* Deskripsi : realisasi body modul Tabel */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 5 September 2022*/

/* Soal 1 */
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    (*T).size = 0;
    for(i=1; i<=10; i++) {
        (*T).wadah[i] = -999;
    }
} 

/* Soal 2 */
/* procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    printf("[");
    for(i=1; i<=10; i++) {
        printf(" %d ", T.wadah[i]);
    }
    printf("]");
}

/* Soal 3 */
/* procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang 'terisi' ke layar} */
void viewTable (Tabel T) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    printf("[");
    if (T.size > 0) { 
        for(i=1; i<=T.size; i++) {
            printf(" %d ", T.wadah[i]);
        }
    } else {
        printf("waduh tabel kosong");
    }
    printf("]");
}

/* Soal 4 */
/* function getSize ( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T} */
int getSize (Tabel T) {
    /*kamus lokal*/
    
    /*algoritma*/
    return T.size;
}

/* Soal 5 */
/* function countEmpty ( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi} */
int countEmpty (Tabel T) {
    /*kamus lokal*/
    
    /*algoritma*/
    return 10 - T.size;
}

/* Soal 6 */
/* function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong} */
boolean isEmptyTable (Tabel T) {
    /*kamus lokal*/
    
    /*algoritma*/
    if (T.size == 0) {
        return true;
    } else {
        return false;
    }
}

/* Soal 7 */
/* function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh} */
boolean isFullTable (Tabel T) {
    /*kamus lokal*/
    
    /*algoritma*/
    if (T.size == 10) {
        return true;
    } else {
        return false;
    }
}

/* Soal 8 */
/* procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0} */
void populate1 (Tabel *T, int N) {
    /*kamus lokal*/
    int i;
    int x;
    
    /*algoritma*/   
    (*T).size = N;
    if(N>0 && N<=10) {
    for(i=1; i<=N; i++) {
        printf("Elemen ke-%d = ",i);
        scanf("%d",&x);
        if(x>0) {
            (*T).wadah[i] = x;
        }
        else {
            i--;
        }
    }
    } 
}

/* Soal 9 */
/* procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah} */
void searchX1 (Tabel T, int X, int *Pos) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    i=1;
    (*Pos)=-999;
    if(T.size != 0) {
        while(T.wadah[i]!=X && i<T.size) {
            i++;
        }
        if(T.wadah[i]==X) {
            (*Pos) = i;
        }
    }
    printf("Ohh, ternyata ada di posisi %d :)\n", *Pos);
}

/* Soal 10 */
/* procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah} */
void countX (Tabel T, int X, int *Byk) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    (*Byk)=0;
    if(T.size != 0) {
        for(i=1; i<=T.size; i++) {
            if(T.wadah[i]==X) {
            (*Byk)++;
            }
        }
    }
    printf("Elemen 3 ada sebanyak %d.\n", *Byk);
}

/* Soal 11 */
/* function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T} */
int SumEl (Tabel T) {
    /*kamus lokal*/
    int i;
    int sum;
    
    /*algoritma*/
    sum = 0;
    for(i=1; i<=T.size; i++) {
        sum += T.wadah[i];
    }
    return sum;
}

/* Soal 12 */
/* function AverageEl ( T:Tabel ) -> integer 
	{mengembalikan nilai rata-rata elemen pengisi T} */
int AverageEl (Tabel T) { 
    /*kamus lokal*/
    int i;
    float sum;
    
    /*algoritma*/
    for(i=1; i<=T.size; i++) {
        sum += T.wadah[i];
    }
    return sum / T.size; 
}

// Maaf pak ini fungsinya saya tambahkan sendiri 
// untuk melihat nilai asli di belakang koma averagenya
float AverageE2 (Tabel T) { 
    /*kamus lokal*/
    int i;
    float sum;
    
    /*algoritma*/
    for(i=1; i<=T.size; i++) {
        sum += T.wadah[i];
    }
    return sum / T.size; 
}

/* Soal 13 */
/* function getMaxEl ( T: Tabel ) -> integer
	{mengembalikan nilai elemen terbesar} */
int getMaxEl (Tabel T) {
    /*kamus lokal*/
    int i;
    int max;
    
    /*algoritma*/
    i=1;
    if(T.size>0) {
        max = T.wadah[i];
        for(i=1; i<=T.size; i++) {
            if(T.wadah[i]>max) {
                max = T.wadah[i];
            }
        }
        return max;
    }
}

/* Soal 14 */
/* function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil} */
int getMinEl (Tabel T) {
    /*kamus lokal*/
    int i;
    int min;
    
    /*algoritma*/
    i=1;
    if(T.size>0) {
        min = T.wadah[i];
        for(i=1; i<=T.size; i++) {
            if(T.wadah[i] < min) {
                min = T.wadah[i];
            }
        }
        return min;
    }
}

/* Soal 15 */
/* procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0} */
void populate2 (Tabel *T) { 
    /*kamus lokal*/
    int i;
    int x;
    
    /*algoritma*/
    i=0;
    scanf("%d", &x);
    while(x>0 && i<10) {
        i++;
        (*T).wadah[i] = x;
        scanf("%d",&x);
    }
    (*T).size = i;
}

/* Soal 16 */
/* procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X} */
void addXTable (Tabel *T, int X) {
    /*kamus lokal*/
    
    /*algoritma*/
    if((*T).size != 10) {
        (*T).size += 1;
        (*T).wadah[(*T).size] = X;
    } else {
        printf("I'm so sorry, wadahnya udah penuh..\n");
    }
}

/* Soal 17 */
/* procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa} */
void delXTable (Tabel *T, int X) {
    /*kamus lokal*/
    int i;
    int j;
    
    /*algoritma*/
    i=1;
    if((*T).size != 0) {
        while(i<(*T).size && (*T).wadah[i]!=X) {
            i++;
        }
        if(i<(*T).size) {
            for(j=i;j<(*T).size;j++) {
                (*T).wadah[j]=(*T).wadah[j+1];
            }
            (*T).wadah[10]=0;
        }
        (*T).size--;
    }
}

/* Soal 18 */
/* procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa} */
void delAllXTable (Tabel *T, int X) {
    /*kamus lokal*/
    int i;
    int j;
    
    /*algoritma*/
    if((*T).size != 0) {
        for(i=1; i<=(*T).size; i++) {
            if((*T).wadah[i]==X) {
                for(j=i; j<=(*T).size; j++) {
                    (*T).wadah[j] = (*T).wadah[j+1];
                }
                i--;
                (*T).wadah[10]  = -999;
                (*T).size--;
            }
        }
    }
}

/* Soal 19 */
/* function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/* asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama */
int Modus (Tabel T) {
    /*kamus lokal*/
    int i;
    int j;
    
    /*algoritma*/
    for(i=1; i<=T.size-1; i++) {
        for(j=i+1; j<=T.size; j++) {
            if(T.wadah[i] == T.wadah[j]) {
                return T.wadah[i];
            }
        }
    }
}

#endif