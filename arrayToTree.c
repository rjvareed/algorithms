#include <stdlib.h>
#include <stdio.h>
typedef struct TNode{
	int data;
	struct TNode* pLeft;
	struct TNode* pRight;
} TNode;

TNode* createTreeRec( int *A, int start, int end ){
    TNode* node = (TNode*)malloc(sizeof(TNode));
    int mid = (end+start)/2;
    node->data = A[mid];
    //base case
    if(start >= end){
        node->pLeft = NULL;
        node->pRight = NULL;
        return node;
    }
    
    //recursive case
    node->pLeft = createTreeRec(A,start,mid-1);
    node->pRight = createTreeRec(A,mid+1,end);
    return node;
}
void printTree( TNode* root){
    if(root!=NULL){
        printTree(root->pLeft);
        printf("%d ",root->data);
        printTree(root->pRight);
    }
}
int main(){
	
	int A[] = {0,1,5,9,12,13,14,17,18,20,24,34,42,43,49,51};
	TNode* tree = createTreeRec(A,0,15);
	printTree(tree);
	printf("\n");
	return 0;
}
