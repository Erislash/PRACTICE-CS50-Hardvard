#include <stdio.h>
#include <cs50.h>
#include <math.h>


int HowMuchPennies(int owed)
{
    //Gives how many pennies do you need to reach the changed owed

    int pennies = 0;

    //Add pennies until you reach the owed quantity
    //If you owe more than the face value of one coin, the others will begin to be used
    while (owed > 0)
    {
        //For instance. If you owe 30 cents in total, you'll use a 25 cents pennie and then, one of 5 pennies
        if (owed >= 25)
        {
            owed -= 25;
        }
        else if (owed >= 10)
        {
            owed -= 10;
        }
        else if (owed >= 5)
        {
            owed -= 5;
        }
        else
        {
            owed -= 1;
        }

        pennies++;
    }

    return pennies;
}

int main()
{
    int owed;

    //Keep asking the change needed until the user inputs a positive number
    do
    {
        owed = round(get_float("How much change do you owe?: $") * 100);
    }
    while (owed <= 0);

    printf("%d\n", HowMuchPennies(owed));

    return 0;
}