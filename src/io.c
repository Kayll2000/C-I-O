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
	char buff[BUFF_LEN];//�������飬BUFF_LEN�����̿��й�
	/*
	Ubuntu���df -k �鿴��ǰ�ķ������
	��Ubuntu�У�ʹ��sudo tune2fs -l /dev/sda1������Block szie:���Ǵ��̿��С��ͨ��IOÿ�ζ�д�ĵ�λ��һ�����̿��С
	���Block size : 4096,��ô�������BUFF_LEN Ϊ 4096�������̿��С����һ�Σ������ϵͳ���ܡ�Ƶ����ȡ�ļ�����¡���
	*/
	ssize_t nreads;//Ҫ���ȡ���ֽ���
	while((nreads = read(fdin,buff,BUFF_LEN)) != 0)//��Ҫ��read���ļ�
	{
		if(nreads < 0){
			fprintf(stderr,"read error!!!:%S\n",strerror(errno));//����Ļ���������Ϣ
		}
		else{
				printf("read size: %d\n",nreads);	//��ӡ��Ҫ���ȡ���ֽ���
				printf("current: %ld\n",lseek(fdin,0L,SEEK_CUR));//��ӡ����ǰ��ƫ����
			if(write(fdout,buff,nreads) != nreads){//ʵ�ʶ�ȡ���ֽ���������Ҫ���ȡ���ֽ��������error
			//write������ -1
				fprintf(stderr,"read error!!!:%S\n",strerror(errno));
			}
		}
	}
}