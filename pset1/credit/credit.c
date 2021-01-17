#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Functions prototypes
int DigitsCount(long int num);
int Digit(long int num, int n);
int DigitSums(long int num);
int CheckSum(long int num);
void LegitCard(long int num);


int main(void)
{
    long int creditCardNum = get_long("Number: ");
    LegitCard(creditCardNum);
}


int DigitsCount(long int num)
{
    //Returns the length of a given number
    int length = 0;
    for (long int i = 10; num % (i / 10) < num; i *= 10)
    {
        length++;
    }
    return length;
}


int Digit(long int num, int n)
{
    //Returns the digit passed as second parameter of the number passed as first argument
    //if you pass an invalid number (greater than the length of the num or less than 0) returns -1

    int digits = DigitsCount(num);
    if (n >= digits || n < 0)
    {
        return -1;
    }
    else
    {
        int digit = digits - n;
        long int zeros = pow(10, digit);
        long int prevZeros = pow(10, digit - 1);

        return (num % zeros - num % prevZeros) / (zeros / 10);
    }
}


int DigitSums(long int num)
{
    //This Function sums all the digits of a num
    int res = 0;
    for (long int i = 10; num % (i / 10) < num; i *= 10)
    {
        res += (num % i - (num % (i / 10))) / (i / 10);
    }
    return res;
}


int CheckSum(long int num)
{
    int res = 0;

    //Multiply by 2 every other digit, starting with the number’s second-to-last digit. And then sums the products
    for (long int i = 100; num % (i / 10) < num; i *= 100)
    {
        res += DigitSums(2 * ((num % i - (num % (i / 10))) / (i / 10)));
    }

    //Sums the digits that weren’t multiplied by 2 (starting from the end)
    for (long int i = 10; num % (i / 10) < num; i *= 100)
    {
        res += (num % i - (num % (i / 10))) / (i / 10);
    }

    return (res);
}


void LegitCard(long int num)
{

    //If the checksu is invalid, print "INVALID"
    //If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if (CheckSum(num) % 10 != 0)
    {
        printf("INVALID\n");
        return;
    }

    //The length of the passed number
    long int numLength = DigitsCount(num);
    //First digit of the number
    int firstDigit = Digit(num, 0);
    //Second digit of the number
    int secondDigit = Digit(num, 1);

    if (numLength == 15 && (firstDigit == 3 && (secondDigit == 4 || secondDigit == 7)))
    {
        printf("AMEX\n");
    }
    else if (numLength == 16 && (firstDigit == 5 && (secondDigit >= 1 && secondDigit <= 5)))
    {
        printf("MASTERCARD\n");
    }
    else if ((numLength == 13 || numLength == 16) && (firstDigit == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}