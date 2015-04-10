//	create函数
//
//	creat函数作用：相当于open(文件， O_WRONLY|O_CREAR|O_TRUNC)
//
//	#include<sys/types.h>
//	#include<sys/stat.h>
//	#include<fcntl.h>
//
//	int creat ( const char *name,mode_t mode);
//	
#include<stdio.h>
int main()
{
	int fd;
	fd = creat("/root/ls", 0644);
	if(fd == -1) 		

	return 0;
}
