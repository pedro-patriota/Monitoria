#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2)
{
    // printf("%d %d ", *num1, *num2);

    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void insert_sort(int *arr, int size)
{
    int j, past_index;
    for (int i = 1; i < size; i++)
    {
        j = i;
        int past_index = j - 1;

        while (arr[j] < arr[past_index] && past_index >= 0)
        {
            swap(&arr[j], &arr[past_index]);
            past_index--;
            j--;
        }

    }
}

int main()
{
    int *arr = malloc(4 * sizeof(int));
    arr[0] = 5;
    arr[1] = 2;
    arr[2] = 9;
    arr[3] = 1;

    insert_sort(arr, 4);
    for (int i = 0; i < 4; i++){
        printf("%d ", arr[i]);
    }
}