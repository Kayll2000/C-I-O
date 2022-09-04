/*
*@设置非阻塞I/O模型
*@Linux编译命令：gcc -o bin/nonblock_read -Iinclude src/io.c src/nonblock_read.c
*@author：Mr.Chen
*@date:2022/9/4
*@last modify:Mr.Chen
*/
#include"io.h"
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(void)
{
	char buffer[4096] = {'\0'};
	ssize_t size = 0;
	//设置非阻塞IO
	set_fl(STDIN_FILENO,O_NONBLOCK);
	sleep(5);
	//5秒后未输入，抛出出错信息【error】
	//在sleep结束前输入，则不会抛出错误，成功读取。
	size = read(STDIN_FILENO,buffer,sizeof(buffer));//从标准输入读取【即从键盘获取】 默认采用阻塞方式
	if(size < 0){
		perror("read error");
		exit(1);
	}else if(size == 0){
		printf("read finished\n");
	}else{
		if(write(STDOUT_FILENO,buffer,size) != size){
			perror("write error");
			exit(1);
		}
	}
	
}