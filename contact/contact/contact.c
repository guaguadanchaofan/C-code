#include"contact.h"


void meau()
{
	printf("-------------------------------------------------------\n");
	printf("-------------1.add                  2.del--------------\n");
	printf("-------------3.search               4.modify-----------\n");
	printf("-------------5.show                 6.sort-------------\n");
	printf("-------------0.exit                       -------------\n");
	printf("-------------------------------------------------------\n");
	printf("请输入操作>>\n");
}

//加载通讯录
void Loadinfo(Contact* pc)
{
	FILE* pfread = fopen("contact.txt", "rb");
	if (pfread == NULL)
	{
		perror("LoadContact");
		return;
	}
	Peoinfo tmp = { 0 };
	while (fread(&tmp, sizeof(Peoinfo), 1, pfread) == 1)
	{
		addcapacity(pc);
		pc->data[pc->count] = tmp;
		pc->count++;
	}
	fclose(pfread);
	pfread = NULL;
}
//初始化通讯录
int initcontact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (Peoinfo*)calloc(3, sizeof(Peoinfo));
	if (pc->data == NULL)
	{
		return 1;
	}
	else
	{
		pc->capacity = 3;
		return 0;
	}
	Loadinfo(pc);
}



//增容
void addcapacity(Contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		Peoinfo* ptr = (Peoinfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(Peoinfo));//扩容+2
		if (ptr == NULL)
		{
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("增容成功，容量+2\n");
		}
	}
}

//添加联系人
void add(Contact* pc)
{
	assert(pc);
	addcapacity(pc);//增容
	printf("请输入要增加人的姓名>\n");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入要增加人的性别>\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入要增加人的年龄>\n");
	scanf("%d", &pc->data[pc->count].age);
	printf("请输入要增加人的电话>\n");
	scanf("%d", &pc->data[pc->count].tele);
	printf("请输入要增加人的地址>\n");
	scanf("%s", pc->data[pc->count].address);
	pc->count++;
}


int findname(const Contact* pc, const char* name)
{
	assert(pc && name);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)//遍历对比
		{
			return i;
		}
	}
	return -1;
}

//删除通讯录(按名字删除)
void del(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	if (pc->count == 0)
	{
		printf("通讯录为空无法删除\n");
		return;
	}
	printf("输入要删除的人名字>>\n");
	scanf("%s", name);
	int ret = findname(pc, name);
	if (ret == -1)
	{
		printf("找不到要删除的人\n");
		return;
	}
	for (int i = ret; i < pc->count - 1; i++)//往后遍历覆盖数据
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}


//显示通讯录
void show(Contact* pc)
{
	assert(pc);
	int i = 0;
	if (pc->count == 0)
	{
		printf("通讯录空\n");
		return;
	}
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-15s\n", "名字", "性别", "年龄", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-15s\t%-5s\t%-5d\t%-12d\t%-15s\n", pc->data[i].name,
			                                        pc->data[i].sex, 
			                                        pc->data[i].age, 
			                                        pc->data[i].tele,
			                                        pc->data[i].address);
	}
}


//查找联系人（按名字）
void search(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	if (pc->count == 0)
	{
		printf("通讯录为空无法查找\n");
		return;
	}
	printf("请输入要查找人的名字>>\n");
	scanf("%s", name);
	int ret = findname(pc, name);
	if (ret == -1)
	{
		printf("找不到要查找的人\n");
		return;
	}
	printf("找到了，显示如下>>>\n");
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-15s\n", "名字", "性别", "年龄", "电话", "地址");
	printf("%-15s\t%-5s\t%-5d\t%-12d\t%-15s\n", pc->data[ret].name,
		pc->data[ret].sex,
		pc->data[ret].age,
		pc->data[ret].tele,
		pc->data[ret].address);
	
}

//更改联系人信息
void modify(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录无联系人无法更改\n");
		return;
	}
	char name[20] = { 0 };
	printf("请输入要更改的联系人姓名>>\n");
	scanf("%s", name);
	int ret = findname(pc, name);
	if (ret == -1)
	{
		printf("找不到要更改的人\n");
		return;
	}
	printf("请输入要更改人的姓名>\n");
	scanf("%s", pc->data[ret].name);
	printf("请输入要更改人的性别>\n");
	scanf("%s", pc->data[ret].sex);
	printf("请输入要更改人的年龄>\n");
	scanf("%d", &pc->data[ret].age);
	printf("请输入要更改人的电话>\n");
	scanf("%d", &pc->data[ret].tele);
	printf("请输入要更改人的地址>\n");
	scanf("%s", pc->data[ret].address);
}


//比较
void cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
//排序
void sort(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录空无法排序\n");
		return;
	}
	qsort(pc->data, pc->count, sizeof(Peoinfo), cmp);//升序
	printf("排序成功\n");
}


//释放内存
void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}


//保存
void save(Contact* pc)
{
	assert(pc);
	FILE* pfwrite = fopen("contact.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("save");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(Peoinfo), 1, pfwrite);
	}
}