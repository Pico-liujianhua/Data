#include <stdio.h>
#include <stdlib.h>
	struct Node
	{
		int iValue;
		struct Node* Site;
	};
void AddToTail(struct Node* stHead, int iData);
void FreeList(struct Node* stHead);
void Look(struct Node* stHead);
void AddToHead(struct Node* stHead, int iData);
void AddBehandData(struct Node* stHead, int iOriginalData,int iData);
void AddByIndexSelf(struct Node* stHead, int iOriginalIndex, int iData);
void AddByIndex(struct Node* stHead, int iOriginalIndex, int iData);
void AddBySomeIndex(struct Node* stHead, int iOriginalIndex, int iCycleNums,int iData);
struct Node* FindNodeByData(struct Node* stHead, int iData);
struct Node* FindNodeByIndex(struct Node* stHead, int iIndex);
void ChangeNodeByData(struct Node* stHead, int iOriginalData, int iData);
void ChangeNodeByIndex(struct Node* stHead, int iOriginalIndex, int iData);
void DeleteSameData(struct Node* stHead);



int main(void)
{
	int iNodeCounts = 0;
	struct Node stHead = { 0,NULL };
	
	AddToTail(&stHead,  2);
	AddToTail(&stHead,  3);
	AddToTail(&stHead,  4);
	AddToTail(&stHead,  5);
	//
	////FreeList(&stHead);
	//AddToHead(&stHead, 1);
	//Look(&stHead);
	//AddBehandData(&stHead, 5, 6);
	//AddByIndex(&stHead, 6, 7);
	//Look(&stHead);
	//AddByIndex(&stHead, 7, 8);
	Look(&stHead);
	//ChangeNodeByData(&stHead, 1, 66);
	DeleteSameData(&stHead);
	//ChangeNodeByIndex(&stHead, 7, 2);
	//AddBySomeIndex(&stHead, 0,3, 8);
	Look(&stHead);
	//struct Node* pt = FindNodeByData(&stHead, 66);
	//struct Node* pt = FindNodeByIndex(&stHead,1);
	/*if (NULL != pt)
	{
		printf("%d\n", pt->iValue);
	}
	else
	{
		printf("���޴����ݣ�\n");
	}*/
	system("pause");
	return 0;
}
void DeleteSameData(struct Node* stHead)//ɾ����ͬ���ݽڵ�
{
	if (NULL == stHead || stHead->iValue <= 1)
		return;
	struct Node* pt = stHead->Site;
	while (NULL != pt)
	{
		struct Node* pa = pt;
		while (NULL != pa->Site)
		{
			if (pa->Site->iValue == pt->iValue)
			{
				struct Node* pb = pa->Site;
				pa->Site = pa->Site->Site;
				stHead->iValue -= 1;
				free(pb);
				continue;
				
			}
			pa = pa->Site;
		}
		pt = pt->Site;
	}

}
void ChangeNodeByIndex(struct Node* stHead, int iOriginalIndex, int iData)//�ı�ָ���ڵ����ݡ��������±�
{
	if (NULL == stHead || stHead->iValue <= 0 || iOriginalIndex<0 || iData<0 ||iOriginalIndex>stHead->iValue || iData>stHead->iValue)
		return ;
	else
	{
		struct Node* pt = FindNodeByIndex(stHead, iOriginalIndex);//��ʹ��ѭ������ʹ�ú���
		if (NULL != pt)
		{
			pt->iValue = iData;
		}
		else
		{
			printf("���޴����ݣ�\n");
		}

	}
}
void ChangeNodeByData(struct Node* stHead, int iOriginalData, int iData)//�ı�ָ���ڵ����ݡ�����������
{
	if (NULL == stHead || stHead->iValue <= 0)
		return ;
	else
	{
		struct Node* pt = stHead->Site;//��ʹ�ú���
		for (int i = 0; i < stHead->iValue; i++)
		{
			if (iOriginalData == pt->iValue)
			{
				pt->iValue = iData;
			}
			pt = pt->Site;
		}
		
		
	}
}
struct Node* FindNodeByIndex(struct Node* stHead, int iIndex)//���ҽڵ㡪�������±�
{
	if (NULL == stHead || iIndex < 0)
		return NULL;
	else
	{
		struct Node* pt = stHead->Site;
		int i = 0;
		while (NULL != pt)
		{
			if (iIndex == i)
				break;
			i++;
			pt = pt->Site;
		}
		return pt;
	}
}
struct Node* FindNodeByData(struct Node* stHead, int iData)//���ҽڵ㡪����������
{
	if (NULL == stHead || stHead->iValue<=0)
		return NULL;
	else
	{
		struct Node* pt = stHead->Site;
		while (pt != NULL)
		{
			if (iData == pt->iValue)
				break;
			pt = pt->Site;
		}
		return pt;
	}
		
}
void AddBySomeIndex(struct Node* stHead, int iOriginalIndex, int iCycleNums, int iData)//����������
{
	if (NULL == stHead || iOriginalIndex < 0 || iOriginalIndex>stHead->iValue)
	{
		return;
	}
	else
	{
		struct Node* pt = stHead;
		int i = 0;
		while (i < iOriginalIndex)
		{
			i++;
			pt = pt->Site;
		}
		for (int i = 0; i < iCycleNums; i++)
		{
		AddToHead(pt, iData);
				pt->iValue -= 1;
				stHead->iValue += 1;
		}
		
	}
}
void AddByIndex(struct Node* stHead, int iOriginalIndex, int iData)//��ָ���±�λ�ò���ڵ�
{
	if (NULL == stHead || iOriginalIndex < 0 || iOriginalIndex>stHead->iValue)
	{
		return;
	}
	else
	{
		struct Node* pt = stHead;
		int i = 0;
		while (i < iOriginalIndex)
		{
			i++;
			pt = pt->Site;
		}
		AddToHead(pt, iData);
		pt->iValue -= 1;
		stHead->iValue += 1;
	}
}
void AddByIndexSelf(struct Node* stHead, int iOriginalIndex, int iData)//��ָ���±�λ�ò���ڵ�
{
	if (NULL == stHead || iOriginalIndex < 0 )//|| iOriginalIndex+1>stHead->iValue
	{
		return;
	}
	else if (0 == iOriginalIndex)
	{
		AddToHead(stHead, iData);
		return;
	}
	else 
	{
		struct Node* pt = stHead->Site;
		int i = 0;
		while (pt != NULL)
		{
			if (i == iOriginalIndex-1)
				break;
			i++;
			pt = pt->Site;
		}
		if (NULL == pt)
		{
			printf("���޴˽ڵ�\n");
			return;
		}
		else
		{
			struct Node* pa = (struct Node*)malloc(sizeof(struct Node));
			if (NULL == pa)
				return;
			pa->iValue = iData;
			pa->Site = NULL;
			pa->Site = pt->Site;
			pt->Site = pa;
			stHead->iValue++;
		}
	}
}
void AddBehandData(struct Node* stHead, int iOriginalData,int iData)//��ָ�����ݺ����������
{
	if (NULL == stHead || iOriginalData < 0 || stHead->iValue <= 0)
	{
		return;
	}
	else
	{
		struct Node* pt = stHead->Site;
		while (pt != NULL)
		{
			if (pt->iValue == iOriginalData)
				break;
			pt = pt->Site;
		}
		if (NULL == pt)
		{
			printf("���޴�����\n");
		}
		else
		{
			struct Node* pa = (struct Node*)malloc(sizeof(struct Node));
			if (pa == NULL)
				return;
			pa->iValue = iData;
			pa->Site = NULL;
			pa->Site = pt->Site;
			pt->Site = pa;
			stHead->iValue++;
			/*AddToHead(pt, iData);
			pt->iValue--;
			stHead->iValue++;*///�ڶ��ַ��������ú���
		}
	}
}
void AddToHead(struct Node* stHead, int iData)//����ͷ���
{
	if (NULL == stHead || iData < 0)
		return;
	struct Node* pt = (struct Node*)malloc(sizeof(struct Node*));
	if (NULL == pt)
		return;
	pt->iValue = iData;
	pt->Site = NULL;
	pt->Site = stHead->Site;
	stHead->Site = pt;
	stHead->iValue++;
}
void Look(struct Node* stHead)//�����������������̨
{
	if (NULL == stHead || stHead->iValue <= 0)
	{
		printf("��������/����������\n");
		return;
	}
	else 
	{
		struct Node* pt = stHead->Site;
		printf("���� %d ������\n", stHead->iValue);
		while (pt != NULL)
		{
			printf("%d ", pt->iValue);
			pt = pt->Site;
		}
		putchar('\n');
	}
}
void FreeList(struct Node* stHead)//�ͷ�����
{
	if (NULL == stHead || 0 == stHead->iValue)
		return;
	struct Node* pt = stHead->Site;
	while (pt->Site != NULL)
	{
		struct Node* pa = pt;
		pt = pt->Site;
		free(pa);

	}
	stHead->iValue = 0;
	stHead->Site = NULL;
	stHead->iValue = 0;
}
void AddToTail(struct Node* stHead,  int iData)//����β���
{
	if (stHead == NULL ||  stHead->iValue < 0)
	{
		return;
	}
	else
	{
		struct Node* pt = (struct Node*)malloc(sizeof(struct Node));
		if (pt != NULL)
		{
			pt->iValue = iData;
			pt->Site = NULL;
			struct Node* pa = stHead;
			while (pa->Site != NULL)
				pa = pa->Site;
			pa->Site = pt;
			(stHead->iValue)++;
			//free(pt);
		}
	}
}