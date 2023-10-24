// Author: Jacob Xie
// Section: 1010
// Fun game of hangman!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_COUNT 1000
#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 128

#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )

const char HANGMAN_FRAMES[7][256] = {"\n  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n\n", "\n  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n\n"};

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
    FILE *fp;
    fp = fopen("words.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return (-1);
    }

    char* words[MAX_WORD_COUNT];
    char buffer[MAX_LINE_LENGTH];
    int index = 0;
    while (index < MAX_WORD_COUNT && fgets(buffer, MAX_LINE_LENGTH, fp) != NULL)
    {
        words[index] = strdup(buffer);
        index++;
    }

    fclose(fp);

    char word[MAX_WORD_LENGTH];
    srand(time(NULL));
    strcpy(word, words[rand() % index]);

    int size = strlen(word) - 1; // Subract one to remove the new-line byte
    char show[size + 1];
    memset(show, '\0', size + 1);

    int frame = 0;

    for (int i = 0 ; i < size ; i++)
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
            printf("Couldn't find character '%c' in the word!\n", guess);

            if (frame == 5)
            {
                printf("%s", HANGMAN_FRAMES[6]);
                printf("Look what you've done...\n");
                printf("%s is dead because of you :(\n", name);
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