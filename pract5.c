#include<stdio.h>
#include<string.h>
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
void lcs(char x[],char y[]){
    int m=strlen(x);
    int n=strlen(y);
    int l=[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                l[i][j]=0;
            }
            else if{
                (x[i-1]==y[j-1]){
                    l[i][j]=l[i-1][j-1]+1;
                }
                else{
                    l[i][j]=max(l[i-1][j],l[i][j-1]);
                }
            }
        }
        int index=l[m][n];
        printf("length of lcs %d\n",index);
        char lcs[index+1];
        lcs[index]='\0';
        int i=m,j=n;
        while(i>0 && j>0){
            if(x[i-1]==y[j-1]){
                lcs[index-1]=x[i-1];
                i--;j--;index--;
            }else if(l[i-1][j]>l[i][j-1])
            i--;
            else j--;
        }
        printf("lcs %s",lcs);
    }
}
int main(){
char x[100],y[100];
printf("enter 1st string");
scanf("%s",x);
printf("enter 2nd string");
scanf("%s",y);

lcs(x,y);
return 0;
}