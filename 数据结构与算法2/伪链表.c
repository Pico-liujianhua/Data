/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	int ivalue;
	struct Node* site;//��һ���ڵ�ĵ�ַ
};
void Look(struct Node* pHead);
struct Node* FindByDate(struct Node* pHead, int iDate);
void ShowDate(struct Node* Find);
struct Node* FindByIndex(struct Node* pHead, int iIndex);
int DateNums(struct Node* pHead, int iDate);
void SameDate(struct Node*pHead,struct Node* *arr, int iDate);
void ChangeByDate(struct Node* pHead, int iDate,int NewDate);
void ChangeByIndex(struct Node* pHead, int iIndex, int NewDate);
int main(void)
{
	struct Node a = { 1,NULL },
		        b = { 2, NULL}, 
				c = { 3,NULL },
				d = { 4,NULL };
	a.site = &b;
	b.site = &c;
	c.site = &d;
	Look(&a);
	//putchar('\n');
	//ChangeByIndex(&a, 0, 22);
	//Look(&a);

	//struct Node* Find = FindByDate(&a, 2);
	//ShowDate(Find);
	//ShowDate(FindByIndex(&a, 3));

	//struct Node* arr[4] = { NULL };
	//SameDate(&a, arr, 2);

	//printf("�����ݵĸ���Ϊ��%d", DateNums(&a, 2));
	
	system("pause");
	return 0;
}
void ChangeByIndex(struct Node* pHead, int iIndex, int NewDate)//ͨ���±�������ݲ��ı���

{
	struct Node* Change = FindByIndex(pHead, iIndex);
	if (Change != NULL)
	{
		Change->ivalue = NewDate;
	}
	else
    printf("�޴����ݣ�\n");
}

void ChangeByDate(struct Node* pHead, int iDate, int NewDate)//ͨ�����ݲ������ݲ��ı���
{
	struct Node* Change = FindByDate(pHead, iDate);
	if (Change != NULL)
	{
		Change->ivalue = NewDate;
	}
	else
		printf("�޴����ݣ�\n");


}

void SameDate(struct Node* pHead, struct Node** arr, int iDate)
{
	int i = 0;
	while (pHead != NULL)
	{
		if (pHead->ivalue == iDate)
		{
			arr[i++] = pHead;
		}

		pHead = pHead->site;
	}
	printf("����Ϊ��");
	for (int i=0 ; i < 4 && arr[i] != NULL; i++)
	{
		printf("%d  ", arr[i]->ivalue);
		
	}
}

int DateNums(struct Node* pHead, int iDate)//����ָ�����ݵĸ���
{
	int count = 0;
	while (pHead != NULL)
	{
		if (pHead->ivalue == iDate)
			count++;
		pHead = pHead->site;
	}
	return count;
}

struct Node* FindByIndex(struct Node* pHead, int iIndex)//�����±���ҽڵ�
{
	int i=0;//��i=0�������±ꣻ��i=1������λ�ã�
	while (pHead != NULL)
		{
			if (i == iIndex)
				return pHead;
			pHead = pHead->site;
			
			i++;
			
		}
	return NULL;
}
void ShowDate(struct Node* Find)//�ж�
{
if (Find == NULL)
	{
		printf("�޴˽ڵ�!\n");
	}
	else
		printf("�˽ڵ��ַ%p\n�˽ڵ�����%d\n", Find, Find->ivalue);
		
}
struct Node* FindByDate(struct Node* pHead, int iDate)//�������ݲ��ҽڵ�
{
	while (pHead != NULL)
	{
		if (pHead->ivalue == iDate)
			return pHead;
		pHead = pHead->site;
	}
	return NULL;
}
void Look(struct Node* pHead)//�������нڵ�����
{
	while (pHead != NULL)
	{
	printf("%d\n", pHead->ivalue);
	pHead = pHead->site;
	}
}*/