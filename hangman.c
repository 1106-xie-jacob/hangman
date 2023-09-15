// Author: Jacob Xie
// Section: 1010

#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_COUNT 1000
#define MAX_LINE_LENGTH 1000

int main() {
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
    }

    return 0;
}