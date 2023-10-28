#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

//打印菜单
void menu();


//初始化棋盘
void initboard(char board[ROW][COL], int row, int col);


//打印棋盘
void displayboard(char board[ROW][COL], int row, int col);


//下棋
void moveboard(char board[ROW][COL], int row, int col);


//电脑下棋
void computermove(char board[ROW][COL], int row, int col);


//判断是否输赢
char iswin(char board[ROW][COL], int row, int col);


////判断是否平局
//char isfull(char board[ROW][COL], int row, int col);



