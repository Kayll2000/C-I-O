/*
*@�ļ���д����,ʵ���ļ���������fd1���ļ�1�� cp��  fd2���ļ�2��
*@errno��һ��������룬�ڳ����ʱ�����ں��׳�
*@stderr�Ǳ�׼����
*@author��Mr.Chen
*@date:2022/9/4
*@last modify:Mr.Chen
*/
#include<unistd.h>

#define buff_len    512	//����������󳤶�
void copy(int fd1,int fd2)
{
	char buff[buff_len];
	ssize_t nreads;//Ҫ���ȡ���ֽ���
	while((nreads = read(fd,buff,buff_len)) != 0)
	{
		if(nreads < 0){
			fprintf(stderr,"read error!!!:%S\n",strerror(errno));//����Ļ���������Ϣ
		}
		else{
			if(write(fd2,buff,nreads) != nreads){//ʵ�ʶ�ȡ���ֽ���������Ҫ���ȡ���ֽ��������error
				fprintf(stderr,"read error!!!:%S\n",strerror(errno));
			}
		}
	}
}