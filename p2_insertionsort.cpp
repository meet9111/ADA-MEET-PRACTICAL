#include"stdio.h"
#include"time.h"                  
#include"stdlib.h"                
#define SIZE 5000
void insertionSort(int arr[]);
int main()
{
   srand(time(NULL));        
   int best[SIZE+1], avg[SIZE+1], worst[SIZE+1];
   clock_t start,end;
   double cpu_time_used;

      
   for(int i=1;i<=SIZE;i++)  best[i-1]=i;             
    start=clock();
    insertionSort(best);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Best): %f\n", (float) cpu_time_used);
   
   for(int i=1;i<=SIZE;i++)  avg[i-1]=rand()%100;
    start=clock();
    insertionSort(avg);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Average): %f\n", (float) cpu_time_used);
    

    
    for(int i=1;i<=SIZE;i++)  worst[i-1]=SIZE-i+1;
    start=clock();
    insertionSort(worst);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Worst): %f\n", (float) cpu_time_used);
   return 0;
}
void insertionSort(int arr[]){
   int temp, j;
   for(int i=1;i<SIZE;i++){

        temp = arr[i];
        j=i-1;

        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
   }
}
