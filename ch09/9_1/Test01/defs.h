/*
	错误示例：在头文件中包含函数定义
*/

#include<stdio.h>

void sayHello(); // 函数声明

void sayHello(){ // 函数定义
	printf("Hello!\n");
}