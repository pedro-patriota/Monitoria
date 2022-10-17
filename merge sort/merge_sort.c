#include <stdio.h>
#include <stdlib.h>

void merge_func(int* arr, int left, int right){
    int aux[right + 1];
    for (int i = left; i <= right; i++){
        aux[i] = arr[i];
    }
    
    int mean = (left + right)/2;
    int i = left; // Cursor for the left part
    int j  = mean +1; // Cursor for the right part

    for (int cursor = left; cursor <= right; cursor++){
        if (i > mean){
            arr[cursor] = aux[j];
            j++;
        }
        else if (j > right){
            arr[cursor] = aux[i];
            i++;
        }
        else if (aux[i] <= aux[j]){
            arr[cursor] = aux[i];
            i++;
        }
        else{
            arr[cursor] = aux[j];
            j++;
        }
    }


}


void mergeSort(int* arr, int left, int right){
    if (left < right){

        int mid = (left + right)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge_func(arr, left, right);
    }
}

int main (void){
    int total_num;
    printf("How many number will you choose?\n");
    scanf("%d", &total_num);
    
    int* arr = malloc(total_num*sizeof(int));
    for (int i = 0; i < total_num; i++){
        int num;
        printf("Type your %d number\n", i);
        scanf("%d", &num);
        arr[i] = num;
    }   

    mergeSort(arr, 0, total_num -1);   
    for (int i = 0; i < total_num; i++){
        printf("%d ", arr[i]);
    }
    
}