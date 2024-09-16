#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LEN 20
#define MAX_TRIES 6

int main(void) {
    char words[][MAX_WORD_LEN] = {"apple", "banana", "cherry", "durian", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
    int num_words = sizeof(words) / sizeof(words[0]);
void print_man(int incorrect_guesses);
    srand(time(NULL));
    int random_index = rand() % num_words;
    char *word_to_guess = words[random_index];

    int word_len = strlen(word_to_guess);
    char guessed_letters[MAX_WORD_LEN] = {0};
    int num_guesses = 0;

    printf("Welcome to Hangman!\n\n");

    int i;
    while (num_guesses < MAX_TRIES) {
        printf("The word is: ");
        for (i = 0; i < word_len; i++) {
            if (guessed_letters[i]) {
                printf("%c", word_to_guess[i]);
            } else {
                printf("-");
            }
        }
        printf("\n");

        printf("Guess a letter: ");
        char guess;
        scanf(" %c", &guess);
        guess = tolower(guess);

        int found_letter = 0;
        for (i = 0; i < word_len; i++) {
            if (word_to_guess[i] == guess) {
                guessed_letters[i] = 1;
                found_letter = 1;
            }
        }

        if (found_letter) {
            printf("Good guess!\n");
        } else {
            printf("Sorry, that letter is not in the word.\n");
            print_man(num_guesses);
            num_guesses++;
        }

        int num_letters_guessed = 0;
        for (i = 0; i < word_len; i++) {
            if (guessed_letters[i]) {
                num_letters_guessed++;
            }
        }

        if (num_letters_guessed == word_len) {
            printf("Congratulations, you guessed the word!\n");
            return 0;
        }
    }

    printf("Sorry, you ran out of guesses. The word was %s.\n", word_to_guess);

    return 0;
}
void print_man(int incorrect_guesses)
{
    printf("\n");
    switch (incorrect_guesses) {
        case 0:
            printf("  O  \n");
            break;
        case 1:
            printf("  O  \n");
            printf("  |  \n");
            break;
        case 2:
            printf("  O  \n");
            printf(" /|  \n");
            break;
        case 3:
            printf("  O  \n");
            printf(" /|\\ \n");
            break;
        case 4:
            printf("  O  \n");
            printf(" /|\\ \n");
            printf(" /   \n");
            break;
        case 5:
            printf("  O  \n");
            printf(" /|\\ \n");
            printf(" / \\ \n");
            break;
    }
}

