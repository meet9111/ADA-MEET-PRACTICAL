#include"stdio.h"
#include"time.h"                  
#include"stdlib.h"                
int linear_search(int arr[], int n, int x);
int binary_search(int arr[], int l, int r, int x);
int main()
{
   srand(time(NULL));        
   clock_t start,end;
   double cpu_time_used;
   
   int position, n=10, element=6;
   int arr[n] = {1,2,3,4,5,6,7,8,9,10};

   start=clock();
   position = linear_search(arr, n, element);
   end=clock();
   cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
   printf("Element present at       : %d\n", position);
   printf("Time of execution(Linear): %f\n\n", (float) cpu_time_used);
   
   start=clock();
   position = binary_search(arr, 0, n-1, element);
   end=clock();
   cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
   printf("Element present at       : %d\n", position);
   printf("Time of execution(Binary): %f\n", (float) cpu_time_used);

   return 0;
}
int linear_search(int arr[], int n, int x){
   for(int i=0; i<n; i++){
      if(arr[i] == x){
         return i;
      }
   }
   return -1;
}
int binary_search(int arr[], int l, int r, int x){
   if (r >= l) {
      int mid = l + (r - l) / 2;
  
      if (arr[mid] == x)
         return mid;
  
      if (arr[mid] > x)
         return binary_search(arr, l, mid - 1, x);
  
      return binary_search(arr, mid + 1, r, x);
   }
   return -1;
}
