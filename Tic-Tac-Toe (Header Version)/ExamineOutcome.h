#pragma once


// An array and an int for the size of the array
// Returns true if the board is full
// to determine if the game ends in a tie
bool checkFullBoard(char array[][boardSize], int boardSize)
{
	//rows
	for (int i = 0; i < boardSize; i++)
	{
		//columns
		for (int j = 0; j < boardSize; j++)
		{
			//if there is still at least one open square, there is no tie.
			if (array[i][j] == '.')
			{
				return false;
			}
		}
	}

	//if we make it past loops, there must be a full board
	return true;

}

// An array and an int for the size of the array
// Returns true if a player has won
// determine if a player has three in a row

bool checkForVictory(char array[][boardSize], int boardSize)
{
	//keep count of owned squares
	unsigned int countX = 0;
	unsigned int countO = 0;

	//first we check rows for victory
	for (int i = 0; i < boardSize; i++)
	{
		//make sure each row count is reset
		countX = 0;
		countO = 0;

		//columns
		for (int j = 0; j < boardSize; j++)
		{
			//increment which ever marker is found
			//or if empty space, forget checking the rest
			if (array[i][j] == '.')
				break;
			else if (array[i][j] == 'O')
				countO++;
			else if (array[i][j] == 'X')
				countX++;
		}

		//did we find a winner?
		if (countX == 3 || countO == 3)
			return true;
	}

	//if not, check columns for victory
	for (int j = 0; j < boardSize; j++)
	{
		//make sure each column count is reset
		countX = 0;
		countO = 0;

		//loop through rows
		for (int i = 0; i < boardSize; i++)
		{
			//increment which ever marker is found
			//or if empty space, forget checking the rest
			if (array[i][j] == '.')
				break;
			else if (array[i][j] == 'O')
				countO++;
			else if (array[i][j] == 'X')
				countX++;
		}

		//did we find a winner?
		if (countX == 3 || countO == 3)
			return true;
	}

	//if not, check left to right diagonal
	//make sure count is reset outside of the loop
	countX = 0;
	countO = 0;
	for (int i = 0; i < boardSize; i++)
	{
		//increment which ever marker is found
		//or if empty space, forget checking the rest
		if (array[i][i] == '.')
			break;
		else if (array[i][i] == 'O')
			countO++;
		else if (array[i][i] == 'X')
			countX++;
	}

	//did we find a winner?
	if (countX == 3 || countO == 3)
		return true;

	//if not, check last diagonal right to left
	//make sure count is reset outside of the loop
	countX = 0;
	countO = 0;
	for (int i = 0, j = (boardSize - 1); i < boardSize; i++, j--)
	{
		//increment which ever marker is found
		//or if empty space, forget checking the rest
		if (array[i][j] == '.')
			break;
		else if (array[i][j] == 'O')
			countO++;
		else if (array[i][j] == 'X')
			countX++;
	}

	//did we find a winner?
	if (countX == 3 || countO == 3)
		return true;

	//if we found no winning conditions
	return false;

}