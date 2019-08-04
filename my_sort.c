#include "algo.h"

int main(int argc, char** argv ) {
    FILE *fIn = stdin; //stream is stdin, in case no filepath is given and pipelining is used.
    int i;
    int inputCount = 0;
    int* pTempArray;
    char puffer[21];
    char* temp; 
    if(argc>4) {
        printf("too many arguments!\n");
        exit(EXIT_FAILURE);
    }
    if(argc == 3 || argc < 2) {
        printf("i am sure you missed something out ;)");
        exit(EXIT_FAILURE);
    }
    if(argc == 4 && strcmp(argv[1], "--path") == 0 ) {
        char* path = argv[2]; // if a filepath is given
        fIn = fopen(path, "r");
        if(fIn == NULL) {
            printf("filepath not found!\n");
            exit(EXIT_FAILURE);
        }
    }
    pTempArray = calloc(MAXNUM, sizeof(int));
    if(!pTempArray) {
        printf("memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    while((temp = fgets(puffer, LINE, fIn ) ) ) {
        if(inputCount > MAXITEMS) {
            printf("Item limit reached! 100 000 is the limit! continuing prog and cutting of exceeding numbers!");
            break;
        }
        if(strcmp(temp, "\n") == 0 ) {
            printf("no data!");
            exit(EXIT_FAILURE);
        }
        pTempArray[inputCount] = atoi(temp);
        if(pTempArray == NULL) {
            printf("Array failure!\n");
            break;
        }
        inputCount++;
    }
    //printf("%d\n", inputCount);
    pTempArray = realloc(pTempArray, inputCount * sizeof(int));
    if(pTempArray == NULL) {
        printf("memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i<inputCount; i++) {
        printf("%d\n", pTempArray[i]);
    }
    fclose(fIn);
    my_sort(pTempArray, inputCount, argc, argv);
    free(pTempArray);
    exit(EXIT_SUCCESS);
}

int my_sort(int digits[], int inputCount, int argc, char** argv) {
    int i, k;
    long long time1, time2;

        if(strcmp(argv[argc-1], "--bubble") == 0 ) {
            //bubble sort
            time1 = GetUSecTime();
            bubbleSort(digits, inputCount, inputCount);
            time2 = GetUSecTime();
            printf("bubble sort\n");
            for(k = 0; k<inputCount; k++) {
                printf("%d\n", digits[k]);
            }
            printf("elapsed time: %lld usec\n", time2-time1);
        }
        else if(strcmp(argv[argc-1], "--selection") == 0 ) {
            //selection sort
            time1 = GetUSecTime();
            selectionSort(digits, inputCount, 0);
            time2 = GetUSecTime();
            printf("selection sort\n");
            for(k = 0; k<inputCount; k++) {
                printf("%d\n", digits[k]);
            }
            printf("elapsed time: %lld usec\n", time2-time1);
        }
        else if(strcmp(argv[argc-1], "--insertion") == 0 ) {
            //insertion Sort
            time1 = GetUSecTime();
            insertionSort(digits, inputCount);
            time2 = GetUSecTime();
            printf("insertion sort\n");
            for(k = 0; k<inputCount; k++) {
                printf("%d\n", digits[k]);
            }
            printf("elapsed time: %lld usec\n", time2-time1);
        }
        else if(strcmp(argv[argc-1], "--quick") == 0 ) {
            //quicksort
            time1 = GetUSecTime();
            quickSort(digits, digits+inputCount-1);
            time2 = GetUSecTime();
            printf("quickSort\n");
            for(i=0;i<inputCount;i++) {
                printf("%d\n", digits[i]);
            }
            printf("elapsed time: %lld usec\n", time2-time1);
        }
    return(EXIT_SUCCESS);

}

int* bubbleSort(int digits[], int inputCount, int arrLen) {
    int i, temp;
    if(inputCount == 1 ) {
        return digits;
    }
    else {
        for(i = 0; i < inputCount - 1; i++) {
            if(digits[i]>digits[i+1]) {
                temp = digits[i];
                digits[i] = digits[i+1];
                digits[i+1] = temp;
            }
        }
        bubbleSort(digits, inputCount-1, arrLen); // i really wanted a recursive bubble sort
    }
    return(EXIT_SUCCESS);
}
int* insertionSort(int digits[], int inputCount) {
    int i, j, sort_val;
    for(i=0;i<inputCount;i++) {
        sort_val = digits[i];
        j=i;
        while(j > 0 && sort_val < digits[j-1]) {
            digits[j] = digits[j-1];
            j--;
        }
        digits[j] = sort_val;
    }
    return digits;
}
int* selectionSort(int digits[], int inputCount, int start) {
    int j, temp;
    //int min = digits[start];
    if(start==inputCount) {
        return digits;
    }
    //search for smallest element and swap smallest with start element
    for(j = start + 1; j < inputCount; j++ ) {
        if(digits[start] > digits[j] ) {
            temp = digits[start];
            digits[start] = digits[j];
            digits[j] = temp;
        }
    }
    selectionSort(digits, inputCount, start+1);
    return digits;
}
void quickSort(int* left, int* right) {
    /* qsort(digits, inputCount, sizeof(int), cmp_integer); // heh;)
    return digits;*/
    //another quickSort
    int *ptr1 = left;
    int *ptr2 = right;
    int w, x;
    x = *(left + ((right - left) >> 1)); // shift instead of division by 2
    do {
        while(*ptr1 < x) ptr1++;
        while(*ptr2 > x) ptr2--;
        if(ptr1 > ptr2) {
            break;
        }
        w = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = w;
    } while(++ptr1 <= --ptr2);
    if(left < ptr2)  quickSort(left, ptr2);
    if(ptr1 < right) quickSort(ptr1, right);
}