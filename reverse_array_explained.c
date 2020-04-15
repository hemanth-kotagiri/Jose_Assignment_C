/*
This is the solution for your second question. :)
This program uses two arrays one the original one which is given and the other to reverse the original.
*/

#include<stdio.h>

int main(){
    int size; // here we are declaring a variable of integer type to hold the size given by the user for the array.
    
    printf("Enter the size of array: ");
    scanf("%d", &size); // taking in the size.
    
    int array[size],rev_array[size]; // here I am using array[size] for storing the original array. then rev_array[size] is
    // another array which I will use later to reverse the original array.
    
    printf("Enter the elements into array: ");
    int i = 0; // here I am initializing this to traverse in the array[size] to add elements from the user.

    for (i = 0; i < size; i++){
        scanf("%d", &array[i]); // adding each and every element given by user.
    }
    
	// this next for loop is a bit abstract, so I will explain tomorrow when you call. :*
	// this forloop is responsible for reversing the array.
	
    for (i = size-1; i >= 0; i--){	
        rev_array[size - 1 - i] = array[i];
    }
    
    // finally, we print out the reverse of the array.
    
    printf("The reverse of the given array is: \n");
    for (i = 0; i < size; i++){
        printf("%d ", rev_array[i]);
    }
    
    return 0; // again, this is something that you will understand while learning about functions. :*
}
