#include <stdio.h>
typedef int ElemType;
#define MAXSIZE 100

//顺序表定义
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SeqList;
//基于动态内存分配的结构体定义
//typedef struct {
//	elemtype* data；
//	int length;
//}seqlist;

//函数原型声明
void initSeqList(SeqList* L);
int appendElem(SeqList* L, ElemType e);
void listElem(SeqList* L);
int insertElem(SeqList* L, int pos, int e);
int deleteElem(SeqList* L, int pos, ElemType* e);
int findElem(SeqList* L, ElemType e);

int main()
{
	//声明一个顺序表并初始化
	SeqList list;
	initSeqList(&list);
	printf("Successful initiatiation .Length takes up %d\n", list.length);
	printf("Currently takes up %zu\n", sizeof(list.data));
	//添加元素
	appendElem(&list, 88);
	appendElem(&list, 91);
	appendElem(&list, 101);
	appendElem(&list, 78);
	//遍历
	listElem(&list);
	//插入元素并遍历
	insertElem(&list, 3, 18);
	listElem(&list);
	//删除元素并遍历
	ElemType delData;
	deleteElem(&list, 2, &delData);
	printf("Delete the data successfully:%d\n", delData);
	listElem(&list);
	//查找元素
	printf("%d\n", findElem(&list, 101));

	return 0;
}


//顺序表初始化
void initSeqList(SeqList* L)
{
	L->length = 0;
}
//基于动态内存分配的顺序表初始化
//SeqList* initSeqList(SeqList* L)
//{
//	SeqList* L = (SeqList*)malloc(sizeof(SeqList));
//	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
//	L->length = 0;
//	return L;
//} 
//尾部添加元素
int appendElem(SeqList* L, ElemType e)
{
	if (L->length >= MAXSIZE)
	{
		printf("顺序表已满\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}
//遍历
void listElem(SeqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}
//中间插入数据
int insertElem(SeqList* L, int pos, int e)
{
	//检查表是否已经满了
	if (L->length >= MAXSIZE) {
		printf("表已经满了\n");
		return 0;
	}

	//检查插入位置是否合法
	if (pos < 1 || pos >= L->length)
	{
		printf("插入位置错误\n");
		return 0;
	}

	//移动元素（从后往前挪）
	if (pos <= L->length)
	{
		//把从pos-1开始的元素往后移动一位，腾出空位
		for (int i = L->length - 1; i >= pos - 1; i--)
		{
			L->data[i + 1] = L->data[i];
		}
		L->data[pos - 1] = e;
		L->length++;
	}
	return 1;
}
//删除数据
int deleteElem(SeqList* L, int pos, ElemType* e)
{
	if (L->length == 0) {
		printf("空表\n");
		return 0;
	}

	if (pos < 1 || pos >= L->length)
	{
		printf("删除位置错误\n");
		return 0;
	}

	//把要删除元素的值赋值给 *e
	*e = L->data[pos - 1];
	//把要删除元素的后面元素的值依次往前赋值
	for (int i = pos; i < L->length; i++)
	{
		L->data[i - 1] = L->data[i];
	}
	L->length--;
	return 1;
}
//查找数据位置
int findElem(SeqList* L, ElemType e)
{
	if (L->length == 0)
	{
		printf("空列表\n");
		return 0;
	}

	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}