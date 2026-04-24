#include<stdio.h>

void firstFit(int items[],int n, int capacity){
    int bin[n];
    int binCount = 0;
for(int i =0;i<n;i++)
        bin[i]=0;
    for(int i=0;i<n;i++){
        if(items[i]>capacity){
            printf("Item %d with size %d cannot be placed in any bin\n",i+1,items[i]);
            continue;
            }

        int placed =0;
        for(int j=0;j<binCount;j++){
            if (bin[j]>=items[i]){
                bin[j]-= items[i];
                printf("Item %d placed in Bin %d\n",items[i],j+1);
                placed = 1;
                break;
            }
        }
        if (!placed){
            bin[binCount] = capacity - items[i];
            printf("Item %d placed in Bin %d\n", items[i],binCount+1);
            binCount++;
        }
    }
    printf("Total bins used=%d\n",binCount);
}

void bestFit(int items[],int n,int capacity){
    int bin[n];
    int binCount = 0;
for(int i =0;i<n;i++)
        bin[i]=capacity;
    for(int i=0;i<n;i++){
        if(items[i]>capacity){
            printf("Item %d with size %d cannot be placed in any bin\n",i+1,items[i]);
            continue;
            }
        int bestIndex = -1;
        int minSpace = capacity +1;
      for(int j=0;j<binCount;j++){
            if (bin[j]>=items[i] && bin[j] - items[i]<minSpace){
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
      }
      if (bestIndex != -1){
          bin[bestIndex] -= items[i];
          printf("Item %d placed in Bin %d\n", items[i],bestIndex+1);
      }
      else{
          bin[binCount]= capacity - items[i];
          printf("Item %d placed in Bin %d\n",items[i], binCount +1);
          binCount++;
      }
    }
    printf("Total bins used = %d\n",binCount);
}

int main() {
int n = 0;
int capacity;
printf("Enter number of items:");
scanf("%d",&n);
int items[n];
printf("Enter weight and value of each item \n");
for(int i=0;i<n;i++){
    printf("item %d:",i+1);
    scanf("%d",&items[i]);
}
printf("Enter capacity of bins:");
scanf("%d",&capacity);

firstFit(items,n,capacity);
bestFit(items,n,capacity);

     return 0;
}
