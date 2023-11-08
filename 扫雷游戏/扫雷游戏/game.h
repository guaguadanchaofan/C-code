#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define  ROW 9
#define  COL 9

#define  ROWS ROW+2
#define  COLS COL+2

#define minecount 10



void initborad(char borad[ROWS][COLS],int rows, int cols,char set);


void dispalyborad(char borad[ROWS][COLS], int row, int col);


void setmine(char borad[ROWS][COLS], int row, int col);


void finemine(char borad[ROWS][COLS], char show[ROWS][COLS], int row, int col);


int get_mine_count(char borad[ROWS][COLS], int x, int y);