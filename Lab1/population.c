#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize;
    int endSize;
    int yearsRequired = 0;

    // TODO: Prompt for start size
    do
    {
        startSize = get_int("Starting llamas population: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    do
    {
        endSize = get_int("Ending llamas population: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    while (startSize < endSize)
    {
        startSize += ((startSize / 3) - (startSize / 4));
        yearsRequired++;
    }
    // TODO: Print number of years
    printf("Years: %d\n", yearsRequired);
}