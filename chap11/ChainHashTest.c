/*ü�� �ؽ��� ���*/
#include<stdio.h>
#include"Member.h"
#include"ChainHash.h"
#pragma warning(disable:4996)

/*---�޴�---*/
typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
}Menu;

/*---�޴� ����---*/
Menu SelectMenu(void)
{
	int ch;
	do {
		printf("(1)�߰� (2)���� (3)�˻� (4)��� ���� (5)���� (6)���� : ");
		scanf("%d", &ch);
	} while (ch<TERMINATE || ch>DUMP);
	return(Menu)ch;
}

/*---����---*/
int main(void)
{
	Menu menu;/*�޴�*/
	ChainHash hash;/*�ؽ� ���̺�*/
	Initialize(&hash, 13);/*�ؽ� ���̺� �ʱ�ȭ*/
	do {
		int result;
		Member x;
		Node* temp;
		switch (menu = SelectMenu())
		{
		case ADD:/*---������ �߰�---*/
			x = ScanMember("�߰�", MEMBER_NO | MEMBER_NAME);
			result = Add(&hash, &x);
			if (result)
				printf("\a���� : �߰��� �����߽��ϴ�(%s).\n", (result == 1) ? "�̹� ��ϵ�" : "�޸� ����");
			break;

		case DELETE:/*---������ ����---*/
			x = ScanMember("����", MEMBER_NO);
			result = Remove(&hash, &x);
			if (result == 1)
				printf("\a���� : �� ��ȣ�� �����Ͱ� �������� �ʽ��ϴ�.\n");
			break;

		case SEARCH:/*---������ �˻�---*/
			x = ScanMember("�˻�", MEMBER_NO);
			temp = Search(&hash, &x);
			if (temp == NULL)
				printf("\a�˻��� �����߽��ϴ�.\n");
			else {
				printf("�˻��� �����߽��ϴ�. : ");
				PrintLnMember(&temp->data);
			}
			break;
		case CLEAR:/*---��� ������ ����---*/
			Clear(&hash);
			break;

		case DUMP:/*---�ؽ� ���̺� ����---*/
			Dump(&hash);
			break;
		}
	} while (menu != TERMINATE);
	Terminate(&hash);/*�ؽ� ���̺� ����*/

	return 0;
}