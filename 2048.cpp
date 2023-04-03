#include <iostream>               // Library for input/output                                                                                                                                                         
#include <ctime>                  // Library for generating random no's (array positions)
#include <conio.h>                // Library for _getch()
using namespace std;
int moves = 0, score = 0, highestscore = 0;         // Globally declare variables 

void display_board(int board[4][4])        // Function for generating game board
{
	// Just trying to make attractive Game's Interface

	cout << "\t\t\t\t\t\t " << "+=============+ " << endl;
	cout << "\t\t\t\t\t\t " << "|  2048 GAME  | " << endl;
	cout << "\t\t\t\t\t\t " << "+=============+ " << endl;

	cout << "\n\t\t\t\t " << "                [ INSTRUCTIONS ]                " << endl;
	cout << "\n\t\t\t\t " << "    - JOIN THE NUMBERS & GET TO THE 2084 TILE ! " << endl;
	cout << "\t\t\t\t " << "    - USE ARROW KEYS FOR THE MOVEMENT OF TILES !  " << endl;
	cout << "\t\t\t\t " << "    - PRESS 'n' TO START NEW GAME !  " << endl;
	cout << "\t\t\t\t " << "    - PRESS 'p' TO PAUSE THE GAME !  " << endl;
	cout << "\t\t\t\t " << "    - PRESS 'r' TO RESUME THE GAME ! " << endl;
	cout << "\t\t\t\t " << "    - PRESS ESC TO EXIT THE GAME !   " << endl;



	cout << "\n\t\t\t\t\t " << " +===========================+ " << endl;
	cout << "\t\t\t\t\t " << "           SCORE : " << score << endl;
	cout << "\t\t\t\t\t " << "           MOVES : " << moves << endl;
	cout << "\t\t\t\t\t " << "       HIGHEST SCORE : " << highestscore << endl;
	cout << "\t\t\t\t\t " << " +===========================+ " << endl;
	cout << endl;

	//generating game's board by using loops 

	for (int i = 0; i < 4; i++)        // using loop for rows        
	{
		cout << "\t\t\t\t\t+===============================+\n\t\t\t\t";
		for (int j = 0; j < 4; j++)   // using loop for columns
		{
			if (board[i][j] == 0)     // conditions to generate board accurately
				cout << "\t|   ";
			else
				cout << "\t| " << board[i][j] << " ";
		}
		cout << "\t|" << endl;
	}
	cout << "\t\t\t\t\t+===============================+\n\t\t\t\t";
}

void up_move(int board[4][4])   // function for moving up the tile's value 
{
	int movecheck = 0;
	int row, column, i, j;
	for (column = 0; column < 4; column++)  //for columns 
	{
		i = 0, j = column;             // other variables of board array to check the upper tile 
		for (row = 1; row < 4; row++)   // for rows
		{
			if (board[row][column] != 0)  // if any tile's value != 0
			{
				if (board[row - 1][column] == 0 || board[row - 1][column] == board[row][column])  // if upper tile's value = 0 || if upper tile's value = lower tile's value 
				{
					if (board[i][j] == board[row][column])  // if upper tile's value = lower tile's value
					{
						board[i][j] *= 2;                   // multilply upper tile's value with 2                                                                    
						board[row][column] = 0;             // do store zero in lower(previous) tile
						score = score + board[i][j];        // store the score in variable 

					}
					else
					{
						if (board[i][j] == 0)                    // if upper tile's value = 0
						{
							board[i][j] = board[row][column];    // do equal the upper tile's value = lower tile's value 
							board[row][column] = 0;              // do store zero in lower(previous) tile
						}
						else
						{
							board[++i][j] = board[row][column];   // move lower tiles to possible upper positions 
							board[row][column] = 0;               // do store zero in previous tile
						}
					}
					movecheck = 1;
				}
				else i++;
			}
		}
	}
	if (movecheck == 1)
		moves++;
}

