#include<stdio.h>
#include<malloc.h>
#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;
void CreateList(SqList*& L, ElemType a[], int n);
void InitList(SqList*& L);
bool ListInsert(SqList*& L, int i, ElemType e);
void PrintList(SqList*& L);
int ListLength(SqList* L);
bool ListEmpty(SqList* L);
bool GetElem(SqList* L, int i, ElemType& e);
int LocateElem(SqList* L, ElemType e);
bool ListDelete(SqList*& L, int i, ElemType& e);
void DestroyList(SqList*& L);
int main() {
	SqList *L;
	ElemType e;
	InitList(L);                    //初始化循序表
	ListInsert(L, 1,'a');           //依次插入a,b,c,d,e
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("输出顺序表L:");
	PrintList(L);                   //输出顺序表
	printf("线性表的长度:%d\n", ListLength(L));              //输出线性表的长度
	printf("顺序表是否为空:%d\n", ListEmpty(L));          //判断顺序表是否为空
	GetElem(L, 4, e);
	printf("输出线性表的第四个元素：%c\n", e);
	printf("元素b的位置：%d\n", LocateElem(L, 'b'));
	ListInsert(L, 2, 'f');
	printf("输出顺序表L：");
	PrintList(L);
	ListDelete(L, 3, e);      //删除顺序表的第三个元素
	printf("输出顺序表L：");
	PrintList(L);
	DestroyList(L);   //释放顺序表
	return 0;

}
void CreateList(SqList*& L, ElemType a[], int n) {   //创立顺序表
	int i = 0, k = 0;
	L = (SqList *)malloc(sizeof(SqList));
	for (i = 0;i < n;i++) {
		L->data[i] = a[i];
		k++;
	}
	L->length = k;
}
void InitList(SqList*& L) {   //初始化顺序表
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
bool ListInsert(SqList*& L, int i, ElemType e) {    //插入数据元素
	int j;
	if (i<1 || i>L->length + 1) {
		return false;
	}
	i--;
	for (j = L->length;j > i;j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return true;
}
void PrintList(SqList*& L) {  //输出顺序表
	for (int i = 0;i < L->length;i++) {
		printf("%c", L->data[i]);
	}
	printf("\n");
}
int ListLength(SqList* L) {    //返回顺序表的线性表的长度
	return(L->length);
}
bool ListEmpty(SqList* L) {     //判断顺序表是否为空
	return(L->length == 0);
}
bool GetElem(SqList* L, int i, ElemType& e) {  //求顺序表的某个数据元素值
	if (i<1 || i>L->length) {
		return false;
	}
	e = L->data[i - 1];
	return true;
}
int LocateElem(SqList* L, ElemType e) {  //按元素查找
	int i = 0;
	while (i < L->length && L->data[i] != e) {
		i++;
	}
	if (i >= L->length) {
		return 0;
	}
	else {
		return i + 1;
	}
}
bool ListDelete(SqList*& L, int i, ElemType& e) {     //删除数据元素
	int j;
	if (i<1 || i>L->length) {
		return false;
	}
	i--;
	e = L->data[i];
	for (j = i;j < L->length;j++) {
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}
void DestroyList(SqList*& L) {  //释放顺序表
	free(L);
}