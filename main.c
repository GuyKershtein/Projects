#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HangMan.h"

int main(void) {
    char words[100][7] = {"accept", "access", "acting", "active", "advice", "almost", "always", "amount", "animal", "answer",
                          "appeal", "arrive", "artist", "aspect", "attack", "author","backed", "beauty", "became","become",
                          "before", "behind", "belief", "better","beyond", "bishop", "border","bottle", "bottom", "branch",
                          "breach", "bridge","budget", "button", "camera","cancer", "career", "castle", "casual", "caught",
                          "center", "chance", "charge","choice", "church", "circle", "client", "closed","coffee", "column",
                          "combat","common", "corner", "county", "course", "covers","create", "credit", "danger", "dealer",
                          "debate", "decide", "defend", "degree","demand", "depend", "design", "detail", "device", "dinner",
                          "doctor", "dollar", "domain", "double", "driver", "during", "easily", "effect", "effort", "either",
                          "energy", "engage", "engine", "enough", "escape", "estate", "ethics", "exceed","except", "extend",
                          "fabric", "facing", "factor", "failed", "fairly", "family", "famous", "faster", "father", "figure"};

    srand(time(NULL));
    int random_index = rand() % 100;
    int i = 0;
    int counter = 0;
    char guess;
    char display_guessed[6] = {'_','_','_','_','_','_'};
    char replay;

    printf("Welcome to Hang Man!\n");
    printf("You will now guess the letters ofa six letter word.\n");
    printf("Be careful! oe someone might pay with their life!\n");

    while (counter < 10) {
        printf("Enter a character: ");
        scanf(" %c", &guess);

        if (guess == words[random_index][i]) {
            display_guessed[i] = words[random_index][i];
        }else {
            counter++;
        }

        for (int j = 0; j < 6; j++) {
            printf(" %c", display_guessed[j]);
        }

        printf("\n");

        if (counter == 1) {
            hangman1();
        } else if (counter == 2) {
            hangman2();
        } else if (counter == 3) {
            hangman3();
        } else if (counter == 4) {
            hangman4();
        } else if (counter == 5) {
            hangman5();
        } else if (counter == 6) {
            hangman6();
        } else if (counter == 7) {
            hangman7();
        } else if (counter == 8) {
            hangman8();
        } else if (counter == 9) {
            hangman9();
        } else if (counter == 10) {
            hangman10();
        }
        i++;
        if (counter == 10) {
            printf("Oh No! someone is dead, and it's because of you!\n");
            printf("would you like to kill someone else or actually guess the word?\n");
            printf("Play again? y/n:");
            scanf(" %c", &replay);
            if (replay == 'y') {
                counter = 0;
                srand(time(NULL));
                random_index = rand() % 100;
                for (int j = 0; j < 6; j++) {
                    display_guessed[j] = '_';
                }
            }else if (replay == 'n') {
                printf("See you later!\n");
            }
        }
    }
}