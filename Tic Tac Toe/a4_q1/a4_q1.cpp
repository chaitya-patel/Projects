// a4_q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//*****************************************************************************
// Student Names: Chaitya Patel and Mayurah Omkararuban
//
//  SYDE 121 Assignment: 4
//  Filename: a4_q1
//
// We hereby declare that this code, submitted for credit for the course SYDE121, is a product of our own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.
//
// Due Date: Friday, November 6, 2020
//**************************************************************

/*Testing and Debugging: To test the code the game was played realistically with two outside players and more planned testing included playing the game in such a
pattern that would test the different possible win or tie patterns by the two players. Scenarios were played out so that both players won through different patterns.
Also, sometimes a repetitive location was entered intentionally to check for reprompting and then game was sometimes played for onyl one round and sometimes multiple
to check to make sure that those scenarious worked as well. Different winners and scores were intentionally played out to check for accurate game stats.*/

#include <iostream>
#include <string>

using namespace std;

void tic_tac_toe();
// PURPOSE: to initiate a tic tac toe game
//  INPUTS: none
// OUTPUTS: none

void print_game_board(string board[][4], int board_size);
// PURPOSE: to print the original configuration of the game board
//  INPUTS: board[][4] - a string array of game board elements to be modified during game play with a max of 4 columns 
//          board_size - size of the game board string array
//  OUTPUTS: none

void player_turn();
// PURPOSE: to alternate between player turns in the game
//  INPUTS: none
// OUTPUTS: none

bool continue_game(string board[][4], int board_size, bool& game_finished);
// PURPOSE: check after every round to make sure the players want to contine their game
//  INPUTS: board[][4] - a string array of game board elements to be modified during game play with a max of 4 columns
//          board_size - size of the game board string array
//          game_finished - 
// OUTPUTS: true - if players want game to be continued
//          false - if players do not want to continue the game

void game_stats(int round_counter, int player1_win_counter, int player2_win_counter, int tie_counter);
// PURPOSE: to print out the stats of the game at the end of game play when the players do not want to continue the game
//  INPUTS: round_counter - counts the number of rounds that the players have played
//          player1_win_counter - number of games won by player 1
//          player2_win_counter - number of games qwon by player 2
//          tie_counter - number of tie games
// OUTPUTS: none


void player1(char player, string board[][4], int board_size);
// PURPOSE: to go through player 1's turn (X)
//  INPUTS: player - the character that will be used as a placeholder for that player in the tic-tac-toe game
//          board[][4] - a string array of game board elements to be modified during game play with a max of 4 columns 
//          board_size - size of the game board string array
// OUTPUTS: none

void player2(char player, string board[][4], int board_size);
// PURPOSE: to go through player 2's turn (O)
//  INPUTS: player - the character that will be used as a placeholder for that player in the tic-tac-toe game
//          board[][4] - a string array of game board elements to be modified during game play with a max of 4 columns 
//          board_size - size of the game board string array
// OUTPUTS: none

bool check_win(string board[][4], int board_size, bool& game_finished, int& player1_win_counter, int& player2_win_counter, int& tie_counter);
// PURPOSE: to check for a winning pattern of X's or O's vertically, diagonally, or horizontally, or a tie
//  INPUTS: board[][4] - a string array of game board elements to be modified during game play with a max of 4 columns 
//          board_size - size of the game board string array
//          game_finished - to change to true if there is a win or tie to indicate end of the round
//          player1_win_counter - number of games won by player 1
//          player2_win_counter - number of games won by player 2
//          tie_counter - number of games tied
// OUTPUTS: true - if a someone won the game or the game is tied in this round
//          false - if there is no winner or tie yet

