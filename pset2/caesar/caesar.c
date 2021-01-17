#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>


int IsNumeric(string str);      //Check if every character in the argument is numerical
string Encrypt(int key, string str);     //Encrypt the string passed as second argument with a key passed as first argument

int main(int argc, string argv[])
{
    //If the number of arguments is different than 1, an error will be
    //      printed and the program will end and return an 1
    if (argc != 2)
    {
        printf("ERROR:\nNumber of arguments different than expected\n\n");
        return 1;
    }

    const string cipherKey = argv[1]; // The command line argument

    //Check if every character in the argument is numerical
    if (IsNumeric(cipherKey) == 0)
    {
        printf("ERROR:\nNon-Numerical argument\n\n");
        return 1;
    }

    int encypthKey = atoi(cipherKey); // Encrypt key converted into an integer

    string wordToEncrypth = get_string("plaintext: ");  // Text to encrypt

    printf("ciphertext: %s\n", Encrypt(encypthKey, wordToEncrypth));    //Encrypted text
    return 0;
}



int IsNumeric(string str)
{
    //IsNumeric : Check if every character in the argument is numerical
    for (int i = 0; str[i] != '\0'; i++)
    {
        //If some of the digits of the command line argument is not numerical,
        //      an error message will be printed and the program will end, returning an 1
        if (!(str[i] >= 48 && str[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

string Encrypt(int key, string str)
{
    //  Encrypt the text passed as second parameter according with the key passed as first arg

    string output = str;
    const int strLen = strlen(str);

    for (int i = 0; i < strLen; i++)
    {
        int letterASCII = (int)str[i];  // TheASCII code of the letter being processed

        //  If the current letter is uppercase, do one type of operation...
        if (letterASCII >= 65 && letterASCII <= 90)
        {
            int originalASCII = letterASCII - 64;
            output[i] = (char)(64 + ((key + originalASCII) % 26));
        }

        //  ...if it's lowercase, do another type...
        else if (letterASCII >= 97 && letterASCII <= 122)
        {
            int originalASCII = letterASCII - 96;
            output[i] = (char)(96 + ((key + originalASCII) % 26));
        }
        //  ...else, just left the same symbol
        else
        {
            output[i] = str[i];
        }
    }

    return (output);
}