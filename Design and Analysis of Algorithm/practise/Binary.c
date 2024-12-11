#include <stdio.h>

int BinarySearch(int arr[], int low, int high, int x){


(high >= low); {

int mid = low + (high - low) / 2;


if(arr[mid]==x){
    return mid;
}

if(arr[mid] > x){
    return BinarySearch(arr, low, mid - 1, x);
}

if(arr[mid] < x){
    return BinarySearch(arr, mid + 1, high, x);
}

}

return -1;

}

int main() {

int arr[] = {1,2,3,4,5};
int n = sizeof(arr)/ sizeof(arr[0]);
int x = 1;
int result = BinarySearch(arr, 0, n-1, x);
if(result==-1){
    printf("Element not found\n");
}
else{
    printf("Element found in the array");
}


}