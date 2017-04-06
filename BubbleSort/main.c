#include <stdio.h>
#include <stdlib.h>

void bubblesort (int *arr, int size);
void fprintf_int_array (FILE *ofp, int *arr, int size);
void print_int_array (int *arr, int size);

int main ()
{
    int array_size = 15;

    int *values = (int*)malloc(array_size*sizeof(int));

    /******************/
    /** test harness **/
    /******************/

    FILE *ifp;
    ifp = fopen("input.txt", "r");

    FILE *ofp;
    ofp = fopen("output.txt", "w");

    int i, j, rows;

    fscanf(ifp, "%d", &rows);

    fprintf(ofp, "%d\n", rows * 2);

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < array_size; j++)
        {
            fscanf(ifp, "%d", &values[j]);
        }

        fprintf_int_array(ofp, values, array_size);

        fprintf(ofp, "\n");

        bubblesort(values, array_size);

        fprintf_int_array(ofp, values, array_size);

        fprintf(ofp, "\n");
    }

    fclose(ifp);
    fclose(ofp);

    /*************************/
    /** end of test harness **/
    /*************************/

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

void fprintf_int_array (FILE *ofp, int *arr, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        if(i < size - 1)
        {
            fprintf(ofp, "%d ", arr[i]);
        }
        else
        {
            fprintf(ofp, "%d", arr[i]);
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
