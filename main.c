/***************************************************************************************
**********
This is to certify that this project is our own work, based on our personal efforts in
studying and applying the concepts learned. We have constructed the functions and their
respective algorithms and corresponding code by ourselves. The program was run, tested,
and debugged by our own efforts. We further certify that we have not copied in part or
whole or otherwise plagiarized the work of other students and/or persons.
Alyssa Jane Santos, DLSU ID# 12209643
Samantha Breanne Sanchez, DLSU ID# 12209953 
Jeck Danielle Sanchez, DLSU ID# 12210145
****************************************************************************************
*********
*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

int gameOver(int over, int turn, int sum)
{
	int win = 0; 
	if(over == true && turn == true && sum < 15 && sum > 0)
	{
		printf("\n\t\t\t\tB wins!\n");
		win = 1;
	}
	else if(over == true && turn == false && sum < 15 && sum > 0)
	{
		printf("\n\t\t\t\tA wins!\n");
		win = 1;		
	}
	else if(over == true && turn == true && sum == 15)
	{
		printf("\n\t\t\t\tA wins!\n");
		win = 1;			
	}
	else if(over == true && turn == false && sum == 15)
	{
		printf("\n\t\t\t\tB wins!\n");
		win = 1;
	}
	
	return win;
}

int sum(int array[])
{
	int i;
	int sum = 0;
	for (i = 0; i < 3; i++)
	{
		sum += array[i];
	}
	return sum;
}

int isFull(int arr[])
{
	int i;
	int count = 0;
	for(i = 0; i < 3; i++)
	{
		if(arr[i] > 0)
			count++;
	}
	return count;
}

void storePeg(int pos[], int pegInp)
{
	int i;
	int found = 0;
	
	for(i = 0; i < 3; i++)
	{
		if(pos[i] == 0 && found < 1)
		{
			pos[i] = pegInp;
			found++;
		}
	}
}

void updatePeg(int peg[], int *size, int pegInp)
{
	int i, index, found = 0;
	
	for(i = 0; i < 9; i++)
	{
		if (peg[i] == pegInp)
		{
			index = i;
			found = 1;	
		}
		
	}
	if (found == 1)
	{
		for(i = index; i<(*size)-1; i++)
		{
			peg[i] = peg[i+1];
		}		
	}

	(*size)--;
}

int takenPegs(int peg[], int pegInp, int *size)
{
	int i, found = 0;
	for(i = 0; i < *size; i++)
	{
		if(peg[i] == pegInp)
			found = 1;
	}
	return found;
}

void negate(bool** i) //to negate the bool value 
{
	if (**i == false)
		**i = true;
	else if (**i == true)
		**i = false;
}

void board(int S[][SIZE], int play) //printing of board
{
	if (play == 10)
	{
		printf("\n\t\t\t   ~~ FINAL TURN ~~\n\n");		
	}
	else
		printf("\n\t\t\t   ~~ TURN %d ~~\n\n", play+1);
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("\t\t\t| %d  |  %d  |  %d  |\n", S[0][0], S[0][1], S[0][2]);
	printf("\t\t\t------------------\n");
    printf("\t\t\t| %d  |  %d  |  %d  |\n", S[1][0], S[1][1], S[1][2]);
	printf("\t\t\t------------------\n");
    printf("\t\t\t| %d  |  %d  |  %d  |\n\n", S[2][0], S[2][1], S[2][2]);
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

void NextPlayerMove (int peg[], int pos[][SIZE])
{
	//INITIALIZE ROWS AND COLUMNS
	int One[3] = {0, 0, 0};
	int Two[3] = {0, 0, 0};
	int Three[3] = {0, 0, 0};
	int Four[3] = {0, 0, 0};
	int Five[3] = {0, 0, 0};
	int Six[3] = {0, 0, 0};
	
	//INITIALIZE BOOLS
	bool ok = false;
	bool turn = true;
	bool next = false;
	bool* okP = &ok;	
	bool* turnP = &turn;	
	bool* nextP = &next;
	
	
	//INITIALIZE FREE AND OCCUPIED
	int row, col;
	bool free[3][3] = {	{true, true, true}, 
						{true, true, true}, 
						{true, true, true}};
	
//	bool occ[3][3] = {	{false, false, false}, 
//						{false, false, false}, 
//						{false, false, false}};

// occ is the same as pos[][] and S[][] where occ is just treated as the opposite of free.
// if needed to specify, occ is the same as the printed board where it shows the positions that are occupied which are the non-zero numbers in the board.
	//OTHER INITIALIZATIONS
	int over;
	int play = 0;
	int size = 9;	
	int pegInp;
	int flag;
	int i;
	
	//game starts here
	for(play = 0; play < 9; play++)
	{
		board(pos, play);
		
		if (turn == true)
			printf("\t\t\tPlayer A's turn:\n\n");
		else if (turn == false)
			printf("\t\t\tPlayer B's turn\n\n");
		
		//loop for taken positions
		do{
			//user input		
			do{
				flag = 0;
				printf("Enter coordinates [row col]: ");
				scanf("%d %d", &row, &col);	
				if(row > 3 || row < 1 || col > 3 || col < 1)
				{
					printf("Invalid coordinates.\n");
					flag = 1;			
				}
				if (free[row-1][col-1] == false)
				{
					printf("Position already has a peg.\n");
					flag = 1;	
				}
			}while (flag == 1);
				
			do{
				flag = 0;
				printf("Enter a peg: ");
				scanf("%d", &pegInp);
				if(pegInp > 9 || pegInp < 1)
				{
					printf("Invalid peg.\n");
					flag = 1;
				}
				if(takenPegs(peg, pegInp, &size) == 0)
				{
					printf("Number has already been used.\n");	
					flag = 1;	
				}
			}while (flag == 1);
			
			//check if the position if free or occupied
			if (free[row-1][col-1] == true)
				negate(&okP);

			pos[row-1][col-1] = pegInp;
			
			//delete pegInp from peg array
			updatePeg(peg, &size, pegInp);
		}while(free[row-1][col-1] == false);
		
		free[row-1][col-1] = false;
//		occ[row-1][col-1] == true;

		if(ok == true)
		{
			switch(row-1)
			{
				case 0: storePeg(One, pegInp);
						negate(&nextP);
						break;
				case 1: storePeg(Two, pegInp);
						negate(&nextP);
						break;
				case 2: storePeg(Three, pegInp);
						negate(&nextP);
			}

			if(next == true)
			{
				switch(col-1)
				{
					case 0: storePeg(Four, pegInp);
							negate(&nextP);
							negate(&okP);
							break;
					case 1: storePeg(Five, pegInp);
							negate(&nextP);
							negate(&okP);
							break;
					case 2: storePeg(Six, pegInp);
							negate(&nextP);
							negate(&okP);
							break;
				}	
			}
		}

		//winning conditions
		int totalIsFifteen = 0;
		for (i = 0; i < 6; i++)
		{
			switch(i)
			{
				case 0: if(isFull(One) == 3)
						{
							if(sum(One) < 15)
							{
								over = true;
								if(gameOver(over, turn, sum(One)) == 1)
								{
									i = 6;
									play = 9;									
								}
							}
							if(sum(One) == 15)
							{
								totalIsFifteen++;
								if(totalIsFifteen == 6)
								{
									over = true;
									if(gameOver(over, turn, sum(One)) == 1)
									{
										i = 6;
										play = 9;									
									}
								}
							}
						}
						else
							over = false;
						break;
				case 1: if(isFull(Two) == 3)
						{
							if(sum(Two) < 15)
							{
								over = true;
								if(gameOver(over, turn, sum(Two)) == 1)
								{
									i = 6;
									play = 9;									
								}
							}
							if(sum(Two) == 15)
							{
								totalIsFifteen++;
								if(totalIsFifteen == 6)
								{
									over = true;
									if(gameOver(over, turn, sum(Two)) == 1)
									{
										i = 6;
										play = 9;									
									}
								}
							}
						}
						else
							over = false;
						break;
				case 2: if(isFull(Three) == 3)
						{
							if(sum(Three) < 15)
							{
								over = true;
								if(gameOver(over, turn, sum(Three)) == 1)
								{
									i = 6;
									play = 9;									
								}
							}
							if(sum(Three) == 15)
							{
								totalIsFifteen++;
								if(totalIsFifteen == 6)
								{
									over = true;
									if(gameOver(over, turn, sum(Three)) == 1)
									{
										i = 6;
										play = 9;									
									}
								}
							}
						} 
						else
							over = false;
						break;
				case 3: if(isFull(Four) == 3)
						{
							if(sum(Four) < 15)
							{
								over = true;
								if(gameOver(over, turn, sum(Four)) == 1)
								{
									i = 6;
									play = 9;									
								}
							}
							if(sum(Four) == 15)
							{
								totalIsFifteen++;
								if(totalIsFifteen == 6)
								{
									over = true;
									if(gameOver(over, turn, sum(Four)) == 1)
									{
										i = 6;
										play = 9;									
									}
								}
							}
						}
						else
							over = false;
						break;
				case 4: if(isFull(Five) == 3)
						{
							if(sum(Five) < 15)
							{
								over = true;
								if(gameOver(over, turn, sum(Five)) == 1)
								{
									i = 6;
									play = 9;									
								}
							}
							if(sum(Five) == 15)
							{
								totalIsFifteen++;
								if(totalIsFifteen == 6)
								{
									over = true;
									if(gameOver(over, turn, sum(Five)) == 1)
									{
										i = 6;
										play = 9;									
									}
								}
							}
						}
						else
							over = false;
						break;
				case 5: if(isFull(Six) == 3)
						{
							if(sum(Six) < 15)
							{
								over = true;
								if(gameOver(over, turn, sum(Six)) == 1)
								{
									i = 6;
									play = 9;									
								}
							}
							if(sum(Six) == 15)
							{
								totalIsFifteen++;
								if(totalIsFifteen == 6)
								{
									over = true;
									if(gameOver(over, turn, sum(Six)) == 1)
									{
										i = 6;
										play = 9;									
									}
								}
							}
						}
						else
							over = false;
			}
		}
		if(over == false)
			negate(&turnP);
	}
	board(pos, play);
}

int main()
{
	//INITIALIZE BOARD
	int S[SIZE][SIZE] = {	{0, 0, 0}, 
							{0, 0, 0}, 
							{0, 0, 0}};
	int Peg[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	NextPlayerMove(Peg, S);
	
	return 0;
}