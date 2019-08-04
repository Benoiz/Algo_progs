#include "algo.h"

int main(int argc, char** argv) {
    FILE *fIn = stdin; //stream is stdin, in case no filepath is given and pipelining is used.
    int i;
    int inputCount = 0;
    int* pTempArray;
    char puffer[21];
    char* temp; 
    if(argc>3) {
        printf("too many arguments!\n");
        exit(EXIT_FAILURE);
    }
    if(argc == 3 && strcmp(argv[1], "--path") == 0 && argv[2] != NULL ) {
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
    printf("double\n");
    while((temp = fgets(puffer, LINE, fIn))) {
        if(inputCount > MAXITEMS) {
            printf("Item limit reached! 100 000 is the limit! continuing prog and cutting of exceeding numbers!");
            break;
        }
        pTempArray[inputCount] = atoi(temp);; //replace with line above...
        if(pTempArray == NULL) {
            printf("Array failure!\n");
            exit(EXIT_FAILURE);
        }
        inputCount++;
    }
    //printf("%d\n", inputCount);
    pTempArray = realloc(pTempArray, inputCount * sizeof(int));
    for(i = 0; i<inputCount; i++) {
        printf("%d\n", pTempArray[i] * 2);
    }
    fclose(fIn);
    //my_sort(pTempArray, inputCount, argc, argv);
    free(pTempArray);
    exit(EXIT_SUCCESS);

}