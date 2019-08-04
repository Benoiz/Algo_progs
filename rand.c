#include "algo.h"

int main(int argc, char** argv) {
    if(argc==2) {
        int i, iRand;
        time_t t;
        srand(t);
        int count = atoi(argv[1]);
        //printf("\n%d", counter);
        for(i=0;i<count;i++) {
            iRand = rand()%MAXNUM+1;
        printf("%d\n", iRand);
        }
        //getchar();
    }
    else {
        printf("wrong parameter count");
    }
}