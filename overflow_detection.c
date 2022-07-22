#include <stdio.h>
#include <stdlib.h>

int uadd_ok(unsigned x, unsigned y){
    return !(x+y<x);
}
int tadd_ok(int x, int y){
    return !( 
    (x>0 && y>0 && x+y <= 0) //positive overflow
    || 
    (x<0 && y<0 && x+y >= 0) //negative overflow
    
    );
}

int main(int argc, char** argv){
	printf("%d\n",tadd_ok(-2147483648,-1));
	printf("%d\n",tadd_ok(-2147483648,0));
	printf("%d\n",tadd_ok(-2147483647,-1));
	return 0;
}
