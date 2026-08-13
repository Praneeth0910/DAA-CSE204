#include<stdio.h>
int smallest(int a[], int n){
    int small = a[0];
    for(int i = 1; i<n; i++){
        if (a[i]<small){
            small = a[i];
        }
    }
    return small;
}
int main(){
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int A[n];
    for(int i = 0; i<n; i++){
        printf("Enter the value of A[%d]:", i+1);
        scanf("%d",&A[i]);
    }
    printf("The smallest element in the array using native method: %d\n", smallest(A,n));
    return 0;
}