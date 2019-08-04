#include "algo.h"

int cmp_integer(const void *val1, const void *val2) {
   return (*(int*)val1 - *(int*)val2);
}

long long GetUSecTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL );
    return (long long )tv.tv_sec*1000000ll + tv.tv_usec;
}

int iarrlen(int* iArr) {
    //size_t count;
    int count;
    count = (int) sizeof(iArr) / sizeof(iArr[0]);
    return count;
}
