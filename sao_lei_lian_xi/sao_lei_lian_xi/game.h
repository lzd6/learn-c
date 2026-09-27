#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEI 10
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//生成雷
void SetMine(char board[ROWS][COLS], int r, int c);

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int r, int c, char set);

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int r, int c);
//排雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int r,int c);