void down_move(int board[4][4])   // function for moving down the tile's value 
{
	int movecheck = 0;
	int row, column, i, j;
	for (column = 0; column < 4; column++)   //for columns
	{
		i = 3, j = column;               // other variables of board array to check the lower tile 
		for (row = 2; row >= 0; row--)   // for rows
		{
			if (board[row][column] != 0)   // if any tile's value != 0
			{
				if (board[row + 1][column] == 0 || board[row + 1][column] == board[row][column])  // if lower tile's value = 0 || if lower tile's value = upper tile's value 
				{
					if (board[i][j] == board[row][column])  // if lower tile's value = upper tile's value
					{
						board[i][j] *= 2;              // multilply lower tile's value with 2 
						board[row][column] = 0;        // do store zero in upper(previous) tile
						score = score + board[i][j];   // store the score in variable 
					}
					else
					{
						if (board[i][j] == 0)          // if lower tile's value = 0
						{
							board[i][j] = board[row][column];    // do equal the lower tile's value = upper tile's value 
							board[row][column] = 0;              // do store zero in lower(previous) tile
						}
						else
						{
							board[--i][j] = board[row][column];  // move upper tiles to possible lower positions 
							board[row][column] = 0;              // do store zero in previous tile
						}
					}
					movecheck = 1;
				}
				else i--;
			}
		}
	}
	if (movecheck == 1)
	{
		moves++;
	}
}

void left_move(int board[4][4])   // function for moving left the tile's value 
{
	int movecheck = 0;
	int row, column, i, j;
	for (row = 0; row < 4; row++)   // for rows
	{
		i = row, j = 0;             // other variables of board array to check the left tile
		for (column = 1; column < 4; column++)   //for columns
		{
			if (board[row][column] != 0)    // if any tile's value != 0
			{
				if (board[row][column - 1] == 0 || board[row][column - 1] == board[row][column]) // if left tile's value = 0 || if left tile's value = right tile's value 
				{
					if (board[i][j] == board[row][column])     // if left tile's value = right tile's value
					{
						board[i][j] *= 2;              // multilply left tile's value with 2 
						board[row][column] = 0;        // do store zero in right(previous) tile
						score = score + board[i][j];   // store the score in variable 
					}
					else
					{
						if (board[i][j] == 0)          // if left tile's value = 0
						{
							board[i][j] = board[row][column];     // do equal the left tile's value = right tile's value 
							board[row][column] = 0;               // do store zero in right(previous) tile
						}
						else
						{
							board[i][++j] = board[row][column];   // move right tiles to possible left positions
							board[row][column] = 0;               // do store zero in previous tile
						}
					}
					movecheck = 1;
				}
				else j++;
			}
		}
	}
	if (movecheck == 1)
	{
		moves++;
	}
}

void right_move(int board[4][4])   // function for moving right the tile's value 
{
	int movecheck = 0;
	int row, column, i, j;
	for (row = 0; row < 4; row++)   // for rows
	{
		i = row, j = 3;            // other variables of board array to check the right tile 
		for (column = 2; column >= 0; column--)   //for columns
		{
			if (board[row][column] != 0)     // if any tile's value != 0
			{
				if (board[row][column + 1] == 0 || board[row][column + 1] == board[row][column])  // if right tile's value = 0 || if right tile's value = left tile's value 
				{
					if (board[i][j] == board[row][column])     // if right tile's value = left tile's value
					{
						board[i][j] *= 2;             // multilply right tile's value with 2 
						board[row][column] = 0;       // do store zero in left(previous) tile
						score = score + board[i][j];  // store the score in variable 
					}
					else
					{
						if (board[i][j] == 0)          // if right tile's value = 0
						{
							board[i][j] = board[row][column];    // do equal the right tile's value = left tile's value 
							board[row][column] = 0;              // do store zero in left(previous) tile
						}
						else
						{
							board[i][--j] = board[row][column];  // move left tiles to possible right positions 
							board[row][column] = 0;              // do store zero in previous tile
						}
					}
					movecheck = 1;
				}
				else j--;
			}
		}
	}
	if (movecheck == 1)
	{
		moves++;
	}
}

