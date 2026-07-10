#include <stdio.h>
#include <stdlib.h> // this is a library function for using  rand and srand;
#include <time.h>
#include <limits.h>
#include <windows.h> // this is a library function for using emoji;

// Function Prototypes
int generateRandomNumber(int maxNumber);
void showWelcomeBanner(int maxNumber);
int selectDifficulty(void);
void playerTurn(int playerNumber, int *guessCount, int maxNumber);
void prepareNextPlayer(void);
void showWinner(int player1GuessCount, int player2GuessCount, int *winCountPlayer1, int *winCountPlayer2, int *drawCount);
void scoreboard(int winCountPlayer1, int winCountPlayer2, int drawCount);
void finalScoreboard(int winCountPlayer1, int winCountPlayer2, int drawCount);
void showBestScore(int bestScore, int bestPlayer);
void saveHighScore(int bestScore, int bestPlayer);
int loadHighScore(int* bestScore, int*  bestPlayer);

// Main Function
int main(void)
{
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8); // This line sets the terminal to UTF-8 mode (for modern characters like emojis)
    char again;
    int player1Wins = 0;
    int player2Wins = 0;
    int draw = 0;
    int bestScore = INT_MAX;
    int bestPlayer = 0;
    int savedBestScore;
    int savedBestPlayer;

    do
    {
        int player1GuessCount = 0;
        int player2GuessCount = 0;
        int maxNumber = selectDifficulty();

        showWelcomeBanner(maxNumber);

        playerTurn(1, &player1GuessCount, maxNumber);

        prepareNextPlayer();

        playerTurn(2, &player2GuessCount, maxNumber);

        showWinner(player1GuessCount, player2GuessCount, &player1Wins, &player2Wins, &draw);

        scoreboard(player1Wins, player2Wins, draw);

        if (player1GuessCount < bestScore)
        {
            bestScore = player1GuessCount;
            bestPlayer = 1;
        }

        if (player2GuessCount < bestScore)
        {
            bestScore = player2GuessCount;
            bestPlayer = 2;
        }

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &again);

        if (again != 'y' && again != 'Y')
        {
            finalScoreboard(player1Wins, player2Wins, draw);

            if (loadHighScore(&savedBestScore, &savedBestPlayer))
            {
                if (bestScore < savedBestScore)
                {
                    saveHighScore(bestScore, bestPlayer);
                    printf("\n🎉 New High Score Saved!\n");

                    savedBestScore = bestScore;
                    savedBestPlayer = bestPlayer;
                }
            }
            else
            {
                saveHighScore(bestScore, bestPlayer);
                printf("\n🎉 First High Score Saved!\n");

                savedBestScore = bestScore;
                savedBestPlayer = bestPlayer;
            }
                showBestScore(savedBestScore, savedBestPlayer);
        }

    } while (again == 'Y' || again == 'y');

    printf(
        "\n----------------------------------------------------------\n"
        "🎮 Thank you for playing!\n"
        "See you again. Goodbye!\n"
        "----------------------------------------------------------\n");

    return 0;
}

