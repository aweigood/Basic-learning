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
//////�����Լ��
//////����һ��һ��������
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
//////������
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
////��ӡ����
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
//////��ӡ3�ı���
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
//////��ӡ����:�ܱ�400�������߿��Ա�4�������ܱ�100����
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
////���������ִӴ�С���
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main() {
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int tmp = 0;
//	printf("����������������");
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
//	printf("���������ɴ�С�����ǣ�%d %d %d\n", a, b, c);
//	return 0;
//}