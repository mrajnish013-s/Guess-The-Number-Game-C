#include <stdio.h>    
#include <stdlib.h>   // for rand and srand
#include <time.h>     // for generate different randomNumber
#include <windows.h>  // this is a library function for using emoji;

#define MAX_NUMBER 100

// function : 1
int generateRandomNumber()
{
    // Generate a new random number for each player
    return (rand()% MAX_NUMBER)+1;
}

// function : 2
void playerTurn(int playerNumber, int *guessCount);    // function prototype

void playerTurn(int playerNumber, int *guessCount)
{
    int randomNumber = generateRandomNumber ();
    int guessed_number;
    printf("----PLAYER %d TURN ----\n", playerNumber);
    do
    {   
        printf("Enter guessed number : ");
        scanf("%d", &guessed_number);
        
        if (guessed_number < 1 || guessed_number > MAX_NUMBER)
        {
            printf("❌ Invalid input! Enter a number between 1 and %d.\n\n", MAX_NUMBER);
            continue;
        }
        
        (*guessCount)++;
        
        if(guessed_number>randomNumber){
            printf("Lower number pleased!\n\n");
        }
        else if (guessed_number<randomNumber){
            printf("Higher number please!\n\n");
        }else
        {
            printf("Congratulations! You guessed the correct number in %d guesses.\n\n", *guessCount);
        }
        
    } while ( guessed_number != randomNumber);

}

// function : 3
void showWinner(int guessed_p1, int guessed_p2);  //function prototype

void showWinner(int guessed_p1, int guessed_p2)
{
    printf("------------------ WINNER DECISION------------------\n");
    printf("==================== RESULT ====================\n");
    printf("Player 1  Guesses : %d\n", guessed_p1);
    printf("Player 2  Guesses : %d\n", guessed_p2);

    if(guessed_p1<guessed_p2){
        printf("🏆 PLAYER 1 is WINNER🎉!!\n");   
    }
    else if(guessed_p1>guessed_p2)
    {
        printf("🏆 PLAYER 2 is WINNER🎉!!\n");   
    }else
    {
        printf("🤝 MATCH TIE! both have equal geusses\n");
    }
    printf("====================================================\n");
}


int main()
{
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8); // This line sets the terminal to UTF-8 mode (for modern characters like emojis)
    char again;
    char ready;

    
    do
    {
        int guessed_p1=0;       // Player 1 guessed in fewer attempts
        int guessed_p2=0;       // Player 2 guessed in fewer attempts
        printf("======== WELCOME TO MULTIPLAYER GUESS THE NUMBER GAME =======\n\n\n");   
        printf("Guess a number between 1 and %d\n\n", MAX_NUMBER);     
        // -------------------PLAYER 1 TURN----------------------------        
        playerTurn(1, &guessed_p1);
        printf("\n------------------------------------------------\n");
        printf("Enter 1 for PLAYER 2 turn :");
        scanf(" %c", &ready);    // Always put a space before %c to clear the input buffer  
        printf("-------------------------------------------------\n\n");
        //----------------------PLAYER 2 TURN---------------------
        playerTurn(2, &guessed_p2);
        // ------------------ WINNER DECISION (If-Else) -----------------
        showWinner(guessed_p1,guessed_p2);
        // --------------------------------------------------------------
        printf("Do you want to play  again ? Enter(Y/N)\n");
        scanf(" %c", &again);
    } while (again == 'Y' || again == 'y');
    printf("\n-------------------------------------------------\n");
    printf("🎮 Thank you for playing!\n");
    printf("See you again. Goodbye!\n");
    printf("-------------------------------------------------\n");
    
    return 0;
} 
