
#include "./prototypes.h"


// main function
int main() {
    srand(time(NULL));
    //variables
    int width = 37;
    char playerName[14];
    int round = 11;
    int currentRound = 1;
    int previousRound = 1;
    int finalScore = 0;
    int choosenDice[5];
    char* playerChoice;
    char* previousPlayerChoice;
    int scores[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
    int chosenCate[11];
    bool hasCompletedaRound;
    bool hasRolledThreeTimes = false;
    int rNo = 0;
    size_t  lenCC = sizeof(chosenCate) / sizeof(int);
    struct Dices {
        int values[5];
        int rollNumber;
    } dice;
    dice.values[0] = 0;
    dice.values[1] = 0;
    dice.values[2] = 0;
    dice.values[3] = 0;
    dice.values[4] = 0;
    dice.rollNumber = 0;
    displayNameOfGame(width);
    printf("\nEnter your name to start the game!\nName: ");
    scanf("%s", &playerName);
    displayWelcomeMessage(width, playerName);
    bool correctInput = true;
    const char* whatToAskFor = "Do you want to roll, score or quit?\n\nEnter (roll / score / quit): ";
    // keep asking player for input untill player types quit or finish all rounds
    while (true)
    {
        if (correctInput == true)
        {
            whatToAskFor = "Do you want to roll, score or quit?\n\nEnter (roll / score / quit): ";
            playerChoice = askRollScoreOrQuit(whatToAskFor);
        }
        else
        {
            whatToAskFor = "Invalid Input,  Enter (roll / score): ";
            playerChoice = askRollScoreOrQuit(whatToAskFor);
        }
        // checks if the player types "roll"
        if (strcmp(playerChoice, "roll") == 0)
        {
            correctInput = true;
            rolldice(dice, currentRound, previousRound);
        }
        // checks if the player types "score"
        else if (strcmp(playerChoice, "score") == 0) {
            correctInput = true;
            displayScoreSheet("Score Sheet", scores, 11);
            int categoryNo = askWhereToScore(chosenCate, lenCC);
            int score = scorePoint(categoryNo, dice.values);
            changeInt(scores, score, categoryNo);
            printf("\n");
            printf("\nScore %d was add to line %d on the score Sheet", score, categoryNo);
            printf("\n\n");
            printStraightAsterik(37);
            printf("\n");
            displayScoreSheet("Score Sheet", scores, 11);
            chosenCate[currentRound] = categoryNo;
            hasCompletedaRound = true;
            currentRound++;
            finalScore += score;
        }
        //checks if the player types "quit"
        else if (strcmp(playerChoice, "quit") == 0) {
            printStraightAsterik(37);
            displayScoreSheet("Score Sheet", scores, 11);
            quitGame(finalScore, scores);
            break;
        }
        else {
            correctInput = false;
        }
        // checks if all rounds are complete
        if (currentRound == 11)
        {
            printStraightAsterik(37);
            displayScoreSheet("Score Sheet", scores, 11);
            quitGame(finalScore,scores);
            break;
        }
        previousPlayerChoice = playerChoice;
    }
    //free(playerChoice);
    return 0;
}
