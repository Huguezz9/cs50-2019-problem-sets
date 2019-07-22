#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
		for (int i = 0, n = strlen(argv[1]); i < n; ++i)
		{
	  if (argv[1][i] < 48 || argv[1][i] > 57)
	  {
	  	printf("Usage: ./caesar key\n");
	    return 1;
	  }
	    else
	    {
	        int key = atoi(argv[1]);
	    }
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");
    for (int j = 0, n = strlen(plaintext); j < n; ++j)
    {
        if (isalpha(plaintext[j]))
        {
            if (isupper(plaintext[j]))
            {
                printf("%c", (((plaintext[j] - 65) + key) % 26) + 65);
            }
            else
            {
                printf("%c", (((plaintext[j] - 97) + key) % 26) + 97);
            }
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}
