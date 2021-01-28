#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
	int iValue;
	struct Node* Site;

};
void AddToEnd(struct Node** pHead, struct Node** pEnd, int iDate);
void AddToEndNoEnd(struct Node** pHead, int iDate);
void FreeList(struct Node* pHead);
void Look(struct Node* pHead);
void AddToHead(struct Node** pHead, struct Node** pEnd,int iDate);
struct Node* FindNodeByIndex(struct Node* pHead, int iIndex);
void InsertNodeByIndex(struct Node** pHead, struct Node** pEnd, int iIndex, int iData);
struct Node* FindNodeByData(struct Node* pHead, int iData);
void ChangeDataByData(struct Node* pHead, int oldData, int newData);
void ChangeSameData(struct Node* pHead,int oldData,int newData);//����ȱ�ݣ��Ҳ��������޷�������ʾ��Ϣ
void ChangeSameDataTest(struct Node* pHead, int oldData, int newData);
void DeleteHead(struct Node** pHead, struct Node** pEnd);
void DeleteEnd(struct Node** pHead, struct Node** pEnd);
struct Node* DeleteOneDateByData(struct Node** pHead, struct Node** pEnd, int iData);
void DeleteAllDateByData(struct Node** pHead, struct Node** pEnd, int iData);
void DeleteDateIndex(struct Node** pHead, struct Node** pEnd, int iIndex);
void SwapByData(struct Node* pHead, int iData1, int iData2);
void SwapTowNode(struct Node** pHead, struct Node** pEnd, int iIndex1, int iIndex2);
int GetNodeNums(struct Node* pHead);
void ReverseByData(struct Node** pHead, struct Node** pEnd);
void ReverseByHelpSpace(struct Node** pHead, struct Node** pEnd);
int main(void)
{
	struct Node* pHead = NULL;
	struct Node* pEnd = NULL;
	
	
	//AddToEnd(&pHead,&pEnd, 1);
	//AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 3);
	AddToHead(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 1);
	AddToEnd(&pHead, &pEnd, 2);
	
	AddToEnd(&pHead, &pEnd, 3);
	AddToEnd(&pHead, &pEnd, 4);
	InsertNodeByIndex(&pHead, &pEnd, 4, 1234);
	Look(pHead);
	for (int i = 0; i < 5; i++)
	{
		AddToEnd(&pHead, &pEnd, 5);
	}
	/*AddToEnd(&pHead, &pEnd, 6);
	Look(pHead);
	ChangeSameData(pHead, 5, 8);*/
	Look(pHead);
	/*ChangeSameDataTest(pHead,55, 15);
	DeleteEnd(&pHead, &pEnd);
	DeleteOneDateByData(&pHead, &pEnd, 3);
	DeleteOneDateByData(&pHead, &pEnd, 2);
	DeleteOneDateByData(&pHead, &pEnd, 5);*/
	//DeleteAllDateByData(&pHead, &pEnd, 4);
	//DeleteDateIndex(&pHead, &pEnd, 0);
	//SwapByData(pHead, 3,4);
	//SwapTowNode(&pHead, &pEnd, 1, 6); 

	/*printf("%d", GetNodeNums(pHead));
	putchar('c');*/
	ReverseByData(&pHead, &pEnd);
	Look(pHead);
	ReverseByHelpSpace(&pHead, &pEnd);
	Look(pHead);
	
	

	system("pause");
	return 0;

}
void ReverseByHelpSpace(struct Node** pHead, struct Node** pEnd)//��ת����__�����ռ�
{

	if (*pHead == NULL || NULL == (*pHead)->Site)
	{
		return;
	}
	else 
	{
		struct Node* pt = *pHead;
		struct Node* pNewHead=NULL;
		struct Node* pNewEnd=NULL;
		while (pt != NULL)
		{
			AddToHead(&pNewHead, &pNewEnd, pt->iValue);
			pt = pt->Site;
		}
		*pHead = pNewHead;
		*pEnd = pNewEnd;
		FreeList(pt);
	}
}
void ReverseByData(struct Node** pHead, struct Node** pEnd)//��ת����__ԭ�ط�ת
{
	if (*pHead == NULL || NULL == (*pHead)->Site)
		{
			return;
		}
	else
	{
		
		int i = 0;
		int j = GetNodeNums(*pHead)-1;
		for (; i < j; i++, j--)
		{
			SwapTowNode(pHead, pEnd, i, j);
		}
		return;
	}
}
int GetNodeNums(struct Node* pHead)//ͳ�ƽڵ����
{
	
	int i = 0;
		while (pHead != NULL)
		{
			i++;
			pHead = pHead->Site;
		}
		return i;
	
	
}
void SwapTowNode(struct Node** pHead, struct Node** pEnd, int iIndex1, int iIndex2)//���������ڵ�
{
	if (iIndex1==iIndex2 || (*pHead)->Site==NULL || *pHead==NULL || iIndex1<0 || iIndex2<0)
			{
				printf("��������!\n");
				return;
			}
	else
	{
		int iMin = iIndex1;
		int iMax = iIndex2;
		if (iIndex1 > iIndex2)
		{
			 iMin = iIndex2;
			 iMax = iIndex1;
		}
		struct Node* pMin=FindNodeByIndex(*pHead, iMin);
		struct Node* pMax = FindNodeByIndex(*pHead, iMax);
		if (NULL == pMin || NULL == pMax)
		{

			return;
		}
		if (pMin == *pHead && pMax == *pEnd)//�ڵ�����β
		{   //�����ڵ�
			if ((*pHead)->Site == *pEnd)
			{
				pMax->Site = *pHead;
				pMin->Site = NULL;
				*pHead = *pEnd;
				*pEnd = (*pHead)->Site;
			}
			else//���������Ͻڵ�
			{
				struct Node* pMaxa = FindNodeByIndex(*pHead, iMax - 1);
				pMax->Site = (*pHead)->Site;
				pMaxa->Site = *pHead;
				(*pHead)->Site = NULL;
				*pHead = *pEnd;
				*pEnd = pMaxa->Site;
			}
		}
		else if (pMin == *pHead && pMax != *pEnd)//�ڵ���ͷ���м�
		{
			if ((*pHead)->Site == pMax)//���ڵ����ڣ���һ���ڵ�
			{
				 
				(*pHead)->Site=pMax->Site;
				pMax->Site=*pHead;
				*pHead = pMax;
				
			}
			else//���ڵ㲻����
			{
				struct Node* pMaxb = FindNodeByIndex(*pHead, iMax - 1);
				struct Node* pt = pMin->Site;
				pMin->Site = pMax->Site;
				pMaxb->Site = pMin;
				pMax->Site = pt;
				*pHead = pMax;
				
			}
		}
		else if(pMax == *pEnd && pMin != *pHead)//�ڵ���β�����м�
		{
			struct Node* pMina = FindNodeByIndex(*pHead, iMin - 1);
			struct Node* pMaxc = FindNodeByIndex(*pHead, iMax - 1);
			if (pMin->Site == *pEnd)//����
			{
				(*pEnd)->Site = pMin;
				pMina->Site = *pEnd;
				pMin->Site = NULL;
			}
			else//������
			{
				 pMaxc->Site= pMin;
				(*pEnd)->Site = pMin -> Site;
				pMina->Site = *pEnd;
				*pEnd=pMin;
				pMin->Site = NULL;

			}
		}
		else//�ڵ����м���м�
		{
			struct Node* pMinb = FindNodeByIndex(*pHead, iMin - 1);
			struct Node* pMaxd = FindNodeByIndex(*pHead, iMax - 1);
			if (pMin->Site == pMax)//����
			{
				
				pMin->Site = pMax->Site;
				pMax->Site = pMin;
				pMinb->Site = pMax;
			}
			else//������
			{
				struct Node* i = pMin->Site;
				pMin->Site = pMax->Site;
				pMaxd->Site = pMin;
				pMax->Site = i;
				pMinb->Site = pMax;
			}
		}

	}

}
void SwapByData(struct Node* pHead, int iData1, int iData2)//���������ڵ������
{
	if (pHead == NULL)
		{
			printf("��������!\n");
			return;
		}
	else
	{
		//�ҵ�����
		struct Node* pt = FindNodeByData(pHead, iData1);
		struct Node* pa = FindNodeByData(pHead, iData2);
		if (pt != NULL && pa != NULL)
		{
			//����
			int i = pt->iValue;
			pt->iValue = pa->iValue;
			pa->iValue = i;
			//ʹ�ú������
			/*struct Node pb = *pt;
			memcpy(pt, pa,4);
			memcpy(pa, &pb, 4);*/
		}
	}
}
void DeleteDateIndex(struct Node** pHead, struct Node** pEnd, int iIndex)//�����±�ɾ���ڵ�
{
	if (*pHead == NULL)
	{
		printf("��������!\n");
		return;
	}
	if (iIndex == 0)
	{
		DeleteHead(pHead, pEnd);//1  2  3  4
	}
	else
	{
		struct Node* pt = FindNodeByIndex(*pHead, iIndex-1);
		if (pt != NULL)
		{
			struct Node* pa = pt->Site;
           pt->Site = pa->Site;
		   free(pa);
		}
		else
		{
			return;
		}
		
		
	}
}
void DeleteAllDateByData(struct Node** pHead, struct Node** pEnd, int iData)//ɾ����������Data�Ľڵ�
{
	if (*pHead == NULL)
	{
		printf("��������");
		return ;
	}
	else
	{
		struct Node* pt = DeleteOneDateByData(pHead, pEnd, iData);
		while (pt != NULL)
		{
			/*DeleteOneDateByData(&pt, pEnd, iData);*/
			pt = DeleteOneDateByData(&pt, pEnd, iData);

		}
	}
}

