#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int shift(char c);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");

        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword\n");

                return 1;
            }
        }
    }
    string k = argv[1];
    int lenk = strlen(k);

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");
    for (int i = 0, index = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", (plaintext[i] - 'A' + toupper(k[index]) - 'A') % 26 + 'A');
            }
            else
            {
                printf("%c", (plaintext[i] - 'a' + toupper(k[index]) - 'A') % 26 + 'a');
            }
            index = (index + 1) % lenk;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

int shift(char c)
{
    //If its a upper case
    if (c > 64 && c < 91)
    {
        return c - 65;
    }
    //If its lower case
    else if (c > 96 && c < 123)
    {
        return c - 97;
    }
    return 0;
}
