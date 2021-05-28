#include <stdio.h>
#include <stdlib.h>

int copy(int *originalArr, int origSize ,int *newArr){
    for (int i = 0; i < origSize; ++i) {
        *(newArr + i) = *(originalArr + i);
    }
    free(originalArr);
}

struct {
    int size;
    int originalArr[];
} arrayList;

int main() {
   arrayList.size = 5;
   arrayList.originalArr[arrayList.size];
}
