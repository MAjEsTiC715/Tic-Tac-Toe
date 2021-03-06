// Tic-Tac-Toe (Header Version).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>		//for atoi
#include "EstablishBoard.h"
#include "NextMove.h"
#include "ExamineOutcome.h"

using namespace std;


int main(int argc, char *argv[])
{
	int games = 1;				//total games to play

								//if a number of games to play was passed in, change games
	if (argc > 1)
	{
		if (atoi(argv[1]) > 0)
			games = atoi(argv[1]);
	}

	int score[2];		//keeps scores for each player in arrays
	score[0] = 0;		//0 == X player
	score[1] = 0;		//1 = Y player; start at 0 score

	int first = 1; 		//helps switch first player

	char player = 'X';	//the current player

	while (games > 0)
	{
		bool victory = false;			//changed to true when victory confirmed
		bool tie = false;				//change to true when board is full
										//but no winner declared

		char board[boardSize][boardSize];//prepare board array

										 //fill board with '.'
		initBoard(board);

		//set up first player
		if (first == 1)
			player = 'X';
		else
			player = 'O';

		//run this game
		do
		{
			drawBoard(board, boardSize);

			getMove(board, boardSize, player);

			victory = checkForVictory(board, boardSize);

			//if player wins and happens to fill the final square
			//checking for a tie would evaluate true but we know its not a tie
			if (!victory)
				tie = checkFullBoard(board, boardSize);

		} while (!tie && !victory);

		//draw final board one more time
		drawBoard(board, boardSize);

		if (tie)
		{
			cout << "No winner\n";
		}
		else
		{
			//the last person to have moved must have set off the victory condition
			//so I'll have to reset the player switch at the end of getMove()
			if (player == 'X')
				player = 'O';
			else
				player = 'X';

			cout << "Player " << player << " has won this game!\n";

			//if X won,increment there score, otherwise increment O's score
			if (player == 'X')
				score[0]++;
			else
				score[1]++;
		}

		//switch player by flipping first value
		first *= -1;

		//finish this game
		games--;
	}

	//all games are done, show final scores
	cout << "Player X won " << score[0] << " games.\n";
	cout << "Player O won " << score[1] << " games.\n";

	//compare scores to anounce final winner
	if (score[0] > score[1])
		cout << "Player X wins the tournament!\n";
	else if (score[1] > score[0])
		cout << "Player O wins the tournament!\n";
	else
		cout << "The players have tied!\n";

	//game over
	return 0;
}