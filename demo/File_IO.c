/*
*******************************************************************************
*@文件IO基础
*@打开文件
*	FILE *fopen(const char *path, const char *mode); 
*@读文件
*	size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
*@写文件
*	size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);
*@关闭文件
*	int fclose(FILE *fp);
*@文件指针位置偏移
	int fseek(FILE *stream, long offset, int fromwhere);
*@author：Mr.Chen
*@date:2022/9/3
*@last modify:Mr.Chen
*******************************************************************************
*/
#include<stdio.h>
#define num(arr) (sizeof(arr))/(sizeof(arr[0]))	//宏定义求数组长度
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
	file = fopen("E:/File_IO_test/test.txt","a+");	//以追加的方式打开file，不覆盖，在file末尾追加，如果该file不存在，则新建。
	if(file == NULL)
	{
		printf("file open defeated!\n");	//文件打开失败
	}
	#if A
	fp = fwrite(arr,sizeof(char),num(arr),file);
	fclose(file);//free【释放内存】
	printf("writed fp = %d\n",fp);
	printf("writed success!\n");
	#endif
	
	#if B
	fp = fread(buff,1,20,file);	//一次读取1个字节，读取一百次，读完最后fp等于fread的返回值，读取的次数即100.
	fclose(file);
	buff[fp] = '\0';	//令最后一个字符为\0即字符串结束标志
	printf("%s\n",buff);
	printf("fp = %d\n",fp);
	#endif
	
	#if C
	fseek(file,2,SEEK_SET);//SEEK_SET表示从文件头开始，SEEK_CUR表示从当前位置开始,SEEK_END表示文件件尾
	fp = fread(&data,1,1,file);	//将偏移后的数据读取到data里。
	printf("data = %c\n",data);
	fclose(file);
	#endif
return 0;
}
