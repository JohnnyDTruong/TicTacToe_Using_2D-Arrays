/*
	Jonathan Truong
	Tic-Tac-Toe (using 2d arrays)
*/

#include <iostream>
using namespace std;

//this function allows the players to play
//player 1 is 'X'
//player 2 is 'O'
void make_move(char player, char arr[3][3]) {
	int row;
	int col;
	bool taken = false;
	do {
		std::cout << "Welcome to Tic-Tac-Toe" << endl;
		std::cout << "======================" << endl;
		do
		{
			std::cout << "Which row would you like (0-2): " << endl;
			std::cin >> row;
			std::cout << "Which col would you like (0-2): " << endl;
			std::cin >> col;
		} while (col >= 3 || col < 0 || row >= 3 || row < 0);

		//this if statement does not allow the spot to be taken when
		//it has already been taken
		//so it tells you to choose another empty spot
		if (arr[row][col] == 'X' || arr[row][col] == 'O')
		{
			cout << "\n Sorry, the spot has been taken!!" << endl;
			taken = true;
		}
		else
		{
			taken = false;
			arr[row][col] = player;
		}
	} while (taken);
}

//these functions do not allow the letters to overlap each other
//so when X is there it cannot be replaced by O
//when the rows are the same
bool rowsSame(char c, char arr[3][3]) 
{
	for (int i = 0; i < 3; ++i) {
		if (c == arr[i][0] && c == arr[i][1] && c == arr[i][2]) { return true; }
	}
	return false;
}

//when the columns are the same
bool colsSame(char c, char arr[3][3]) 
{
	for (int i = 0; i < 3; ++i) {
		if (c == arr[0][i] && c == arr[1][i] && c == arr[2][i]) { return true; }
	}
	return false;
}

//when the diagnol lines are the same
bool diagonalsSame(char c, char arr[3][3]) 
{
	if (c == arr[0][0] && c == arr[1][1] && c == arr[2][2]) { return true; }
	if (c ==arr[0][2] && c == arr[1][1] && c == arr[2][0]) { return true; }
	return false;
}

//this function tells the players who won whenever someone
//gets three X or O in a row, column, or diagnol
bool game_win(char c, char arr[3][3]){
 return rowsSame(c, arr) || colsSame(c, arr) || diagonalsSame(c, arr); }

char game_win(char arr[3][3]) { return game_win('X', arr) || game_win('O', arr); }


//this function builds the tic tac toe board
void print_board(char arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr[i][j];
			if (j != 2) {
				std::cout << "|";
			}
		}
		if (i != 2) {
			std::cout << "\n-----\n";
		}
	}
	std::cout << endl;
}

//this checks the empty spot
//game ends when all spots are filled
bool check_empty(char arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == ' ')
			return true;
		}
	}	
	return false;
}

//this function allows either player 1 or player 2 to win
//when there are three 'X' or three 'O' in a row
//column or in a diagnol then the that player will win
// player 1 is 'X' and player 2 is 'O'
void checkwin(char arr[3][3], char current_player) 
{
	//for player 1 and player 2
	//for rows, columns, diagnol wins
	if (rowsSame(current_player, arr) || colsSame(current_player, arr) || diagonalsSame(current_player, arr))
	{
		cout << "Player " << current_player << " WINS!!" << endl;
	}
}

//this function determines what player goes
//this tells the players who won
//the function will check when every space is filled and if it the game will end
int main() {
	char arr[3][3] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char player1 = 'X';
	char player2 = 'O';
	char current_player = player1;
	while (!game_win(arr) && check_empty(arr)) {
		if (current_player == player1) cout << "\n Player 1 turn 'X' " << endl;
		else cout  << "\n Player 2 turn 'O' " << endl;
		make_move(current_player, arr);
		current_player = current_player == player1 ? player2 : player1;
		checkwin(arr, current_player);
		print_board(arr);
	}
	current_player = current_player == player1 ? player2 : player1;
	cout << "Player " << current_player << " WINS!!" << endl;
	return 0;
}
 /*


 Player 1 turn 'X'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):

0
Which col would you like (0-2):
0
X| |
-----
 | |
-----
 | |

 Player 2 turn 'O'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
1
Which col would you like (0-2):
0
X| |
-----
O| |
-----
 | |

 Player 1 turn 'X'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
1
Which col would you like (0-2):
1
X| |
-----
O|X|
-----
 | |

 Player 2 turn 'O'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
2
Which col would you like (0-2):
0
X| |
-----
O|X|
-----
O| |

 Player 1 turn 'X'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
2
Which col would you like (0-2):
2
X| |
-----
O|X|
-----
O| |X
Player X WINS!!

C:\Users\CSUFTitan\source\repos\TicTacToeExample1\Debug\TicTacToeExample1.exe (process 6540) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .



  CAT'S game
 Player 1 turn 'X'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
0
Which col would you like (0-2):
0
X| |
-----
 | |
-----
 | |

 Player 2 turn 'O'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
1
Which col would you like (0-2):
1
X| |
-----
 |O|
-----
 | |

 Player 1 turn 'X'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
2
Which col would you like (0-2):
2
X| |
-----
 |O|
-----
 | |X

 Player 2 turn 'O'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
0
Which col would you like (0-2):
2
X| |O
-----
 |O|
-----
 | |X

 Player 1 turn 'X'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
2
Which col would you like (0-2):
0
X| |O
-----
 |O|
-----
X| |X

 Player 2 turn 'O'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
2
Which col would you like (0-2):
1
X| |O
-----
 |O|
-----
X|O|X

 Player 1 turn 'X'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
0
Which col would you like (0-2):
1
X|X|O
-----
 |O|
-----
X|O|X

 Player 2 turn 'O'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
1
Which col would you like (0-2):
0
X|X|O
-----
O|O|
-----
X|O|X

 Player 1 turn 'X'
Welcome to Tic-Tac-Toe
======================
Which row would you like (0-2):
1
Which col would you like (0-2):
2
X|X|O
-----
O|O|X
-----
X|O|X

C:\Users\CSUFTitan\source\repos\TicTacToeExample1\Debug\TicTacToeExample1.exe (process 13324) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

 */