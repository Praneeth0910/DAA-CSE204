#include<stdio.h>
int sum_rec(int x, int n){
	if(n==0)
		return 1;
	else
		return 1 + x*sum_rec(x, n-1);
}
int sum_native(int x, int n){
	int total_sum = 0;
	for(int i =0; i<=n;i++){
		int power = 1;
		for(int j =0; j<i;j++){
			power *= x;
		}
		total_sum += power;
	}
	return total_sum;
}
int main(){
	int x,n;
	printf("Enter the value of the X:");
	scanf("%d",&x);
	printf("Enter the value of the n:");
	scanf("%d",&n);
	int rec_result = sum_rec(x,n);
	printf("Using recurrsion: %d\n",rec_result);
	int nav_result = sum_native(x,n);
	printf("Using native: %d\n",nav_result);
	return 0;
}
