#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

// Array of slot emoji symbols (Using string pointers since emojis are multi-byte characters)
const char* SYMBOLS[] = {"🍒", "🍋", "🍊", "🍉", "👑"};
const int NUM_SYMBOLS = 5;

// Colors for the terminal text
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"

void print_reel(const char* sym) {
    // Check byte sequences to safely apply background/text colors
    if (sym[0] == '\xf0' && sym[1] == '\x9f' && sym[2] == '\x91' && sym[3] == '\x91') {
        printf(YELLOW "[ %s ]" RESET, sym); // 👑
    } else if (sym[0] == '\xf0' && sym[1] == '\x9f' && sym[2] == '\x8d' && sym[3] == '\x92') {
        printf(RED "[ %s ]" RESET, sym); // 🍒
    } else if (sym[0] == '\xf0' && sym[1] == '\x9f' && sym[2] == '\x8d' && sym[3] == '\x8b') {
        printf(GREEN "[ %s ]" RESET, sym); // 🍋
    } else if (sym[0] == '\xf0' && sym[1] == '\x9f' && sym[2] == '\x8d' && sym[3] == '\x89') {
        printf(MAGENTA "[ %s ]" RESET, sym); // 🍉
    } else {
        printf(BLUE "[ %s ]" RESET, sym); // 🍊
    }
}

int main() {
    int balance = 1000;
    int bet;

    // Seed the random number generator
    srand(time(NULL));

    printf("=== WELCOME TO TERMINAL SLOTS ===\n");
    printf("You start with $%d\n\n", balance);

    while (balance > 0) {
        printf("Current Balance: $%d\n", balance);
        printf("Enter your bet (0 to quit): ");

        if (scanf("%d", &bet) != 1) {
            printf("Invalid input!\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (bet == 0) {
            break;
        }

        if (bet > balance || bet < 0) {
            printf("Invalid bet amount!\n\n");
            continue;
        }

        balance -= bet;

        // Generate the definitive final outcome
        const char* reel1 = SYMBOLS[rand() % NUM_SYMBOLS];
        const char* reel2 = SYMBOLS[rand() % NUM_SYMBOLS];
        const char* reel3 = SYMBOLS[rand() % NUM_SYMBOLS];

        printf("\n");

        // --- SINGLE ROW SPINNING ANIMATION EFFECT ---
        for (int i = 0; i < 21; i++) {
            const char* anim1 = (i < 7)  ? SYMBOLS[rand() % NUM_SYMBOLS] : reel1;
            const char* anim2 = (i < 14) ? SYMBOLS[rand() % NUM_SYMBOLS] : reel2;
            const char* anim3 = (i < 20) ? SYMBOLS[rand() % NUM_SYMBOLS] : reel3;

            // Grid spacing updated to 6 dashes ('------') and 3 spaces between blocks
            // to match the exact visual width of the emoji boxes.
            printf("  ------   ------   ------\n  ");
            print_reel(anim1);
            printf("   ");
            print_reel(anim2);
            printf("   ");
            print_reel(anim3);
            printf("\n  ------   ------   ------\n");

            fflush(stdout);

            if (i < 20) {
                usleep(100000); // 100ms delay per frame
                printf("\033[3A\r"); // Pull cursor up 3 lines to overwrite cleanly
            }
        }
        printf("\n");
        // --------------------------------------------

        // Check win conditions universally using safe string matching (strcmp)
        if (strcmp(reel1, reel2) == 0 && strcmp(reel2, reel3) == 0) {
            int winnings = 0;
            if (strcmp(reel1, SYMBOLS[4]) == 0) { // "👑"
                winnings = bet * 10;
                printf(YELLOW "JACKPOT!! You won $%d!\n\n" RESET, winnings);
            } else {
                winnings = bet * 5;
                printf(GREEN "Three of a kind! You won $%d!\n\n" RESET, winnings);
            }
            balance += winnings;
        } else if (strcmp(reel1, reel2) == 0 || strcmp(reel2, reel3) == 0 || strcmp(reel1, reel3) == 0) {
            int winnings = bet * 2;
            printf(BLUE "Pair! You won $%d!\n\n" RESET, winnings);
            balance += winnings;
        } else {
            printf(RED "No match. Better luck next time!\n\n" RESET);
        }
    }

    printf("Game over! You walked away with $%d.\n", balance);
    return 0;
}
