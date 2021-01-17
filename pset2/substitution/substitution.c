#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int IsAlphabetical(string str);      //Check if every character in the argument is numerical
int RepeatedLetters(string str);
int CheckArgument(string str);
string Encrypt(string key, string str);

int main(int argc, string argv[])
{
    //If the number of arguments is different than 1, an error will be
    //      printed and the program will end and return an 1
    if (argc != 2)
    {
        printf("ERROR:\nNumber of arguments different than expected\n\n");
        return 1;
    }

    if (!CheckArgument(argv[1]))
    {
        printf("ERROR:\nInvalid argument\n\n");
        return 1;
    }

    string wordToEncrypth = get_string("plaintext: ");  // Text to encrypt

    printf("ciphertext: %s\n", Encrypt(argv[1], wordToEncrypth));    //Encrypted text

    return 0;
}

int IsAlphabetical(string str)
{
    //IsNotNumeric : Check if every character in the argument is a letter


    for (int i = 0; str[i] != '\0'; i++)
    {
        //If some of the digits of the command line argument is numerical,
        //      the function will end, returning an 0
        if (!((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90)))
        {
            return 0;
        }
    }
    return 1;
}

int RepeatedLetters(string str)
{
    // RepeatedLetters : If a letter is repeated, return a 1, otherwise, a 0

    for (int i = 0; str[i] != '\0'; i++)
    {
        //  Take one letter...
        char currentLetter = tolower(str[i]);
        for (int j = i + 1; str[j] != '\0'; j++)
        {
            //  ...and compare it with all the rest of the letters
            if (currentLetter == tolower(str[j]))
            {
                return 1;
            }
        }
    }

    return 0;
}

int CheckArgument(string str)
{
    return (IsAlphabetical(str) == 1 && strlen(str) == 26 && !RepeatedLetters(str));
}

string Encrypt(string key, string str)
{
    string output = str;

    for (int i = 0; str[i] != '\0'; i++)
    {
        //  If the letter is uppercase, look for the corresponding letter according with the key, subtracting 65 (65 is the ASCII code for 'A')...
        if (str[i] >= 65 && str[i] <= 90)
        {
            output[i] = toupper(key[(int)str[i] - 65]);
        }

        //  ...if it's lowercase, subtracting 97 (97 is the ASCII code for 'a')...
        else if (str[i] >= 97 && str[i] <= 122)
        {
            output[i] = tolower(key[(int)str[i] - 97]);
        }
        //  ...else, just left the same symbol
        else
        {
            output[i] = str[i];
        }
    }

    return output;
}