#include<stdio.h>
/*this is the solution for your first problem.

there is no such thing as using the int keyword only twice or thrice.
You can use int as many times as you want to declare variables/ arrays/ constants.

the int before main is different. It's called as a return type for a function.
You will understand why we write int before main while you would be introduced to functions in programming. :)
*/

int main(){
	int num; // here we are declaring the variable num to store the multiplicand.
	
	printf("Enter the number: ");
	scanf("%d",&num);
	
	int i = 1, array[3][10]; // here we are initializing a 2d array.
	// the 3 in the first of array[_] is something that I will explain tomorrow. :)
	// the 10 in the second of array[3][_] is the number of times to multiply the number.
	
	for(i; i<=10; i++){
		// I will explain this tomorrow.
		
		array[0][i] = num;
		array[1][i] = i;
		array[2][i] = array[0][i] * array[1][i];
	}
	
	// finally printing the multiplication table by just using the array. :)
	
	for(i=1; i<=10; i++){
		printf("%d * %d = %d\n",array[0][i],array[1][i],array[2][i]);
	}
	
	return 0; // again, this is something that you will understand while learning about functions. :*
}

