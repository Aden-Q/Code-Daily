#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXSIZE 1005

int main()
{
    int Nv,Ne;              //number of vertexs and number of edges
    double c;               //constant c
    int flag;
    int ran;                //random integer
    int i,j;
    int row,col;
    int matrix[MAXSIZE][MAXSIZE];       //store the case number
    long int Res;   //input restriction, size of long int should be 4 bytes if your computer is in place
    while(1){
        srand((int)time(0));        //generate a random number seed, alternating with running time
        printf("Please Enter The Number Of Vertexs And Edges, Splitted With A Space:\n");
        scanf("%d %d %lf",&Nv,&Ne,&c);
        for(i=0;i<MAXSIZE;i++)
            for(j=0;j<MAXSIZE;j++)
                matrix[i][j]=0;      //initialize the number matrix
        Res = Nv*(Nv-1)/2;      //maximum number of edges, for exception handling
        if(Ne>Res||Nv>1000)
            printf("Error input!\n");
        for(i=1;i<=Ne;i++){
            ran=1+(int)(rand()%200);
            row=(int)(rand()%(Nv-1));     //row should be from 0 to Nv-2
            col=row+1+(int)(rand()%(Nv-row-1));     //col should be from row+1 to Nv-1
            while(matrix[row][col]!=0){     //if this entry of matrix has been filled, generate again
                row=(int)(rand()%(Nv-1));
                col=row+1+(int)(rand()%(Nv-row-1));
            }
            matrix[row][col]=ran;
        }
        printf("-----------------------------\n");
        printf("The test case is:\n");
        printf("%d %d %.0f\n",Nv,Ne,c);
        for(i=0;i<Nv;i++)
            for(j=i+1;j<Nv;j++)
                if(matrix[i][j]!=0)
                    printf("%d %d %d\n",i,j,matrix[i][j]);
        printf("-----------------------------\n");
        printf("Enter 1 to run it again or other number to quit:");
        scanf("%d",&flag);
        if(flag==1)
            continue;
        else
            exit(0);
    }
    return 0;
}

