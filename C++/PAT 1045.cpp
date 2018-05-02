#include <iostream>
#include <vector>

using namespace std;

int matrix[201][10001]={0};

int main() {
    int N, M, L;        //M rows, L cols
    int i, j;
    int val;
    int maxentry;
    int maxval=0;
    cin >> N;
    cin >> M;
    //ignore matrix[0][0]
    for (i = 1; i <=M; i++) {
        cin >> val;
        matrix[i][0]=val;
    }
    cin>>L;
    for(i=1;i<=L;i++){
        cin>>val;
        matrix[0][i]=val;
    }
    for(i=1;i<=M;i++){
        for(j=1;j<=L;j++) {
            if(i==1&&j==1)
                matrix[i][j] = 0;        //initialization
            else if(i==1&&j!=1)     //row 1, cols '1
                matrix[i][j]=matrix[i][j-1];
            else if(j==1)
                matrix[i][j]=matrix[i-1][j];
            else{
                maxentry=matrix[i-1][j-1];
                if(matrix[i-1][j]>maxentry)
                    maxentry=matrix[i-1][j];
                if(matrix[i][j-1]>maxentry)
                    maxentry=matrix[i][j-1];
                matrix[i][j]=maxentry;
            }

            if (matrix[0][j] == matrix[i][0]){
                if(j==1)
                    matrix[i][j]=1;
                else
                    matrix[i][j]=matrix[i][j-1]+1;
            }
        }
    }

    /*
    for(i=0;i<=M;i++){
        for(j=0;j<=L;j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
    */

    for(i=1;i<=M;i++){
        for(j=1;j<=L;j++){
            if(matrix[i][j]>maxval)
                maxval=matrix[i][j];
        }
    }
    cout<<maxval;

    return 0;

}