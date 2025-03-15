#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void ticTacToe();
void guessTheNumber();
void rockPaperScissors();
void showMenu();
void clearScreen();

int main() {
    int choice;
    
    do {
        clearScreen();
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: clearScreen(); ticTacToe(); break;
            case 2: clearScreen(); guessTheNumber(); break;
            case 3: clearScreen(); rockPaperScissors(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

// Function to display the main menu
void showMenu() {
    cout << "\n=== Gaming Zone ===\n";
    cout << "1. Tic-Tac-Toe\n";
    cout << "2. Guess the Number\n";
    cout << "3. Rock-Paper-Scissors\n";
    cout << "4. Exit\n";
}

// Function to clear the screen (Works for both Windows and Linux/macOS)
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Linux/macOS
    #endif
}

// Function to ask if the user wants to play again or go to menu
bool playAgain() {
    char choice;
    cout << "\nDo you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

// Function to display Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "\nTic-Tac-Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

// Tic-Tac-Toe Game
void ticTacToe() {
    do {
        char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
        int player = 1, choice;
        char mark;
        bool gameOver = false;

        displayBoard(board);
        
        for (int i = 0; i < 9 && !gameOver; i++) {
            player = (i % 2) + 1;
            mark = (player == 1) ? 'X' : 'O';

            cout << "Player " << player << ", enter a number (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9) {
                cout << "Invalid input! Try again.\n";
                i--;
                continue;
            }

            int row = (choice - 1) / 3, col = (choice - 1) % 3;
            if (board[row][col] == choice + '0') {
                board[row][col] = mark;
            } else {
                cout << "Position already taken! Try again.\n";
                i--;
                continue;
            }

            displayBoard(board);

            if (checkWin(board)) {
                cout << "Player " << player << " wins!\n";
                gameOver = true;
            }
        }

        if (!gameOver) cout << "It's a draw!\n";

    } while (playAgain());
}

// Guess the Number Game
void guessTheNumber() {
    do {
        srand(time(0));
        int number = rand() % 100 + 1, guess, attempts = 0;

        cout << "\n=== Guess the Number ===\n";
        cout << "I have selected a number between 1 and 100. Try to guess it!\n";

        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess > number) cout << "Too high! Try again.\n";
            else if (guess < number) cout << "Too low! Try again.\n";
            else cout << "Congratulations! You guessed it in " << attempts << " attempts.\n";

        } while (guess != number);

    } while (playAgain());
}

// Rock-Paper-Scissors Game
void rockPaperScissors() {
    do {
        srand(time(0));
        int userChoice, computerChoice;
        string choices[] = {"Rock", "Paper", "Scissors"};

        cout << "\n=== Rock-Paper-Scissors ===\n";
        cout << "1. Rock\n2. Paper\n3. Scissors\n";
        cout << "Enter your choice (1-3): ";
        cin >> userChoice;
        
        if (userChoice < 1 || userChoice > 3) {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        computerChoice = rand() % 3 + 1;
        cout << "You chose: " << choices[userChoice - 1] << endl;
        cout << "Computer chose: " << choices[computerChoice - 1] << endl;

        if (userChoice == computerChoice) cout << "It's a tie!\n";
        else if ((userChoice == 1 && computerChoice == 3) || 
                 (userChoice == 2 && computerChoice == 1) || 
                 (userChoice == 3 && computerChoice == 2)) {
            cout << "You win!\n";
        } else {
            cout << "Computer wins!\n";
        }

    } while (playAgain());
}

