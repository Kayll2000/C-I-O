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
	char buff[BUFF_LEN];//缓存数组，BUFF_LEN跟磁盘块有关
	/*
	Ubuntu命令：df -k 查看当前的分区情况
	在Ubuntu中，使用sudo tune2fs -l /dev/sda1，其中Block szie:就是磁盘块大小，通过IO每次读写的单位是一个磁盘块大小
	如果Block size : 4096,那么最好设置BUFF_LEN 为 4096，跟磁盘块大小保持一次，可提高系统性能【频繁读取文件情况下】。
	*/
	ssize_t nreads;//要求读取的字节数
	while((nreads = read(fdin,buff,BUFF_LEN)) != 0)//打开要求read的文件
	{
		if(nreads < 0){
			fprintf(stderr,"read error!!!:%S\n",strerror(errno));//从屏幕输出出错信息
		}
		else{
				printf("read size: %d\n",nreads);	//打印出要求读取的字节数
				printf("current: %ld\n",lseek(fdin,0L,SEEK_CUR));//打印出当前的偏移量
			if(write(fdout,buff,nreads) != nreads){//实际读取的字节数不等于要求读取的字节数，输出error
			//write出错返回 -1
				fprintf(stderr,"read error!!!:%S\n",strerror(errno));
			}
		}
	}
}