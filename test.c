#include<stdio.h>
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 0;
//	c = Add(a, b);
//	printf("%d\n", c);
//	return 0;
//}
//void Bubble_sort(int a[],int sz)
//{
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	for (i = 0;i < sz-1;i++)
//	{
//		for (j = 0;j < sz - 1 - i;j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int a[] = { 27,3,47,5,38,15,36,26,2,38,19,44,46,4,48,50 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int i = 0;
//	printf("冒泡排序之前：");
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", a[i]);
//	}
//	Bubble_sort(a, sz);
//	printf("\n");
//	printf("冒泡排序之后：");
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", a[i]);
//	}
//
//	return 0;
//}
#include"game.h"
void menu()
{
	printf("***************************************\n");
	printf("******    1.play     0.exit      ******\n");
	printf("***************************************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	char ret;
	while (1)
	{
		PlayerMove(board,ROW,COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		
		ComputerMove(board,ROW,COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int i = 0;
	do
	{
		menu();
		printf("请输入您的选择（1/0):");
		scanf_s("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (i);
	
	return 0;
}