struct Node* DeleteOneDateByData(struct Node** pHead, struct Node** pEnd, int iData)//ɾ���ض����ݽڵ�
{
	if (*pHead == NULL)
		{
			printf("��������");
			return NULL;
		}
	if ((*pHead)->iValue == iData)//������ͷ��
	{
		DeleteHead(pHead, pEnd);
		return *pHead;
	}
	else if ((*pEnd)->iValue == iData)//������β��
	{
		DeleteEnd( pHead, pEnd);
		return *pHead;

	}
	else
	{
		struct Node* pt = *pHead;
			while(pt->Site !=NULL)//Ѱ�Ҹ����ݵ�ǰһ���ڵ�
			{
				if (pt->Site->iValue == iData)
				{
					//pt->Site = pt->Site->Site;
					break;
				}
					
				/*else
					printf("�޴����ݣ�\n");*/
				pt = pt->Site;
			}
			if (pt->Site != NULL)
			{
				struct Node* pa = pt->Site;
					pt->Site = pa->Site;
					free(pa);	
					return pt->Site;
			}
			else
			{
				printf("�޴����ݣ�\n");
				return NULL;
			}
			
			

	}
}
void DeleteEnd(struct Node** pHead, struct Node** pEnd)//ɾ��β
{
	
	if ((*pHead)->Site == NULL)
	{
		free(*pHead);
		*pHead = NULL;
		*pEnd = NULL;
	}
	else
	{
		struct Node* pt = *pHead;
		while (pt->Site != *pEnd)
		{
			pt = pt->Site;
		}
		free(*pEnd);
		*pEnd = pt;
		pt->Site = NULL;
	}
}
void DeleteHead(struct Node** pHead, struct Node** pEnd)//ɾ��ͷ��ȱ�ݣ�ʹ��AddToEnd������ֵ��һ���ڵ�ᱨ���ѽ��2021��1��18��15:46:08
{
	if (*pHead == NULL)
	{
		printf("��������");
		return;
	}
	if ((*pHead)->Site == NULL)
	{
		free(*pHead);
		*pHead = NULL;
		*pEnd = NULL;
	}
	else
	{
		struct Node* pt = *pHead;
		*pHead = (*pHead)->Site;
			free(pt);
	}

}
void ChangeSameDataTest(struct Node* pHead, int oldData, int newData)//�ҵ�������ͬ�ڵ㣬���ı���(Ч�ʵͣ�
{
	if (pHead == NULL)
	{
		printf("��������");
		return;
	}
	else
	{
		struct Node* pt = FindNodeByData(pHead, oldData);
		while (pt != NULL)
		{
			ChangeDataByData(pHead, oldData, newData);
			pt = pt->Site;
		}
	}
}
void ChangeSameData(struct Node* pHead, int oldData, int newData)//�ҵ�������ͬ�ڵ㣬���ı���
{
	if (pHead == NULL)
		{
			printf("��������");
			return ;
		}
	else
	{
		while (pHead != NULL)
		{
			if (pHead->iValue == oldData)
				pHead->iValue = newData;
			pHead = pHead->Site;
		}
	}
}
void ChangeDataByData(struct Node* pHead, int oldData, int newData)//�������ҵ��ڵ㣬���ı���������
{
	struct Node* pt = FindNodeByData(pHead, oldData);
	if (pt != NULL)
	{
	
	pt->iValue = newData;
	}
}
struct Node* FindNodeByData(struct Node* pHead, int iData)//���������ҽڵ㣬�����ظýڵ�
{
	if (pHead == NULL)
	{
		printf("��������");
		return NULL;
	}
	else
	{
		while (pHead != NULL)
		{
			if (pHead->iValue == iData)
			{
				return pHead;
			}
			pHead=pHead->Site;
		}
	}
	printf("�޴����ݣ�\n");
	return NULL;
}
void InsertNodeByIndex(struct Node** pHead, struct Node** pEnd, int iIndex, int iData)//ָ���ڵ��������(���ڽ�β����)
{//��������
	if (iIndex < 0 )
	{
		printf("��������\n");
		return;
	}
//�����ڵ�
	
	if (iIndex == 0)
	{
		AddToHead(pHead, pEnd, iData);
		return;
	}
	else
	{
		struct Node* pt = (struct Node*)malloc(sizeof(struct Node));
		pt->iValue = iData;
		pt->Site = NULL;
		struct Node* pa=FindNodeByIndex(*pHead, iIndex-1);
		if (pa != NULL)
		{
			pt->Site = pa->Site;
			pa->Site = pt;
			
		}
		else
		{
			printf("�޴˽ڵ�");
		}
		
		
	}
	
}
struct Node* FindNodeByIndex(struct Node* pHead, int iIndex)//�����±�������ݣ������ظýڵ�
{//��������
	if (pHead == NULL || iIndex < 0)
	{
		printf("�����������\n");
		return NULL;
	}
	int i = 0;
	while (pHead != NULL)
	{
		if (iIndex == i)
		{
			return pHead;
		}
		i++;
		pHead = pHead->Site;
	}
	printf("��������/�޴�����\n");
	return NULL;

}
void AddToHead(struct Node** pHead, struct Node** pEnd,int iDate)//���ͷ���ڵ㣨������
{
	//�����ڵ�

	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	//��ֵ
	pTemp->iValue = iDate;
	pTemp->Site = NULL;
	//�жϴ����ɹ�
	if (pTemp != NULL)
	{
		if (*pHead == NULL)
		{
			*pHead = pTemp;
			*pEnd = pTemp;
		}
		else
		{
			pTemp->Site = *pHead;
			*pHead = pTemp;

			
		}
	}
}
void Look(struct Node* pHead)//�鿴����

