// Tonya Kieffer
// ID223-10013
// Tic-Tac-Toe with Comments

// preprocessor directives to include iostream, string, vector, and algorithm "header" files from the standard library:
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; // this directive keeps me from having to use a prefix every time I use one of the objects from the namespace

// Global constants:
const char X = 'X'; // read only and declared outside of any function
const char O = 'O'; // char is variable type that is assigned a charater value
const char EMPTY = ' ';
const char TIE = 'T'; // this is char variable named 'tie' with a value of 'T'
const char NO_ONE = 'N';;

// Function prototypes
// Declaring functions that will return a value
void instructions(); // void function does not return a value or have parameters
char askYesNo(string question); // string object named 'question' is a parameter for the char function named 'askYesNo'

int askNumber(string question, int high, int low = 0); // argument that returns a number value with parameters in parentheses; default argument is low with value of '0'

char humanPiece(); // variable named 'humanPiece' that can have multiple arguments and will be defined later

char opponent(char piece); // returns a value based on a given value
void displayBoard(const vector<char>& board); // vector of chars that will display the board; parameter is a constant reference to vector of charaters named 'board'

char winner(const vector<char>& board); // same as above but returns a character value; will return certain character based on board

bool isLegal(const vector<char>& board, int move);  // returns true or false value based on parameters of the board and the move

int humanMove(const vector<char>& board, char human);   // recieves board and char information for player 'human' and returns chosen move

int computerMove(vector<char> board, char computer); // receives board and returns AI move based on parameters that will be given later

void announceWinner(char winner, char computer, char human);    // receives information from parameters in parenthesis and returns character value

int main() // function called 'main' that can return an integer value
{   
    int move; // function called 'move' that can return an integer value
    const int NUM_SQUARES = 0;  // constant function given a value of 0
    vector<char> board(NUM_SQUARES, EMPTY); // vector of characters named 'board' is foundation for empty board

    instructions ();    // instructions function
    char human = humanPiece(); // declaring and initializing 
    char computer = opponent(human);
    char turn = X;

    displayBoard(board);    // shows board as it is currently
    
    while (winner(board) == NO_ONE) // while loop with parameters specifying that no winner has been determined yet so gameplay continues
    {
        if (turn == human)
        {
            move = humanMove(board, human);
            board[move] = human;
        }
        else
        {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        
        displayBoard(board);
        turn = opponent(turn);
    }
    announceWinner(winner(board), computer, human);
    
    return 0;
}

void instructions() // The following is what the player sees
{
    cout << "\nWelcome to the ultimate man-machine showdown:\nTic-Tac-Toe\n";
    cout << "--where human brain is pit against silicon processor.\n\n";

    cout << "Make your move known by entering a number 0 - 8.\nThe number";
    cout <<"corresponds to the desired board position,\nas illustrated:\n\n";

    cout << " 0 | 1 | 2\n";
    cout << " ---------\n";
    cout << " 3 | 4 | 5\n";
    cout << " ---------\n";
    cout << " 6 | 7 | 8\n\n";

    cout << "Prepare yourself, human.The battle is about to begin.\n\n";
}

char askYesNo(string question)  // returns a string of characters-string is named 'question'
{
    char response;  // return value is a character which is labeled 'response'
    
    do  // do loop
    {
        cout << question << " (y/n): "; // refers to question about first move
        cin >> response;    // player input
    }

    while (response != 'y' && response != 'n'); // while loop

    return response;    // goes back to asking for response to first move question as long as the input is not 'y' or 'n'
}

int askNumber(string question, int high, int low)   // returns an integer value, named 'askNumber', and parameters in parenthesis. Player must respond within a given range. The following is the loop.
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "):";
        cin >> number;
    }

    while (number > high || number < low);

    return number;
}

char humanPiece()
{
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y')
    {
        cout << "\nThen take the first move. You will need it.\n";
        return X;
    }
    else{
        cout << "\nYour bravery will be your undoing...I will go first.\n";
        return O;
    }
}

char opponent(char piece)
{
    if(piece == X)
    {
        return O;
    }
    
    else
    {
        return X;
    }
}

void displayBoard(const vector<char>& board)    // parameter is a constant reference to a vector of char named 'board.' 'displayBoard()' cannot change 'board'
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

char winner(const vector<char>& board)  // constant reference called 'board' as a parameter for char function named 'winner'
{
    // all possible winning rows
    const int WINNING_ROWS[8][3] = {    // array of the board 8x3
                                    {0,1,2},
                                    {3,4,5},
                                    {6,7,8},
                                    {0,3,6},
                                    {1,4,7},
                                    {2,5,8},
                                    {0,4,8},
                                    {2,4,6}
                                    };

    const int TOTAL_ROWS = 8;   // initializing a constant with value of 8

    // if any winning row has three values that are the same (and not EMPTY),
    // then we have a winner
    for(int row = 0; row < TOTAL_ROWS; ++row)   //parameters of for loop
    {
        if ( (board[WINNING_ROWS[row][0]] != EMPTY) &&
             (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
             (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
        {
            return board[WINNING_ROWS[row][0]];
        }
    }

        // since nobody has won, check for a tie (no empty squares left)
        if (count(board.begin(), board.end(), EMPTY) == 0)

        return TIE;

        // since nobody has won and it isn't a tie, the game ain't over

        return NO_ONE;
}

inline bool isLegal(int move, const vector<char>& board)    //testing true/false value called 'isLegal' where the board is passed through constant reference
{
    return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)    // 'humanMove' returns an integer value with parameters of current board and uses a constant reference
{
    int move = askNumber("Where will you move?", (board.size() - 1));
    while (!isLegal(move, board))   // asks player for input and while loop continues until a valid response is given
    {
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", (board.size() - 1));
    }
    cout << "Fine...\n";

    return move;    // continues loop
}

int computerMove(vector<char> board, char computer) //outlines possible moves for the AI - not a reference, but a value
{
    unsigned int move = 0;
    bool found = false;

    // if computer can win on next move, thats the move to make
    while(!found && move < board.size())
    {
        if (isLegal (move, board))  // first look for move to win
        {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        }
        if (!found)
        {
            ++move;
        }
    }

    // otherwise, if human can win on next move, that's the move to make
    if (!found) // or find spot needed to block player win
    {
        move = 0;
        char human = opponent(computer);

        while (!found && move < board.size())    // && means both parameters must be true
        {
            if (isLegal (move, board))
            {
                board[move] = human;
                found = winner (board) == human;
                board[move] = EMPTY;
            }
            if (!found)
            {
                ++move;
            }
        }
    }

    //otherwise, moving to the best open square is the move to make
    if (!found) // if no winning squares available, AI chooses from array with first available value
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        // pick best open squarewhile (!found && i < board.size())
        {
            move = BEST_MOVES[i];
            if (isLegal (move, board))
            {
                found = true;
            }

            ++i;
        }
    }

    cout << "I shall take square number " << move << endl;
    return move;
}

void announceWinner(char winner, char computer, char human)
{
    if (winner == computer)
    {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }

    else if (winner == human)
    {
        cout << winner << "'s won!\n";
        cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
        cout << "But never again! I, the computer, so swear it!\n";
    }

    else
    {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate...for this is the best you will ever achieve.\n";
    }
}