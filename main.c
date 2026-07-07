#include <stdio.h>
#include <stdlib.h> // this is a library function for using  rand and srand;
#include <time.h>
#include <windows.h> // this is a library function for using emoji;

// Function Prototypes
int generateRandomNumber(int maxNumber);
void showWelcomeBanner(int maxNumber);
int selectDifficulty(void);
void playerTurn(int playerNumber, int *guessCount, int maxNumber);
void prepareNextPlayer(void);
void showWinner(int player1GuessCount, int player2GuessCount);

// Main Function
int main(void)
{
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8); // This line sets the terminal to UTF-8 mode (for modern characters like emojis)
    char again;

    do
    {
        int player1GuessCount = 0;
        int player2GuessCount = 0;
        int maxNumber = selectDifficulty();

        showWelcomeBanner(maxNumber);

        playerTurn(1, &player1GuessCount, maxNumber);

        prepareNextPlayer();

        playerTurn(2, &player2GuessCount, maxNumber);

        showWinner(player1GuessCount, player2GuessCount);

        printf("Do you want to play again? (Y/N):\n");
        scanf(" %c", &again);
    } while (again == 'Y' || again == 'y');

    printf(
        "\n----------------------------------------------------------\n"
        "🎮 Thank you for playing!\n"
        "See you again. Goodbye!\n"
        "----------------------------------------------------------\n");

    return 0;
}

//  Function Definitions 1
int generateRandomNumber(int maxNumber)
{
    return (rand() % maxNumber) + 1;
}
// Function Definitions 2
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
// Function Definitions 3
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
                "❌ Invalid choice !\n"
                "Enter choice again (1-3):");
            break;
        }
    } while (choice < 1 || choice > 3);
    printf("==========================================================\n\n\n");

    return selectedMaxNumber;
}
// Function Definitions 4
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
            printf("Congratulations! You guessed the correct number in %d attempts.\n\n", *guessCount);
        }

    } while (guessedNumber != randomNumber);
}
// Function Definitions 5
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
// Function Definitions 6
void showWinner(int player1GuessCount, int player2GuessCount)
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
    }
    else if (player1GuessCount > player2GuessCount)
    {
        printf("🏆 Congratulations! Player 2 Wins 🎉!\n");
    }
    else
    {
        printf("🤝 MATCH TIE! both have equal guesses\n");
    }
    printf("\n==========================================================\n");
}
