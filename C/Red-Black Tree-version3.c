#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define EndWithoutError 0
#define No 1
#define Yes 2
#define MAXSIZE 1000
#define MAXLENGTH 30

typedef struct TreeNode *Tree;
typedef int ElementType;
typedef enum NodeColor NodeColor;                                                      

Tree Insert(ElementType a, Tree T);														//build a 'pseudo' red-black tree(to be check if it is a genuine red-black tree) 
void PathGenerator(Tree T, int BlackCount, int *top, int *BlackNum);                    //generate all paths of one node
void Test(Tree T);																		//a function for test, you can ignore it now
void CheckRedNode(Tree T,int *pflag);               									//this function check if there are continuous red nodes in the binary tree
void CheckPath(int *pflag, int *top, int *BlackNum);									//after generator a node's path, check if they meet the requirements(rule 5)	
void CheckRule5(Tree T, int *pflag,int *top, int *BlackNum);							//check rule 5(combine function CheckPath and function PathGenerator)

enum NodeColor{
	Red,
	Black
};

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
	NodeColor color;	  //specify a red or black node
};

int main(void)
{
	clock_t start,stop;
	double Ticks;
	double Duration;
	Tree T;                         //root pointer
	ElementType data[MAXLENGTH], i, K, N, flag;       		//N represent the number of datas
	int BlackNum[MAXSIZE];
	int topofstack;      
	int *top=&topofstack;
	int *pflag=&flag;
	scanf("%d", &K);
	while(K>0){
	T=NULL;
	flag=Yes;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d", data+i);
	}
	start=clock();
	for(i=0;i<N;i++)
		T=Insert(data[i], T);
//	Test(T);
//	printf("\n");
    CheckRedNode(T,pflag);
	if(flag==Yes)
		CheckRule5(T,pflag,top,BlackNum);
	if(flag==No||T==NULL||T->color==Red)
		printf("No\n");
	else
		printf("Yes\n");
	K--;
	stop=clock();
	Ticks=(double)(stop-start);
	Duration=Ticks/CLK_TCK;
	printf("Ticks = %.15f\n",Ticks);
	printf("Duration = %.15f\n",Duration);
	}
	return EndWithoutError;
}

Tree Insert(ElementType a, Tree T)   
{
	NodeColor ColorFlag;
	ElementType Absolute_a;
	Absolute_a=a<0? -a:a; 				 		   //take the absolute value of a
	ColorFlag = a>0?Black:Red;                     //judge the color of node to be inserted
	if(T==NULL){					               //every insertion the function handle an empty node
		T=(Tree) malloc(sizeof(struct TreeNode));
		if(T==NULL)                                //exception handling
			printf("Out of space!");
		else{
			T->color=ColorFlag;		            //initialize the new node
			T->Element=Absolute_a;
			T->Left=NULL;
			T->Right=NULL;
		}
	}
	else if(Absolute_a>T->Element)			//the tree already exists and find the appropriate position to insert
		T->Right=Insert(a, T->Right);		//insert into the right subtree recursively
	else if(Absolute_a<T->Element)
		T->Left=Insert(a, T->Left);         //insert into the left subtree recursively
	else                                    //the only case is that a==T->Element
		;									//do nothing
	return T;
}

void Test(Tree T)
{
	if(T==NULL)
		return;
	Test(T->Left);
	Test(T->Right);
	printf("Element: %d	  Color: %d\n", T->Element, T->color);
	return; 
	
}

void CheckRedNode(Tree T,int *pflag)            //this function only does not examine path and root
{
	static int flag=Yes;              //flag of judement 
	if(*pflag==No)   				     //if we have already judge the tree is not a Red Black Tree, then return	
		return;
	else if(T==NULL){                 //T==NULL indicates the current path has gone out
		return;
	}
	else if(T->color==Red){           //handle red nodes
		 if(T->Left!=NULL&&T->Left->color==Red){
			*pflag=No;
			return;
		}
		 else if(T->Right!=NULL&&T->Right->color==Red){
     		*pflag=No;
     		return;
     	}
		else{                          //this 'else' indicate the case that left and right nodes are both black or both NULL
			CheckRedNode(T->Left,pflag);
			CheckRedNode(T->Right,pflag);
		}	
	}
	else{								//this 'else' indicate the case that the current node is black
			CheckRedNode(T->Left,pflag);
			CheckRedNode(T->Right,pflag);
	}
	return;
}

void PathGenerator(Tree T, int BlackCount, int *top, int *BlackNum)         //generate path
{
	if(T==NULL){                 //T==NULL indicates the current path has gone out
		BlackCount++;
		BlackNum[*top]=BlackCount;
		(*top)++;
		return;
	}
	else if(T->color==Black)
		BlackCount++;
	PathGenerator(T->Left, BlackCount, top, BlackNum);
	PathGenerator(T->Right, BlackCount, top, BlackNum);
	return;
}

void CheckPath(int *pflag, int *top, int *BlackNum)					//examine path
{
	int i;
	for(i=0;i<*top;i++){
		if(BlackNum[0]!=BlackNum[i])
			break;
	}
	if(i<*top)
		*pflag=No;
	return;	
}

void CheckRule5(Tree T,int *pflag ,int *top, int *BlackNum)
{
	if(*pflag==No)                                       //only when flag==Yes needs further checking
		return;
	if(T==NULL)
		return;
	else{
		*top=0;
		PathGenerator(T,0,top,BlackNum);
		CheckPath(pflag, top, BlackNum);
	}
	CheckRule5(T->Left,pflag,top,BlackNum);
	CheckRule5(T->Right,pflag,top,BlackNum);
	return;
}


