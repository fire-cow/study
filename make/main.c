#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int configs_strcmp (const char * ps, const char * pe, const char * s, int len, const char **pp)
// {
// 	for (; len > 0 && ps < pe; len--, ++ps, ++s) {
// 		if (*ps != *s) return -1;
// 	}
// 	*pp = ps;
// 	return len;
// }

// int main (int argc, char * argv[])
// {
// 	const char * pstart;
// 	const char * pend;
// 	const char * p;
// 	int plen;
// 	const char * pp;


// 	printf ("****************************************************************************************************\r\n");
//     printf ("* %s %s: %d *\r\n", __FILE__, __func__, __LINE__);
//     printf ("****************************************************************************************************\r\n");

// 	pstart = "hello world !";
// 	pend = pstart + strlen (pstart);
// 	p = "hello";
// 	plen = strlen (p);
// 	pp = pstart;

// 	printf ("[%p] [%p] [%c] [%c] [%p] [%p]\r\n", &pstart, &pend, *pstart, *(pend - 1), &(*pstart), pp);

// 	if (!configs_strcmp (pstart, pend, p, plen, &pp))
// 		printf ("[%p] [%p] [%c] [%c] [%p] [%p]\r\n", &pstart, &pend, *pstart, *(pend - 1), &(*pstart), pp);

// 	return 0;
// }


// typedef int (*pFun) (int, int);
// int Max (int a, int b)
// {
// 	return a > b ? a : b;
// }
// int Min (int a, int b)
// {
// 	return a < b ? a : b;
// }
// int Result (pFun fun, int a, int b)
// {
// 	return (*fun) (a, b);
// }
// void main ()
// {
// 	int a = 3;
// 	int b = 4;
// 	printf ("Max is : %d Min is : %d\r\n", Result (Max, a, b), Result (Min, a, b));
// }


// int s;
// int *sum (int x, int y)
// {
// 	s= x + y;
// 	return &s;
// }

// void main ()
// {
// 	int * r = sum (10, 9);
// 	printf ("10 + 9 = %d", *r);
// }

// int main ()
// {
// 	int  arr [10] = {1,2,3,4,5,6,7,8,9,10};
// 	int (* parr) [10] = & arr;
// 	printf ("arr = %p\r\n", arr);
// 	printf ("& arr = %p\r\n", & arr);
// 	printf ("parr = %p\r\n", parr);
// 	printf ("parr + 1 = %p\r\n", parr + 1);
// 	printf ("& arr + 1 = %p\r\n", & arr + 1);
// 	printf ("arr + 1 = %p\r\n", arr + 1);
// 	printf ("& arr + 1 - & arr= %p", & arr + 1 - & arr);
// 	return 0;
// }


// void show (int (* p)[5], int x, int y)
// {
// 	for (int i = 0; i < x; i++) {
// 		for (int j = 0; j < y; j++) {
// 			printf ("%d", *(*(p + i) + j));
// 		}
// 		printf ("\r\n");
// 	}
// }
// void main ()
// {
// 	 int arr[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
// 	 show (arr, 3, 5);
// }


// int add (int x, int y)
// {
// 	return x + y;
// }

// int main ()
// {
// 	int a = 10;
// 	int b = 20;
// 	add (a, b);
// 	int (*pa) (int, int) = add;
// 	printf ("(*pa) (a,b) = %d", (*pa) (a,b));
// 	return 0;
// }


// void show (char * s)
// {
// 	printf ("%s\r\r", s);
// }

// void test (void (* ps)(char *))
// {
// 	ps ("abcdef");
// }

// int main ()
// {
// 	test (show);
// 	return 0;
// }


/*#include <stddef.h>
#include <stdio.h>

struct address {
   char name[50];
   
   int phone;

   char street[50];
}add;
//TODO
//BUG
//TAG
//DONE
//MARK
//TEST
//UPDATE
//FIX
//NOTE
//INFO
//STAR

int main()
{
	printf("name = %d, street = %d, phone = %d\r\n",add.name , add.street, &add.phone);

	printf("address 结构中的 name 偏移 = %d 字节。\n",
	offsetof(struct address, name));

	printf("address 结构中的 street 偏移 = %d 字节。\n",
	offsetof(struct address, street));

	printf("address 结构中的 phone 偏移 = %d 字节。\n",
	offsetof(struct address, phone));
	

	return(0);
} */

/*
// 函数声明
unsigned int swapEndian(unsigned int num);

int main() {
    unsigned int num;

    printf("请输入一个十六进制数（例如：0x1A2B3C4D）：");
    scanf("%x", &num);

    unsigned int swappedNum = swapEndian(num);
    
    printf("原数：0x%X\n", num);
    printf("转换后的数：0x%X\n", swappedNum);

    return 0;
}

// 大小端转换函数
unsigned int swapEndian(unsigned int num) {
    return ((num >> 24) & 0x000000FF) | // 取出最高字节
           ((num >> 8)  & 0x0000FF00) | // 取出次高字节
           ((num << 8)  & 0x00FF0000) | // 取出次低字节
           ((num << 24) & 0xFF000000);  // 取出最低字节
}
*/


struct IO_BITS
{
    unsigned int A:1;
    unsigned int B:1;
    unsigned int R:30;    
};
union IO_REG
{
    unsigned int    all;
    struct IO_BITS  bit;
};

typedef struct
{
    volatile union IO_REG P0;
}IO_Typedef;

void fun(union IO_REG *pio)
{
    pio->bit.A = 1;
    pio->bit.B = 0;
}

//int main(int argc, const char *argv[])
int main()
{
    IO_Typedef *pa;

    //unsigned int a = 6;
    //pa = (IO_Typedef *)&a;

    //unsigned int a[2] = {6,3};
    //pa = (IO_Typedef *)a;

    pa = (IO_Typedef *)malloc(sizeof(IO_Typedef));
    pa->P0.all = 6;
    printf("start...\r\n");

    printf("pa->P0 = %d\r\n", pa->P0.all);
    fun((union IO_REG *)&pa->P0);
    printf("pa->P0 = %d", pa->P0.all);
    return 0;
}

