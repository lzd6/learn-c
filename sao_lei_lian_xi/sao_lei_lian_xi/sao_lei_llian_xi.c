#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//排雷
static int GetMinecount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] +
		mine[x - 1][y + 1] + mine[x][y - 1] +
		mine[x][y + 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	int win = 0;
	while (win < r * c - LEI)
	{
		printf("请输入要排的坐标:");
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					int count = GetMinecount(mine, x, y);
					show[x][y] =(char) count + '0';
					DisplayBoard(show, ROW, COL);
					win++;
				}
			}
			else
				printf("该雷已经排查过,不用重复排查\n");
		}
		else
			printf("非法坐标，请重新输入\n");
	}
	if (win ==r * c - LEI)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}


//设置雷
void SetMine(char board[ROWS][COLS], int r, int c)
{
	int count = LEI;
	while (count)
	{
		int x = rand() % r + 1;
		int y = rand() % c + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int r, int c, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < r;i++)
	{
		for (j = 0;j < c;j++)
		{
			board[i][j] = set;
		}
	}
}



//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int r, int c)
{
	int i = 0, j = 0;
	for (j = 0;j <= c;j++)
	{
		printf("%d ", j);

	}
	printf("\n");
	for (i = 1;i <= r;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= c;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
