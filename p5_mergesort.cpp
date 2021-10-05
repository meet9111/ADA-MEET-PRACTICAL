#include"stdio.h"
#include"time.h"                  
#include"stdlib.h"                
#define SIZE 5000
void merge_sort(int arr[], int start, int end);
void merge(int arr[], int beg, int mid, int end);
int main()
{
   srand(time(NULL));        
   int best[SIZE], avg[SIZE], worst[SIZE];
   clock_t start,end;
   double cpu_time_used;

   
    for(int i=0;i<SIZE-1;i++)  best[i]=i;             
    start=clock();
    merge_sort(best, 0, SIZE-1);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Best): %f\n", (float) cpu_time_used);
   
    for(int i=0;i<SIZE-1;i++)  avg[i]=rand()%100;   
    start=clock();
    merge_sort(avg, 0, SIZE-1);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Average): %f\n", (float) cpu_time_used);
	
	for(int i=0;i<SIZE-1;i++)  worst[i]=SIZE-1-i; 
    start=clock();
    merge_sort(worst, 0, SIZE-1);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Worst): %f\n", (float) cpu_time_used);

   return 0;
}
void merge_sort(int arr[], int start, int end){

   int mid;
   if(start<end){
      mid = (start+end)/2;
      merge_sort(arr, start, mid);
      merge_sort(arr, mid+1, end);
      merge(arr, start, mid, end);
   }
}
void merge(int arr[], int start, int mid, int end){
   int i=start, j=mid+1, index=start, temp[SIZE], k;
   while((i<=mid) && (j<=end)){
      if(arr[i] < arr[j]){
         temp[index] = arr[i];
         i++;
      }
      else{
         temp[index] = arr[j];
         j++;
      }
      index++;
   }
   if(i>mid){
      while(j<=end){
         temp[index] = arr[j];
         j++;
         index++;
      }
   }
   else{
      while(i<=mid){
         temp[index] = arr[i];
         i++;
         index++;
      }
   }
   for(k=start; k<index; k++)   arr[k] = temp[k];
}
