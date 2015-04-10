//
//
//perror strerror strerror_r
//
//下面的内容包括 
//	1简单的函数demo
//	2区别
//	3安全（简单）问题
//	4error.h文件的分析
//

//  1 perror demo  
//
//	 01
//	 #include<stdio.h>
//       perror(const char *str);
//
//	 02
//	 #include<string.h>
//	 char * strerror(inr errnum);
//
//	 03
//	 #include<string.h>
//	 int strerror_r (int errnum, char *buf. size_t len);
//
//  2 区别
//  	 说说我对这几个函数的理解 
//  	 3个函数的作用就是将int 型error变量输出成字符串
//  	 区别嘛 ????
//
//  3 安全问题
//  	书上说strerror不是线程安全的
//  	strerror_r是线程安全的
//  	????
//  4 error.h的分析
//  	find / -name error.h结果
//	/usr/include/error.h
//	/usr/include/linux/can/error.h
//	/usr/include/bits/error.h
//
//	-------------------------不分析了
//	-------------------------眼高手低


#include<stdio.h>
#include<string.h>


void perror_demo()
{
	FILE *fp;
	printf("perror demo \n");
	if((fp = fopen("/root/没有此文件","r")) == NULL)
		perror("/root/没有此文件");	
}

void strerror_demo()
{
	FILE *fp;	
	extern int error;
	printf("strerror demo \n");
	if((fp = fopen("/root/没有此文件","r")) == NULL)
		printf("%s\n",strerror(error));		
}

void strerror_r_demo()
{
	FILE *fp;	
	extern int error;
	int i;
	char buf[256];
	printf("strerror_r demo \n");
	if((fp = fopen("/root/没有此文件","r")) == NULL)
		strerror_r(error,buf, sizeof(buf));
		for(i = 0; i < 256; i++)
			printf("%c",buf[i]);
		printf("%s",buf);	
}

int main()
{
	perror_demo();
	strerror_demo();
	strerror_r_demo();
//	strerror_r函数有问题 不会写  ????	

		
	return  0;
}
