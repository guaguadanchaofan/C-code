#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
enum opt //ö�ٲ˵�ѡ��
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

typedef struct Peoinfo //����Ϣ�ṹ��
{
	char name[20];
	char sex[6];
	int age;
	int tele;
	char address[20];

}Peoinfo;


typedef struct Contact //ͨѶ¼�ṹ��
{
	Peoinfo* data;
	int count;
	int capacity;
}Contact;




void meau();

void add(Contact* pc);//����

int initcontact(Contact* pc);//��ʼ��ͨѶ¼

void addcapacity(Contact* pc);//����

void del(Contact* pc);//ɾ��

void show(Contact* pc);//��ʾ

void search(Contact* pc);//������ϵ��(�����ֲ���)

void modify(Contact* pc);//������ϵ����Ϣ

void sort(Contact* pc);//����

void Loadinfo(Contact* pc);//����ͨѶ¼

void DestroyContact(Contact* pc);//�ͷ��ڴ�

void save(Contact* pc);//����
