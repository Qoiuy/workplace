//       01    open函数
//
//	 功能 打开文件---> 系统调用 
//
//       #include<sys/types.h>
//       #include<sys/stat.h>
//       #include<fcntl.h>
//       int open ( const char *name, flags);
//       int open ( const char *name, flags, mode_t mode);

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd;

	fd = open ( "/root/ls",O_RDONLY);

	if(fd == -1)	
		
	close(fd);

	return 0;
}
