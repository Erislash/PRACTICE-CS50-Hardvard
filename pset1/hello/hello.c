#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Main Function
    string name = get_string("What's your name? ");
    printf("hello, %s", name);
}