#include <stdio.h>
#include <stdlib.h>
#define INF 100000

typedef struct gEdge{        // define the edge
    int  V1;
    int  V2;
    double  Weight;
    int flag;                //use to judge if the edge is in the Minimum spanning tree
}gEdge;

int cmp(const void *a, const void *b);   // use for sort the edge
int findroot(int a,int *p);              // use for find the root of the vertex
void merge(int a,int b,int *p);          // union
double findH(int a,int *p,double c,gEdge *s,int Ne,int Nv);  // find the H(C)
void print(int *p,int Nv);               // print the result

int main()
{
    int Nv,Ne;    // the number of vertexs and the number of the edges
    double c;     // constant number c
    double temp1,temp2; // store the H(C)
    int i;
    gEdge *p;     // store the edges
    //printf("Please enter the number of the vertexs,edges and the constant c:\n");
    scanf("%d%d%lf",&Nv,&Ne,&c);
    //printf("----------------------------------\n");
    //printf("Enter the vertexs V1,V2 and the Weight\n");
    p = (gEdge *)malloc(sizeof(gEdge)*Ne);
    for(i=0;i<Ne;i++)
    {
        scanf("%d%d%lf",&p[i].V1,&p[i].V2,&p[i].Weight);
        p[i].flag=0;
    }
    qsort(p, Ne, sizeof(gEdge), cmp);   // use quick sort to order the edges
    int path[1000];   // store the root
    for(i=0;i<1000;i++)
        path[i]=-1;     // initialize
    for(i=0;i<Ne;i++)
    {
        temp1 = findH(p[i].V1, path, c, p, Ne, Nv);  // store H(V1)
        temp2 = findH(p[i].V2, path, c, p, Ne, Nv);  // store H(V2)
        if(findroot(p[i].V1,path)!=findroot(p[i].V2, path)&&(temp1>=p[i].Weight&&temp2>=p[i].Weight))
        {   // if the edge satisfy H(V1) and H(V2) are larger than D(C1,C2)
            // then union C1 and C2
            merge(p[i].V1, p[i].V2, path);
            p[i].flag=1;
        }
    }
    print(path, Nv);  //print the result
    return 0;
}

int cmp(const void*a, const void *b)    // compare the two edges' weight
{
    return (int)(((gEdge*)a)->Weight - ((gEdge*)b)->Weight);
}

int findroot(int a,int *p)  //use path comparession to find the root
{
    int b=a,c=a;
    while(p[a]>-1)   //find the root
        a=p[a];
    while(p[b]>-1)   //path comparession
    {
        b=p[b];
        p[c]=a;
        c=b;
    }
    return a;
}

void merge(int a,int b,int *p)  //union by size
{
    int r1 = findroot(a,p);
    int r2 = findroot(b,p);
    int tmp = p[r1] + p[r2];   //the sum of vertexs of the two sets
    if(p[r1] > p[r2])
    {
        p[r1] = r2;
        p[r2] = tmp;
    }
    else
    {
        p[r2] = r1;
        p[r1] = tmp;
    }
}

double findH(int a,int *p,double c,gEdge *s,int Ne,int Nv)  // find the H(C)
{
    double max=-1;
    int i,j,number,root;
    root=findroot(a, p);  //find the root of a
    number=p[root]*(-1);  // count the number of the vertexs in this set
    for(i=0;i<Nv;i++)
        if(findroot(i, p)==root)
            for(j=0;j<Ne;j++)
            {
                if(s[j].V1==i&&s[j].flag==1)    // find the maximum edge weight of the minimum spanning tree of C
                    if(findroot(s[j].V2, p)==root&&s[j].Weight>max)
                        max=s[j].Weight;
                if(s[j].V2==i&&s[j].flag==1)
                    if(findroot(s[j].V1, p)==root&&s[j].Weight>max)
                        max=s[j].Weight;
            }
    if(max==-1)   //infinity if no such edge exists
        return INF;
    max=max+c/(number*1.0); // get the value of H(C)
    return max;
}

void print(int *p,int Nv)  // print the result
{
    int visit[1000];
    int i,j;
    int root;
    printf("----------------------------------\n");
    printf("the result is:\n");
    for(i=0;i<Nv;i++)      // store if the vertex is printed
        visit[i]=0;
    for(i=0;i<Nv;i++)
        if(!visit[i])      // if it is not printed yet, print it
        {
            visit[i]=1;
            printf("%d",i);
            root=findroot(i, p);
            for(j=i+1;j<Nv;j++)  // print its set
                if(findroot(j, p)==root&&!visit[j])
                {
                    visit[j]=1;
                    printf(" %d",j);
                }
            printf("\n");
        }
}

