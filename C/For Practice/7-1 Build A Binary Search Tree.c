#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *Tree;

struct TNode{
    int Key;
    Tree Left;
    Tree Right;
    int depth;
    int num;
};
void PostorderTest(Tree T);
void LevalorderTest(Tree *T,int N,int *stack,int *ptop);
void Insert(Tree T,int *data,int N);
void CalDepth(Tree T,int *stack,int *ptop);


int main(void)
{
	int stack[300],data[120];
	int i,j,N,num1,num2,top,temp,topofstack;
	int *ptop;
	topofstack=-1;
	ptop=&topofstack;
	Tree T[200];
	T[0]=(Tree) malloc(sizeof(struct TNode));      //根节点
//	T[0]->Key=0; 
	T[0]->Left=T[0]->Right=NULL;
	T[0]->num=0;
	scanf("%d",&N);							//节点数
	for(i=1;i<N;i++){
		T[i]=(Tree) malloc(sizeof(struct TNode));
		T[i]->Left=T[i]->Right=NULL;
		T[i]->num=i;                    //节点序号 
	}
	for(i=0;i<N;i++){
		scanf("%d %d",&num1,&num2);			//读一行中的两个数
		if(num1!=-1) 
			T[i]->Left=T[num1];
		if(num2!=-1)
			T[i]->Right=T[num2];
	}
	for(i=0;i<N;i++)              //读取最后衣一行的N个数 
		scanf("%d",data+i); 
	for(j=1;j<=N;j++){
		for(i=0;i<N-1;i++){
			if(data[i]>data[i+1]){
				temp=data[i];
				data[i]=data[i+1];
				data[i+1]=temp;
			}
		}
	}
//	for(i=0;i<N;i++)
//		printf("%d ",data[i]);
	Insert(T[0],data,N);  		  //插入 
	CalDepth(T[0],stack,ptop);
//	PostorderTest(T[0]);
	LevalorderTest(T,N,stack,ptop);				 
		
	return 0;
}


void PostorderTest(Tree T)
{
	if(T==NULL)
	return;
	else{
		printf("Node %d: %d\n",T->Key,T->depth);
		PostorderTest(T->Left);
		PostorderTest(T->Right);
	} 
	//printf("Node %d: %d\n",T->Key,T->depth);
	return;
}

void Insert(Tree T,int *data,int N)
{
	static int i=0;
	if(T==NULL||i==N)           //插入N个节点的数据后结束
		return;
	Insert(T->Left,data,N);
	T->Key=data[i];
	i++;
	Insert(T->Right,data,N);
	return;
}

void CalDepth(Tree T,int *stack,int *ptop)			//计算每一个节点的深度(每个节点只遍历一次) 
{
	static int depth=1;
	static int topofstack=-1;
	if(T==NULL)
		return;
	if(T->Left!=NULL){ 
		depth++;
		CalDepth(T->Left,stack,ptop);
	} 
	if(T->Right!=NULL){ 
		depth++;
		CalDepth(T->Right,stack,ptop);
	} 
	T->depth=depth;
	stack[++(*ptop)]=T->num; 
	depth--;
	return;	
}

void LevalorderTest(Tree *T,int N,int *stack,int *ptop)
{
	int i,j;
	int count=1;
	int maxdepth;
	if(T[0]==NULL)
		return;
	maxdepth=T[0]->depth;
	for(i=0;i<N;i++)
		if(T[i]->depth>maxdepth)     //
			maxdepth=T[i]->depth;			//最深深度
	for(j=1;j<=maxdepth;j++){
		for(i=0;i<=*ptop;i++){
			if(T[stack[i]]->depth==j){      //
				if(count==N)
					printf("%d",T[stack[i]]->Key);
				else
					printf("%d ",T[stack[i]]->Key);
				count++;
			}
		}
	}	
	
}




