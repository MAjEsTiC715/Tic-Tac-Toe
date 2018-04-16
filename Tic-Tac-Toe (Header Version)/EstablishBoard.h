#pragma once

#include <iostream>
#include <cstdlib>		//for atoi

using namespace std;

extern const int boardSize = 3;

// Prepares a fresh game board
void initBoard(char array[][boardSize])
{
	//rows
	for (int i = 0; i < boardSize; i++)
	{
		//columns
		for (int j = 0; j < boardSize; j++)
		{
			array[i][j] = '.';
		}
	}
}


// An array and an int for the size of the array
// draws the current state of the board
void drawBoard(char array[][boardSize], int boardSize)
{
	// print column coordinates
	cout << "\n  0  1  2\n";

	//rows
	for (int i = 0; i < boardSize; i++)
	{
		//print row coordinates
		cout << i << " ";

		//columns
		for (int j = 0; j < boardSize; j++)
		{
			//print square with spaces
			cout << array[i][j] << "  ";
		}

		//space for next row
		cout << endl;
	}

	//some space underneath
	cout << endl;
}