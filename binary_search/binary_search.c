#include <stdio.h>
#include <stdlib.h>

int binary_search(int* arr, int num, int left, int right){ 
    int mean = (left + right)/2;

    if (arr[mean] == num){
        return mean;
    }
    else if (right == left){
        return -1;
    }
    else if (num < arr[mean]){
        binary_search(arr, num, left, mean -1);
    }
    else if (num > arr[mean]){
        binary_search(arr, num, mean +1, right);
    }
    

}

int main(void){
    int* arr = malloc(5*sizeof(int));
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 6;
    arr[3] = 8;
    arr[4] = 9;

    printf("%d", binary_search(arr,6, 0, 4));
}