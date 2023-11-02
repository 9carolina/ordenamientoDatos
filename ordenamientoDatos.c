#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int findMin(int b[], int l){
	int a, index, i;
	a=1000000;
	index=-1;
	for(i=0;i<l;i++)
		if(b[i]<a){
			a=b[i];
			index=i;
		}
	return index;
}

int findMax(int b[], int l) {
    int a, index, i;
    a=-1000000;
    index=-1;
    for (i=0; i<l; i++)
        if (b[i]>a) {
            a=b[i];
            index=i;
        }
    return index;
}

double findMean(int b[], int l) {
    double sum = 0.0;
    int i;
    for (i=0; i<l; i++) {
        sum += b[i];
    }
    return sum / l;
}

double findMedian(int b[], int l) {
    double sum=0.0;
    int i, j;
    for (i=0; i<l; i++) {
        for (j=i+1; j<l; j++) {
            if (b[i]>b[j]) {
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    if (l%2==1) {
        return b[l/2];
    } else {
        int m1=b[l/2-1];
        int m2=b[l/2];
        return (double)(m1+m2)/2.0;
    }
}

int findMode(int b[], int l) {
    int maxCount=0;
    int mode=-1;
    int i, j;

    for (i=0; i<l; i++) {
        int count=0;
        for (j=0; j<l; j++) {
            if (b[i]==b[j]) {
                count++;
            }
        }
        if (count>maxCount) {
            maxCount=count;
            mode=b[i];
        }
    }
    if (maxCount==1) {
        return -1;
    }
    return mode;
}

void printHistogram(int b[], int l) {
    printf("\nHistogram:\n");
    
    int maxFrequency = 0,i,j;
    for ( i = 0; i < l; i++) {
        if (b[i] > maxFrequency) {
            maxFrequency = b[i];
        }
    }

    for ( i = 0; i < l; i++) {
        printf("%2d: ", i + 1);
        for ( j = 0; j < b[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}


int main() {
	srand(time(NULL));
    int i, j, n, posAnterior=0, numeroActual=0;

    printf("Numero de elementos a ordenar: ");
    scanf("%d", &n);

    int lista[n];

    printf("Lista desordenada\n");
    for (i=0; i<n; i++) {
        lista[i]=rand() %30+1;
        printf(" %d ", lista[i]);
    }
    printf("\n");

    for (i=0; i<n; i++) {
        numeroActual = lista[i];
        posAnterior = i-1;
        while (posAnterior>=0 && lista[posAnterior]>numeroActual) {
            lista[posAnterior+1] = lista[posAnterior];
            posAnterior--;
        }
        lista[posAnterior+1]=numeroActual;
    }

    printf("\nLista ordenada\n");
    for (i=0; i<n; i++)
        printf(" %d ", lista[i]);
	
	int minIndex=findMin(lista, n);
	printf("\n\nMin value: %d ", lista[minIndex]);
	
    int maxIndex=findMax(lista, n);
    printf("\n\nMax value: %d\n", lista[maxIndex]);
    
    double mean=findMean(lista, n);
    printf("\n\nMean: %.2f\n", mean);

	double median=findMedian(lista, n);
    printf("\nMedian: %.2f\n", median);
    
    int mode=findMode(lista, n);

    if (mode==-1) {
        printf("\nNo mode (no hay numeros repetidos).\n");
    } else {
        printf("\nMode: %d\n", mode);
    }
    
    printf("\nHistogram of the sorted list:\n");

    int frequency[30] = {0}; 

    for (i = 0; i < n; i++) {
        frequency[lista[i] - 1]++;
    }

    printHistogram(frequency, 30);
    
    return 0;
}
