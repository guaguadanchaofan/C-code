#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

//��ӡ�˵�
void menu();


//��ʼ������
void initboard(char board[ROW][COL], int row, int col);


//��ӡ����
void displayboard(char board[ROW][COL], int row, int col);


//����
void moveboard(char board[ROW][COL], int row, int col);


//��������
void computermove(char board[ROW][COL], int row, int col);


//�ж��Ƿ���Ӯ
char iswin(char board[ROW][COL], int row, int col);


////�ж��Ƿ�ƽ��
//char isfull(char board[ROW][COL], int row, int col);



