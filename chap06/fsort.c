/* ���� ���� ���α׷� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*---���� ���� �Լ�(�迭�� ��ڰ��� 0 �̻� max �����Դϴ�)---*/
void fsort(int a[], int n, int max)
{
	int i;
	int* f = calloc(max + 1, sizeof(int)); /* ���� ���� */
	int* b = calloc(n, sizeof(int)); /* �۾��� ���� �迭 */

	for (i = 0; i <= max; i++) f[i] = 0; /* [step0] */
	for (i = 0; i < n; i++) f[a[i]]++; /* [step1] */
	for (i = 1; i < max; i++) f[i] += f[i - 1]; /* [step2] */
	for (i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i]; /* [step3] */
	for (i = 0; i < n; i++) a[i] = b[i]; /* [step4] */

	free(b);
	free(f);
}

int main(void)
{
	int i, nx;
	int* x; /* �迭�� ù ��° ��ҿ� ���� ������ */
	const int max = 100; /* ���� ū �� */
	puts("���� ����");
	printf("��� ���� : ");

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("0 ~ %d�� ������ �Է��ϼ���.\n", max);

	for (i = 0; i < nx; i++)
	{
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i]<0 || x[i] > max);
	}

	fsort(x, nx, max); /* �迭 x�� ���� ���� */
	puts("������������ �����߽��ϴ�.");

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x); /* �迭�� ���� */

	return 0;
}