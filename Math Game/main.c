//
//  main.c
//  Math Game
//
//  Created by Oliver Andrews on 2015-05-05.
//  Copyright (c) 2015 Oliver Andrews. All rights reserved.
//

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int numberOfLives;
    int score;
    int answer;
    char loseLives;
} Player;

int randomNumber(); // 1 to 20
int generateQuestionAndAnswer();
void play(Player *player);
void showScores(Player *player1, Player *player2);

int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    
    Player player1;
    Player *player1Pointer;
    player1Pointer = &player1;
    player1.index = 1;
    player1.numberOfLives = 3;
    player1.score = 0;
    player1.answer = 0;
    player1.loseLives = 'N';
    
    Player player2;
    Player *player2Pointer;
    player2Pointer = &player2;
    player2.index = 2;
    player2.numberOfLives = 3;
    player2.score = 0;
    player2.answer = 0;
    player2.loseLives = 'N';
    
    while (player1.numberOfLives > 0 && player2.numberOfLives > 0) {
        play(&player1);
        showScores(&player1, &player2);
        play(&player2);
        showScores(&player1, &player2);
    }
    
    if (player1.numberOfLives == 0 && player2.numberOfLives == 0) {
        printf("Tie!\n");
    } else if (player2.numberOfLives == 0) {
        printf("Player 1 won!\n");
    } else if (player1.numberOfLives == 0) {
        printf("Player 2 won!\n");
    }
    
    return 0;
}

// Function bodies

int randomNumber() {
    int r = rand() % 20 + 1;
    return r;
}

int generateQuestionAndAnswer(int playerNumber) {
    int num1 = randomNumber();
    int num2 = randomNumber();
    printf("Player %d: What does %d plus %d equal?\n", playerNumber, num1, num2);
    return num1 + num2;
}

void play(Player *player) {
    int correctAnswer = generateQuestionAndAnswer(player->index);
    int answer;
    scanf("%d", &answer);
    player->answer = answer;
    if (player->answer == correctAnswer) {
        player->score++;
        player->loseLives = 'N';
    } else {
        player->numberOfLives--;
        player->score--;
        player->loseLives = 'Y';
    }
}

void showScores(Player *player1, Player *player2) {
    if (player1->loseLives == 'Y' | player2->loseLives == 'Y') {
        printf("Player1 score: %d\nPlayer2 score: %d\n", player1->score, player2->score);
        player1->loseLives = 'N';
        player2->loseLives = 'N';
    }
    
}
