#include <stdio.h>
#include <stdlib.h>
#define EndWithoutError 0
#define No 1																   //symbol to judge if the tree is a red-black tree
#define Yes 2
#define MAXSIZE 1000						
#define MAXLENGTH 30

typedef struct TreeNode *Tree;
typedef int ElementType;
typedef enum NodeColor NodeColor;                                              

Tree Insert(ElementType a, Tree T);												//build a binary search tree(to be check if it is a genuine red-black tree) 
void PathGenerator(Tree T, int BlackCount, int *top, int *BlackNum);            //generate all paths of one node to all the black leaf nodes
void CheckRedNode(Tree T,int *pflag);               						    //this function check if there are continuous red nodes in the binary tree
void CheckPath(int *pflag, int *top, int *BlackNum);							//after generating a node's paths, check if they meet the requirements of rule 5	
void CheckRule5(Tree T, int *pflag,int *top, int *BlackNum);					//check rule 5 for root node(combine function "CheckPath" and function "PathGenerator")

enum NodeColor{																	//enumerated type to distinguish red or black node 
	Red,
	Black
};

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
	NodeColor color;				//specify the node's color(red or black)
};

int main(void)
{
	double Duration;
	Tree T;                             //point to the root of the tree
	ElementType data[MAXLENGTH];       	//this array stores datas that users input
	int i, j, K, N, flag;				//N represent the number of datas, K tree(s) to judge,flag:result of judging(Yes or No)
	int BlackNum[MAXSIZE];				//this array stores numbers of black nodes of all paths for one node
	int topofstack;      				//topofstack points to the top path elements 
	int *top=&topofstack;
	int *pflag=&flag;
	scanf("%d", &K);
	while(K>0){
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d", data+i);
	}
	T=NULL;
	flag=Yes;						//assume it is a red-black tree
	for(i=0;i<N;i++)
		T=Insert(data[i], T);			//generate a Binary search tree
    CheckRedNode(T,pflag);				//check if there are continuous red nodes
	if(flag==Yes)						//if the check result is "Yes", continue checking rule 5
		CheckRule5(T,pflag,top,BlackNum);     //check if all the paths to leaf node have the same amount of black nodes
	if(flag==No||T==NULL||T->color==Red)      //also handle the case that the root's color is red or the tree is empty
		printf("No\n");						  
	else
		printf("Yes\n");
	K--;
	}
	system("pause");
	return EndWithoutError;					//end successfully
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

void CheckRedNode(Tree T,int *pflag)            //this function only does not examine path and root(rule 5)
{
	static int flag=Yes;				 //flag of judement 
	if(*pflag==No)   				     //if it has already confirmed that the tree is not a Red Black Tree, then return	
		return;
	else if(T==NULL){                 //T==NULL indicates the current path has gone out,then return
		return;
	}
	else if(T->color==Red){           //handle red nodes
		 if(T->Left!=NULL&&T->Left->color==Red){	//if it's left child is also red,return with no
			*pflag=No;
			return;
		}
		 else if(T->Right!=NULL&&T->Right->color==Red){      //if it's right child is also red,return with no
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

void PathGenerator(Tree T, int BlackCount, int *top, int *BlackNum)         //generate all paths of T to all leaf nodes(black)
{
	if(T==NULL){                 //T==NULL indicates the current path has gone out
		BlackCount++;			 //because 'NULL' represent a null black node,so it should be '++'
		BlackNum[*top]=BlackCount;	//write the number of black nodes in to the stack
		(*top)++;				 //finish one path and topofstack++
		return;
	}
	else if(T->color==Black)		//if it's a black node
		BlackCount++;
	PathGenerator(T->Left, BlackCount, top, BlackNum);    //recurse
	PathGenerator(T->Right, BlackCount, top, BlackNum);   //recurse
	return;
}

void CheckPath(int *pflag, int *top, int *BlackNum)		//examine if all numbers of black nodes in paths are the same(rule 5)
{
	int i;
	for(i=0;i<*top;i++){
		if(BlackNum[0]!=BlackNum[i])
			break;
	}
	if(i<*top)						//if 'break' happens in advance,then return with flag=No
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
		PathGenerator(T,0,top,BlackNum);				//generates numbers of black nodes of all paths for the root node
		CheckPath(pflag, top, BlackNum);
	}
	return;
}


