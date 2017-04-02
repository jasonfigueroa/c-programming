//this program outputs a text file with a 2d array to be used for testing sorting
//algorithms
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, rows, columns;
    time_t t;

    FILE *ofp;
    char filename[] = "../SelectionSort_2_Test/input.txt";

    ofp = fopen(filename, "w");

    rows = 20;
    columns = 15;

//    Intializes random number generator
    srand((unsigned) time(&t));

    fprintf(ofp, "%d\n", rows);

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            if(j < columns - 1)
            {
                fprintf(ofp, "%d ", rand() % 1000);
            }
            else
            {
                fprintf(ofp, "%d", rand() % 1000);
            }
        }
        fprintf(ofp, "\n");
    }

    fclose(ofp);
    return 0;
}
