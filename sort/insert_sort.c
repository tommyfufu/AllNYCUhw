#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void SWAP(int *a, int *b)
{
    if (*a == *b)
        return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void merge(int *arr, int left, int mid, int right)
{
    int i, j, k;
    int nl = (mid - left + 1), nR = (right - mid);
    int L[nl], R[nR];
    for (i = 0; i < nl; i++)
        L[i] = arr[left + i];
    for (j = 0; j < nR; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < nl && j < nR)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < nR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int low, int up)
{
    if (low < up)
    {
        int mid = low + (up - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, up);
        merge(arr, low, mid, up);
    }
}
void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pk = arr[left];
        int i = left + 1, j = right + 1;
        while (i < j)
        {
            while (arr[i] < pk)
                i++;
            // while (arr[j] > pk)
            //     j--;
            do
            {
                j--;
            } while (arr[j] > pk);

            if (i < j)
                SWAP(&arr[j], &arr[i]);
        }
        SWAP(&arr[left], &arr[j]);
        quick_sort(arr, left, j - 1);
        quick_sort(arr, j + 1, right);
    }
}
void bubble_sort(int *arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        bool flag = false;
        for (int j = 0; j < num - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                SWAP(&arr[j], &arr[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
    printf("\nbubble sort\n");
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
}
void select_sort(int *arr, int num)
{
    int i = 0, j = 0;
    for (i = 0; i < num - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < num; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (i != min)
        {
            arr[min] ^= arr[i];
            arr[i] ^= arr[min];
            arr[min] ^= arr[i];
        }
    }
    printf("\nselect sort\n");
    for (i = 0; i < num; i++)
        printf("%d ", arr[i]);
}
void insert_fun(int *sor_arr, int nsnum, int snum)
{
    int j = snum;
    while (nsnum < sor_arr[j] && j >= 0)
    {
        sor_arr[j + 1] = sor_arr[j];
        j--;
    }
    sor_arr[j + 1] = nsnum;
}
void insert_sort(int *arr, int num_size)
{
    int i;
    for (i = 1; i < num_size; i++)
        insert_fun(arr, arr[i], i - 1);

    printf("insert sort\n");
    for (i = 0; i < num_size; i++)
        printf("%d ", arr[i]);
}
int reset_array(int *arr, char **argv, int number)
{
    int i;
    for (i = 0; i < number; i++)
        arr[i] = atoi(argv[i + 1]);
}

int main(int argc, char **argv)
{
    int number = argc - 1, i;
    int array[number];
    reset_array(array, argv, number);
    insert_sort(array, number);
    reset_array(array, argv, number);
    select_sort(array, number);
    reset_array(array, argv, number);
    bubble_sort(array, number);
    reset_array(array, argv, number);
    quick_sort(array, 0, number - 1);
    printf("\nquick sort\n");
    for (int i = 0; i < number; i++)
        printf("%d ", array[i]);
    reset_array(array, argv, number);
    merge_sort(array, 0, number - 1);
    printf("\nmerge sort\n");
    for (int i = 0; i < number; i++)
        printf("%d ", array[i]);
}