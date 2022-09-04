/*
*@�ļ�׷�ӣ�ʵ��fcntl_set����׷���ļ�״̬��־   clr_fl���׷���ļ�״̬��־
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

#define BUFF_LEN 1024

int main(int argc ,char *argv[])
{
	char buff[BUFF_LEN];
	
	if(argc < 3){
		fprintf(stderr,"usage:%s content destfile\n",argv[0]);
		exit(1);
	}
	int fd = open(argv[2],O_WRONLY);
	//����׷���ļ�״̬��־
	set_fl(fd,O_APPEND);
	//���׷���ļ�״̬��־
//	clr_fl(fd,O_APPEND);	//�����δ��벻ע�ͣ����ļ�ִ�к󽫲�����׷�Ӷ��Ǹ��ǡ�
	/*
	������δ��빦��
	int fd = open(argv[2],O_WRONLY | O_APPEND);
	if(fd < 0){
		perror("open error");
		exit(1);
	*/
	//��λ���ļ�β
	//lseek(fd,0L,SEEK_END);
	sleep(10);
	//���ļ�β��׷������
	size_t size = strlen(argv[1]) * sizeof(char);
if(write(fd,buff,size) != size){//ʵ�ʶ�ȡ���ֽ���������Ҫ���ȡ���ֽ��������error
	fprintf(stderr,"read error!!!:%S\n",strerror(errno));
	exit(1);
	}
	return 0;
	}