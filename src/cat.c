/*
*@实现Linux中的cat命令
*@使用带参主函数，因为要以命令行方式输入
*@Ubuntu自带的cat命令： 输入重定向cat < file 输出重定向 cat > file
*@Ubuntu编译命令：gcc -o bin/cat -Iinclude src/io.c src/cat.c
*@Ubuntu使用命令：bin/cat file1 file2 ····
*@author：Mr.Chen
*@date:2022/9/4
*@last modify:Mr.Chen
*/
#incldue<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc,char *argv[])
{
	int fd_in = STDIN_FILENO;//0
	int fd_out = STDOUT_FILENO;//1  标准输出即屏幕
	
	int i;
	for(i = 1;i < argc;i++)	//0代表cat命令本身
	{
		fd_in = open(argv[i],O_RDONLY);
		if(fd_in < 0){
			perror("open error");
			continue;
		}
		copy(fd_in,fd_out);
		close(fd_in);
	}
	if(argc == 1){copy(fd_in,fd_out);}
	return 0;
}