#include<stdio.h>

void inputarr(int arr[10][10],int *r,int *c);
void tupdisplay(int arr[][3]);
void spardisplay(int arr[10][10],int r,int c);
int  compare(int a,int b,int p,int q);
void tup_sum(int tup1[][3],int tup2[][3]);
void spartotup(int arr[10][10],int r,int c,int tup[][3]);
void tuptospar(int tup[][3],int arr[10][10]);
void tup_transpose(int tup[][3],int tupt[][3]);


int main()
{
int arr1[10][10],arr2[10][10],tup1[10][3],tup2[10][3],tupt1[10][3],tupt2[10][3],r1,r2,c1,c2,a;
printf("Enter the 1 st array\n");
inputarr(arr1,&r1,&c1);
printf("Enter the 2nd array\n");
inputarr(arr2,&r2,&c2);
while(1)
{ printf("1:Tuple form\n2:Sum\n3:Transpose\n4:exit\n");
  scanf("%d",&a);
  if(a==1)
  {spartotup(arr1,r1,c1,tup1);spartotup(arr2,r2,c2,tup2);}
  else if(a==2)
  tup_sum(tup1,tup2);
  else if(a==3)
  {tup_transpose(tup1,tupt1);tup_transpose(tup2,tupt2);}
  else
  return 0;

}
}


void inputarr(int arr[10][10],int *r,int *c){
    printf("Enter the no of rows and columns:");
    scanf("%d %d",r,c);
    printf("Enter the elements");
    for(int i=0;i<*r;i++){
        for(int j=0;j<*c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    spardisplay(arr,*r,*c);
}

void tupdisplay(int arr[][3]){
    for(int i=0;i<=arr[0][2];i++)
        printf("%d | %d | %d\n",arr[i][0],arr[i][1],arr[i][2]);
    printf("\n");
}

void spardisplay(int arr[10][10],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr[i][j]);
        }printf("\n");
    }
    printf("\n");
}

void spartotup(int arr[10][10],int r,int c,int tup[][3]){
    int pos=1;
    tup[0][0]=r;tup[0][1]=c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]!=0){
                tup[pos][0]=i;
                tup[pos][1]=j;
                tup[pos][2]=arr[i][j];
                pos++;
            }
        }
    }
    tup[0][2]=pos-1;
    tupdisplay(tup);
}

void tuptospar(int tup[][3],int arr[10][10]){
    for(int i=1;i<=tup[0][2];i++)
        arr[tup[i][0]][tup[i][1]]=tup[i][2];
    spardisplay(arr,tup[0][0],tup[0][1]);
}

int compare(int a,int b,int p,int q){
    if(a==b){
        if(p==q) return 0;
        else if(p<q) return 1;
        else if(p>q) return 2;
    }
    else if(a<b) return 1;
    else if(a>b) return 2;

}

void tup_sum(int tup1[][3],int tup2[][3]){
    int p1=1,p2=1,p3=1;
    int sum[10][3];
    sum[0][0]=tup1[0][0];sum[0][1]=tup1[0][1];
    while(p1<=tup1[0][2] && p2<=tup2[0][2]){
        switch(compare(tup1[p1][0],tup2[p2][0],tup1[p1][1],tup2[p2][1])){
            case 0:
            if(tup1[p1][2]+tup2[p2][2]!=0){
                sum[p3][0]=tup1[p1][0];
                sum[p3][1]=tup1[p1][1];
                sum[p3][2]=tup1[p1][2]+tup2[p2][2];

                p3++;
                }
                p1++;p2++;
                break;
            case 1:
                sum[p3][0]=tup1[p1][0];
                sum[p3][1]=tup1[p1][1];
                sum[p3][2]=tup1[p1][2];

                p1++;p3++;
                break;
            case 2:
                sum[p3][0]=tup2[p2][0];
                sum[p3][1]=tup2[p2][1];
                sum[p3][2]=tup2[p2][2];

                p2++;p3++;
                break;

        }
    }
    while(p1<=tup1[0][2]){
        sum[p3][0]=tup1[p1][0];
        sum[p3][1]=tup1[p1][1];
        sum[p3][2]=tup1[p1][2];
        p1++;p3++;
    }
    while(p2<=tup2[0][2]){
        sum[p3][0]=tup2[p2][0];
        sum[p3][1]=tup2[p2][1];
        sum[p3][2]=tup2[p2][2];
        p2++;p3++;
    }
    sum[0][2]=p3-1;
    tupdisplay(sum);

}

void tup_transpose(int tup[][3],int tupt[][3]){
    tupt[0][0]=tup[0][1];
    tupt[0][1]=tup[0][0];
    tupt[0][2]=tup[0][2];
    int pos=1;
    for(int i=0;i<tup[0][1];i++){
        for(int j=1;j<=tup[0][2];j++){
            if(tup[j][1]==i){
                tupt[pos][0]=tup[j][1];
                tupt[pos][1]=tup[j][0];
                tupt[pos][2]=tup[j][2];
                pos++;
            }
        }
    }
    tupdisplay(tupt);
}
