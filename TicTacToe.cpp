/*
* Main.cpp
*
* Version information v0.1
* Author: Dr. Effirul Ramlan
* Date: 18/10/2019
* Description: A simple tic-tac-toe program in C++ using pointers
* Copyright notice
*/

#include <iostream>
using namespace std;

void CheckWin(char c[], int &i);
void PlayGame(char c[], int &i, int &p, char m);
void ResetBoard(char c[]);

int main()
{
	char square[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int player = 1, result, choice;
	char mark;
	
	do
	{
		ResetBoard(square);
		player = (player % 2) ? 1 : 2;

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;

		mark = (player == 1) ? 'X' : int(178);
		PlayGame(square, choice, player, mark);
		CheckWin(square, result);
		player++;
	} while (result == -1);

	ResetBoard(square);
	cout << "   ----- GAME OVER -----\n";
	if (result == 1)
		cout << "   Player " << --player << " WIN ";
	else
		cout << "   Game DRAW";

	cin.ignore();
	cin.get();
	return 0;
}

// Function to check the board status and update the result variable
// Result = 1, if there is a win
// Result = 0, if it is a draw
// Result = -1, to indicate that the game is still ongoing
//
void CheckWin(char square[], int &result)
{
	char* ptrSquare{ &square[0] };
	int* ptrResult{ &result };

	// Checking the status of the array value using pointer
	if (ptrSquare[1] == ptrSquare[2] && ptrSquare[2] == ptrSquare[3])
		*ptrResult = 1;
	else if (ptrSquare[4] == ptrSquare[5] && ptrSquare[5] == ptrSquare[6])
		*ptrResult = 1;
	else if (ptrSquare[7] == ptrSquare[8] && ptrSquare[8] == ptrSquare[9])
		*ptrResult = 1;
	else if (ptrSquare[1] == ptrSquare[4] && ptrSquare[4] == ptrSquare[7])
		*ptrResult = 1;
	else if (ptrSquare[2] == ptrSquare[5] && ptrSquare[5] == ptrSquare[8])
		*ptrResult = 1;
	else if (ptrSquare[3] == ptrSquare[6] && ptrSquare[6] == ptrSquare[9])
		*ptrResult = 1;
	else if (ptrSquare[1] == ptrSquare[5] && ptrSquare[5] == ptrSquare[9])
		*ptrResult = 1;
	else if (ptrSquare[3] == ptrSquare[5] && ptrSquare[5] == ptrSquare[7])
		*ptrResult = 1;
	else if (ptrSquare[1] != '1' && ptrSquare[2] != '2' && ptrSquare[3] != '3'
		&& ptrSquare[4] != '4' && ptrSquare[5] != '5' && ptrSquare[6] != '6'
		&& ptrSquare[7] != '7' && ptrSquare[8] != '8' && ptrSquare[9] != '9')
		*ptrResult = 0;
	else
		*ptrResult = -1;
}

// Function for playing tic-tac-toe game
// The box will change according to the selection made by player
// Player will pick again if the number is invalid 
//
void PlayGame(char square[], int &choice, int &player, char mark) {
	char* ptrSquare{ &square[0] };
	
	// check the status of array and choice made by player
	if (choice == 1 && ptrSquare[1] == '1')
		ptrSquare[1] = mark;
	else if (choice == 2 && ptrSquare[2] == '2')
		ptrSquare[2] = mark;
	else if (choice == 3 && ptrSquare[3] == '3')
		ptrSquare[3] = mark;
	else if (choice == 4 && ptrSquare[4] == '4')
		ptrSquare[4] = mark;
	else if (choice == 5 && ptrSquare[5] == '5')
		ptrSquare[5] = mark;
	else if (choice == 6 && ptrSquare[6] == '6')
		ptrSquare[6] = mark;
	else if (choice == 7 && ptrSquare[7] == '7')
		ptrSquare[7] = mark;
	else if (choice == 8 && ptrSquare[8] == '8')
		ptrSquare[8] = mark;
	else if (choice == 9 && ptrSquare[9] == '9')
		ptrSquare[9] = mark;
	else
	{
		cout << "Invalid move - Please choose the no. of the box";
		player--;
		cin.ignore();
		cin.get();
	}
}

// Init function to begin the game
//
void ResetBoard(char square[])
{
	char* ptrSquare{ &square[0] };
	system("cls");
	cout << "*****************************";
	cout << "\n\tTic Tac Toe\n";
	cout << "*****************************";
	cout << "\nPlayer 1 (X)  -  Player 2 (" << char(int(178)) << ")\n\n";
	cout << endl;
	cout << "          |     |     " << endl;
	cout << "       " << ptrSquare[1] << "  |  " << ptrSquare[2] << "  |  " << ptrSquare[3] << endl;
	cout << "     _____|_____|_____" << endl;
	cout << "          |     |     " << endl;
	cout << "       " << ptrSquare[4] << "  |  " << ptrSquare[5] << "  |  " << ptrSquare[6] << endl;
	cout << "     _____|_____|_____" << endl;
	cout << "          |     |     " << endl;
	cout << "       " << ptrSquare[7] << "  |  " << ptrSquare[8] << "  |  " << ptrSquare[9] << endl;
	cout << "          |     |     " << endl << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
