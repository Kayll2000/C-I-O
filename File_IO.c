/*
*******************************************************************************
*@�ļ�IO����
*@���ļ�
*	FILE *fopen(const char *path, const char *mode); 
*@���ļ�
*	size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
*@д�ļ�
*	size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);
*@�ر��ļ�
*	int fclose(FILE *fp);
*@�ļ�ָ��λ��ƫ��
	int fseek(FILE *stream, long offset, int fromwhere);
*@author��Mr.Chen
*@date:2022/9/3
*@last modify:Mr.Chen
*******************************************************************************
*/
#include<stdio.h>
#define num(arr) (sizeof(arr))/(sizeof(arr[0]))	//�궨�������鳤��
#define A 1		//fwrite
#define B 0		//fread
#define C 0		//fseek
int main()
{
	FILE *file;
	int fp;
	char data;
	char arr[] = "today is sunny!";
	char buff[20];
	file = fopen("E:/File_IO_test/test.txt","a+");	//��׷�ӵķ�ʽ��file�������ǣ���fileĩβ׷�ӣ������file�����ڣ����½���
	if(file == NULL)
	{
		printf("file open defeated!\n");	//�ļ���ʧ��
	}
	#if A
	fp = fwrite(arr,sizeof(char),num(arr),file);
	fclose(file);//free���ͷ��ڴ桿
	printf("writed fp = %d\n",fp);
	printf("writed success!\n");
	#endif
	
	#if B
	fp = fread(buff,1,20,file);	//һ�ζ�ȡ1���ֽڣ���ȡһ�ٴΣ��������fp����fread�ķ���ֵ����ȡ�Ĵ�����100.
	fclose(file);
	buff[fp] = '\0';	//�����һ���ַ�Ϊ\0���ַ���������־
	printf("%s\n",buff);
	printf("fp = %d\n",fp);
	#endif
	
	#if C
	fseek(file,2,SEEK_SET);//SEEK_SET��ʾ���ļ�ͷ��ʼ��SEEK_CUR��ʾ�ӵ�ǰλ�ÿ�ʼ,SEEK_END��ʾ�ļ���β
	fp = fread(&data,1,1,file);	//��ƫ�ƺ�����ݶ�ȡ��data�
	printf("data = %c\n",data);
	fclose(file);
	#endif
return 0;
}
