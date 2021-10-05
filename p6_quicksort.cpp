#include"stdio.h"
#include"time.h"                  
#include"stdlib.h"                
#define SIZE 5000
void quick_sort(int arr[], int beg, int end);
int main()
{
   srand(time(NULL));        
   int best[SIZE], avg[SIZE], worst[SIZE];
   clock_t start,end;
   double cpu_time_used;

      
               
                
    for(int i=0;i<SIZE-1;i++)  best[i]=i; 
    start=clock();
    quick_sort(best, 0, SIZE-1);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Best): %f\n", (float) cpu_time_used);
   
    for(int i=0;i<SIZE-1;i++)  avg[i]=rand()%100;
    start=clock();
    quick_sort(avg, 0, SIZE-1);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Average): %f\n", (float) cpu_time_used);
	
	for(int i=0;i<SIZE-1;i++)  worst[i]=SIZE-1-i;
    start=clock();
    quick_sort(worst, 0, SIZE-1);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time of execution(Worst): %f\n", (float) cpu_time_used);

   return 0;
}
int partition(int a[], int beg, int end){
   int left, right, temp, loc, flag;
   loc = left = beg;
   right = end;
   flag=0;
   while(flag!=1){
      while((a[loc] <= a[right]) && (loc!=right))  right--;
      if(loc == right)  flag=1;
      else if(a[loc] > a[right]){
         temp = a[loc];
         a[loc] = a[right];
         a[right] = temp;
         loc = right;
      }
      if(flag!=1){
         while((a[loc] >= a[left]) && (loc!=left))    left++;
         if(loc == left)   flag = 1;
         else if(a[loc] < a[left]){
            temp = a[loc];
            a[loc] = a[left];
            a[left] = temp;
            loc = left;
         }
      }
   }
   return loc;
}
void quick_sort(int a[], int beg, int end){
   int loc;
   if(beg<end){
      loc=partition(a, beg, end);
      quick_sort(a, beg, loc-1);
      quick_sort(a, loc+1, end);
   }
}
