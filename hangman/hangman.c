// C program to implement hangman game
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6

// Struct to hold a word and its hint
struct WordWithHint {
    char word[MAX_WORD_LENGTH];
    char hint[MAX_WORD_LENGTH];
};

// Function to display the current state of the word
void display_word(const char word[], const bool guessed[]);

// Function to draw the hangman
void draw_hangman(int tries);

// driver code
int main()
{
    // Seed the random number generator with the current
    // time
    srand(time(NULL));
    // Array of words with hints
    struct WordWithHint word_list[] = {
        { "geeksforgeeks", "Computer coding" },
        { "elephant", "A large mammal with a trunk" },
        { "pizza", "A popular Italian dish" },
        { "beach", "Sandy shore by the sea" },
        // Add more words and hints here
    };

    // Select a random word from the list
    int word_index = rand() % 4;

    const char* secret_word = word_list[word_index].word;
    const char* hint = word_list[word_index].hint;

    int word_length = strlen(secret_word);
    char guessed_word[MAX_WORD_LENGTH] = { 0 };
    bool guessed_letters[26] = { false };

    printf("Welcome to Hangman!\n");
    printf("Hint: %s\n", hint);

    int tries = 0;

    while (tries < MAX_TRIES) {
        printf("\n");
        display_word(guessed_word, guessed_letters);
        draw_hangman(tries);

        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        if (guessed_letters[guess - 'a']) {
            printf("You've already guessed that letter. "
                   "Try again.\n");
            continue;
        }

        guessed_letters[guess - 'a'] = true;

        bool found = false;
        for (int i = 0; i < word_length; i++) {
            if (secret_word[i] == guess) {
                found = true;
                guessed_word[i] = guess;
            }
        }

        if (found) {
            printf("Good guess!\n");
        }
        else {
            printf("Sorry, the letter '%c' is not in the "
                   "word.\n",
                   guess);
            tries++;
        }

        if (strcmp(secret_word, guessed_word) == 0) {
            printf("\n_congratulations! You've guessed the "
                   "word: %s\n",
                   secret_word);
            break;
        }
    }

    if (tries >= MAX_TRIES) {
        printf("\n_sorry, you've run out of tries. The word "
               "was: %s\n",
               secret_word);
    }

    return 0;
}

void display_word(const char word[], const bool guessed[])
{
    printf("Word: ");
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessed[word[i] - 'a']) {
            printf("%c ", word[i]);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n");
}

void draw_hangman(int tries)
{
    const char* hangman_parts[]
        = { "     _________",    "    |         |",
            "    |         O",   "    |        /|\\",
            "    |        / \\", "    |" };

    printf("\n");
    for (int i = 0; i <= tries; i++) {
        printf("%s\n", hangman_parts[i]);
    }
}
