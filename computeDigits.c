#include <stdlib.h>
#include <stdio.h>

int * getDigits(int number, int base, int * arraySize){
	//find size of array to return
	int temp = number;
	*arraySize = 0;
    do{
        (*arraySize)++;
        temp /= base;
    }while (temp != 0);
    
    int * ret = (int*)malloc( (*arraySize) * sizeof(int));
    
    //fill array with digits
    do{
    	//digit at place is number % base
        ret[*arraySize-1-temp++]=(number % base);
        number /= base;
    }while (number != 0);
    
    return ret;
}
int main(){
	while(1){
	int number,base;
	printf("enter number and base\n");
	scanf("%d%d",&number,&base);
	int size;
	int * digits = getDigits(number,base,&size);
	printf("%d in base %d is:",number,base);
	for(int i = 0; i < size; i++)
		printf(" %d ",digits[i]);
	printf("\n");
	free(digits);
	}
	return 0;
}
