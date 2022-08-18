#include<iostream>
/*
	C语言中使用字符串数组作为函数参数
*/
#include<stdlib.h>
#include<string>
#include<stdio.h>
void helper(char** p) {
	*p = (char*)malloc(100);
	strcpy(*p, "hello world");
}
int main4() {
	char* str = NULL;
	helper(&str);
	printf("%s/n", str);
	free(str);
	return 0;
}