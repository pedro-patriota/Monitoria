#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int left, int right)
{
    int pivot = arr[left]; // Basic pivot funct
    int i = left;
    int j = right + 1;

    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int temp = arr[i]; // Undoing the last swap
    arr[i] = arr[j];
    arr[j] = temp;

    temp = arr[j];
    arr[j] = arr[left]; // Swaps the pivot
    arr[left] = temp;

    return j;
}

void quickSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int position = partition(arr, left, right);
        quickSort(arr, left, position - 1);
        quickSort(arr, position + 1, right);
    }
}

int main(void)
{   
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

    quickSort(arr, 0, total_num -1);   
    for (int i = 0; i < total_num; i++){
        printf("%d ", arr[i]);
    }
    
}