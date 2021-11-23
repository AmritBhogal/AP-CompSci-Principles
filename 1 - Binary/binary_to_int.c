#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define BYTE_CHARACTER_LENGTH   9

int main()
{
    printf("Input binary number: ");
    char buffer[BYTE_CHARACTER_LENGTH]; //Max 8 chars + null char
    scanf("%s", buffer);
    int result = 0;

    for (size_t i = BYTE_CHARACTER_LENGTH; i >= 0; --i)
    {
        char ch = buffer[i];
        switch (ch)
        {
        default:
        case '\0':
        case '0':
            continue;
        case '1':
            long num = roundtol(pow(2, BYTE_CHARACTER_LENGTH - (i + 2)));
            result += num;
            continue;
        }
    }

    printf("Result: %d\n", result);
}

