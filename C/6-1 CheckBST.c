#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
int CheckBST ( BinTree T, int K );
void Test(BinTree T);
struct TNode{
    int Key;
    BinTree Left;
    BinTree Right;
};

int main(void)
{
	BinTree T[9];
	int i;
	for(i=1;i<=8;i++){
	T[i]=(BinTree) malloc(sizeof(struct TNode));
	T[i]->Key=i; 
	T[i]->Left=T[i]->Right=NULL;
	} 
	T[5]->Left=T[3];
	T[5]->Right=T[6];
	T[3]->Left=T[1];
	T[3]->Right=T[4];
	T[6]->Left=T[2];
	T[6]->Right=T[7];
	T[7]->Right=T[8];
	printf("%d\n",CheckBST(T[5],3));
	//Test(T[5]);
	return 0;
}


void Test(BinTree T)
{
	if(T==NULL)
	return;
	else{
		Test(T->Left);
		Test(T->Right);
	} 
	printf("%d\n",T->Key);
	return;
}




int CheckBST ( BinTree T, int K )
{
	static int i=0;
	static int stack[1000];
	static int topofstack=0;
	static num=0;
	static int depth=1; 
	static int depthleft,depthright;
	if(T==NULL)
		return --num;          //记录递归深度 
	else{
		if(T->Left!=NULL||T->Right!=NULL)
			depth++;
		num++;   			   //调用两次，但需要分开自增 
		CheckBST(T->Left,K);
		stack[++topofstack]=T->Key;     //begin at stack[1]
		if(num==0){
			depthleft=depth;
			if(T->Right!=NULL)
				depth=2;
			else
				depth=1;
		}
		num++;
		CheckBST(T->Right,K);
		if(num==0){
			depthright=depth;
			depth=1;
		}
	}
	if(num==0){                   //0层调用表明在第一个函数位置处(说明所有的递归都已经结束了，等待返回到main，此时栈达到最大)
		for(i=1;i<topofstack;i++){
			if(stack[i+1]<=stack[i])
				break;						//此时的跳出表明不满足排序要求，即若i<topofstack则输出No 
		}
		if(i<topofstack)                    //应当输出为树的深度(非搜索树)
			return depthleft>depthright?-depthleft:-depthright;
		else{					     	   
		    return stack[topofstack+1-K];
		}
	}
	return --num;
} 
