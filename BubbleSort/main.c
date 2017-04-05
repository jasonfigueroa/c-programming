#include <stdio.h>
#include <stdlib.h>

void bubblesort (int *arr, int size);
void print_int_array (int *arr, int size);

int main ()
{
    int array_size = 10;

    int *values = (int*)malloc(array_size*sizeof(int));

    values[0] = 33;
    values[1] = 17;
    values[2] = 11;
    values[3] = 110;
    values[4] = 51;
    values[5] = 68;
    values[6] = 89;
    values[7] = 15;
    values[8] = 233;
    values[9] = 42;

    print_int_array(values, array_size);

    printf("\n");

    bubblesort(values, array_size);

    print_int_array(values, array_size);

    free(values);

    return 0;
}

void bubblesort (int *arr, int size)
{
    int i, j, temp;

    for(i = 0; i < size - 1; i++)
    {
        for(j = i + 1; j > 0; j--)
        {
            if(arr[j] < arr[j - 1])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void print_int_array (int *arr, int size)
{
    int i;

    printf("{");
    for(i = 0; i < size; i++)
    {
        if(i < size - 1)
        {
            printf("%d, ", arr[i]);
        }
        else
        {
            printf("%d", arr[i]);
        }
    }
    printf("}\n");
}
