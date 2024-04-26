/* Program   : matriks.c */
/* Deskripsi : realisasi body file modul ADT Matriks */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 12 September 2022*/
/***********************************/
#include <stdio.h>
#include "matriks.h"
#include "boolean.h"
#ifndef MATRIKS_C

/*Soal 1*/
/*KONSTRUKTOR*/
/* procedure makeMatriks(output M:Matriks)*/
/* {I.S: -} */
/* {F.S: M terdefinisi, M.nbbar=0, M.nbkol=0 } */
/* {Proses: menginisialisasi semua cell matriks M dengan -999 } */
void makeMatriks(Matriks *M) {
    /*kamus lokal*/
    int i;
    int j;
    
    /*logaritma*/
    (*M).nbbar = 0;
    (*M).nbkol = 0;
    for(i=1; i<=10; i++) {
        for(j=1; j<=10; j++) {
            (*M).wadah[i][j] = -999;
        }
    }
}

/*Soal 2*/
/**********SELEKTOR*/
/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbbar(Matriks M) {
    /*kamus lokal*/
    /*algoritma*/
    return M.nbbar;
}

/*Soal 3*/
/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak kolom matriks M}*/
int getNbkol(Matriks M) {
    /*kamus lokal*/
    /*algoritma*/
    return M.nbkol;
}

/*Soal 4*/
/*function getInfoCell(M:Matriks,X:integer,Y:integer)->integer*/
/*{mengembalikan nilai/isi elemen baris X, kolom Y, matriks M}*/
int getInfoCell(Matriks M, int X, int Y) {
    /*kamus lokal*/
    /*algoritma*/
    return M.wadah[X][Y];
}

/*Soal 5*/
/*********MUTATOR*/
/*procedure setNbbar(input/output M:Matriks, input X:integer)*/
/*{I.S.: M,X terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak baris efektif dengan X}*/
void setNbbar(Matriks *M, int X) {
    /*kamus lokal*/
    /*algoritma*/
    (*M).nbbar = X;
}

/*Soal 6*/
/*procedure setNbkol(input/output M:Matriks, input Y:integer)*/
/*{I.S.: M,Y terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak kolom efektif dengan Y}*/
void setNbkol(Matriks *M, int Y) {
    /*kamus lokal*/
    /*algoritma*/
    (*M).nbkol = Y;    
}

/*Soal 7*/
/*procedure setInfoCell(input/output M:Matriks, 
  input X:integer, input Y:integer, input C:integer)*/
/*{I.S.: M,X,Y,C terdefinisi, C=nilai/info pengganti}*/
/*{F.S.: cell (X,Y) berisi C }*/
/*{proses: mengisi cell pada baris X, kolom Y dengan C }*/
void setInfoCell(Matriks *M, int X, int Y, int C) {
    /*kamus lokal*/
    /*algoritma*/
    (*M).wadah[X][Y] = C;    
}

/* Soal 8 */
/*********PREDIKAT*/
/*function isEmptyMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M kosong}*/
boolean isEmptyMatriks(Matriks M) {
    /*kamus lokal*/
    /*algoritma*/
    if(M.nbbar == 0 || M.nbkol == 0) {
        return true;
    } else {
        return false;
    }
}

/* Soal 9 */
/*function isFullMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M penuh}*/
boolean isFullMatriks(Matriks M) {
    /*kamus lokal*/
    /*algoritma*/
    if(M.nbbar == 10 && M.nbkol == 10) {
        return true;
    } else {
        return false;
    }
}

/* Saol 10 */
/*********SUBRUTIN LAIN*/
/*procedure printMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks ke layar, termasuk sel kosong}*/
void printMatriks(Matriks M) {
    /*kamus lokal*/
    int i;
    int j;
    
    /*algoritma*/
    for(i=1; i<=M.nbbar; i++) {
        for(j=1; j<=M.nbkol; j++) {
            printf("%d  ", (M).wadah[i][j]);
        } printf("\n");
    }
}

/* Soal 11 */
/*procedure viewMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks yang tidak kosong ke layar}*/
void viewMatriks(Matriks M) {
    /*kamus lokal*/
    int i;
    int j;
    
    /*algoritma*/
    if(!isEmptyMatriks(M)) {
        for(i=1; i<=M.nbbar; i++) {
            for(j=1; j<=M.nbkol; j++) {
                if(M.wadah[i][j] != -999) {
                    printf("%d  ", M.wadah[i][j]);
                }
            } printf("\n");
        } 
    } else {
        printf("Moon maap matriks kosong..\n");
    }
}

