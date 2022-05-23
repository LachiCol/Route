#include<stdio.h>
 
int max(int x, int y)
{
    return (x>y)? x:y;
}
 
int matrixPath(int arr[][4], int i, int j, int *cnt) {
    
 if(i==0 && j==0)
    return arr[0][0];
    
 else if(i==0){
  
     return (arr[0][j]+ matrixPath(arr, 0, j-1, cnt));
 }
 
 else if(j==0){
 
     return (arr[i][0]+ matrixPath(arr, i-1, 0, cnt));
 }
    
 else{
     printf("(%d,%d)\n",i,j);
     return (arr[i][j] + max(matrixPath(arr, i-1, j, cnt), matrixPath(arr, i, j-1, cnt)));
    }
 }
 
int main() {
    
   int cnt = 0;
   int arr[][4] = {
            {6,7,12,5},
            {5,3,11,18},
            {7,17,3,3},
            {8,10,14,9}
    };
 

    printf("%d\n",matrixPath(arr,3,3,&cnt));
    printf("=====\n");
        
}

