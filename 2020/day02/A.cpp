#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int lowerLimit;
    int upperLimit;
    char letter;
    char word[30];

    int validPasswordCounter{ 0 };
    while (4 == scanf_s("%d-%d %c: %s\n", &lowerLimit, &upperLimit, &letter, 1, word, (unsigned)_countof(word)))
    {
        int letterCounter{ 0 };

        for (int i{ 0 }; word[i] != '\0'; ++i)
        {
            if (word[i] == letter)
            {
                ++letterCounter;
            }
        }

        if (letterCounter >= lowerLimit && letterCounter <= upperLimit)
        {
            ++validPasswordCounter;
        }
    }

    cout << validPasswordCounter << endl;

    return 0;
}
