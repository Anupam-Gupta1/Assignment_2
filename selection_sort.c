/**
 * Program to check Selection_sort runtime analysis
 *
 * Compilation : gcc -o selection_sort selection_sort.c
 * Execution : ./selection_sort
 *
 * Anupam Gupta and 1910990303  02/08/21
 * Assignment -> Assignment_2
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
* Function to generate Input
* type 1-> Random Numbers
* type 2-> Sorted Numbers in Ascending Order
* type 3-> Sorted Numbers in Descending Order
*/

void input_value(int arr[],int n,int type){
    
    if(type == 1) {
        
        //Random Values
        for(int i = 0; i < n; i++){
            arr[i] = rand() % n +1;
        }
        
    }

    //Ascending Values
    else if(type == 2) {
        
        for(int i = 0; i < n; i++){
            arr[i] = i;
        }
        
    }

    //Descending Values
    else if(type == 3) {
        
	int k=n-1;

        for(int i = 0; i < n; i++){
            arr[i] = k;
	    k--;
        }
        
    }
       
}

/*
* Selection Sort Algorithm
* In Place and Not Stable
* Cache friendly -> Good 
*/

void selection_sort(int arr[],int n){
    
    int min_index = 0;

    for(int i = 0; i < n; i++){
        
	min_index = i;
        
        for(int j = i+1; j < n; j++){
            
            // checking minimum index
            if(arr[j] < arr[min_index]){
		min_index = j;
            }
        }

	int temp = arr[min_index];
	arr[min_index] = arr[i];
	arr[i] = temp;
    }
    
}

int main()
{
    int n;
    int type;
    scanf("%d", &n);
    scanf("%d", &type);
    int arr[n];


    // type 1-> Random Numbers
    // type 2-> Sorted Numbers in Ascending Order 
    // type 3-> Sorted Numbers in Descending Order 
    input_value(arr,n,type);
    //Calling Function for generating Input

    struct timeval e;
    gettimeofday(&e, NULL);
    long long start_time = e.tv_sec * 1000LL + e.tv_usec / 1000;
    
    selection_sort(arr,n);
    // Calling selection_sort to sort array

    gettimeofday(&e, NULL);
    long long end_time = e.tv_sec * 1000LL + e.tv_usec / 1000;
    
    printf("Time Taken");
    
    printf("\t %lld",end_time - start_time);
    printf("\n");
    
    return 0;
}