void Generate_new_number(int board[4][4])   // function to generate new numbers after every move 
{
	int i, j;
	srand(time(0));
	while (true)   // infinite loop
	{
		// generating random position 
		i = rand() % 4;
		j = rand() % 4;
		if (board[i][j] == 0)   // check whether tile's value is zero or not  
		{
			board[i][j] = pow(2, i % 2 + 1);  // this power formula will only generate 2 OR 4 which will insert in random position 
			break;
		}
	}

}

int check(int temp[4][4], int board[4][4]) // using a function to check whether any tile is zero or not 
{
	int Check = 1, i, j;
	for (i = 0; i < 4; i++)
	for (j = 0; j < 4; j++)
	if (temp[i][j] != board[i][j])    // condition to check whether all the tile's value in board = temporary array variable or not
	{
		Check = 0;
		break;
	}
	return Check;
}

int check_win(int board[4][4])         // function to check whether the user wins the game 
{
	//  Using loop to check whether any tile's score is 2048 
	for (int i = 0; i < 4; i++)      // for rows  
	{
		for (int j = 0; j < 4; j++)   // for columns 
		{
			if (board[i][j] == 2048)   // if any tile's value = 2048 
			{
				cout << "\n\t\t\t\t\t " << " +===========================+ " << endl;
				cout << "\t\t\t\t\t " << " |      CONGRATULATOINS        | " << endl;
				cout << "\t\t\t\t\t " << " |    YOU'VE WON THE GAME      | " << endl;
				cout << "\t\t\t\t\t " << " +===========================+   " << endl;
				return 0;
			}
		}
	}
}

int check_win2(int board[4][4])  // function for the 2nd possibility of highest score of tile 
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 131072)    // highest tile's score limit according to project requirements 
			{
				cout << "\t\t\t\t | You've Reached At Maximum Tile's Value |" << endl;
				return 0;
			}
		}
	}
}

int game_over(int board[4][4])
{
	int count = 0;
	int count1 = 0;

	// checking zeroes in each tile
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
				count++;           // remaining zeroes

		}
	}

	// checking possibilities of adding
	// conditions to check whether all tiles are still adding or not
	// different logic for corner tiles, side tiles & middle tiles 
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (i == 0 && j == 0)
			{
				if (board[i][j] == board[i][j + 1] || board[i][j] == board[i + 1][j])
				{
					count1++;
				}
			}

			if (i == 3 && j == 0)
			{
				if (board[i][j] == board[i - 1][j] || board[i][j] == board[i][j + 1])
				{
					count1++;
				}
			}

			if (i == 0 && j == 3)
			{
				if (board[i][j] == board[i][j - 1] || board[i][j] == board[i + 1][j])
				{
					count1++;
				}
			}

			if (i == 3 && j == 3)
			{
				if (board[i][j] == board[i - 1][j] || board[i][j] == board[i][j - 1])
				{
					count1++;
				}
			}

			else if (i == 1 && j == 1 || i == 1 && j == 2 || i == 2 && j == 1 || i == 2 && j == 2)
			{
				if (board[i][j] == board[i - 1][j] || board[i][j] == board[i][j - 1] || board[i][j] == board[i + 1][j]
					|| board[i][j] == board[i][j + 1])
				{
					count1++;
				}
			}
		}
	}

	// if there is no zero && no adding possibility
	if (count == 0 && count1 == 0)
	{
		cout << "\n\n\t\t\t\t\t   -----[ GAME OVER ]-----\n";
		return 0;
	}
}

void new_game(int board[4][4])   // Function for new game
{
	int x, y;
	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			board[x][y] = 0;        // do equal all tiles == 0
		}
	}

	// Generating 2 & 4 on random positions 
	int i, j;
	srand(time(0));
	while (1)
	{
		i = rand() % 4;
		j = rand() % 4;
		if (board[i][j] == 0)
		{
			board[i][j] = pow(2, i % 2 + 1);
			break;
		}
	}
	// do also equal the score == 0
	score = 0;
	moves = 0;
}

