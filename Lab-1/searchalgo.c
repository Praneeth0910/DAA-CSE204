#include<stdio.h>
int linearsearch(int a[],int  n,int  target){
	for (int i = 0; i<n; i++){
		if (a[i] == target){
			return i;
		}
	}
	return -1;
}
int binarysearch(int a[], int n, int target){
	int low = 0;
	int high = n-1;
	while (low <= high){
		int mid = low + (high - low) / 2;
		if (a[mid] == target){
			return mid;
		}
		if (a[mid]<target){
			low = mid +1;
		}
		else{
			high = mid -1;
		}

	}
	return -1;
}
int main(){
	int n;
	printf("Enter the number of elements of the data set:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the values of the data set:");
	for (int i =0; i<n; i++){
		printf("Enter the %d value:", i+1);
		scanf("%d,",&a[i]);
	}
	int target;
	printf("Enter the value to search in the data set:");
	scanf("%d", &target);
	int type;
	printf("Which type of search:");
	printf("1. Linear Search");
	printf("2. Binary Search");
	scanf("%d", &type);
	if (type == 1){
		int result = linearsearch(a,n,target);
		if (result != -1){
			printf("The element found at %d", result);
		}else{
			printf("The element is not found in the data set!!");
		}
	}
	else if (type == 2){
                int result = binarysearch(a,n,target);
                if (result != -1){
                        printf("The element found at %d", result);
                }else{
                        printf("The element is not found in the data set!!");
                }
        }
	else{
		printf("Eneterd value is worng try again!!");
	}
	return 0;
}
