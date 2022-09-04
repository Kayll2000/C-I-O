/*
*@文件读写案例,实现文件拷贝，将fd1【文件1】 cp到  fd2【文件2】
*@errno是一个错误编码，在出错的时候由内核抛出
*@stderr是标准错误
*@author：Mr.Chen
*@date:2022/9/4
*@last modify:Mr.Chen
*/
#include<unistd.h>

#define buff_len    512	//缓冲数组最大长度
void copy(int fd1,int fd2)
{
	char buff[buff_len];
	ssize_t nreads;//要求读取的字节数
	while((nreads = read(fd,buff,buff_len)) != 0)
	{
		if(nreads < 0){
			fprintf(stderr,"read error!!!:%S\n",strerror(errno));//从屏幕输出出错信息
		}
		else{
			if(write(fd2,buff,nreads) != nreads){//实际读取的字节数不等于要求读取的字节数，输出error
				fprintf(stderr,"read error!!!:%S\n",strerror(errno));
			}
		}
	}
}