/*
*@文件拷贝测试用例
*@errno是一个错误编码，在出错的时候由内核抛出
*@stderr是标准错误
*@使用带参主函数，因为要以命令行方式输入
*@Ubuntu编译命令：gcc -o bin/cp -Iinclude obj/io.c src/cp.c
*@Ubuntu使用该测试用例命令： bin/cp  /etc/passwd  ./passwd	//将etc下的passwd拷贝到当前目录下passwd
*@ fd 0  标准输入
*@ fd 1  标准输出
*@ fd 2  标准错误
*@author：Mr.Chen
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
	//文件路径通过命令行传递进去,语法为bin/cp  file1 file2	【3个参数】
	if(argc != 3){//语法不对，丢出错误
		fprintf(stderr,"usage:%s srcfile destfile\n",argv[0]);
		exit(1);
	}
	int fdin,fdout;
	fdin = open(argv[1],O_RDONLY);//以只读形式打开待读取文件
	if(fdin < 0){
		fprintf(stderr,"open error: %s\n",strerror(errno));
		exit(1);//程序中断运行
	}else{
		printf("open success! fd = %d\n",fdin);
	}
	//打开一个待写文件
	fdout = open(argv[2],O_WRONLY | O_CREAT,0777);//前面的0是 黏着位，后面777 是权限rwx
	
	if(fdout < 0){
		fprintf(stderr,"open errpr : %s\n",strerror(errno));
		exit(1);
	}
	//调用文件复制函数copy
	copy(fdin,fdout);
	close(fdin);	//free
	close(fdout);	//free
	
	return 0;//程序正常退出
}