/* Soal 12 */
/*function sumCellMatriks(M:Matriks)->integer*/
/*{mengembalikan jumlah nilai elemen matriks M}*/
int sumCellMatriks(Matriks M) {
    /*kamus lokal*/
    int i;
    int j;
    int sum;
    
    /*algoritma*/
    sum = 0;
    if(!isEmptyMatriks(M)) {
        for(i=1; i<=M.nbbar; i++) {
            for(j=1; j<=M.nbkol; j++) {
                if(M.wadah[i][j] != -999 && M.wadah[i][j] != 0) {
                    sum += M.wadah[i][j];
                }
            }
        }
    } return sum;
}

/* Soal 13 */
/*function avgCellMatriks(M:Matriks)->real*/
/*{mengembalikan rataan nilai elemen matriks M}*/
float avgCellMatriks(Matriks M) {
    /*kamus lokal*/
    int i;
    int j;
    float sum;
    float byk;
    
    /*algoritma*/
    sum = 0;
    byk = 0;
    if(!isEmptyMatriks(M)) {
        for(i=1; i<=M.nbbar; i++) {
            for(j=1; j<=M.nbkol; j++) {
                if(M.wadah[i][j] != -999 && M.wadah[i][j] != 0) {
                    sum += M.wadah[i][j];
                    byk++;
                }
            }
        } return sum/byk;
    }
}

/* Saol 14 */
/*function maxCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terbesar elemen matriks M}*/
int maxCellMatriks(Matriks M) {
    /*kamus lokal*/
    int i;
    int j;
    int max;
    
    /*algoritma*/
    max = M.wadah[1][1];
    if(!isEmptyMatriks(M)) {
        for(i=1; i<=M.nbbar; i++) {
            for(j=1; j<=M.nbkol; j++) {
                if(M.wadah[i][j] > max) {
                    max = M.wadah[i][j];
                }
            }
        }
    } return max;
}

/* Soal 15 */
/*function minCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terkecil elemen matriks M}*/
int minCellMatriks(Matriks M) {
    /*kamus lokal*/
    int i;
    int j;
    int min;
    
    /*algoritma*/
    min = M.wadah[1][1];
    if(!isEmptyMatriks(M)) {
        for(i=1; i<=M.nbbar; i++) {
            for(j=1; j<=M.nbkol; j++) {
                if(M.wadah[i][j] < min && M.wadah[i][j] != -999) {
                    min = M.wadah[i][j];
                }
            }
        }
    } return min;
}

/* Saol 16 */
/*function countA(M:Matriks,A:integer)->integer*/
/*{mengembalikan banyak elemen bernilai A dalam matriks M}*/
int countA(Matriks M, int A) {
    /*kamus lokal*/
    int i;
    int j;
    int hitungA;
    
    /*algoritma*/
    hitungA = 0;
    if(!isEmptyMatriks(M)) {
        for(i=1; i<=M.nbbar; i++) {
            for(j=1; j<=M.nbkol; j++) {
                if(M.wadah[i][j] == A) {
                    hitungA++;
                }
            }
        }
    } return hitungA;
}

/* Soal 17 */
/*procedure searchMatriks(input M:Matriks, input A:integer, 
output X:integer, output Y:integer)*/
/*{I.S.: M,A terdefinisi, A=nilai/info cell yang dicari}*/
/*{F.S.: X=indeks baris, Y=indeks kolom, tempat ditemukannya A}*/
/*{proses: mencari nilai A dalam cell matriks M}*/
/*{bila tidak ketemu, X=Y=-999}*/
void searchMatriks(Matriks M, int A, int *X, int *Y) {
    /*kamus lokal*/
    int i;
    int j;

    /*algoritma*/
    (*X) = -999;
    (*Y) = -999;
    if(!isEmptyMatriks(M)){
        for(i=1; i<=M.nbbar; i++) {
            for(j=1; j<=M.nbkol; j++) {
                if(M.wadah[i][j] == A) {
                    (*X) = i;
                    (*Y) = j;
                }
            }
        }
    } printf("Nilai %d ada di baris ke-%d kolom ke-%d.\n", A, (*X), (*Y));
}

/* Soal 18 */
/*procedure transpose(input/output M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{proses: mengubah susunan cell matriks, 
baris menjadi kolom dan sebaliknya}*/
/*{misal: M=[1,2] menjadi [1,4]
____________[4,5]         [2,5] }*/
void transpose(Matriks *M) {
    /*kamus lokal*/
    int i;
    int j;
    int buffer;
    
    /*algoritma*/
    if(!isEmptyMatriks(*M)) {
        for(i=1; i<=(*M).nbbar; i++) {
            for(j=i; j<=(*M).nbkol; j++) {
                buffer = (*M).wadah[i][j];
                (*M).wadah[i][j] = (*M).wadah[j][i];
                (*M).wadah[j][i] = buffer;
            }
        }
    }
    buffer = (*M).nbbar;
    (*M).nbbar = (*M).nbkol;
    (*M).nbkol = buffer;
}

#endif