{
	while (pHead != NULL)
	{
		printf("%d ", pHead->iValue);
		pHead = pHead->Site;
	}
	putchar('\n');
}
void FreeList(struct Node* pHead)//�ͷſռ�
{
	while (pHead != NULL)
	{
		struct Node* pt = pHead;
		pHead = pHead->Site;
		free(pt);
	}
}
void AddToEnd(struct Node** pHead, struct Node** pEnd, int iDate)//���β���ڵ㣨������
{
	//�����ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp != NULL)
	{
	//�ڵ��Ա��ֵ
	pTemp->iValue = iDate;
	pTemp->Site = NULL;
	//����ȥ
	if (*pHead == NULL)//������
	{
		*pHead = pTemp;
		*pEnd = pTemp;
	}
	else
	{
		(*pEnd)->Site = pTemp;
		*pEnd = pTemp;
	}
	}
}
void AddToEndNoEnd(struct Node** pHead, int iDate)//���ӽڵ�
{
	//�����ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (NULL != pTemp)
	{
		//��Ա��ֵ
		pTemp->iValue = iDate;
		pTemp->Site = NULL;
		if (*pHead == NULL)
		{
			*pHead = pTemp;
		}
		else
		{
			struct Node* pt = *pHead;
			while (pt->Site !=NULL)//Ѱ�����һ���ڵ�
			{
				pt = pt->Site;
				
			}
			pt->Site = pTemp;
		}

	}
}