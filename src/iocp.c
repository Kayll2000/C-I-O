/*
*@�ļ�������������
*@errno��һ��������룬�ڳ����ʱ�����ں��׳�
*@stderr�Ǳ�׼����
*@ʹ�ô�������������ΪҪ�������з�ʽ����
*@Ubuntu�������gcc -o bin/cp -Iinclude obj/io.c src/cp.c
*@Ubuntuʹ�øò���������� bin/cp  /etc/passwd  ./passwd	//��etc�µ�passwd��������ǰĿ¼��passwd
*@ fd 0  ��׼����
*@ fd 1  ��׼���
*@ fd 2  ��׼����
*@author��Mr.Chen
*@date:2022/9/4
*@last modify:Mr.Chen
*/
#include"io.h"
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>#include<string.h>
#include<errno.h>
#include<stdio.h>
int main(int argc ,char *argv[])
{
	//�ļ�·��ͨ�������д��ݽ�ȥ,�﷨Ϊbin/cp  file1 file2	��3��������
	if(argc != 3){//�﷨���ԣ���������
		fprintf(stderr,"usage:%s srcfile destfile\n",argv[0]);
		exit(1);
	}
	int fdin,fdout;
	fdin = open(argv[1],O_RDONLY);//��ֻ����ʽ�򿪴���ȡ�ļ�
	if(fdin < 0){
		fprintf(stderr,"open error: %s\n",strerror(errno));
		exit(1);//�����ж�����
	}else{
		printf("open success! fd = %d\n",fdin);
	}
	//��һ����д�ļ�
	fdout = open(argv[2],O_WRONLY | O_CREAT,0777);//ǰ���0�� ���λ������777 ��Ȩ��rwx
	
	if(fdout < 0){
		fprintf(stderr,"open errpr : %s\n",strerror(errno));
		exit(1);
	}
	//�����ļ����ƺ���copy
	copy(fdin,fdout);
	close(fdin);	//free
	close(fdout);	//free
	
	return 0;//���������˳�
}