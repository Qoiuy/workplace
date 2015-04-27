#include "demo.h"

void open_fun();
void creat_fun();

int main()
{
	open_fun();
	creat_fun();
	return 0;
}

void open_fun()
{
/*
 *	#include <sys/types.h>
 * 	#include <sys/stat.h>
 * 	#include <fcntl.h>
 * 	返回值：成功返回文件描述符 失败返回-1并把errno设置成相应的错误值
 */

/* 以只读的方式 打开一个文件 */
	int fd;
	fd = open("/root/.bashrc", O_RDONLY);
	/*选项介绍 O_RDONLY 只读 O_WRONLY 只写 O_RDWR 读写*/
	if(fd == -1)
		perror("open files /root/.bashrc");
	if(close(fd) == -1)
		perror("error");
/*创建一个文件*/
	fd = open("/root/bash", O_WRONLY|O_CREAT|O_TRUNC);
	/*O_CREAT 当指定的文件不存在时,内核自动创建文件.*/
	/*O_TRUNC 当指定的文件存在.把文件长度截断为0.*/
	if(fd == -1)
		perror("open files /root/bash");
	if(close(fd) == -1)
		perror("error");
/*创建一个带有权限的文件, 功能上等同于creat*/
	fd = open("/root/bash", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	/*0644 等同于 S_IWUSR|S_IRUSR|S_IWGRP|S_IRGRP|S_IROTH*/
	if(fd == -1)
		perror("open files /root/bash");
	if(close(fd) == -1)
		perror("error");
}

void creat_fun()
{
/*
 *	#include <sys/types.h>
 *	#include <sys/stat.h>
 *	#include <fcntl.h>
 *	返回值：成功返回文件描述符 失败返回-1并把errno设置成相应的错误值
 */

/*创建一个带有权限的文件*/
	int fd;
	fd = creat("/root/bash",0644);
	
	if(fd == -1)
		perror("open files /root/bash");
	if(close(fd) == -1)
		perror("error");
}
