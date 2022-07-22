#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool getVal(unsigned char *, int);
//unsigned char pow2(char k){
//	return 1 << k;
//}
void setVal(unsigned char * data, int index,bool val){
	if(val && !getVal(data,index))
		data[index/8]+= 1 << (index%8);
	else if (!val && getVal(data,index))
		data[index/8]-= 1 << (index%8);

	//if(val)
	//	data[index/8] += (unsigned char)val * pow2(index % 8);
	//else
	//	data[index/8] -= (unsigned char)val * pow2(index % 8);
}

bool getVal(unsigned char * data, int index){
	return ( data[index/8] & ( 1 << (index%8) ) ) == 0;
    //return (data[index/8]/pow2(index%8)) % 2;
}
int main(){
    const int SIZE = 32;
    int i;
    bool * k = (bool*)malloc(SIZE*sizeof(bool));
    unsigned char * j = (unsigned char*)malloc(SIZE/8*sizeof(unsigned char));
    for(i = 0; i < SIZE; i++){
        bool s = rand() % 2;
        k[i] = s;
        setVal(j,i,s);
    }
    for(i=0; i < SIZE; i++){
        printf("%d %d\n",k[i],getVal(j,i));
    }
	
    free(k);
    free(j);
    return 0;
}
