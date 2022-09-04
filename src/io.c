/*
*@文件读写案例,实现文件拷贝，将fdin【文件1】 cp到  fdout【文件2】
*@errno是一个错误编码，在出错的时候由内核抛出
*@stderr是标准错误
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

#define BUFF_LEN 512	//每次读的字节 

void copy(int fdin,int fdout)
{
	char buff[buff_len];
	ssize_t nreads;//要求读取的字节数
	while((nreads = read(fdin,buff,buff_len)) != 0)//打开要求read的文件
	{
		if(nreads < 0){
			fprintf(stderr,"read error!!!:%S\n",strerror(errno));//从屏幕输出出错信息
		}
		else{
			if(write(fdout,buff,nreads) != nreads){//实际读取的字节数不等于要求读取的字节数，输出error
			//write出错返回 -1
				fprintf(stderr,"read error!!!:%S\n",strerror(errno));
			}
		}
	}
}