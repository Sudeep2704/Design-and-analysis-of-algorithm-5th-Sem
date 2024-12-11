//Find max and Min element in an array using divide and conquer approach

#include <stdio.h>

struct MinMax {
int min;
int max;
};

struct MinMax findMinMax(int arr[], int low, int high) {
    struct MinMax result, leftResult, rightResult;
//only one element
if(low==high){

result.min=arr[low];
result.max=arr[low];
return result;

}
//2 element
if(high == low + 1){

if(arr[low]<arr[high]){
    result.min=arr[low];
    result.max=arr[high];
}

else{

result.min=arr[high];
result.max=arr[low];


}
return result;


}
//more element, divide the array into two subarrays
int mid = (low + high) / 2;

leftResult = findMinMax(arr, low, mid);
rightResult = findMinMax(arr, mid + 1, high);
if (leftResult.min < rightResult.min) {
        result.min = leftResult.min;
    } else {
        result.min = rightResult.min;
    }
    
    if (leftResult.max > rightResult.max) {
        result.max = leftResult.max;
    } else {
        result.max = rightResult.max;
    }
    
    return result;
}

int main() {


int arr[] = {100, 20, 500, 3, 77, 45, 32, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    struct MinMax result = findMinMax(arr, 0, n - 1);
    
    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);
    
    return 0;
}





