void Level_order ( Tree T, void (*visit)(Tree ThisNode) )
{
    Tree a[1000];
    ElementType i,j,k;
    a[0]=T;
    i=0;
    j=0;
    k=1;
    ElementType flag=0;
    if(T==NULL)
        return;
    else;
    while(1){
        flag=0;
        for(;i<=j;i++){
            if(a[i]->Left!=NULL&&a[i]->Right!=NULL){
                a[k]=a[i]->Left;
                a[k+1]=a[i]->Right;
                k=k+2;
                flag=1;
            }
            else if(a[i]->Left!=NULL&&a[i]->Right==NULL){
                a[k]=a[i]->Left;
                k++;
                flag=1;
            }
            else if(a[i]->Left==NULL&&a[i]->Right!=NULL){
                a[k]=a[i]->Right;
                k++;
                flag=1;
            }
            else if(a[i]->Left==NULL&&a[i]->Right==NULL);
            else;
        }
        if(flag==0)
            break;
        i=j+1;
        j=k-1;
    }
    
    
    for(i=0;i<=j;i++)
        (*visit)(a[i]);
    
}
