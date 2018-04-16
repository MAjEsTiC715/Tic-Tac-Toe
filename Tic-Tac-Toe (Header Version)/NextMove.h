#pragma once
#include <iostream>
#include <cstdlib>		//for atoi
#include "ClearMemory.h"

using namespace std;


// An array and an int for the size of the array and the player
// gets a square form the player, checks if it is a valid
// move, puts player's char in the space
void getMove(char array[][boardSize], int boardSize, char &mark)
{
	//pointer to player marker
	char *ptr = &mark;

	cout << "Player " << *ptr << ": please enter your move.\n";

	//movement storage initialized to too high a value
	unsigned int row = boardSize;
	unsigned int column = boardSize;

	while ((row < 0 || row > 2) || (column < 0 || column > 2))
	{
		//get the square coordinates separated by a space
		cin >> row;
		cin >> column;
		clear_cin();
	}

	//is this square taken?
	if (array[row][column] != '.')
	{
		cout << "That square is already taken.\n";
		//get move again
		getMove(array, boardSize, mark);
	}
	else
	{
		//put the players piece in the square
		array[row][column] = *ptr;

		//switch player
		if (*ptr == 'X')
			*ptr = 'O';
		else
			*ptr = 'X';
	}


}