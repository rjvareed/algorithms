#include <stdio.h>
#include <stdlib.h>
int efficientExponent(int,unsigned);

int main(int argc,char **argv){
	if(argc != 3){
		printf("Enter two integers as arguments\n");
		return 2389754;
	}
	
	int base = atoi(argv[1]);
	unsigned exp = atoi(argv[2]);
	
	if(base < 0)
		printf("(%d)",base);
	else
		printf("%d",base);
	printf("^%u=%d\n",exp,efficientExponent(base,exp));
	
	return 0;
}

int efficientExponent(int base, unsigned exp){
	int result = 1,multiplier=base;
	for(unsigned char n = 0; n<32; n++){
		if( (exp & (1 << n)) != 0 )		// if there is a digit at decimal place n
			result *= multiplier;		// then multiple the result by base^(2^n)
		multiplier *= multiplier;
	}
	return result;
}
