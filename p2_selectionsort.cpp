#include"stdio.h"
#include"time.h"                  
#include"stdlib.h"                
#define SIZE 5000
void selectionSort(int arr[]);
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int main()
{
   srand(time(NULL));        
   int best[SIZE], avg[SIZE], worst[SIZE];
   clock_t start,end;
   double cpu_time_used;
   
    for(int i=0;i<SIZE-1;i++)  best[i]=i;   
	start=clock();
    selectionSort(best);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Best): %f\n", (float) cpu_time_used);
   
    for(int i=0;i<SIZE-1;i++)  avg[i]=rand()%100; 
    start=clock();
    selectionSort(avg);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Average): %f\n", (float) cpu_time_used);
	
	for(int i=0;i<SIZE-1;i++)  worst[i]=SIZE-1-i;
    start=clock();
    selectionSort(worst);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Worst): %f\n", (float) cpu_time_used);

   return 0;
}

void selectionSort(int arr[]){
   
    for(int i=0;i<(SIZE-1-1);i++)
    {
      int min=i;

      for (int j=i+1;j<SIZE-1;j++)
      {
         if(arr[min]>arr[j])
            min = j;
      }
      swap(&arr[i],&arr[min]);
    }
   
}


