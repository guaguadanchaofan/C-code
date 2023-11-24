#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
enum opt //枚举菜单选项
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

typedef struct Peoinfo //人信息结构体
{
	char name[20];
	char sex[6];
	int age;
	int tele;
	char address[20];

}Peoinfo;


typedef struct Contact //通讯录结构体
{
	Peoinfo* data;
	int count;
	int capacity;
}Contact;




void meau();

void add(Contact* pc);//增加

int initcontact(Contact* pc);//初始化通讯录

void addcapacity(Contact* pc);//扩容

void del(Contact* pc);//删除

void show(Contact* pc);//显示

void search(Contact* pc);//查找联系人(按名字查找)

void modify(Contact* pc);//更改联系人信息

void sort(Contact* pc);//排序

void Loadinfo(Contact* pc);//加载通讯录

void DestroyContact(Contact* pc);//释放内存

void save(Contact* pc);//保存
