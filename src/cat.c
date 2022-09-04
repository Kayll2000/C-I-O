/*
*@ʵ��Linux�е�cat����
*@ʹ�ô�������������ΪҪ�������з�ʽ����
*@Ubuntu�Դ���cat��� �����ض���cat < file ����ض��� cat > file
*@Ubuntu�������gcc -o bin/cat -Iinclude src/io.c src/cat.c
*@Ubuntuʹ�����bin/cat file1 file2 ��������
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

int main(int argc,char *argv[])
{
	int fd_in = STDIN_FILENO;//0
	int fd_out = STDOUT_FILENO;//1  ��׼�������Ļ
	
	int i;
	for(i = 1;i < argc;i++)	//0����cat�����
	{
		fd_in = open(argv[i],O_RDONLY);
		if(fd_in < 0){
			perror("open error");
			continue;
		}
		copy(fd_in,fd_out);
		close(fd_in);
	}
	if(argc == 1){copy(fd_in,fd_out);}
	return 0;
}