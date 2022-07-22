#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

unsigned char pow2(char k){
    return 1 << k;
}
void setVal(unsigned char * data, int index,bool val){
	if(val)
		data[index/8] += (unsigned char)val * pow2(index % 8);
	else
		data[index/8] -= (unsigned char)val * pow2(index % 8);
}

bool getVal(unsigned char * data, int index){
    return (data[index/8]/pow2(index%8)) % 2;
}

int main(){
    int n,q,*nums,i,pi=0;
	scanf("%d%d",&n,&q);
	nums = (int*)malloc(q*sizeof(int));
	for(i = 0; i < q; i++)
		scanf("%d",nums+i);
	unsigned char * isComposite = (unsigned char*)malloc(n/8*sizeof(unsigned char));

	for(int k=1; k < n; k++)
		setVal(isComposite,k,0);
	const int limit = (int)sqrt((double)n);
	for(i=2; i <= limit; i++){
		if(getVal(isComposite,i))
			continue;
		for(int k = 2; k <= n/i; k++){
			setVal(isComposite,i*k,1);
			printf("set %d to composite\n",i*k);
			}
	}
	for(i=1;i < n;i++){
		pi+=!getVal(isComposite,i);
		printf("%d %d %d\n",i,!getVal(isComposite,i),pi); ///////////////////
	}
	printf("%d\n",pi);
	for(i=0;i<q;i++)
		printf("%d\n",getVal(isComposite,nums[i]));
	free(isComposite);
	free(nums);
	return 0;
}

