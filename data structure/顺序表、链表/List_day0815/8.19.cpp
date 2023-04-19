//////
//////#include <stdio.h>
//////#include<string.h>
//////int main() {
//////	char arr1[] = "bit";
//////	char arr2[] = { 'b', 'i', 't' };
//////	char arr3[] = { 'b', 'i', 't','\0' };
//////	printf("%s\n", arr1);
//////	printf("%s\n", arr2);
//////	printf("%s\n", arr3);
//////	printf("%d\n", strlen("c:\test\328\test.c"));
//////	return 0;
//////}
////
////#include<stdio.h>
////int main() {
////	int i = 0, a = 0, b = 2, c = 3, d = 4;
////	i = a++ && ++b && d++;
////	//i = a++||++b||d++; ? 
////	printf("a = %d\n b = %d\n c = %d\nd = %d\ni = %d\n", a, b, c, d,i); 
////
////	return 0;}
//
//
//
//
//
//
//
////
//////求最大公约数
//////方法一：一个个遍历
////#include <stdio.h>
////int MostNum1(int a, int b) {
////	int n = a > b ? a : b;
////	while (n)
////	{
////		if (n % a == 0 && n % b == 0)
////			return n;
////		n++;
////	}
////}
////
//////方法二
////int Mostnum2(int a, int b) {
////	int i = 1;
////	while (a * i % b != 0)
////		i++;
////	return (a * i);
////}
////
////void text() {
////	int a = 20;
////	int b = 10;
////	printf("%d\n", Mostnum2(a, b));
////	printf("%d\n", MostNum1(a, b));
////}
////
////int main()
////{
////	text();
////	return 0;
////}
////
//
//
//
//
//
////打印素数
////#include <stdio.h>
////#include<math.h>
////void Prinf_num(int a, int b)
////{
////	int j = b;
////	int i = a;
////        for (i ; i <= b; ++i) {
////            for (j = 2; j <= b; ++j) {
////                if (i % j == 0) {
////                    break;
////                }
////            }
////            if (i == j) {
////                printf("%d,", i);
////            }
////        }
////   
////	}
////int main() {
////	Prinf_num(2, 100);
////	return 0;
////}
//
//
//
//
//////打印3的倍数
////#include <stdio.h>
////void Printf_third(int a,int b) {
////	int i = a;
////	while (i <= b)
////	{
////		if (i % 3 == 0)
////		{
////			printf("%d\t", i);
////		}
////		i++;
////	}
////}
////int main() {
////	Printf_third(0, 100);
////}
//
//
//
//
//
//
//////打印闰年:能被400整除或者可以被4整除不能被100整除
////#include<stdio.h>
////void Printf_Run(int year1,int year2) {
////	for (int i = year1;i <=year2;i++) {
////		if (i % 400==0) {
////			printf("%d\t", i);
////		}
////		else if (i % 4 == 0 && i % 100 != 0) {
////			printf("%d\t", i);
////		}
////	}
////}
////int main() {
////	Printf_Run(1000, 2000);
////	return 0;
////}
//
//
//
//
//
////将三个数字从大到小输出
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main() {
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int tmp = 0;
//	printf("请输入三个整数：");
//	scanf("%d%d%d", &a, &b, &c);
//	if (a < b) {
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c) {
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c) {
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("三个整数由大到小依次是：%d %d %d\n", a, b, c);
//	return 0;
//}