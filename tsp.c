#include<stdio.h>
#include<limits.h>
#define MAX 10
#define INF INT_MAX
int n;
int d[MAX][MAX];
int dpt[MAX][1<<MAX];
int g(int i,int s){
    if (s==0)
        return d[i][0];

    if (dpt[i][s]!=-1)
        return dpt[i][s];

int minCost = INF;
for (int k=0;k<n;k++)
{
    if(s&(1<<k))
    {
        int cost = d[i][k]+g(k,s&~(1<<k));

        if(cost < minCost)
          minCost = cost;
    }
}

return dpt[i][s] = minCost;
}
int main(){
    printf("Enter number of cities:");
    scanf("%d",&n);
    printf("Enter cost of matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           scanf("%d",&d[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int mask=0;mask<(1<<n);mask++){
          dpt[i][mask]=-1;
        }
    }
    int s=0;
    for(int i=1;i<n;i++){
        s |=(1<<i);
    }
    int result = g(0,s);

    printf("Given Cost Matrix\n");
    for(int i =0;i<n;i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
             printf(" %d " , d[i][j]);
        printf("|\n");
    }
    printf("Minimum traveling cost:%d\n",result);

return 0;
}
