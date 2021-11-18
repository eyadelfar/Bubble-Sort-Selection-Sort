#include <stdio.h>
#include <time.h>
double time1,time2, timedif;

void Swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Bubble_Sort(int *arr,int size){
    for(int i=0;i<size-1;i++) //O(n)
        for(int j = 0;j<size-1;j++) //O(n)
            if(arr[j]>arr[j+1])
                Swap(&arr[j],&arr[j+1]);
}        //O(n^2)

void Selection_Sort(int *arr,int size){
    int min; 
    for(int i=0;i<size-1;i++){  // O(n)
        min = i;
        for(int j = i+1;j<size;j++) //O(n)
            if(arr[j]<arr[min])
                Swap(&arr[j],&arr[min]);
    
    }   // O(n^2)
}

void main(){
    int arr[100000];
    int size= sizeof(arr)/sizeof(arr[1]);
    for(int i = 0;i<size;i++)
        arr[i]=rand()%100000;

    printf("\nBubble Sort: ");

    time1 = (double) clock();
    time1 = time1 / CLOCKS_PER_SEC; 
    Bubble_Sort(arr,size); 
    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("The elapsed time is %f seconds\n", timedif);

    printf("\nSelection Sort: ");
    time1 = (double) clock();
    time1 = time1 / CLOCKS_PER_SEC; 
    Selection_Sort(arr,size);
    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("The elapsed time is %f seconds\n", timedif);
}