/*
*@ʵ��Linux�е�cat����,������+ -������ԭ��cat �ض��������< >
*@ʹ�ô�������������ΪҪ�������з�ʽ����
*@Ubuntu�Դ���cat��� �����ض���cat < file ����ض��� cat > file
*@Ubuntu�������gcc -o bin/cat -Iinclude src/io.c src/cat.c
*@Ubuntuʹ������������ض��� bin/mcat + file.txt
*@Ubuntuʹ�����������ض��� bin/mcat - file.txt
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

int mian(int argc,char *argv[])
{
	int fd_in,fd_out;
	int flag = 0;
	int i;
	for(i = 1;i < argc;i++){
		if(!strcmp("+",argv[i])){
/*
strcmp�ַ����Ƚ�  int strcmp(char *str1,char * str2);
���ַ���1�����ַ���2�����ؽ�������㣻
���ַ���1С���ַ���2�����ؽ��С���㣻
���ַ���1�����ַ���2�����ؽ�������㡣	
*/		
		fd_in = open(argv[++i],O_RDONLY);//++i����>��2��ʼ
		if(fd_in < 0){
			perror("open error");
			exit(1);
		}
		//����׼�����ض����ļ�
		if(dup2(fd_in,STDIN_FILENO) != STDIN_FILENO)
			//dup2(fd_in,STDIN_FILENO);��fd_in��Ӧ��ָ�� ���Ƹ�STDIN_FILENO��Ӧ��ָ��
		//��STDIN_FILENO���ڴӱ�׼�����ж�ȡ�����Ǵ�fd_in��Ӧ���ļ���ȡ���ı������ض���
		{
			perror("dup2 error");
			exit(1);
		}
		close(fd_in);
		}else if(!strcmp("-",argv[i])){
			fd_out = open(argv[++i],O_WRONLY | O_CREAT | O_TRINC,0777);
			if(fd_out < 0)
			{
				perror("open error");
				exit(1);
			}
		//����׼����ض����ļ�
		if(dup2(fd_out,STDIN_FILENO) != STDIN_FILENO)
		{
			perror("dup2 error");
			exit(1);
		}
			close(fd_out);
		}else{
			flag = 1;
			fd_in = open(argv[i],O_RDONLY);
		if(fd_in < 0){
			perror("open error");
			exit(1);
		}
		if(dup2(fd_in,STDIN_FILENO) != STDIN_FILENO)
		{
			perror("dup2 error");
			exit(1);
		}
		copy(STDIN_FILENO,STDOUT_FILENO);
		close(fd_in);
		}
	}
	if(!flag)
	{
		copy(STDIN_FILENO,STDOUT_FILENO);
	}
	return 0;
}