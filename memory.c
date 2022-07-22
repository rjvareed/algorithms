#include <stdio.h>
#include <stdlib.h>
int a = 0,b;
void function(){}

int main(){
	static int q;
    int * k = (int*)malloc(4*sizeof(int));
    int m[4] = {1,2,3,4};
    int n = 12;
    printf("text :%p\ndata :%p\nbss  :%p %p\nheap :%p\nstack:%p %p\n",&function,&a,&b,&q,k,&n,&m);
    free(k);
    return 0;
}
