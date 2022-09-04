/*
*@���÷�����I/Oģ��
*@Linux�������gcc -o bin/nonblock_read -Iinclude src/io.c src/nonblock_read.c
*@author��Mr.Chen
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
	//���÷�����IO
	set_fl(STDIN_FILENO,O_NONBLOCK);
	sleep(5);
	//5���δ���룬�׳�������Ϣ��error��
	//��sleep����ǰ���룬�򲻻��׳����󣬳ɹ���ȡ��
	size = read(STDIN_FILENO,buffer,sizeof(buffer));//�ӱ�׼�����ȡ�����Ӽ��̻�ȡ�� Ĭ�ϲ���������ʽ
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