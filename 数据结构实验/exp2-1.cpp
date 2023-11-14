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
	InitList(L);                    //��ʼ��ѭ���
	ListInsert(L, 1,'a');           //���β���a,b,c,d,e
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("���˳���L:");
	PrintList(L);                   //���˳���
	printf("���Ա�ĳ���:%d\n", ListLength(L));              //������Ա�ĳ���
	printf("˳����Ƿ�Ϊ��:%d\n", ListEmpty(L));          //�ж�˳����Ƿ�Ϊ��
	GetElem(L, 4, e);
	printf("������Ա�ĵ��ĸ�Ԫ�أ�%c\n", e);
	printf("Ԫ��b��λ�ã�%d\n", LocateElem(L, 'b'));
	ListInsert(L, 2, 'f');
	printf("���˳���L��");
	PrintList(L);
	ListDelete(L, 3, e);      //ɾ��˳���ĵ�����Ԫ��
	printf("���˳���L��");
	PrintList(L);
	DestroyList(L);   //�ͷ�˳���
	return 0;

}
void CreateList(SqList*& L, ElemType a[], int n) {   //����˳���
	int i = 0, k = 0;
	L = (SqList *)malloc(sizeof(SqList));
	for (i = 0;i < n;i++) {
		L->data[i] = a[i];
		k++;
	}
	L->length = k;
}
void InitList(SqList*& L) {   //��ʼ��˳���
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
bool ListInsert(SqList*& L, int i, ElemType e) {    //��������Ԫ��
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
void PrintList(SqList*& L) {  //���˳���
	for (int i = 0;i < L->length;i++) {
		printf("%c", L->data[i]);
	}
	printf("\n");
}
int ListLength(SqList* L) {    //����˳�������Ա�ĳ���
	return(L->length);
}
bool ListEmpty(SqList* L) {     //�ж�˳����Ƿ�Ϊ��
	return(L->length == 0);
}
bool GetElem(SqList* L, int i, ElemType& e) {  //��˳����ĳ������Ԫ��ֵ
	if (i<1 || i>L->length) {
		return false;
	}
	e = L->data[i - 1];
	return true;
}
int LocateElem(SqList* L, ElemType e) {  //��Ԫ�ز���
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
bool ListDelete(SqList*& L, int i, ElemType& e) {     //ɾ������Ԫ��
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
void DestroyList(SqList*& L) {  //�ͷ�˳���
	free(L);
}