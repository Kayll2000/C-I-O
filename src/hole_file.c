/*
*@生成空洞文件
*@使用带参主函数，因为要以命令行方式输入
*@Ubuntu编译命令：bin/hole_file hole.txt
*@通过od -c hole.txt进行查看或者用 vi hole.txt打开
*@author：Mr.Chen
*@date:2022/9/4
*@last modify:Mr.Chen
*/
#incldue<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

//生成空洞文件，使用lseek 将偏移量定位到文件尾【SEEK_END】然后offset参数设置为负

char *buff = "0123456789";

int main(int argc,char *argv[])
{
	if(argc != 2){
		fprintf(stderr,"-usage:%s [file]\n",argv[0]);
		exit(1);
	}
	int fd = open(argv[1],O_WRONLY | O_CREAT | O_TRUNC,0777);
	if(fd < 0){
		perror("open error");//自动处理错误信息
		exit(1);
	}
	size_t size = strlen(buff)*sizeof(char);
	//将字符串写入到空洞文件之中
	if(write(fd,buff,size) != size){
		perror("write error!");
		exit(1);
	}
	//定位到文件尾部10个字节处
	if(lseek(fd,10L,SEEK_END) < 0){
		perror("lseek error");
		exit(1);
	}
	//从文件尾部的10个字节处再次写入字符串 buff
	if(write(fd,buff,size) != size){
		perror("write error!");
		exit(1);
	}	
	close(fd);
	
	return 0;
}