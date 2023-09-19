// Author: Jacob Xie
// Section: 1010

#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_COUNT 1000
#define MAX_LINE_LENGTH 1000

char HANGMAN_FRAMES[7][256] = {"\n  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n\n"};

int characterGuess(char guess, char *word, char *show, int size)
{
    int change = 0;
    for (int i = 0; i < size; i++)
    {
        if (show[i] == '_')
        {
            if (word[i] == guess)
            {
                show[i] = guess;
                change++;
            }
            else
            {
                show[i] = '_';
            }
        }
    }

    return change;
}

int main()
{
    char word[] = "testing";
    int size = sizeof(word) / sizeof(word[0]) - 1;
    char show[size + 1];
    int frame = 0;

    for (int i = 0; i < size; i++)
    {
        show[i] = '_';
    }

    int remaining = size;

    system("cls");
    printf("Hello there! Let's play a game of hangman\n");
    printf("First of all, let's give hangman a name.\n");
    printf("Enter a name: ");
    char name[64];
    scanf("%63s", &name);
    printf("%s is such a good name! Let's hope you don't kill them.\n", name);
    printf("Press enter to start!\n");
    scanf("%*c%*c");

    system("cls");
    char guess;
    printf("Enter your guess:\n");
    scanf(" %c", &guess);
    system("cls");

    while (remaining > 0)
    {
        int found = characterGuess(guess, word, show, size);
        remaining -= found;

        if (found == 0)
        {
            printf("Couldn't find that character!\n");

            if (frame == 5)
            {
                printf("%s", HANGMAN_FRAMES[6]);
                printf("Look what you've done...\n");
                printf(name);
                printf(" is dead because of you :(\n");
                printf("The word was: %s\n", word);
                return 0;
            }

            frame++;
            printf("%s", HANGMAN_FRAMES[frame]);
            printf("Current word: %s\n", show);

            printf("Try another character:\n");
            scanf("%*c%c", &guess);
            system("cls");
        }
        else
        {
            printf("Found a matching character!\n");
            printf("%s", HANGMAN_FRAMES[frame]);

            if (remaining == 0)
            {
                printf("Good job! %s is still alive thanks to you\n", name);
                printf("The word was: %s\n", show);

                return 0;
            }

            printf("Current word: %s\n", show);

            printf("Try another character:\n");
            scanf("%*c%c", &guess);
            system("cls");
        }
    }

    return 0;
}