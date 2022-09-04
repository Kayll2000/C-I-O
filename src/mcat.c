/*
*@实现Linux中的cat命令,并且用+ -来代替原先cat 重定向命令的< >
*@使用带参主函数，因为要以命令行方式输入
*@Ubuntu自带的cat命令： 输入重定向cat < file 输出重定向 cat > file
*@Ubuntu编译命令：gcc -o bin/cat -Iinclude src/io.c src/cat.c
*@Ubuntu使用命令：【输入重定向】 bin/mcat + file.txt
*@Ubuntu使用命令：【输出重定向】 bin/mcat - file.txt
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

int mian(int argc,char *argv[])
{
	int fd_in,fd_out;
	int flag = 0;
	int i;
	for(i = 1;i < argc;i++){
		if(!strcmp("+",argv[i])){
/*
strcmp字符串比较  int strcmp(char *str1,char * str2);
若字符串1大于字符串2，返回结果大于零；
若字符串1小于字符串2，返回结果小于零；
若字符串1等于字符串2，返回结果等于零。	
*/		
		fd_in = open(argv[++i],O_RDONLY);//++i——>从2开始
		if(fd_in < 0){
			perror("open error");
			exit(1);
		}
		//将标准输入重定向到文件
		if(dup2(fd_in,STDIN_FILENO) != STDIN_FILENO)
			//dup2(fd_in,STDIN_FILENO);将fd_in对应的指针 复制给STDIN_FILENO对应的指针
		//即STDIN_FILENO不在从标准输入中读取，而是从fd_in对应的文件读取【改变输入重定向】
		{
			perror("dup2 error");
			exit(1);
		}
		close(fd_in);
		}else if(!strcmp("-",argv[i])){
			fd_out = open(argv[++i],O_WRONLY | O_CREAT | O_TRINC,0777);
			if(fd_out < 0)
			{
				perror("open error");
				exit(1);
			}
		//将标准输出重定向到文件
		if(dup2(fd_out,STDIN_FILENO) != STDIN_FILENO)
		{
			perror("dup2 error");
			exit(1);
		}
			close(fd_out);
		}else{
			flag = 1;
			fd_in = open(argv[i],O_RDONLY);
		if(fd_in < 0){
			perror("open error");
			exit(1);
		}
		if(dup2(fd_in,STDIN_FILENO) != STDIN_FILENO)
		{
			perror("dup2 error");
			exit(1);
		}
		copy(STDIN_FILENO,STDOUT_FILENO);
		close(fd_in);
		}
	}
	if(!flag)
	{
		copy(STDIN_FILENO,STDOUT_FILENO);
	}
	return 0;
}