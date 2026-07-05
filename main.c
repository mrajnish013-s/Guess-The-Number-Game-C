#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>     
#include <windows.h>  // this is a library function for using emoji;

#define MAX_NUMBER 100


// Function Prototypes
int generateRandomNumber(void);
void showWelcomeBanner(void);
void playerTurn(int playerNumber, int *guessCount);    
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
        int player1GuessCount=0;       // Player 1 guessed in fewer attempts
        int player2GuessCount=0;       // Player 2 guessed in fewer attempts
       
        showWelcomeBanner();

        playerTurn(1, &player1GuessCount);

        prepareNextPlayer();

        playerTurn(2, &player2GuessCount);

        showWinner(player1GuessCount,player2GuessCount);

        printf("Do you want to play again? (Y/N):\n");
        scanf(" %c", &again);
    } while (again == 'Y' || again == 'y');

    printf(
        "\n----------------------------------------------------------\n"
        "🎮 Thank you for playing!\n"
        "See you again. Goodbye!\n"
        "----------------------------------------------------------\n"
    );
    
    return 0;
} 

//  Function Definitions


int generateRandomNumber(void)
{
    return (rand() % MAX_NUMBER) + 1;
}




void showWelcomeBanner(void)
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
        MAX_NUMBER
   );
    
}



void playerTurn(int playerNumber, int *guessCount)
{
    int randomNumber = generateRandomNumber ();
    int guessedNumber;

    printf("==========================================================\n"
           "                    PLAYER %d TURN\n"
           "==========================================================\n",
           playerNumber
        );
    do
    {   
        printf("Current Attempt #%d\n", *guessCount + 1);
        printf("Enter guessed number : ");
        scanf("%d", &guessedNumber);
        
        if (guessedNumber < 1 || guessedNumber > MAX_NUMBER)
        {
            printf("❌ Invalid input! Enter a number between 1 and %d.\n\n", MAX_NUMBER);
            continue;
        }
        
        (*guessCount)++;
        
        if(guessedNumber>randomNumber){
            printf("Lower number please!\n\n");
        }
        else if (guessedNumber<randomNumber){
            printf("Higher number please!\n\n");
        }else
        {
            printf("Congratulations! You guessed the correct number in %d guesses.\n\n", *guessCount);
        }
        
    } while ( guessedNumber != randomNumber);

}





void prepareNextPlayer(void)
{
    printf(
        "\n==========================================================\n"
        "Pass the keyboard to Player 2.\n"
        "Press Enter to start next player turn ..."
    );
    getchar();  
    getchar();  
    printf("==========================================================\n\n");
}






void showWinner(int player1GuessCount, int player2GuessCount)
{
    printf(
        "==========================================================\n"
        "                          RESULT\n"                      
        "==========================================================\n\n"
        "Player 1  Guesses : %d\n"
        "Player 2  Guesses : %d\n\n",
        player1GuessCount,
        player2GuessCount
    );

    if(player1GuessCount<player2GuessCount){
        printf("🏆 Congratulations! Player 1 Wins 🎉!\n");   
    }
    else if(player1GuessCount>player2GuessCount)
    {
        printf("🏆 Congratulations! Player 1 Wins 🎉!\n");   
    }else
    {
        printf("🤝 MATCH TIE! both have equal guesses\n");
    }
    printf("\n==========================================================\n");
}



