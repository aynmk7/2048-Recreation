// the game 2048
// the file where i declare the functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int board[4][4];            // Keeps track of board
    int score;                          // Keeps track of score
} GameStats;

typedef struct {
    GameStats games[100];  // Store multiple games
    int totalGames;        // Number of games played
    int scores[100];       // Keep track of scores for each game
} GameTracker;

GameStats play(GameStats games, GameTracker *tracker, char c);
GameStats placeSquares(GameStats games);
GameStats moveLeft(GameStats games);
GameStats moveUp(GameStats games);
GameStats moveRight(GameStats games);
GameStats moveDown(GameStats games);
void printBoard(GameStats games);
GameStats initializeGame(GameStats games);
void displayScores(GameTracker tracker);
GameTracker initializeTracker() ;
