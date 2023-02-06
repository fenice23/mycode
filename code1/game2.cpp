#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"
void menu()
{
	printf("*****************************************\n");
	printf("*****        Mine   Game!!!         *****\n");
	printf("*****         0. Exit Game          *****\n");
	printf("*****         1. Play Game          *****\n");
	printf("*****************************************\n");
}
void InitBoard(char board[][COLS], int rows, char content)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = content;
		}
	}
}
void DisplayBoard(char board[][COLS], int row, int col)
{
	printf("---------------------扫雷游戏----------------------\n");
	for (int i = 0; i <= col; i++)
		printf("%d ", i);
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		putchar(10);
	}
	printf("---------------------扫雷游戏----------------------\n");
}
void SetMine(char board[][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (1)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			count--;
			board[x][y] = '1';
		}
		if (!count)
			break;
	}
}
static int get_count_of_mine(char mine[][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void FindMine(char mine[][COLS], char show[][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (1)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾,你被炸死了!\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = get_count_of_mine(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
				if (row * col - win == EASY_COUNT)
				{
					printf("恭喜您,排完了所有的雷!\n");
					DisplayBoard(mine, row, col);
					break;
				}
			}
		}
		else
		{
			printf("输入的坐标非法!\n");
		}
	}
}
void game2()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, '0');
	InitBoard(show, ROWS, '*');
	DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
}