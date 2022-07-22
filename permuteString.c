#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO: Make swap inline (and skip the redundant swap)
//TODO: Fix duplicate prints

void permuteString(char*,size_t,size_t);
void swap(char*,char*);

char * lastPrinted;
int main(int argc, char **argv){
	if(argc != 2)
		return 238749;
	
	size_t size = 0;
	while(argv[1][++size] != '\0');
	
	printf("Permuting string \"%s\" of size %ld\n",argv[1],size);
	
	lastPrinted = (char*)malloc(size*sizeof(char));
	permuteString(argv[1],0,size);
	free(lastPrinted);
	
	return 0;
}

void permuteString(char *s,size_t recursionLevel,const size_t size){
	for(size_t i=recursionLevel;i<size;i++){
		swap(s+recursionLevel*sizeof(char),s+i*sizeof(char));
		if(strcmp(lastPrinted,s) != 0){
			printf("%s\n",s);
			memcpy(lastPrinted,s,size*sizeof(char));
		}
		permuteString(s,recursionLevel+1,size);
		swap(s+recursionLevel*sizeof(char),s+i*sizeof(char));
	}
}

void swap(char *a,char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}
