#include "demo.h"

void open_fun();
void creat_fun();
void read_fun();

int main()
{
	open_fun();
	creat_fun();
	read_fun();
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

void read_fun()
{
/*
 * 	#include <unistd.h>
 * 	函数定义
 * 	ssize_t read (int fd, void *buf, size_t len);
 * 	从fd指向的文件的当前偏移开始  读取len字节长度 到 buf所指向的内存中
 *
 * 	返回值:
 * 		ssize_t len 	返回写入buf中字节数
 * 		0		到达文件末尾
 * 		-1		出错
 */

/*从"/root/.bashrc"文件中读取前20的字符 到 buf中*/
	int 	fd;
	char	buf[21];
	ssize_t	fr;
	fd = open("/root/.bashrc",O_RDONLY);
	if(fd == -1)
                perror("open files /root/.bashrc");
	
	fr = read(fd, &buf[0], 20);
	
	/*	printf("%s\n",buf);	*/

        if(close(fd) == -1)
                perror("error");

/*从"/root/.bashrc"文件中真正读入len个字节*/
	int len = 10000;
	char buf_a[10001] = "nima";
	fd = open("/root/.bashrc", O_RDONLY);
	if(fd == -1)
		perror("open files /root/.bashrc");
	
	/*一直读完所有len字节(len==0) 或读到文件末尾(fr==0)  */
	while( len != 0 && (fr = read(fd, &buf_a[0], len) != 0)) {
		if(fd == -1) {
			/* 读取任何字节之前接收到信号 调用可以重新执行 -->调用返回-1 并且errno的值为EINTR*/
			if(errno == EINTR)
				continue;
			perror("read");
			break;
		}
		
		/*情况二 读入的字节数大于0小于len*/
		len -= fr;
		/*???原意是将内存扩大fr个字节*/
		/*&buf_a += fr;*/
	}
	/*printf("%s", buf_a); */
	 	

}
