#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef unsigned char byte;
bool getVal(byte*,size_t);

void setVal(byte *data, size_t index,bool val){
	if(val && !getVal(data,index))
		data[index/8]+= 1 << (index%8);
	else if (!val && getVal(data,index))
		data[index/8]-= 1 << (index%8);
}

inline bool getVal(byte *data, size_t index){
	return ( data[index/8] & ( 1 << (index%8) ) ) == 0;
}

int main(){
    srand(time(NULL));
    const size_t SIZE = 32;
	size_t i;

    bool *k = (bool*)malloc(SIZE*sizeof(bool));
    byte *j = (byte*)malloc(SIZE/8*sizeof(byte));

	for(i = 0; i < SIZE; i++){
        bool s = rand() % 2;
        k[i] = s;
        setVal(j,i,s);
    }
    
	for(i=0; i < SIZE; i++)
        printf("%d %d\n",k[i],getVal(j,i));
	
    free(k);
    free(j);
    return 0;
}
