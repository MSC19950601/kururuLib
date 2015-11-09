#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 260
/*现在开始定义栈结构*/
typedef struct __stack__
{
	/*用int类型举例吧*/
	char    date[MAX_LENGTH];
	/*想了许久，还是用链式存储吧*/
	struct __stack__* next;
}STACK;
//现在开始定义栈变量

STACK* stack = NULL;

//还是一样 初始化栈
static
int    init_stack(void){
	if(stack != NULL)
	{
		printf("栈不为空，创建失败\n");
		return -1;
	}
	/* 开始创建栈
	 * 首先创建一个栈顶指针，指向栈顶
	 * 由栈顶开始压入元素
	 */
	stack = (STACK*) malloc(sizeof(STACK));
	if(stack == NULL)
	{
		printf("栈创建失败，原因：内存分配失败\n");
		return -2;
	}
	stack->next = NULL;
	return 1;
}
/* 这里进行的是取栈顶元素
 * 但是这里不删除栈顶的元素
 */
static
char*    get_top(void){
	if(stack == NULL)
	{
		printf("栈尚未创建\n");
		return 0;
	}
	return stack->date;
}
/* 弹出元素
 * 从栈顶弹出元素，并删除栈顶，重新调整栈指针
 * 使其指向栈顶
 */
static
char*    stack_pop(void){
	if(stack == NULL)
	{
		printf("栈尚未创建\n");
		return 0;
	}
	char* rtvalue = stack->date;
	//删除栈顶元素，并调整栈顶指针
	STACK* top = stack->next;
	free(stack);
	stack = top;
	return rtvalue;
}
/* 压栈操作
 * 创建一个新的栈帧
 * 并插入到栈顶
 * 调整栈顶指针，使其重新指向栈顶
 */
static
int    stack_push(const char* value){
	if(stack == NULL)
	{
		printf("栈尚未创建，是否依旧压栈？");
		char q = 0;
		scanf("%c",&q);
		if(q != 'y' && q != 'Y')
			return 0;
	}
	//创建栈帧
	STACK* top = (STACK*)malloc(sizeof(STACK));
	if(top == NULL)
	{
		printf("栈帧创建失败：内存分配失败\n");
		return 0;
	}
	strcpy(top->date,value);
	top->next = stack;
	stack = top;
	return 1;
}
/* 销毁栈
 * 删除所有栈帧
 */
static
int    destory_stack(void){
	if(stack == NULL)
		return 0;
	/* 开始销毁栈 */
	while(stack != NULL)
	{
		STACK* next = stack->next;
		free(stack);
		stack = next;
	}
	return 0;
}

/* usage 
 * 打印所有的命令以及使用方法
 */
static
void    print_usage(void){
	printf("help，打印这个帮助菜单\n");
	printf("push,压栈数据\n");
	printf("pop,出栈数据\n");
	printf("get,打印栈顶数据\n");
	printf("exit,退出");
	return ;
}

int    main(void){
	if(init_stack() != 1)
	{
		return 3;
	}
	print_usage();
	char command[MAX_LENGTH] = {0};
	printf("请输入命令：");
	scanf("%s",command);
	while(strcmp(command,"exit") != 0)
	{
		if(strcmp(command,"help")==0)
			print_usage();
		else if(strcmp(command,"push")==0)
		{
			char input[MAX_LENGTH] = {0};
			printf("请输入一个压栈数值:");
			scanf("%s",input);
			stack_push(input);
		}
		else if(strcmp(command,"pop")==0)
		{
			char* pop_num = stack_pop();
			printf("栈中弹出 %s\n",pop_num);
		}
		else if(strcmp(command,"get")==0)
		{
			char* num = get_top();
			printf("栈顶的数是:%s,栈顶没有被更改\n",num);
		}
		printf("请输入命令:");
		scanf("%s",command);
	}
	destory_stack();
	return 0;
}
