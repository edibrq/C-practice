#include <stdio.h>

void add(int* a, int* b){
    *a+=1;
    *b+=1;
}

int main() {
    printf("Hello, World!\n");
    int a = 5;
    int b = 6;
    printf("a = %d,\nb = %d\n",a,b);
    add(&a,&b);
    printf("Values now is:\n");
    printf("a = %d,\nb = %d",a,b);
    return 0;
}
