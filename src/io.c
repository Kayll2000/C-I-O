/*
*@�ļ���д����,ʵ���ļ���������fdin���ļ�1�� cp��  fdout���ļ�2��
*@errno��һ��������룬�ڳ����ʱ�����ں��׳�
*@stderr�Ǳ�׼����
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

#define BUFF_LEN 512	//ÿ�ζ����ֽ� 

void copy(int fdin,int fdout)
{
	char buff[buff_len];
	ssize_t nreads;//Ҫ���ȡ���ֽ���
	while((nreads = read(fdin,buff,buff_len)) != 0)//��Ҫ��read���ļ�
	{
		if(nreads < 0){
			fprintf(stderr,"read error!!!:%S\n",strerror(errno));//����Ļ���������Ϣ
		}
		else{
			if(write(fdout,buff,nreads) != nreads){//ʵ�ʶ�ȡ���ֽ���������Ҫ���ȡ���ֽ��������error
			//write������ -1
				fprintf(stderr,"read error!!!:%S\n",strerror(errno));
			}
		}
	}
}