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
        if ((word[lowerLimit - 1] == letter && word[upperLimit - 1] != letter) ||
            (word[lowerLimit - 1] != letter && word[upperLimit - 1] == letter))
        {
            ++validPasswordCounter;
        }
    }

    cout << validPasswordCounter << endl;

    return 0;
}