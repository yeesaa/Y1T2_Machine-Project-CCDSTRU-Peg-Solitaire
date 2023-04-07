#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

//SYSTEM VARIABLES
/*
	int free = {{0, 0, 0}, 
				{0, 0, 0}, 
				{0, 0, 0}};
	int occ = {	{0, 0, 0}, 
				{0, 0, 0}, 
				{0, 0, 0}};
	
	int One[SIZE] = {0, 0, 0};
	int Two[SIZE] = {0, 0, 0};
	int Three[SIZE] = {0, 0, 0};
	int Four[SIZE] = {0, 0, 0};
	int Five[SIZE] = {0, 0, 0};
	int Six[SIZE] = {0, 0, 0};
	int Peg[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	bool ok = false;
	bool turn = true;
	bool over;
	bool next = false;

*/

bool negate(bool i) //to negate the bool value 
{
	if (i == false)
		i = true;
	if (i == true)
		i = false;
	printf("%d\n", i);
	
	return i;
}

void board(int S[][SIZE], int play) //printing of board
{
	printf("\n\t\t\t   ~~ TURN %d ~~\n\n", play+1);
	printf("\t\t===================================\n\n");
	printf("\t\t\t| %d  |  %d  |  %d  |\n", S[0][0], S[0][1], S[0][2]);
	printf("\t\t\t------------------\n");
    printf("\t\t\t| %d  |  %d  |  %d  |\n", S[1][0], S[1][1], S[1][2]);
	printf("\t\t\t------------------\n");
    printf("\t\t\t| %d  |  %d  |  %d  |\n\n", S[2][0], S[2][1], S[2][2]);
	printf("\t\t===================================\n\n");
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
	
	//INITIALIZE FREE AND OCCUPIED
	int row, col;
	bool free[3][3] = {	{true, true, true}, 
						{true, true, true}, 
						{true, true, true}};
	
	bool occ[3][3] = {	{false, false, false}, 
						{false, false, false}, 
						{false, false, false}};
	//OTHER INITIALIZATIONS
	int play = 0;
	int flag;
	int pegInp;
	
	//game starts here
	for(play = 0; play < 9; play++)
	{
		board(pos, play);
		
		if (turn == true)
			printf("\t\t\tPlayer A's turn:\n\n");
		else if (turn == false)
			printf("\t\t\tPlayer B's turn");
		
		//loop for taken positions
//		do{
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
			}while (flag == 1);
			
			//check if the position if free or occupied
			if (free[row][col] == true)
			{
				ok = negate(ok);
				printf("%d", ok);
			}			
		}	

//	}while
	
	
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