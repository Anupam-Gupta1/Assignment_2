/**
 * Program to check Insertion_sort runtime analysis
 *
 * Compilation : gcc -o Insertion_sort Insertion_sort.c
 * Execution : ./insertion_sort
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
            arr[i] = rand() % n + 1;
        }
        
    }

    //Ascending Values
    else if(type == 2){

	    for(int i = 0; i < n; i++){
		    arr[i] = i;
	    }
    }

    //Descending Values
    else if(type == 3) {
        
        for(int i = 0; i < n; i++){
            arr[i] = n-i-1;
        }
        
    }
    
}

/*
* Insertion Sort Algorithm
* In Place and Stable
* Cache friendly -> Good 
*/

void insertion_sort(int arr[],int n){

	int key;
	
	for(int i = 1; i < n; i++)
	{
	      int j = i-1;
	      key = arr[i];
	      
	      while(j >= 0 && arr[j] > key)
	      {
		      arr[j+1] = arr[j];
		      j--;
	      }

	      arr[j+1] = key;
	}

}

int main(){
    
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
    
    insertion_sort(arr,n); 
    // Calling insertion_sort to sort array

    gettimeofday(&e, NULL);
    long long end_time = e.tv_sec * 1000LL + e.tv_usec / 1000;
    
    printf("Time Taken");
    
    printf("\t %lld",end_time - start_time);
    printf("\n");

   return 0;
}