void first_turn(int board[4][4])  //function to generate two random no's 
{
	// this function will only executes 1st time
	int x, y;
	srand(time(0));
	while (true)   // infinite loop
	{
		// generating random position 
		x = rand() % 4;
		y = rand() % 4;
		if (board[x][y] == 0)   // check whether tile's value is zero or not  
		{
			board[x][y] = pow(2, x % 2 + 1);  // this power formula will only generate 2 OR 4 which will insert in random position 
			break;
		}
	}

	int i, j;
	srand(time(0));
	while (1)
	{
		i = rand() % 4;
		j = rand() % 4;
		if (board[i][j] == 0)
		{
			board[i][j] = pow(2, i % 2 + 1);
			break;
		}
	}
}
int main()    // main function
{
	system("color 0a");       // here 0 = black console color && a = font green color 

	// interface before starting game
	cout << "\n\t\t\t\t Enter Any Key To Play The Game " << endl;
	cout << "\n\t\t\t\t\t" << "+=============+ " << endl;
	cout << "\t\t\t\t\t" << "|  2048 GAME  | " << endl;
	cout << "\t\t\t\t\t" << "+=============+ " << endl;

	_getch();          // pause the screen 
	system("cls");     // clear the screen 

	int board[4][4] = { 0 }, temp[4][4] = { 0 };    // initializing two 2D arrays 
	first_turn(board);
	display_board(board);

	int i, j;
	int key;
	while (true)  //infinite loop
	{
		for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			temp[i][j] = board[i][j];       // storing board initial values in temporary array variable 

		key = _getch();
		system("cls");

		// moving fuctions according to their (arrows button) ascii codes

		if (key == 72) up_move(board);           // if user press up-arrow key apply up_move function
		if (key == 80) down_move(board);         // if user press down-arrow key apply down_move function
		if (key == 75) left_move(board);         // if user press left-arrow key apply left_move function
		if (key == 77) right_move(board);        // if user press right-arrow key apply right_move function
		if (key == 110) new_game(board);         // if user press 'n' key apply new_game function
		if (key == 27) break;                    // if user press esc key exit the game 
		if (key == 112)                          // if user press 'p'  key pause the game 
		{
			while (true)
			{
				// don't let user move to moving keys loop until user press r 
				system("cls");
				display_board(board);
				cout << "\n\t\t\t\t\t       ---| P A U S E |---" << endl;
				cout << "\n\t\t\t\t\t  Press 'r' to Resume The Game..." << endl;
				key = _getch();
				if (key == 114)                 // if user press 'r' key resume the game
				{
					system("cls");
					break;
				}
			}
		}

		if (score > highestscore)              // Condition To Show Highest Score according to project requirement
		{
			highestscore = score;              // store High Score in variable & display it in "Display_board(board)"
		}

		if (!check(temp, board))                // Function --> if any tile is empty           
			Generate_new_number(board);         // Function --> Generate No's 2 or 4 
		display_board(board);                   // Function --> Display the Board after generating no's

		if (!check_win(board))     // Function --> if any tile == 2048 
		{
			//statements according to project requirements 
			cout << "\n\t\t\t\t | Do YOU WANT TO CONTINUE YOUR GAME | " << endl;
			cout << "\t\t\t\t    - Press 1 To Continue... " << endl;
			cout << "\t\t\t\t    - Press Esc To Exit The Game..." << endl;

			if (key == 1)   // if user Press 1 it will Continue the game
			{
				continue;
			}
			if (key == 27)  // if user Press esc it will exit the game
			{
				break;
			}
		}

		// highest score limit according to project requirements 
		if (score >= 3866976)
		{
			cout << "\n\t\t\t\t | You've Reached At Maximum Score | " << endl;
			break;
		}

		// highest moves limit according to project requirements 
		if (moves >= 131038)
		{
			cout << "\n\t\t\t\t | You've Reached At Maximum Moves | " << endl;
			break;                 // break the loop & end the game
		}

		if (!check_win2(board))     // explained in checkwin2(board) function
			break;                  // break the loop & end the game

		if (!game_over(board))     // Function --> if all tile's are filled & no move is possible 
		{
			cout << "\n\t\t\t\t\t -> Press 'n' To Play New Game..." << endl;
			cout << "\t\t\t\t\t -> Press 'Esc' To Exit The Game... " << endl;
		}
	}

	system("pause");
	return 0;
}