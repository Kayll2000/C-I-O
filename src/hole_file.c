/*
*@���ɿն��ļ�
*@ʹ�ô�������������ΪҪ�������з�ʽ����
*@Ubuntu�������bin/hole_file hole.txt
*@ͨ��od -c hole.txt���в鿴������ vi hole.txt��
*@author��Mr.Chen
*@date:2022/9/4
*@last modify:Mr.Chen
*/
#incldue<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

//���ɿն��ļ���ʹ��lseek ��ƫ������λ���ļ�β��SEEK_END��Ȼ��offset��������Ϊ��

char *buff = "0123456789";

int main(int argc,char *argv[])
{
	if(argc != 2){
		fprintf(stderr,"-usage:%s [file]\n",argv[0]);
		exit(1);
	}
	int fd = open(argv[1],O_WRONLY | O_CREAT | O_TRUNC,0777);
	if(fd < 0){
		perror("open error");//�Զ����������Ϣ
		exit(1);
	}
	size_t size = strlen(buff)*sizeof(char);
	//���ַ���д�뵽�ն��ļ�֮��
	if(write(fd,buff,size) != size){
		perror("write error!");
		exit(1);
	}
	//��λ���ļ�β��10���ֽڴ�
	if(lseek(fd,10L,SEEK_END) < 0){
		perror("lseek error");
		exit(1);
	}
	//���ļ�β����10���ֽڴ��ٴ�д���ַ��� buff
	if(write(fd,buff,size) != size){
		perror("write error!");
		exit(1);
	}	
	close(fd);
	
	return 0;
}