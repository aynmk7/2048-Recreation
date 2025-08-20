#include "projectfunc.h"



int main() {

        printf("\nWelcome to the remake of the game 2048! \n");
    // Initialize the tracker
    GameTracker tracker = initializeTracker();

    // Start the game logic
    GameStats currentGame = initializeGame(tracker.games[tracker.totalGames]);

    char input;
    while (1) {
        printBoard(currentGame);
        printf("Select 'n' (new game), 't' (view scores), 'q' (quit), \n'w' (up), 'a' (left), 'd' (right), 's' (down): ");
        scanf(" %c", &input);

        if (input == 'q') {
            printf("Exiting the game. Thank you for playing!\n");
            break;
        } else if (input == 'n') {
            // Start a new game
            tracker.scores[tracker.totalGames] = currentGame.score;
            tracker.totalGames++;
            currentGame = initializeGame(currentGame); // Initializing it
            tracker.games[tracker.totalGames] = currentGame;
            printf("New game started!\n");
        } else if (input == 't') {
            displayScores(tracker);
        } else if (input == 'd' || input == 'w' || input == 's' || input == 'a') {
            // Play current game
            currentGame = play(currentGame, &tracker, input);
        } else printf("Invalid input! Try again\n");
    }

    return 0;
}
