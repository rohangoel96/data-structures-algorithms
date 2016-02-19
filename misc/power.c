#include "stdio.h"

//THIS FUNCTION IS NOT GOOD AND IT's COMPLEXITY IS N as POWER IS CALLED 2 TIMES

// int power(int x, int n){
// 	if (n>1)
// 	{
// 		if (n%2==0)
// 		{
// 			return power(x, n/2)*power(x, n/2);
// 		}
// 		else 
// 		{
// 			return power(x, n/2)*power(x, (n/2)+1);
// 		}
// 	}
// 	else{
// 		return x;
// 	}
	
// }

//BETTER STORE IN A VARIABLE

int power(int x, int n){
	if (n>1)
	{	int temp = power(x, n/2);
		if (n%2==0)
		{
			return temp * temp;
		}
		else 
		{
			return temp*temp*x;
		}
	}
	else{
		return x;
	}
	
}


int main(int argc, char const *argv[])
{
	int x,n;
	printf("Enter x : ");
	scanf("%d",&x);
	
	printf("Enter n : ");
	scanf("%d",&n);

	printf("%d^%d = %d\n", x,n,power(x,n));

	return 0;
}