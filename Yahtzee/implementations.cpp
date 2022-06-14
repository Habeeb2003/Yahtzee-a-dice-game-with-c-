#include "prototypes.h"
#include <stdio.h>

// function called when user types quit
void quitGame(int finalScore, int scores[]) {
    int sumOfFirstSix = 0;
    for (int i = 0; i < 6; i++)
    {
        sumOfFirstSix += scores[i];
    }
    printStraightLine(37);
    printf("\n");
    printf("Final Score is: %d\n", finalScore);
    if (sumOfFirstSix >= 63)
    {
        int totalScore = sumOfFirstSix + finalScore;
        printf("Bonus Point is: %d\n", sumOfFirstSix);
        printf("Total Score is: %d\n", totalScore);
    }
    printStraightLine(37);
    printf("\n");
    printf("\n");
    printStraightLine(37);
    printf("\n");
    printf("         Quitting the game!          ");
    printf("\n");
    printf("         Good Bye                    ");
    printf("\n");
    printStraightLine(37);
}

//function that changes the update the value of the scores in the score array
void changeInt(int arr[], int score, int categoNo) {
    arr[categoNo - 1] = score;
}
//Display Score Sheet
void displayScoreSheet(const char head[], int scores[], int size) {
    int length = (37 / 2) - ((strlen(head) + 2) / 2);
    int sn[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
    const char* a[11];
    a[0] = "1s";
    a[1] = "2s";
    a[2] = "3s";
    a[3] = "4s";
    a[4] = "5s";
    a[5] = "6s";
    a[6] = "3 of a kind";
    a[7] = "4 of a kind";
    a[8] = "Full House";
    a[9] = "Yahtzee";
    a[10] = "Chance";
    printf("\n");
    for (int i = 0; i <= (37 - strlen(head)); i++)
    {
        (i == length) ? printf("%s", head) : printf("-");
    }
    printf("\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%d- %s: %d\n", sn[i], a[i], scores[i]);
    }
    printStraightAsterik(37);
    printf("\n");
    printf("\n");
    printStraightAsterik(37);
    printf("\n");
}
void printRow(int len, int row[]) {
    for (int i = 0; i < len; i++)
    {
        printf("%c", row[i]);
    }
}
// function prints the a graphical representation of the dice values
void printDiceTable(int val[], int width, int diceRollNo) {
    printStraightLine(width);
    printf("\nThis is roll #%d\n", diceRollNo);
    printStraightLine(width);
    char diceRep1[6][6] = { {"-----"},{"|   |"},{"|   |"},{"|   |"},{"-----"} };
    char diceRep2[6][6] = { {"-----"},{"|   |"},{"|   |"},{"|   |"},{"-----"} };
    char diceRep3[6][6] = { {"-----"},{"|   |"},{"|   |"},{"|   |"},{"-----"} };
    char diceRep4[6][6] = { {"-----"},{"|   |"},{"|   |"},{"|   |"},{"-----"} };
    char diceRep5[6][6] = { {"-----"},{"|   |"},{"|   |"},{"|   |"},{"-----"} };
    char(*ptr)[6];
    ptr = diceRep1;
    for (int i = 0; i < 5; i++)
    {
        switch (i)
        {
        case 0:
            ptr = diceRep1;
            break;
        case 1:
            ptr = diceRep2;
            break;
        case 2:
            ptr = diceRep3;
            break;
        case 3:
            ptr = diceRep4;
            break;
        case 4:
            ptr = diceRep5;
            break;
        }
        switch (val[i])
        {
        case 1:
            *(*(ptr + 2) + 2) = '*';
            break;
        case 2:
            *(*(ptr + 1) + 1) = '*';
            *(*(ptr + 3) + 3) = '*';
            break;
        case 3:
            *(*(ptr + 1) + 1) = '*';
            *(*(ptr + 2) + 2) = '*';
            *(*(ptr + 3) + 3) = '*';
            break;
        case 4:
            *(*(ptr + 1) + 1) = '*';
            *(*(ptr + 1) + 3) = '*';
            *(*(ptr + 3) + 1) = '*';
            *(*(ptr + 3) + 3) = '*';
            break;
        case 5:
            *(*(ptr + 1) + 1) = '*';
            *(*(ptr + 1) + 3) = '*';
            *(*(ptr + 2) + 2) = '*';
            *(*(ptr + 3) + 1) = '*';
            *(*(ptr + 3) + 3) = '*';
            break;
        case 6:
            *(*(ptr + 1) + 1) = '*';
            *(*(ptr + 1) + 3) = '*';
            *(*(ptr + 2) + 1) = '*';
            *(*(ptr + 2) + 3) = '*';
            *(*(ptr + 3) + 1) = '*';
            *(*(ptr + 3) + 3) = '*';
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\n");
        for (int j = 0; j < 5; j++)
        {
            printf("%c", diceRep1[i][j]);
        }
        printf("\t");
        for (int j = 0; j < 5; j++)
        {
            printf("%c", diceRep2[i][j]);
        }
        printf("\t");
        for (int j = 0; j < 5; j++)
        {
            printf("%c", diceRep3[i][j]);
        }
        printf("\t");
        for (int j = 0; j < 5; j++)
        {
            printf("%c", diceRep4[i][j]);
        }
        printf("\t");
        for (int j = 0; j < 5; j++)
        {
            printf("%c", diceRep5[i][j]);
        }
    }
    printf("\n");
    printStraightLine(37);
}
//function ask player which category they want to score
int askWhereToScore(int arr[], size_t len) {

    bool correctInput = true;
    bool scoreTaken = false;
    const char* whatToAskFor = "\nChoose an option you want to score\n\nEnter a value between (1-11): ";
    int scoreChoice;
    while (true)
    {
        if (correctInput == true)
        {
            whatToAskFor = "\nChoose an option you want to score\n\nEnter a value between (1-11): ";
            if (scoreTaken == true)
            {
                whatToAskFor = "\nYou entered a score choice that have already been chosen.\n\n Choose another score: ";
                scoreTaken = false;
                printStraightAsterik(37);
            }
            printf("%s", whatToAskFor);
            scanf("%d", &scoreChoice);
            for (int i = 0; i < len; i++)
            {
                if (arr[i] == scoreChoice)
                {
                    scoreTaken = true;
                    break;
                }
            }
            if (scoreTaken == true)
            {
                continue;
            }
            correctInput = false;
        }
        else {
            whatToAskFor = "Invalid input, Enter a value between (1-11): ";
            if (scoreTaken == true)
            {
                whatToAskFor = "You entered a score choice that have already been chosen.\n\n Choose another score: ";
                scoreTaken = false;
                
            }
            printf("\n");
            printStraightAsterik(37);
            printf("\n\n%s", whatToAskFor);
            scanf("%d", &scoreChoice);
            for (int i = 0; i < len; i++)
            {
                if (arr[i] == scoreChoice)
                {
                    scoreTaken = true;
                    break;
                }
            }
            if (scoreTaken == true)
            {
                continue;
            }
        }

        for (int i = 1; i < 12; i++)
        {
            if (scoreChoice == i)
            {
                correctInput = true;
                break;
            }
        }
        if (correctInput == true)
        {
            break;
        }
    }

    printf("\n");
    printStraightAsterik(37);
    printf("\n\n");
    printStraightLine(37);
    return scoreChoice;
}
//count how many times a die value occured in one roll
int countHowManyTimesOccurred(int arr[], int no, int val) {
    int count = 0;
    for (int i = 0; i < no; i++)
    {
        if (arr[i] == val)
        {
            count++;
        }
    }
    return count;
}
//returns the sum of all the dice values
int returnSumOfDice(int arr[], int n) {
    int points = 0;
    for (int i = 0; i < n; i++)
    {
        points += arr[i];
    }
    return points;
}
//returns the points scored by the player
int scorePoint(int scoreParam, int diceVals[]) {
    bool seenAnyOfscoreParam = false;
    int points = 0;
    int n = 5;
    if (scoreParam == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (diceVals[i] == 1)
            {
                points += 1;
            }
        }
        return points;
    }
    if (scoreParam == 2)
    {
        for (int i = 0; i < n; i++)
        {
            if (diceVals[i] == 2)
            {
                points += 2;
            }
        }
        return points;
    }
    if (scoreParam == 3)
    {
        for (int i = 0; i < n; i++)
        {
            if (diceVals[i] == 3)
            {
                points += 3;
            }
        }
        return points;
    }
    if (scoreParam == 4)
    {
        for (int i = 0; i < n; i++)
        {
            if (diceVals[i] == 4)
            {
                points += 4;
            }
        }
        return points;
    }
    if (scoreParam == 5)
    {
        for (int i = 0; i < n; i++)
        {
            if (diceVals[i] == 5)
            {
                points += 5;
            }
        }
        return points;
    }
    if (scoreParam == 6)
    {
        for (int i = 0; i < n; i++)
        {
            if (diceVals[i] == 6)
            {
                points += 6;
            }
        }
        return points;
    }
    if (scoreParam == 7)
    {
        int noOfSameDice = 0;
        for (int i = 0; i < n; i++)
        {
            int count = countHowManyTimesOccurred(diceVals, n, diceVals[i]);
            
            if (count > noOfSameDice)
            {
                noOfSameDice = count;
            }
        }
        if (noOfSameDice >= 3)
        {
            points = returnSumOfDice(diceVals, n);
        }
        return points;
    }
    if (scoreParam == 8)
    {
        int noOfSameDice = 0;
        for (int i = 0; i < n; i++)
        {
            int count = countHowManyTimesOccurred(diceVals, n, diceVals[i]);
            if (count > noOfSameDice)
            {
                noOfSameDice = count;
            }
        }
        if (noOfSameDice >= 4)
        {
            points = returnSumOfDice(diceVals, n);
        }
        return points;
    }
    if (scoreParam == 9)
    {
        bool seenThree = false;
        bool seenTwo = false;
        for (int i = 0; i < n; i++)
        {
            int count = countHowManyTimesOccurred(diceVals, n, diceVals[i]);
            if (count == 3)
            {
                seenThree = true;
            }
            if (count == 2)
            {
                seenTwo = true;
            }
            if (seenThree == true && seenTwo == true) {
                points = 25;
                break;
            }
        }
        return points;
    }
    if (scoreParam == 10)
    {
        for (int i = 0; i < n; i++)
        {
            int count = countHowManyTimesOccurred(diceVals, n, diceVals[i]);
            if (count == 5)
            {
                points = 50;
            }
        }
        return points;
    }
    if (scoreParam == 11)
    {
        points = returnSumOfDice(diceVals, n);
        return points;
    }
    return points;
}
// prints straight lines
void printStraightLine(int width) {
    for (int i = 0; i < width; i++)
    {
        printf("-");
    }
}
//prints straight asterisks
void printStraightAsterik(int width) {
    for (int i = 0; i < 37; i++)
    {
        printf("*");
    }
}
// ask player if they want to roll, score or quit
char* askRollScoreOrQuit(const char* ptr) {
    char* playChoice = (char *)malloc(sizeof(char) * 7);
    char choice[7];
    printf("\n%s", ptr);
    scanf("%s", &choice);
    strcpy(playChoice, choice);
    printf("\n");
    return playChoice;
}
// displays the name of the game "Rollzee"
void displayNameOfGame(int width) {
    char gameName[] = "Rollzee";
    int length = (width / 2) - ((strlen(gameName) + 2) / 2);
    for (int i = 0; i < width; i++)
    {
        printf("*");
    }
    printf("\n");
    for (int i = 0; i <= (width - strlen(" Rollzee ")); i++)
    {
        (i == length) ? printf(" %s ", gameName) : printf("*");
    }
    printf("\n");
    for (int i = 0; i < width; i++)
    {
        printf("*");
    }
    printf("\n");
}
//rolling of the dice function
void rolldice(struct Dices *dice, int currentRound, int previousRound) {
    
    for (int i = 0; i < 5; i++)
    {
        int diceVal = (rand() % 6) + 1;
        dice->values[i] = diceVal;
    }
    printf("\ncurrent round: %d,  previous round: %d \n", currentRound, previousRound);
    if (currentRound == previousRound)
    {
        dice->rollNumber ++;
    }
    else {
        dice->rollNumber = 1;
    }
    previousRound = currentRound;
    printf("\n %d \n", dice.rollNumber);
    printDiceTable(dice.values, 37, dice.rollNumber);
}
// displays welcome message with the name of the player
void displayWelcomeMessage(int width, char player[]) {
    int howManyTimesRolled;
    printf("\n");
    for (int i = 0; i < 37; i++)
    {
        printf("*");
    }
    printf("\n");
    char welcomeMessage[23] = " Welcome ";
    strcat(welcomeMessage, player);
    int f = (width / 2) - (strlen(welcomeMessage) / 2);
    for (int i = 0; i < (width - strlen(welcomeMessage)); i++)
    {
        (i == f) ? printf("%s ", welcomeMessage) : printf("*");
    }
    printf("\n");
    for (int i = 0; i < 37; i++)
    {
        printf("*");
    }
    printf("\n\n");
}
char test() {
    char p = 'a';
    return p;
}
