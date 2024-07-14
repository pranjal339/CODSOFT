#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numberToGuess, guess, attempts = 0;
    
    
    srand(time(0));
    
    
    
    numberToGuess = rand() % 100 + 1;
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess a number between 1 and 100\n");
    
    do {
        
        printf("Enter your guess: ");
        scanf("%d", &guess);
        

        attempts++;
        
        
        if (guess == numberToGuess) {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", numberToGuess, attempts);
        } else if (guess < numberToGuess) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }
    } while (guess != numberToGuess);
    
    return 0;
}