//  Function Definitions
int generateRandomNumber(int maxNumber)
{
    return (rand() % maxNumber) + 1;
}
// Function Definitions
void showWelcomeBanner(int maxNumber)
{

    printf(
        "==========================================================\n"
        "            MULTIPLAYER GUESS THE NUMBER GAME\n"
        "==========================================================\n"
        "\n"
        "🎮 Welcome, Players!\n"
        "\n"
        "Rules:\n"
        "1. Each player gets a different secret number.\n"
        "2. Guess a number between 1 and %d.\n"
        "3. The player with fewer guesses wins.\n"
        "\n"
        "Good Luck to Both Players!\n"
        "==========================================================\n\n\n",
        maxNumber);
}
// Function Definitions
int selectDifficulty(void)
{
    int choice;
    int selectedMaxNumber = 100;
    printf(
        "==========================================================\n"
        "                    SELECT DIFFICULTY\n"
        "==========================================================\n"

        "1. Easy (1 - 50)\n"
        "2. Medium (1 - 100)\n"
        "3. Hard (1 - 500)\n\n"

        "Enter your choice (1-3) : ");
    do
    {
        if (scanf("%d", &choice) != 1)
        {
            printf(
                "❌ Invalid input!\n\n"
                "Enter numbers only (1-3) : ");
            while (getchar() != '\n')
                ; // Clear the input buffer
            choice = 0;
            continue;
        }
        switch (choice)
        {
        case 1:
            selectedMaxNumber = 50;
            printf("✅ Easy selected! (1 - 50)\n");
            break;
        case 2:
            selectedMaxNumber = 100;
            printf("✅ Medium selected! (1 - 100)\n");
            break;
        case 3:
            selectedMaxNumber = 500;
            printf("✅ Hard selected! (1 - 500)\n");
            break;
        default:
            printf(
                "\n❌ Invalid choice !\n"
                "Enter choice again (1-3):");
            break;
        }
    } while (choice < 1 || choice > 3);
    printf("==========================================================\n\n\n");

    return selectedMaxNumber;
}
// Function Definitions
void playerTurn(int playerNumber, int *guessCount, int maxNumber)
{
    int randomNumber = generateRandomNumber(maxNumber);
    int guessedNumber;

    printf("==========================================================\n"
           "                    PLAYER %d TURN\n"
           "==========================================================\n\n",
           playerNumber);
    do
    {
        printf("Current Attempt #%d\n", *guessCount + 1);
        printf("Enter guessed number : ");

        int result = scanf("%d", &guessedNumber);
        if (result != 1)
        {
            printf("❌ Invalid input! Enter numbers only .\n\n");
            while (getchar() != '\n')
                ; // Clear the input buffer
            continue;
        }

        if (guessedNumber < 1 || guessedNumber > maxNumber)
        {
            printf("❌ Invalid input! Enter a number between 1 and %d.\n\n", maxNumber);
            continue;
        }

        (*guessCount)++;

        if (guessedNumber > randomNumber)
        {
            printf("Lower number please!\n\n");
        }
        else if (guessedNumber < randomNumber)
        {
            printf("Higher number please!\n\n");
        }
        else
        {
            printf(
                "\nCongratulations! 🎉\n"
                "You guessed the correct number in %d attempts.\n\n",
                *guessCount);
        }

    } while (guessedNumber != randomNumber);
}
// Function Definitions
void prepareNextPlayer(void)
{
    printf(
        "\n==========================================================\n"
        "Pass the keyboard to Player 2.\n"
        "Press Enter to start next player turn ...");
    getchar();
    getchar();
    printf("==========================================================\n\n");
}
// Function Definitions
void showWinner(int player1GuessCount, int player2GuessCount, int *winCountPlayer1, int *winCountPlayer2, int *drawCount)
{

    printf(
        "==========================================================\n"
        "                         RESULT\n"
        "==========================================================\n\n"
        "Player 1  Guesses : %d\n"
        "Player 2  Guesses : %d\n\n",
        player1GuessCount,
        player2GuessCount);

    if (player1GuessCount < player2GuessCount)
    {
        printf("🏆 Congratulations! Player 1 Wins 🎉!\n");
        (*winCountPlayer1)++;
    }
    else if (player1GuessCount > player2GuessCount)
    {
        printf("🏆 Congratulations! Player 2 Wins 🎉!\n");
        (*winCountPlayer2)++;
    }
    else
    {
        printf("🤝 MATCH TIE! both have equal guesses\n");
        (*drawCount)++;
    }
    printf("\n==========================================================\n");
}
// Function Definitions
void scoreboard(int winCountPlayer1, int winCountPlayer2, int drawCount)
{

    printf(
        "\n==========================================================\n"
        "                        SCOREBOARD\n"
        "===========================================================\n\n"

        "🏆 Player 1 Wins : %d\n"
        "🏆 Player 2 Wins : %d\n"
        "🤝 Draws         : %d\n\n"

        "==========================================================\n",
        winCountPlayer1,
        winCountPlayer2,
        drawCount);
}
// Function Definitions 5
void finalScoreboard(int winCountPlayer1, int winCountPlayer2, int drawCount)
{

    printf(
        "\n==========================================================\n"
        "                     FINAL SCOREBOARD\n"
        "==========================================================\n\n"

        "🏆 Player 1 Wins : %d\n"
        "🏆 Player 2 Wins : %d\n"
        "🤝 Draws         : %d\n\n",
        winCountPlayer1,
        winCountPlayer2,
        drawCount);

    if (winCountPlayer1 > winCountPlayer2)
    {
        printf(
            "🏆 Overall Champion : Player 1\n"
            "Congratulations! 🎉\n");
    }
    else if (winCountPlayer1 < winCountPlayer2)
    {
        printf(
            "🏆 Overall Champion : Player 2\n"
            "Congratulations! 🎉\n");
    }
    else
    {
        printf(
            "🤝 It's Tie !\n"
            "Both players have won the same number of times.\n");
    }

    printf(
        "Thank you for playing!\n\n"
        "==========================================================\n");
}
// Function Definitions
void showBestScore(int bestScore, int bestPlayer)
{
    printf(
        "\n==========================================================\n"
        "                     BEST SCORE\n"
        "==========================================================\n\n"

        "🏅 Best Score : %d Attempts\n"
        "👤 Achieved By : Player %d\n"

        "\n==========================================================\n",
        bestScore,
        bestPlayer);
}
//function definition 
void saveHighScore(int bestScore, int bestPlayer)
{

    FILE *fptr;
    fptr = fopen("highscore.txt", "w");

    if (fptr == NULL)
    {
        printf("Unable to save high score.\n");
        return;
    }
    fprintf(fptr, "%d\n", bestScore);
    fprintf(fptr, "%d\n", bestPlayer);

    fclose(fptr);

    printf("High Score Saved Successfully.\n");
}
//cunction definition 
int loadHighScore(int* bestScore, int*  bestPlayer)
{

        
        FILE *fptr ;
        fptr = fopen("highscore.txt", "r");

        if (fptr == NULL)
        {
            printf("No high score found. Play a game first!\n");
            return 0;
        }
                
        if(fscanf(fptr,"%d %d", bestScore , bestPlayer) != 2)
        {
            printf("High score file is corrupted.\n");
            fclose(fptr);
            return 0;
        }
        fclose(fptr);
        return 1;
}




// int loadHighScore(int* bestScore, int*  bestPlayer)
// {

        
//         FILE *fptr ;
//         fptr = fopen("highscore.txt", "r");

//         if (fptr == NULL)
//         {
//             printf("No high score found. Play a game first!\n");
//             return 0;
//         }
                
//         if(fscanf(fptr,"%d %d", bestScore , bestPlayer) != 2)
//         {
//             printf("High score file is corrupted.\n");
//             fclose(fptr);
//             return 0;
//         }
//         printf(
//             "==========================================================\n"
//             "                        BEST SCORE\n"
//             "==========================================================\n");
        
//         printf("Best Score : %d Attempts\n", *bestScore);
//         printf("Achieved By : Player %d\n", *bestPlayer);
//         printf("==========================================================\n");
//         fclose(fptr);
//         return 1;
// }