// Author: Jacob Xie
// Section: 1010

#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_COUNT 1000
#define MAX_LINE_LENGTH 1000

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
    /* Text file reading stuff
    FILE *textfile;
    char *words;
    char line[MAX_LINE_LENGTH];

    words = (char*)malloc(MAX_WORD_COUNT * MAX_LINE_LENGTH * sizeof(char));

    // Open text file containing all possible words for hangman
    textfile = fopen("test.txt", "r");

    // Checks if the file exists
    if(textfile == NULL)
        return 1;

    // Adds every line to the words array and then closes the file
    int i = 0;
    while(fgets(line, MAX_LINE_LENGTH, textfile)) {
        strcpy(words[i++], line);
    }
    fclose(textfile);

    for (i = 0 ; i < MAX_WORD_COUNT ; i++) {
        int k;
        for (k = 0 ; k < strlen(words[i]) ; k++) {
            if (words[i][k] == 0x0A) {
                printf("THERE IS A NEW LINE!!!!!!!\n");
            } else {
                printf("%X ", words[i][k]);
            }
        }
        printf("\n");
    }*/

    char word[] = "testing";
    int size = sizeof(word) / sizeof(word[0]) - 1;
    char show[size + 1];

    for (int i = 0; i < size; i++)
    {
        show[i] = '_';
    }

    int remaining = size;

    while (remaining > 0) {
        char guess;
        printf("Enter your guess:\n");
        scanf(" %c", &guess);

        int found = characterGuess(guess, word, show, size);
        remaining -= found;

        if (found == 0) {
            printf("Couldn't find that character!\n");
        } else {
            printf("Found a matching character!\n");
        }

        printf("Current word: %s\n", show);
    }

    return 0;
}