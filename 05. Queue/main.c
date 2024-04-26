/* Program   : main.c */
/* Deskripsi : file DRIVER modul queue1 */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 26 September 2022*/
/***********************************/

#include <stdio.h>
#include "tqueue1.h"
#include "boolean.h"

int main() 
{	/* kamus main */
    tqueue(A);
    tqueue(B);
    char E;

	/* algoritma */
	printf("================== Q U E U E 1 ==================\n");
	printf("\n");
	
	createQueue(&A);
	
	printf("Print Queue = ");
	printQueue(A);
	printf("\n");
	
	printf("View Queue  = ");
	viewQueue(A);
	printf("\n");
	
	enqueue(&A, 'j');
	enqueue(&A, 'i');
	enqueue(&A, 's');
	enqueue(&A, 'o');
	enqueue(&A, 'o');
	printf("\nEnqueue\n");
	printQueue(A);
	printf("\nPosisi head = %d", Head(A));
	printf("\nPosisi tail = %d", Tail(A));
	printf("\nInfo head   = %c", infoHead(A));
	printf("\nInfo tail   = %c", infoTail(A));
    printf("\nPanjang antrean, yaitu %d.\n", sizeQueue(A));

    printf("\nBoolean\n");
	printf("1 = true | 0 = false\n");
	printf("Apakah queue kosong? %d\n", isEmptyQueue(A));
	printf("Apakah queue penuh? %d\n", isFullQueue(A));
    printf("Apakah queue hanya memiliki 1 elemen? %d\n", isOneElement(A));
    
    dequeue(&A, &E);
    printf("\nDequeue\n");
	printf("Dequeue 1\t= ");
	printQueue(A);
	printf("\n");
	
	dequeue(&A, &E);
	printf("Dequeue 2\t= ");
	printQueue(A);
	printf("\n");

	printf("View Dequeue\t= ");
	viewQueue(A);
	printf("\n");
	
	
	printf("\nLonger..\n");
	createQueue(&B);
	enqueue(&B, 'r');
	enqueue(&B, 'o');
	enqueue(&B, 's');
	enqueue(&B, 'e');
	
	printf("Queue 1 = ");
	viewQueue(A);
	printf("\n");
	printf("Queue 2 = ");
	viewQueue(B);
	printf("\n");
	
	printf("Ukuran Q1 = %d dan ukuran Q2 = %d.\n", sizeQueue(A), sizeQueue(B));
	printf("Ukuran terpanjang queue, yaitu %d.\n", longer(A,B));
	
	printf("\nEnqueue Queue Terpendek\n");
	enqueueShort(&A, &B, 'm');
	printf("Queue 1 = ");
	printQueue(A);
	printf("\n");
	printf("Queue 2 = ");
	printQueue(B);
	printf("\n");
	
	printf("\nDequeue Queue Terpanjang\n");
    dequeueLong(&A, &B, &E);
	printf("Queue 1 = ");
	printQueue(A);
	printf("\n");
	printf("Queue 2 = ");
	printQueue(B);
	printf("\n");

	return 0;
}