#include <stdio.h>

void swap(int *a, int *b){

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){

int pivot =  arr[low];
int i = low;
int j = high;

while(i < j){

while(arr[i] <= pivot && i <= high - 1){
    i++;
}

while(arr[j] > pivot && j >= low + 1){
    j--;
}
if(i < j){
    swap(&arr[i], &arr[j]);
}

}

swap(&arr[low], &arr[j]);
return j;

}

void quicksort(int arr[], int low, int high){

if(low < high){

int partindex = partition(arr,low,high);
quicksort(arr, low, partindex-1);
quicksort(arr, partindex+1, high);



}


}


int main() {

int arr[] = {6,5,7,4,54,8,76,1,97,9};
int n = sizeof(arr) / sizeof(arr[0]);


printf("Original array\n");
for(int i = 0; i < n; i++)
{
    printf("%d\t", arr[i]);
}

quicksort(arr, 0, n-1);
printf("\n");
printf("Sorted array\n");
for(int i = 0; i < n; i++){
    printf("%d\t", arr[i]);
}

}