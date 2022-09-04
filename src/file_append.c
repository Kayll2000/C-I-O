/*
*@文件追加，实现fcntl_set设置追加文件状态标志   clr_fl清除追加文件状态标志
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

#define BUFF_LEN 1024

int main(int argc ,char *argv[])
{
	char buff[BUFF_LEN];
	
	if(argc < 3){
		fprintf(stderr,"usage:%s content destfile\n",argv[0]);
		exit(1);
	}
	int fd = open(argv[2],O_WRONLY);
	//设置追加文件状态标志
	set_fl(fd,O_APPEND);
	//清除追加文件状态标志
//	clr_fl(fd,O_APPEND);	//如果这段代码不注释，那文件执行后将不会是追加而是覆盖。
	/*
	代替这段代码功能
	int fd = open(argv[2],O_WRONLY | O_APPEND);
	if(fd < 0){
		perror("open error");
		exit(1);
	*/
	//定位到文件尾
	//lseek(fd,0L,SEEK_END);
	sleep(10);
	//往文件尾部追加内容
	size_t size = strlen(argv[1]) * sizeof(char);
if(write(fd,buff,size) != size){//实际读取的字节数不等于要求读取的字节数，输出error
	fprintf(stderr,"read error!!!:%S\n",strerror(errno));
	exit(1);
	}
	return 0;
	}