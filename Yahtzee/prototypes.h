#pragma once

// headers
#define _CRT_SECURE_NO_WARNINGS
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>    
#include <conio.h>  
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// prototypes

int countHowManyTimesOccurred(int arr[], int no, int val);
void quitGame(int finalScore, int scores[]);
char* askRollScoreOrQuit(const char* ptr);
void printRow(int len, int row[]);
void displayScoreSheet(const char head[], int scores[], int size);
int askWhereToScore(int arr[], size_t len);
void printDiceTable(int val[], int width, int diceRollNo);
void printStraightLine(int width);
void printStraightAsterik(int width);
void rolldice(struct Dices *dice, int currentRound, int previousRound);
int scorePoint(int scoreParam, int diceVals[]);
void displayNameOfGame(int width);
int returnSumOfDice(int arr[], int n);
void changeInt(int arr[], int score, int categoNo);
void displayWelcomeMessage(int width, char player[]);

#endif