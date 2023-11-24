#include"contact.h"


void meau()
{
	printf("-------------------------------------------------------\n");
	printf("-------------1.add                  2.del--------------\n");
	printf("-------------3.search               4.modify-----------\n");
	printf("-------------5.show                 6.sort-------------\n");
	printf("-------------0.exit                       -------------\n");
	printf("-------------------------------------------------------\n");
	printf("���������>>\n");
}

//����ͨѶ¼
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
//��ʼ��ͨѶ¼
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



//����
void addcapacity(Contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		Peoinfo* ptr = (Peoinfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(Peoinfo));//����+2
		if (ptr == NULL)
		{
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("���ݳɹ�������+2\n");
		}
	}
}

//�����ϵ��
void add(Contact* pc)
{
	assert(pc);
	addcapacity(pc);//����
	printf("������Ҫ�����˵�����>\n");
	scanf("%s", pc->data[pc->count].name);
	printf("������Ҫ�����˵��Ա�>\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("������Ҫ�����˵�����>\n");
	scanf("%d", &pc->data[pc->count].age);
	printf("������Ҫ�����˵ĵ绰>\n");
	scanf("%d", &pc->data[pc->count].tele);
	printf("������Ҫ�����˵ĵ�ַ>\n");
	scanf("%s", pc->data[pc->count].address);
	pc->count++;
}


int findname(const Contact* pc, const char* name)
{
	assert(pc && name);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)//�����Ա�
		{
			return i;
		}
	}
	return -1;
}

//ɾ��ͨѶ¼(������ɾ��)
void del(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ���޷�ɾ��\n");
		return;
	}
	printf("����Ҫɾ����������>>\n");
	scanf("%s", name);
	int ret = findname(pc, name);
	if (ret == -1)
	{
		printf("�Ҳ���Ҫɾ������\n");
		return;
	}
	for (int i = ret; i < pc->count - 1; i++)//���������������
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}


//��ʾͨѶ¼
void show(Contact* pc)
{
	assert(pc);
	int i = 0;
	if (pc->count == 0)
	{
		printf("ͨѶ¼��\n");
		return;
	}
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-15s\t%-5s\t%-5d\t%-12d\t%-15s\n", pc->data[i].name,
			                                        pc->data[i].sex, 
			                                        pc->data[i].age, 
			                                        pc->data[i].tele,
			                                        pc->data[i].address);
	}
}


//������ϵ�ˣ������֣�
void search(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ���޷�����\n");
		return;
	}
	printf("������Ҫ�����˵�����>>\n");
	scanf("%s", name);
	int ret = findname(pc, name);
	if (ret == -1)
	{
		printf("�Ҳ���Ҫ���ҵ���\n");
		return;
	}
	printf("�ҵ��ˣ���ʾ����>>>\n");
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	printf("%-15s\t%-5s\t%-5d\t%-12d\t%-15s\n", pc->data[ret].name,
		pc->data[ret].sex,
		pc->data[ret].age,
		pc->data[ret].tele,
		pc->data[ret].address);
	
}

//������ϵ����Ϣ
void modify(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼����ϵ���޷�����\n");
		return;
	}
	char name[20] = { 0 };
	printf("������Ҫ���ĵ���ϵ������>>\n");
	scanf("%s", name);
	int ret = findname(pc, name);
	if (ret == -1)
	{
		printf("�Ҳ���Ҫ���ĵ���\n");
		return;
	}
	printf("������Ҫ�����˵�����>\n");
	scanf("%s", pc->data[ret].name);
	printf("������Ҫ�����˵��Ա�>\n");
	scanf("%s", pc->data[ret].sex);
	printf("������Ҫ�����˵�����>\n");
	scanf("%d", &pc->data[ret].age);
	printf("������Ҫ�����˵ĵ绰>\n");
	scanf("%d", &pc->data[ret].tele);
	printf("������Ҫ�����˵ĵ�ַ>\n");
	scanf("%s", pc->data[ret].address);
}


//�Ƚ�
void cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
//����
void sort(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼���޷�����\n");
		return;
	}
	qsort(pc->data, pc->count, sizeof(Peoinfo), cmp);//����
	printf("����ɹ�\n");
}


//�ͷ��ڴ�
void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}


//����
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