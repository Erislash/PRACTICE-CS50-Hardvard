#include <cs50.h>
#include <stdio.h>

int main()
{
    //The binding of the height of the pyramid
    int size;


    //Ask for the height of the pyramid. Keep asking if the user input isn't between 1 and 8 (inclusive)
    do
    {
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);

    //For each row build the columns
    for (int i = 1; i <= size; i++)
    {

        //The number of hashes in each row is the same as the number of the row we are in.
        //As we have to print the pyramid begining on the right, we have to print white spaces until we pass a certain "column"
        //and there is when we'll print hashes. That column can be calculated by

        //(totalSize - rowNumber)


        for (int j = 1; j <= size; j++)
        {
            if (j > (size - i))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("  ");
        for (int j = 1; j <= size; j++)
        {
            if (j <= i)
            {
                printf("#");
            }
        }

        printf("\n");
    }

    return 0;
}