//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h>
//
//struct donshuzu
//{
//	int* shuzu;
//	unsigned int RonLiang;
//	unsigned int ShuLiang;
//};
//void shuru(struct donshuzu* p);
//void ZenJia(struct donshuzu* pshuzu, int Nshuju);
//void ChaRu(struct donshuzu* pshuzu, int ShuJu, unsigned int XiaBiao);
//void shuchu(struct donshuzu* p);
//void BianDa(struct donshuzu* pshuzu);
////void ZenJiaDuoGe(struct donshuzu* pshuzu, int* a, int* b, int c);
//void ShanChuWeiBu(struct donshuzu* pshuzu);
//void ShanChuQuanBu(struct donshuzu* pshuzu);
//void ShanChuZhonJian(struct donshuzu* pshuzu, unsigned int ilocation);
//
//int main(void)
//{
//	struct donshuzu  moveshuzu;
//
//	shuru(&moveshuzu);
//	ZenJia(&moveshuzu, 3);
//	ZenJia(&moveshuzu, 2);
//	ZenJia(&moveshuzu, 1);
//	
//	ChaRu(&moveshuzu, 5, 11);
//
//	shuchu(&moveshuzu);
//
//	//ShanChuZhonJian(&moveshuzu, 3);ɾ���м�һ������
//	//shuchu(&moveshuzu);
//	//ShanChuWeiBu(&moveshuzu);ɾ��β��һ������
//	//shuchu(&moveshuzu);
//	//ShanChuQuanBu(&moveshuzu);ɾ��ȫ������
//	//shuchu(&moveshuzu);
//
//	free(moveshuzu.shuzu);
//	system("pause");
//	return 0;
//}
//void ShanChuZhonJian(struct donshuzu* pshuzu, unsigned int ilocation)
//{
//	if (NULL == pshuzu || ilocation>pshuzu->ShuLiang)
//		{
//			printf("�����������\n");
//			return;
//		}
//	//ѭ��Ųλ��
//	for (unsigned int i = ilocation - 1; i < pshuzu->ShuLiang-1; i++)
//	{
//		pshuzu->shuzu[i] = pshuzu->shuzu[i + 1];
//	}
//	//����-1
//	pshuzu->ShuLiang--;
//}
//void ShanChuQuanBu(struct donshuzu* pshuzu)
//{
//	if (NULL == pshuzu)
//	{
//		printf("�����������");
//		return;
//	}
//	pshuzu->ShuLiang = 0;
//	pshuzu->RonLiang = 0;
//	free(pshuzu->shuzu);
//	pshuzu->shuzu = NULL;
//}
//void ShanChuWeiBu(struct donshuzu* pshuzu)
//{
//	if (NULL == pshuzu)
//	{
//		printf("�����������");
//		return;
//	}
//	pshuzu->ShuLiang--;
//}
//
//
//
//void shuru(struct donshuzu* p)
//{
//	if (NULL == p)
//	{
//		printf("�����������");
//		return;
//	}
//	p->RonLiang = 5;
//	p->shuzu = (int*)malloc(sizeof(int) * p->RonLiang);
//	p->ShuLiang = 0;
//}
//void ZenJia(struct donshuzu* pshuzu, int Nshuju)
//{
//	if (NULL == pshuzu)
//	{
//		printf("�����������");
//		return;
//	}
//	//�ж��Ƿ��Ѿ�����
//	if (pshuzu->RonLiang == pshuzu->ShuLiang)
//	{
//		BianDa(pshuzu);
//
//	}
//	//������װ��ȥ������++
//	pshuzu->shuzu[pshuzu->ShuLiang] = Nshuju;
//	pshuzu->ShuLiang++;
//	return;
//}
//void BianDa(struct donshuzu* pshuzu)
//{
//	if (NULL == pshuzu)
//	{
//		printf("�����������");
//		return;
//	}
//	//�������
//	pshuzu->RonLiang += 10;
//	//����ռ�
//	int* New = (int*)malloc(sizeof(int) * pshuzu->RonLiang);
//	//memset(New, 0, sizeof(int) * pshuzu->RonLiang);
//	//����ԭ����
//	for (unsigned int i = 0; i < pshuzu->ShuLiang; i++)
//	{
//		New[i] = pshuzu->shuzu[i];
//	}
//	//��ԭ�ռ��ͷ�
//	free(pshuzu->shuzu);
//	//��ԭ�ռ�ָ���¿ռ�
//	pshuzu->shuzu = New;
//
//
//}
//void ChaRu(struct donshuzu* pshuzu, int ShuJu, unsigned int XiaBiao)
//{
//	if (NULL == pshuzu)
//	{
//		printf("�����������");
//		return;
//	}
//	//����±�����������Ͱ����ݼ��ں���
//	if (XiaBiao > pshuzu->ShuLiang)
//	{
//		XiaBiao = pshuzu->ShuLiang;
//		
//
//	}
//
//	//ѭ��Ųλ��
//	for (unsigned int i = pshuzu->ShuLiang; i >= XiaBiao; i--)
//	{
//		pshuzu->shuzu[i] = pshuzu->shuzu[i - 1];
//	}
//	//��ֵ��ֵ��ָ��λ��
//	pshuzu->shuzu[XiaBiao] = ShuJu;
//	//��������
//	pshuzu->ShuLiang++;
//}
//
//
//
//
//
//void shuchu(struct donshuzu* p)
//{
//	if (NULL == p)
//	{
//		printf("�����������");
//		return;
//	}
//	printf("������%u ������%u", p->RonLiang, p->ShuLiang);
//	printf("\n���ݣ� ");
//	for (unsigned int i = 0; i < p->ShuLiang; i++)
//	{
//		printf("%d ", p->shuzu[i]);
//	}
//	printf("\n");
//}
//void ZenJiaDuoGe(struct donshuzu* pshuzu,int*a,int*b,int c)
//{
//	for (int i = 0; i < c; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			ChaRu(pshuzu, a[i], b[i]);
//		}
//	}
//}