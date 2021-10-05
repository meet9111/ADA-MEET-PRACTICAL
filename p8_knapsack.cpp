#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct knapsack 
{
    int v;
    int w;
    float vw;
} knapsack;

int byW(knapsack k[], int n, int w);
int byV(knapsack k[], int n, int w);
int byVW(knapsack k[], int n, int w);


int main(){
    knapsack knap[10];
    int n, w;
    scanf("%d %d", &n, &w);

   for(int i=0;i<n;i++){
        scanf("%d %d", &knap[i].w, &knap[i].v);
        knap[i].vw = (float)knap[i].v/knap[i].w;
    }

    printf("By Weight : %d" ,byW(knap, n, w));
    printf("By Value : %d",byV(knap, n, w));
    printf("By Value/Weight : %d",byVW(knap, n, w));
    return 0;
}

int byW(knapsack knap[], int n, int w){

    knapsack t;
    int totalw=0, currentv=0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(knap[i].w > knap[j].w){
                t = knap[i];
                knap[i] = knap[j];
                knap[j] = t;
            }
        }
    }

    for(int i=0;i<n;i++){
        totalw += knap[i].w;
        
        if(totalw > w){
            currentv += (float)( w - totalw + knap[i].w )/knap[i].w * knap[i].v;
            break;

        }
        currentv += knap[i].v;
    }

    return currentv;
}

int byV(knapsack knap[], int n, int w){

    knapsack t;
    int totalw=0, currentv=0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(knap[i].w < knap[j].w){
                t = knap[i];
                knap[i] = knap[j];
                knap[j] = t;
            }
        }
    }

    for(int i=0;i<n;i++){
        totalw += knap[i].w;
        
        if(totalw > w){
            currentv += (float)( w - totalw + knap[i].w )/knap[i].w * knap[i].v;
            break;

        }
        currentv += knap[i].v;
    }

    return currentv;
}

int byVW(knapsack knap[], int n, int w){

    knapsack t;
    int totalw=0, currentv=0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(knap[i].w < knap[j].w){
                t = knap[i];
                knap[i] = knap[j];
                knap[j] = t;
            }
        }
    }

    for(int i=0;i<n;i++){
        totalw += knap[i].w;
        
        if(totalw > w){
            currentv += (float)( w - totalw + knap[i].w )/knap[i].w * knap[i].v;
            break;

        }
        currentv += knap[i].v;
    }

    return currentv;
}