bool check_taken(char player, int entry, string board[][4], int board_size, int location1, int location2);
// PURPOSE: to check if the desired index of entry is already filled with and X or O
//  INPUTS: player - the character that will be used as a placeholder for that player in the tic-tac-toe game
//          entry - the desired place of entry by the player
//          board[][4] - a string array of game board elements to be modified during game play with a max of 4 columns 
//          board_size - size of the game board string array
//          location1 - the row that the player wants to place their token in
//          location2 - the column that the player wants to place their token in
// OUTPUTS: true - in the cases that the originally intended place of token was already filled by an X or O

void update_board(char player, int entry, string board[][4], int board_size);
// PURPOSE: to update and fill the game board with player tokens
//  INPUTS: player - the character that will be used as a placeholder for that player in the tic-tac-toe game
//          entry - the desired place of entry by the player
//          board[][4] - a string array of game board elements to be modified during game play with a max of 4 columns 
//          board_size - size of the game board string array
//  OUTPUTS: none

void tic_tac_toe() {
    // [SETUP] step0. declare and initialize variables
    char play; // a character to be entered if the game wants to be played

    //[PROCESSING] step1. ask the user if they want to play and lay out some rules
    cout << "4-SQUARED TIC-TAC-TOE" << endl << "Enter the letter P to play: ";
    cin >> play;
    if (play == 'p') {
        cout << "P1 (Player 1) will be X and will start, and P2 (Player 2) will be O" << endl;
        player_turn(); // to alternate between player turns in the game
    }
}
void player_turn() {
    //[SETUP]step0. declare and initialize variables and arrays
    int player1_win_counter = 0; 
    int player2_win_counter = 0;
    int tie_counter = 0;
    char player_x = 'X';
    char player_o = 'O';
    int round_counter = 0;
    bool game_finished = false; // is the game still being played or is the round finished
    string board[4][4] = { {"1", "2", "3", "4"}, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"} }; // game board configuration

    //[OUTPUT]step1. to show the player the game board configuration
    print_game_board(board, 4);

    //[PROCESSING]step2. to start with player 1 (X) and alterate starting player as more than one round is played
    do {
        if (round_counter % 2 == 0) { // if round is even, then player 1 goes first, if odd then player 2 goes first
            while (game_finished == false) {
                if (check_win(board, 4, game_finished, player1_win_counter, player2_win_counter, tie_counter) != true) {  // to check for winning/tie patterns to be undetected before continuing game
                    player1(player_x, board, 4); // initiation of player 1's turn
                }
                if (game_finished == false) {
                    if (check_win(board, 4, game_finished, player1_win_counter, player2_win_counter, tie_counter) != true) {  // to check for winning/tie patterns to be undetected before continuing game
                        player2(player_o, board, 4); // initiation of player 2's turn
                    }
                }
            }
        }
        else {
            while (game_finished == false) {
                if (check_win(board, 4, game_finished, player1_win_counter, player2_win_counter, tie_counter) != true) {   // to check for winning/tie patterns to be undetected before continuing game
                    player2(player_o, board, 4); // initiation of player 2's turn
                }
                if (game_finished == false) {
                    if (check_win(board, 4, game_finished, player1_win_counter, player2_win_counter, tie_counter) != true) {  // to check for winning/tie patterns to be undetected before continuing game
                        player1(player_x, board, 4); // initiation of player 1's turn
                    }
                }
            }
        }
        round_counter += 1; // to count a completed round

    } while (continue_game(board, 4, game_finished) == true); // keep playing while the players wants the game to continue 

    //[OUTPUT]step3. output game stats at the end of the game
   game_stats(round_counter, player1_win_counter, player2_win_counter, tie_counter); // function to print the stats of the game after it is ended
}

void print_game_board(string board[][4], int board_size) {
    //[OUTPUT] print game board
    cout << "   " << board[0][0] << "   " << board[0][1] << "   " << board[0][2] << "   " << board[0][3] << endl
        << "   " << board[1][0] << "   " << board[1][1] << "   " << board[1][2] << "   " << board[1][3] << endl
        << "   " << board[2][0] << "   " << board[2][1] << "  " << board[2][2] << "  " << board[2][3] << endl
        << "   " << board[3][0] << "  " << board[3][1] << "  " << board[3][2] << "  " << board[3][3] << endl;
}

void player1(char player, string board[][4], int board_size) {
    //[SETUP]step0. declare and initialize variables
    int entry_x; // location that player 1 wants to put their X 

    //[INPUT]step1. retrieve location where player 1 wants to put their piece
    cout << "P1, enter the number where you would like to place an X: ";
    cin >> entry_x;

    //[PROCESSING]step2. pass on location to update the game board
    update_board(player, entry_x, board, 4);
}

void player2(char player, string board[][4], int board_size) {
    //[SETUP]step0. declare and initialize variables
    int entry_o; // location that player 2 wants to put their O 

    //[INPUT]step1. retrieve location where player 1 wants to put their piece
    cout << "P2, enter the number where you would like to place an O: ";
    cin >> entry_o;

    //[PROCESSING]step2. pass on location to update the game board
    update_board(player, entry_o, board, 4);
}


void update_board(char player, int entry, string board[][4], int board_size) {
    //[PROCESSING] based on the user entry, go to that location on the game board, check if place is taken, if not update and print game board
    switch (entry) {
    case 1:
        if (check_taken(player, entry, board, 4, 0, 0) != true) {
            board[0][0] = player;
            print_game_board(board, 4);
        }
        break;
    case 2:
        if (check_taken(player, entry, board, 4, 0, 1) != true) {
            board[0][1] = player;
            print_game_board(board, 4);
        }
        break;
    case 3:
        if (check_taken(player, entry, board, 4, 0, 2) != true) {
            board[0][2] = player;
            print_game_board(board, 4);
        }
        break;
    case 4:
        if (check_taken(player, entry, board, 4, 0, 3) != true) {
            board[0][3] = player;
            print_game_board(board, 4);
        }
        break;
    case 5:
        if (check_taken(player, entry, board, 4, 1, 0) != true) {
            board[1][0] = player;
            print_game_board(board, 4);
        }
        break;
    case 6:
        if (check_taken(player, entry, board, 4, 1, 1) != true) {
            board[1][1] = player;
            print_game_board(board, 4);
        }
        break;
    case 7:
        if (check_taken(player, entry, board, 4, 1, 2) != true) {
            board[1][2] = player;
            print_game_board(board, 4);
        }
        break;
    case 8:
        if (check_taken(player, entry, board, 4, 1, 3) != true) {
            board[1][3] = player;
            print_game_board(board, 4);
        }
        break;
    case 9:
        if (check_taken(player, entry, board, 4, 2, 0) != true) {
            board[2][0] = player;
            print_game_board(board, 4);
        }
        break;
    case 10:
        if (check_taken(player, entry, board, 4, 2, 1) != true) {
            board[2][1] = player;
            print_game_board(board, 4);
        }
        break;
    case 11:
        if (check_taken(player, entry, board, 4, 2, 2) != true) {
            board[2][2] = player;
            print_game_board(board, 4);
        }
        break;
    case 12:
        if (check_taken(player, entry, board, 4, 2, 3) != true) {
            board[2][3] = player;
            print_game_board(board, 4);
        }
        break;
    case 13:
        if (check_taken(player, entry, board, 4, 3, 0) != true) {
            board[3][0] = player;
            print_game_board(board, 4);
        }
        break;
    case 14:
        if (check_taken(player, entry, board, 4, 3, 1) != true) {
            board[3][1] = player;
            print_game_board(board, 4);
        }
        break;
    case 15:
        if (check_taken(player, entry, board, 4, 3, 2) != true) {
            board[3][2] = player;
            print_game_board(board, 4);
        }
        break;
    case 16:
        if (check_taken(player, entry, board, 4, 3, 3) != true) {
            board[3][3] = player;
            print_game_board(board, 4);
        }
        break;
    }
}

bool check_taken(char player, int entry, string board[][4], int board_size, int location1, int location2) {
    //[PROCESSING]step1. check if the desired input location by the player is already occupied by a game piece
    if (board[location1][location2] == "X") { // check if there is an X in the location
        cout << "This spot is already taken." << endl;
        // if place taken, reprompt user to enter a different location
        if (player == 'X') 
            player1(player, board, 4); 
        else if (player == 'O')
            player2(player, board, 4);
        return true; // return true if place is taken
    }
    if (board[location1][location2] == "O") { // check if there is an O in the location
        cout << "This spot is already taken." << endl;
        // if place taken, reprompt user to enter a different location
        if (player == 'X')
            player1(player, board, 4);
        else if (player == 'O')
            player2(player, board, 4);
        return true; // return true if place is taken
    }

}

bool check_win(string board[][4], int board_size, bool& game_finished, int& player1_win_counter, int& player2_win_counter, int& tie_counter) {
    //[SETUP]step0. declare and initialize variables
    int alpha_counter = 0; // to count the number of letters already entered in the game board

    // [PROCESSING]step1. check for win vertically, horizontally or diagonally and update win counter for corresponding player
    // also set game_finished to truet to indicate the round has finished and return true to indicate that there has been a win
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == board[3][0]) {
        if (board[0][0] == "X") {
            player1_win_counter += 1;
            cout << "Player 1 wins the round!" << endl;
            game_finished = true;
            return true;
        }
        if (board[0][0] == "O") {
            player2_win_counter += 1;
            cout << "Player 2 wins the round!" << endl;
            game_finished = true;
            return true;
        } 
    }
    if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == board[3][1]) {
        if (board[0][1] == "X") {
            player1_win_counter += 1;
            cout << "Player 1 wins the round!" << endl;
            game_finished = true;
            return true;
        }
        if (board[0][1] == "O") {
            player2_win_counter += 1;
            cout << "Player 2 wins the round!" << endl;
            game_finished = true;
            return true;
        }
    }
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == board[3][2]) {
        if (board[0][2] == "X") {
            player1_win_counter += 1;
            cout << "Player 1 wins the round!" << endl;
            game_finished = true;
            return true;
        }
        if (board[0][2] == "O") {
            player2_win_counter += 1;
            cout << "Player 2 wins the round!" << endl;
            game_finished = true;
            return true;
        }
    }
    if (board[0][3] == board[1][3] && board[1][3] == board[2][3] && board[2][3] == board[3][3]) {
        if (board[0][3] == "X") {
            player1_win_counter += 1;
            cout << "Player 1 wins the round!" << endl;
            game_finished = true;
            return true;
        }
        if (board[0][3] == "O") {
            player2_win_counter += 1;
            cout << "Player 2 wins the round!" << endl;
            game_finished = true;
            return true;
        }
    }
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == board[0][3]) {
        if (board[0][0] == "X") {
            player1_win_counter += 1;
            cout << "Player 1 wins the round!" << endl;
            game_finished = true;
            return true;
        }
        if (board[0][0] == "O") {
            player2_win_counter += 1;
            cout << "Player 2 wins the round!" << endl;
            game_finished = true;
            return true;
        }
    }
    if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == board[1][3]) {
        if (board[1][0] == "X") {
            player1_win_counter += 1;
            cout << "Player 1 wins the round!" << endl;
            game_finished = true;
            return true;
        }
        if (board[1][0] == "O") {
            player2_win_counter += 1;
            cout << "Player 2 wins the round!" << endl;
            game_finished = true;
            return true;
        }
    }
    if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == board[2][3]) {
        if (board[2][0] == "X") {
            player1_win_counter += 1;
            cout << "Player 1 wins the round!" << endl;
            game_finished = true;
            return true;
        }
        if (board[2][0] == "O") {
            player2_win_counter += 1;
            cout << "Player 2 wins the round!" << endl;
            game_finished = true;
            return true;
        }
    }
    if (board[3][0] == board[3][1] && board[3][1] == board[3][2] && board[3][2] == board[3][3]) {
        if (board[3][0] == "X") {
            player1_win_counter += 1;
            cout << "Player 1 wins the round!" << endl;
            game_finished = true;
            return true;
        }
        if (board[3][0] == "O") {
            player2_win_counter += 1;
            cout << "Player 2 wins the round!" << endl;
            game_finished = true;
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        if (board[0][0] == "X") {
            player1_win_counter += 1;
            cout << "Player 1 wins the round!" << endl;
            game_finished = true;
            return true;
        }
        if (board[0][0] == "O") {
            player2_win_counter += 1;
            cout << "Player 2 wins the round!" << endl;
            game_finished = true;
            return true;
        }
    }
    if (board[3][0] == board[2][1] && board[2][1] == board[1][2] && board[1][2] == board[0][3]) {
        if (board[3][0] == "X") {
            player1_win_counter += 1;
            cout << "Player 1 wins the round!" << endl;
            game_finished = true;
            return true;
        }
        if (board[3][0] == "O") {
            player2_win_counter += 1;
            cout << "Player 2 wins the round!" << endl;
            game_finished = true;
            return true;
        }
    }

    //step2. check if all indices in the board array are filled with letters, in that case there is a tie and the round is finished
    for (int index1 = 0; index1 < 4; index1++) {
        for (int index2 = 0; index2 < 4; index2++) {
            if (board[index1][index2] == "X" || board[index1][index2] == "O") {
                alpha_counter += 1; // count every X or O in the array
                if (alpha_counter == 16) { // if total is 16 that means array is filled with X's and O's
                    tie_counter += 1; // count the tie to keep score
                    cout << "This round is a tie!" << endl;
                    game_finished = true; // indicates that game has finished for this round
                    return true; // return true to indicate that a win/tie has been detected
                }
            }
        }
    }
}

