
// C Program to implement Snake and Ladder Game 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
// Function to roll a six-sided die 
int roll_die() { return rand() % 6 + 1; } 
  
// global variables to store postions of player1 and player2 
int player1 = 0, player2 = 0; 
  
// Function to print the board 
void print_board() 
{ 
    // logic to print a snake-ladder Game board 
    // programmer can implement their own logic for the board, 
      // this is one way to print a snake ladder board. 
    int board[101]; 
    for (int i = 1; i <= 100; i++) { 
        board[i] = i; 
    } 
  
    int alt = 0; // to switch between the alternate nature of the board 
    int iter_l_r = 101; // iterator to print from left to right 
    int iter_r_l = 80;  // iterator to print from right to left 
    int val = 100;     
    while (val--) { 
        if (alt == 0) { 
            iter_l_r--; 
            if (iter_l_r == player1) { 
                printf("#P1    "); 
            } 
            else if (iter_l_r == player2) { 
                printf("#P2    "); 
            } 
            else
                printf("%d    ", board[iter_l_r]); 
  
            if (iter_l_r % 10 == 1) { 
                printf("\n\n"); 
                alt = 1; 
                iter_l_r -= 10; 
            } 
        } 
        else { 
            iter_r_l++; 
            if (iter_r_l == player1) { 
                printf("#P1    "); 
            } 
            else if (iter_r_l == player2) { 
                printf("#P2    "); 
            } 
            else
                printf("%d    ", board[iter_r_l]); 
  
            if (iter_r_l % 10 == 0) { 
                printf("\n\n"); 
                alt = 0; 
                iter_r_l -= 30; 
            } 
        } 
        if (iter_r_l == 10) 
            break; 
    } 
    printf("\n"); 
} 
  
// Function to move the player 
int move_player(int current_player, int roll) 
{ 
    int new_position = current_player + roll; 
    // Define the positions of snakes and ladders on the 
    // board 
    int snakes_and_ladders[101]; 
  
    for (int i = 0; i <= 100; i++) { 
        snakes_and_ladders[i] = 0; 
    } 
    
      // here positive weights represent a ladder 
      // and negative weights represent a snake. 
    snakes_and_ladders[6] = 40; 
    snakes_and_ladders[23] = -10; 
    snakes_and_ladders[45] = -7; 
    snakes_and_ladders[61] = -18; 
    snakes_and_ladders[65] = -8; 
    snakes_and_ladders[77] = 5; 
    snakes_and_ladders[98] = -10; 
  
    int new_square 
        = new_position + snakes_and_ladders[new_position]; 
  
    if (new_square > 100) { 
        return current_player; // Player cannot move beyond 
                              // square 100 
    } 
  
    return new_square; 
} 
  
int main() 
{ 
    srand(time(0)); // Initialize random seed 
    int current_player = 1; 
    int won = 0; 
  
    printf("Snake and Ladder Game\n"); 
  
    while (!won) { 
  
        printf( 
            "\n_player %d, press Enter to roll the die...", 
            current_player); 
        getchar(); // Wait for the player to press Enter 
        int roll = roll_die(); 
        printf("You rolled a %d.\n", roll); 
  
        if (current_player == 1) { 
            player1 = move_player(player1, roll); 
            printf("Player 1 is now at square %d.\n\n", 
                   player1); 
            print_board(); 
            if (player1 == 100) { 
                printf("Player 1 wins!\n"); 
                won = 1; 
            } 
        } 
        else { 
            player2 = move_player(player2, roll); 
            printf("Player 2 is now at square %d.\n\n", 
                   player2); 
            print_board(); 
            if (player2 == 100) { 
                printf("Player 2 wins!\n"); 
                won = 1; 
            } 
        } 
  
        // Switch to the other player 
        current_player = (current_player == 1) ? 2 : 1; 
    } 
  
    return 0; 
}

