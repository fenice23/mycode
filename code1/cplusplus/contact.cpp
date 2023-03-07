#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->_sz = 0;
//	//memset(pc->arr, 0, sizeof(pc->arr));
//}
void InitContact(Contact* pc)
{
	assert(pc);
	pc->_data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (NULL == pc->_data)
	{
		perror("malloc fail");
		exit(errno);
	}
	pc->_capacity = DEFAULT_SZ;
	pc->_sz = 0;
	LoadContact(pc);
}
void CheckCapacity(Contact* pc)
{
	assert(pc);
	if (pc->_sz == pc->_capacity)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pc->_data, (pc->_capacity + INC_SZ) * sizeof(PeoInfo));
		if (NULL == tmp)
		{
			perror("realloc fail");
			free(pc->_data);
			pc->_data = NULL;
			pc->_sz = pc->_capacity = 0;
			exit(errno);
		}
		pc->_data = tmp;
		pc->_capacity = pc->_capacity + INC_SZ;
	}
}
void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->_data);
	pc->_data = NULL;
	pc->_capacity = pc->_sz = 0;
}
void LoadContact(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("contact.dat", "rb");
	if (NULL == pf)
	{
		perror("fopen fail");
		return;
	}
	PeoInfo tmp = { 0 };
	PeoInfo* pt = pc->_data;
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		CheckCapacity(pc);
		pc->_data[pc->_sz++] = tmp;
	}
	fclose(pf);
	pf = NULL;
}
void AddContact(Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);
	printf("请输入名字:>");
	scanf("%s", pc->_data[pc->_sz]._name);
	printf("请输入年龄:>");
	scanf("%d", &pc->_data[pc->_sz]._age);
	printf("请输入性别:>");
	scanf("%s", pc->_data[pc->_sz]._sex);
	printf("请输入电话:>");
	scanf("%s", pc->_data[pc->_sz]._tele);
	printf("请输入地址:>");
	scanf("%s", pc->_data[pc->_sz]._addr);
	pc->_sz++;
}
void PrintContact(Contact* pc)
{
	assert(pc);
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < pc->_sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->_data[i]._name, pc->_data[i]._age, pc->_data[i]._sex, pc->_data[i]._tele, pc->_data[i]._addr);
	}
}
void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "wb");
	if (NULL == pf)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < pc->_sz; i++)
	{
		fwrite(pc->_data + i, sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
static int FindByName(Contact* pc, char* name)
{
	for (int i = 0; i < pc->_sz; i++)
	{
		if (!strcmp(name, pc->_data[i]._name))
			return i;
	}
	return -1;
}
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = "";
	if (pc->_sz == 0)
	{
		printf("通讯录已空,fail\n");
		return;
	}
	printf("请输入要删除的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("要删除的人不存在:>");
	}
	else
	{
		for (int i = pos; i < pc->_sz - 1; i++)
		{
			pc->_data[i] = pc->_data[i + 1];
		}
		pc->_sz--;
	}
}
void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = "";
	printf("请输入要查找人名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("要查找的人不存在!\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->_data[pos]._name, pc->_data[pos]._age,
			pc->_data[pos]._sex, pc->_data[pos]._tele, pc->_data[pos]._addr);
	}
}
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = "";
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("查无此人!\n");
		return;
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->_data[pos]._name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->_data[pos]._age));
		printf("请输入性别:>");
		scanf("%s", pc->_data[pos]._sex);
		printf("请输入电话:>");
		scanf("%s", pc->_data[pos]._tele);
		printf("请输入地址:>");
		scanf("%s", pc->_data[pos]._addr);
	}
}
void SortContact(Contact* pc)
{
	assert(pc);
	bool f = true;
	for (int i = 0; i < pc->_sz - 1; i++)
	{
		f = true;
		for (int j = 0; j < pc->_sz - 1 - i; j++)
		{
			if (pc->_data[j]._age > pc->_data[j + 1]._age)
			{
				f = false;
				PeoInfo t = pc->_data[j];
				pc->_data[j] = pc->_data[j + 1];
				pc->_data[j + 1] = t;
			}
		}
		if (f)
			break;
	}
}