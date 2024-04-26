/* Program   : main.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 19 September 2022*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tstack.h"
#include "boolean.h"

int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	int p;
	int i;
	char c;
	char X;
	char b;
	char kata[100] = "IBU RATNA ANTAR UBI";
	
	/* algoritma */
	printf("================== S T A C K ==================\n");
	printf("\n");
	
	createStack (&A);
	
	printf("Print Stack\t= ");
	printStack (A);
	printf("\n");
	
	printf("View Stack\t= ");
	viewStack (A);
	printf("\n");
	
	printf("\nBoolean\n");
	printf("1 = true | 0 = false\n");
	printf("Apakah stack kosong? %d\n", isEmptyStack (A));
	printf("Apakah stack penuh? %d\n", isFullStack (A));
	
	push(&A, 't');
	push(&A, 'a');
	push(&A, 't');
	push(&A, 'a');
	printf("\nPush\n");
	printStack(A);
	printf("\n");
	viewStack(A);
	printf("\nPosisi puncak stack A, yaitu %d.", top(A));
	printf("\nIsi elemen puncak stack A, yaitu %c.\n", infotop(A));
	
	printf("\nPop\n");
	pop(&A, &c);
	printStack(A);
	printf("\n");
	viewStack(A);
	printf("\nPosisi puncak stack A, yaitu %d.", top(A));
	printf("\nIsi elemen puncak stack A, yaitu %c.\n", infotop(A));
	
	printf("\nP A L I N D R O M\n");
	printf("Apakah kata IBU RATNA ANTAR UBI palindrom? ");
	p = (strlen(kata));
	createStack(&A);
	
	for (i=0; i<(p/2); i++) {
	    push(&A, kata[i]);
	}
	
	if((p%2) == 1) {
	    i = i+1;
	} do {
	    i = i+1;
	    pop(&A, &c);
	} 
	
	while ((c == kata[i-1]) && (i<p));
	if(c == kata[i-1]) {
	    printf("true\n");
	} else {
	    printf("false\n");
	}
	
	printf("\nPush N\n");
	pushN (&A, 9);
	printf("Hasil\n");
	printStack(A);
	printf("\n");
	viewStack(A);
	
    printf("\n\nPush Babel\n");
 	pushBabel1 (&A, '!');
	printStack(A);
	printf("\n");
	viewStack(A);

	return 0;
}