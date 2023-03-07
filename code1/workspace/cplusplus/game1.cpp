#define _CRT_SECURE_NO_WARNINGS 1
#include "game1.h"
void menu()
{
	printf("****************************************\n");
	printf("*****          Chess Game          *****\n");
	printf("*****         1. Play Game         *****\n");
	printf("*****         0. Exit Game         *****\n");
	printf("****************************************\n");
}
void InitBoard(char board[][COL], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[][COL], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != COL - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int k = 0; k < COL; k++)
			{
				printf("---");
				if (k != COL - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[][COL], int row)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入您要下棋的坐标:>");
		scanf("%d%d", &x, &y);
		if (x <= row && x >= 1 && y <= COL && y >= 1)
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("输入坐标非法,因为已经有落子,请重新输入!\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("输入坐标非法,请重新输入坐标!\n");
		}
	}
}
void ComputerMove(char board[][COL], int row)
{
	printf("电脑走:>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
char IsWin(char board[][COL], int row)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (int i = 0; i < COL; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[0][0];
	}
	if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2])
	{
		return board[1][1];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
				return 'C';
		}
	}
	return 'Q';
}
void game1()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW);
	DisplayBoard(board, ROW);
	char ret = 0;
	while (1)
	{
		PlayerMove(board, ROW);
		DisplayBoard(board, ROW);
		ret = IsWin(board, ROW);
		if (ret != 'C')
			break;
		ComputerMove(board, ROW);
		DisplayBoard(board, ROW);
		ret = IsWin(board, ROW);
		if (ret != 'C')
			break;
	}
	if (ret == 'Q')
	{
		printf("平局!\n");
	}
	else if (ret == '*')
	{
		printf("Player Win!\n");
	}
	else
	{
		printf("Computer Win!\n");
	}
	DisplayBoard(board, ROW);
}