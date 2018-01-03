/* Author: Qian Zecheng; ID: 3160102418; No.01 */ 

#include <stdio.h>
#include <stdlib.h>

#define MAXN 30								//maximal N
#define MAXDEPTH 30							//maximal depth							

typedef struct TreeNode *BTree;				//tree node structure 
struct TreeNode {
	int value;
	int depth;
	BTree Left;
	BTree Right;
};
struct TreeLayer {					
	int stack[MAXN];
	int topofstack;
}Layer[MAXDEPTH];						//layer stack structure of the tree for output

BTree BuildBTree(BTree T, int Inorder[], int InLeft, int InRight, int Postorder[], int PostLeft, int PostRight,struct TreeLayer *Layer);	//build a binary tree
void ZigZaggingPrint(struct TreeLayer *Layer);			//print

int main(void)
{
	int i, N;
	int Inorder[MAXN];			//store inorder sequence
	int Postorder[MAXN];		//store postorder sequence
	int InLeft, InRight, PostLeft, PostRight;			//range
	BTree T;
	if (Inorder == NULL || Postorder == NULL) {			//error handling
		printf("Out of space!!!");
		return 0;
	}
	scanf("%d", &N);					//read
	for (i = 0; i<N; i++)
		scanf("%d", Inorder + i);		
	for (i = 0; i<N; i++)
		scanf("%d", Postorder + i);		
	InLeft = PostLeft = 0;
	InRight = PostRight = N - 1;
	T = (BTree)malloc(sizeof(struct TreeNode));
	for (i = 0; i < MAXDEPTH; i++)
		Layer[i].topofstack = -1;		//initialize stack
	T = BuildBTree(T, Inorder, InLeft, InRight, Postorder, PostLeft, PostRight,Layer);		//build a tree	
	ZigZaggingPrint(Layer);			//print
	return 0;
}


BTree BuildBTree(BTree T, int Inorder[], int InLeft, int InRight, int Postorder[], int PostLeft, int PostRight,struct TreeLayer *Layer)
{
	static int count;					//prevent to apply memory for the root
	static int depth;					//used to record the depth of each node
	if (InLeft>InRight || PostLeft>PostRight)
	{
		depth--;						//depth reduce by1 before function return
		return NULL;
	}
	int i;
	int last = Postorder[PostRight];			//get the last element of the postorder sequence
	for (i = InLeft; i <= InRight; i++)
		if (Inorder[i] == last)			//find the index in inorder sequence
			break;
	if(count!=0)
		T = (BTree)malloc(sizeof(struct TreeNode));		//apply memoory for the current pointer
	if (T != NULL) {
		T->value = last;			//write value
		T->depth = depth;			//write depth
		Layer[depth].stack[++(Layer[depth].topofstack)] = T->value;		//store the node in the stack after handling
		count++;
		depth++;
		T->Left = BuildBTree(T->Left, Inorder, InLeft, i - 1, Postorder, PostLeft, PostLeft + i - InLeft - 1,Layer);			//recursion
		depth++;
		T->Right =  BuildBTree(T->Right, Inorder, i + 1, InRight, Postorder, PostLeft + i - InLeft, PostRight - 1,Layer);		//recursion
	}
	depth--;
	return T;
}

void ZigZaggingPrint(struct TreeLayer *Layer)
{
	int i, j, k;
	j = Layer[0].topofstack;			//get tof of stack
		if (j >= 0) {					//if the stack is not empty
			printf("%d", Layer[0].stack[0]);		//output the first element of the first layer
			for (i = 1; i <= j; i++)
				printf(" %d", Layer[0].stack[i]);	//output other elements in the first layer
		}
	for (k = 1; k < MAXDEPTH; k++) {			//output other elements in the other layers
		j = Layer[k].topofstack;
		if (j >= 0) {
			if(k%2==0)					//reverse when k is an even number
				for (i = j; i >= 0; i--)
					printf(" %d", Layer[k].stack[i]);
			else
				for (i = 0; i <=j; i++)
					printf(" %d", Layer[k].stack[i]);
		}
	}
	printf("\n");
}
