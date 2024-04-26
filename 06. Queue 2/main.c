/* Program   : main.c */
/* Deskripsi : file DRIVER modul queue1 */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 3 Oktober 2022*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"

int main() 
{	/* kamus main */
    tqueue2(A);
    tqueue2(B);
    // tqueue(B);
    char E;

	/* algoritma */
	printf("================== Q U E U E 2 ==================\n");
	printf("\n");
	
	createQueue2(&A);
	
	printf("Print Queue2 = ");
	printQueue2(A);
	printf("\n");
	
	printf("View Queue2  = ");
	viewQueue2(A);
	printf("\n");
	
	enqueue2(&A, 's');
	enqueue2(&A, 'u');
	enqueue2(&A, 'n');
	printf("\nEnqueue2\n");
    viewQueue2(A);
	printf("\nPosisi head = %d", head2(A));
	printf("\nPosisi tail = %d", tail2(A));
	printf("\nInfo head   = %c", infoHead2(A));
	printf("\nInfo tail   = %c", infoTail2(A));
    printf("\nPanjang antrean, yaitu %d.\n", sizeQueue2(A));

    printf("\nBoolean\n");
	printf("1 = true | 0 = false\n");
	printf("Apakah queue kosong? %d\n", isEmptyQueue2(A));
	printf("Apakah queue penuh? %d\n", isFullQueue2(A));
    printf("Apakah queue hanya memiliki 1 elemen? %d\n", isOneElement2(A));
    
    createQueue2(&B);
    enqueue2(&B, 'g');
	enqueue2(&B, 'r');
	enqueue2(&B, 'e');
	enqueue2(&B, 'a');
	enqueue2(&B, 't');
	printf("\nEnqueue2\t= ");
    viewQueue2(B);

    dequeue2(&B, &E);
    dequeue2(&B, &E);
    printf("\nDequeue2\t= ");
	printQueue2(B);
	
    printf("\nReset Head\t= ");
	resetHead(&B);
	printQueue2(B);
	printf("\n");
	
	printf("\nNew Enqueue\n");
    enqueue2N(&B, 2);
    printQueue2(B);

	return 0;
}