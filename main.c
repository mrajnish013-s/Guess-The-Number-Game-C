#include <stdio.h>    // for printf and scanf
#include <stdlib.h>   // for rand and srand
#include <time.h>     // for  different randomNumber
#include <windows.h> // 1. Yeh library lagao  [ emoji use karne ke liye]

int main()
{
    srand(time(0));

    // 2. Yeh line terminal ko UTF-8 (Modern Characters jaise -emoji ) mode mein set kar deti hai21
    SetConsoleOutputCP(CP_UTF8);

    int randomNumber;     // computer ka number 
    int guessed_number;   // player ka number 

    int guessed_p1=0;       // total number guessed of gussed of p1
    int guessed_p2=0;       /// total number guessed of gussed of p2

    printf("======== WELCOME TO MULTIPLAYER NUMBER GUSSED GAME =======\n\n\n");

    // -------------------PLAYER 01 TURN----------------------------
    // har player ke liye nya random number generate karega
    randomNumber=(rand()%100)+1;
    printf("----PLAYER 1 TURN ----\n");

    do
    {
      printf("Enter guessed number :");
      scanf("%d", &guessed_number);
      guessed_p1++;
      if(guessed_number>randomNumber){
        printf("Lower number pleased!\n\n");
      }
      else if (guessed_number<randomNumber){
        printf("Higher number please!\n\n");
      }else
      {
        printf("CONGRATS! you guessed correct in %d guessed\n\n", guessed_p1);
      }
    } while ( guessed_number != randomNumber);

    printf("\n------------------------------------------------\n");
    char reddy;
    printf("Enter 1 for PLAYER 2 turn :");
    scanf(" %c", &reddy);      // %c se pehle ek space zaroor lagana buffer saaf karne ke liy
    printf("\n-------------------------------------------------\n\n");

    //----------------------PLAYER 2 TURN---------------------
    //============PLAYER 2 KE NYA RANDOM NUMBER==============
    randomNumber=(rand()%100)+1;
    printf("-------PLAYER 2 TURN----------\n");
    do
    {
         printf("Enter guessed number :");
         scanf("%d", &guessed_number);
         guessed_p2++;
         if (guessed_number>randomNumber){
             printf("Lower number please!\n\n");
         }
         else if (guessed_number<randomNumber){
             printf("Higher number please!\n\n");
         }
         else{
             printf("CONGRATS! you guessed correct in %d guessed\n\n", guessed_p2);
         }       
    } while (guessed_number != randomNumber);

    // ------------------ WINNER DECISION (If-Else) ------------------
    printf("------------------ WINNER DECISION------------------\n");
    printf("==================== RESULT ====================\n");
    printf("Player 1  Guesses : %d\n", guessed_p1);
    printf("Player 2  Guesses : %d\n", guessed_p2);

    if(guessed_p1<guessed_p2){
        printf("🏆 PLAYER 1 is WINNER🎉!!\n");   //(Kyunki guesses kam hain)
    }
    else if(guessed_p1>guessed_p2)
    {
        printf("🏆 PLAYER 2 is WINNER🎉!!\n");   //(Kyunki guesses kam hain)
    }else
    {
        printf("🤝 MATCH TIE! both have equal geusses\n");
    }
    printf("====================================================\n");

    return 0;
} 