bool continue_game(string board[][4], int board_size, bool& game_finished) {
    //[SETUP]step0. declare and initialize variables
    char play; // a character entered by the user to indicate whether they want to continue playing

    //[INPUT]step1. retrieve user input for decision on continuing the game
    cout << "Do you want to play again? Enter the letter Y to continue, if you want to exit press any other key:";
    cin >> play;

    //[PROCESSING]step2. if players want to continue then restart game config and continue playing
    if (play == 'y') {
        int board_number = 0; // declare and initialize to fill the game board array with numbered locations
        for (int index1 = 0; index1 < 4; index1++) {
            for (int index2 = 0; index2 < 4; index2++) {
                board_number += 1;
                board[index1][index2] = to_string(board_number);
            }
        }
        game_finished = false; // inidicate that game is not finished yet
        print_game_board(board, 4); // reprint the game board configuration
        return true; // continue game play
    }
    
    //step3. if players don't want to continue then return false to indicate end of game
    else {
        return false;
    }
}

void game_stats(int round_counter, int player1_win, int player2_win, int tie) {
    //[OUTPUT] print the game stats
    cout << "END OF GAME STATS:" << endl;
    cout << "Rounds Played: " << round_counter << endl;
    cout << "Number of Rounds Won by Player 1: " << player1_win << endl;
    cout << "Number of Rounds Won by Player 2: " << player2_win << endl;
    cout << "Number of Rounds Tied: " << tie << endl;
   
    // indicate the winner or game conclusion
    if (player1_win > player2_win)
        cout << "Player 1 Wins! Better Luck Next Time Player 2 :)" << endl;
    else if (player1_win < player2_win)
        cout << "Player 2 Wins! Better Luck Next Time Player 1 :)" << endl;
    else
        cout << "Tie Game!" << endl;

    cout << "Thank You for Playing! See You Next Time!" << endl;
}

int main()
{
    tic_tac_toe(); // initiate a 4x4 game of 2 player tic-tac-toe
}

