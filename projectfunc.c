// the game 2048
// the functions file

#include "projectfunc.h"


GameStats initializeGame(GameStats games) {
    // Loop through all rows and columns to set board elements to 0
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            games.board[i][j] = 0;
        }
    }

    // Set the score to 0
    games.score = 0;

    // Place initial squares on the board
    games = placeSquares(games);
    games = placeSquares(games);

    return games;
}


GameStats placeSquares(GameStats games) {
    int x, y, attempts = 0;

    do {
        x = rand() % 4; // Generating a random coordinate for the random number
        y = rand() % 4;
        attempts++;
    } while (games.board[x][y] != 0 && attempts < 100);

    if (attempts < 100) {
        games.board[x][y] = (rand() % 2 + 1) * 2; // Ensuring similar probabilities per the online library
    }

    return games;
}

void printBoard(GameStats games) { // Printing the board
    printf("\nScore: %d\n", games.score);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (games.board[i][j] == 0) {
                printf(".\t");
            } else {
                printf("%d\t", games.board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void displayScores(GameTracker tracker) {
    printf("\nScores of all games played:\n");
    for (int i = 0; i < tracker.totalGames; i++) {
        printf("Game %d: %d\n", i + 1, tracker.scores[i]); // Displaying the scores using the struct
    }
    printf("\n");
}

GameStats play(GameStats games, GameTracker *tracker, char input) {

    switch (input) { // Switch cases for user selection
        case 'a':
            games = moveLeft(games);
            break;
        case 'w':
            games = moveUp(games);
            break;
        case 'd':
            games = moveRight(games);
            break;
        case 's':
            games = moveDown(games);
            break;
        default:
            printf("Invalid input. Try again.\n");
            return games;
    }

    games = placeSquares(games);  // Add a new square after a valid move
    return games;
}

GameStats moveLeft(GameStats games) {
    for (int i = 0; i < 4; i++) {
        int merged[4] = {0, 0, 0, 0};
        for (int j = 1; j < 4; j++) {
            int k = j;
            while (k > 0) { // Constraint for bounds
                if (games.board[i][k - 1] == 0 && games.board[i][k] != 0) { // checking if it can move left
                    games.board[i][k - 1] = games.board[i][k];
                    games.board[i][k] = 0;
                    k--;
                } else if (games.board[i][k - 1] == games.board[i][k] && !merged[k - 1] && games.board[i][k] != 0) { // Checking if it should combine or not
                    games.board[i][k - 1] *= 2;
                    games.score += games.board[i][k - 1];
                    games.board[i][k] = 0;
                    merged[k - 1] = 1;
                    break;
                } else {
                    break;
                }
            }
        }
    }
    return games;
}


// Same logic repeated for all these three, except changing the directions of right, up, or down
GameStats moveRight(GameStats games) {
    for (int i = 0; i < 4; i++) {
        int merged[4] = {0, 0, 0, 0};
        for (int j = 2; j >= 0; j--) {
            int k = j;
            while (k < 3) {
                if (games.board[i][k + 1] == 0 && games.board[i][k] != 0) {
                    games.board[i][k + 1] = games.board[i][k];
                    games.board[i][k] = 0;
                    k++;
                } else if (games.board[i][k + 1] == games.board[i][k] && !merged[k + 1] && games.board[i][k] != 0) {
                    games.board[i][k + 1] *= 2;
                    games.score += games.board[i][k + 1];
                    games.board[i][k] = 0;
                    merged[k + 1] = 1;
                    break;
                } else {
                    break;
                }
            }
        }
    }
    return games;
}

GameStats moveUp(GameStats games) {
    for (int j = 0; j < 4; j++) {
        int merged[4] = {0 ,0 ,0 ,0};
        for (int i = 1; i < 4; i++) {
            int k = i;
            while (k > 0) {
                if (games.board[k - 1][j] == 0 && games.board[k][j] != 0) {
                    games.board[k - 1][j] = games.board[k][j];
                    games.board[k][j] = 0;
                    k--;
                } else if (games.board[k - 1][j] == games.board[k][j] && !merged[k - 1] && games.board[k][j] != 0) {
                    games.board[k - 1][j] *= 2;
                    games.score += games.board[k - 1][j];
                    games.board[k][j] = 0;
                    merged[k - 1] = 1;
                    break;
                } else {
                    break;
                }
            }
        }
    }
    return games;
}

GameStats moveDown(GameStats games) {
    for (int j = 0; j < 4; j++) {
        int merged[4] = {0, 0,0,0};
        for (int i = 2; i >= 0; i--) {
            int k = i;
            while (k < 3) {
                if (games.board[k + 1][j] == 0 && games.board[k][j] != 0) {
                    games.board[k + 1][j] = games.board[k][j];
                    games.board[k][j] = 0;
                    k++;
                } else if (games.board[k + 1][j] == games.board[k][j] && !merged[k + 1] && games.board[k][j] != 0) {
                    games.board[k + 1][j] *= 2;
                    games.score += games.board[k + 1][j];
                    games.board[k][j] = 0;
                    merged[k + 1] = 1;
                    break;
                } else {
                    break;
                }
            }
        }
    }
    return games;
}


GameTracker initializeTracker() {
    GameTracker tracker;

    tracker.totalGames = 0;  // Initialize totalGames to 0

    // Initialize all game scores to 0
    for (int i = 0; i < 100; i++) {
        tracker.scores[i] = 0;
    }

    // Initialize all games
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                tracker.games[i].board[j][k] = 0;
            }
        }
        tracker.games[i].score = 0;  // Initialize scores for each game
    }

    return tracker;
}
