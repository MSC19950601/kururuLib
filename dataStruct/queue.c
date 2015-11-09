#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 这个demo介绍并实现了
 * 一个简单的队列
 * 一个简单的队列只能
 * 从一头插入数据
 * 从另一头取出（删除）数据
 */

//依旧定义一个最大长度的宏定义
#define MAX_LENGTH 260
//清零内存宏定义
#define zero_memory(des,size) memset((des),0,(size))
//以下进行队列结构定义
//此处队列依旧使用链式存储
//链式存储中，只要内存够大
//是不存在满队列的情况的
typedef struct __quene__
{
	//队列数据存放，这里使用 char 类型举例
	//最大接受字符串 260 个字符
	//由 MAX_LENGTH 宏定义
	char               date[MAX_LENGTH];
	//指向队列下一个节点的指针
	struct __quene__*  next;
} QUENE;

//队列头节点
QUENE* quene = NULL;

//初始化队列
int    init_quene(void){
	if(quene != NULL)
	{
		printf("队列非空\n");
		return -1;
	}
	//分配队列内存
	quene = (QUENE*)malloc(sizeof(QUENE));
	if(quene == NULL)
	{
		printf("内存分配失败\n");
		return -2;
	}
	zero_memory(quene->date,sizeof(char)*MAX_LENGTH);
	quene->next = NULL;
	return 0;
}

//入队操作
//规定入队操作
//从队列末尾插入数据
int    into_quene(const char* src){
	if(quene == NULL)
	{
		printf("队列没有初始化\n");
		return -3;
	}
	QUENE* now_head = quene;
	if(src == NULL)
	{
		printf("传入非法指针\n");
		return -1;
	}
	//初始化一个队列元素
	QUENE* eml = (QUENE*)malloc(sizeof(QUENE));
	if(eml == NULL)
	{
		printf("内存分配失败\n");
		return -2;
	}
	strcpy(eml->date,src);
	eml->next = NULL;
	while(now_head->next != NULL)
		now_head = now_head->next;
	now_head->next = eml;
	return 0;
}

//出队操作
//出队将删除队首元素
//并返回队首元素的值
int    out_quene(char* rtdate){
	if(quene == NULL)
	{
		printf("队列没有初始化\n");
		return -3;
	}
	QUENE* top_eml = quene->next;
	//队首没有元素，默认返回NULL
	if(top_eml == NULL)
		return -1;
	if(rtdate == NULL)
	{
		printf("传入参数错误\n");
		return -2;
	}
	QUENE* next_eml = top_eml->next;
	strcpy(rtdate,top_eml->date);
	free(top_eml);
	quene->next = next_eml;
	return 0;
}

//获取队首元素
//该获取不改变队列状态
int    get_quene(char* rtdate){
	if(quene == NULL)
	{
		printf("队列没有初始化\n");
		return -3;
	}
	if(rtdate == NULL)
	{
		printf("参数错误\n");
		return -2;
	}
	if(quene->next == NULL)
	{
		printf("队列里没有元素\n");
		return -1;
	}
	strcpy(rtdate,quene->next->date);
	return 0;
}
//销毁队列.......
//竟然以惊人的理由忘了写这个函数
int    destory_quene(void){
	if(quene == NULL)
	{
		printf("队列没有初始化\n");
		return -3;
	}
	while(quene != NULL)
	{
		QUENE* next_quene = quene->next;
		free(quene);
		quene = next_quene;
	}
	return 0;
}

void    usage(void){
	printf("in:进入队列\n");
	printf("out:离开队列\n");
	printf("get:获取队首元素\n");
	printf("exit:退出\n");
}

int main(void){
	char command[10] = {0};
	init_quene();
	usage();
	scanf("%s",command);
	while(strcmp(command,"exit"))
	{
		if(!strcmp(command,"in"))
		{
			printf("请输入一个入队数据:");
			char date[MAX_LENGTH] = {0};
			scanf("%s",date);
			into_quene(date);
		}
		else if(!strcmp(command,"out"))
		{
			char* buff = (char*)malloc(sizeof(char)*MAX_LENGTH);
			out_quene(buff);
			printf("%s 出队\n",buff);
			free(buff);
		}
		else if(!strcmp(command,"get"))
		{
			char* buff = (char*)malloc(sizeof(char)*MAX_LENGTH);
			get_quene(buff);
			printf("队首元素是 %s\n",buff);
			free(buff);
		}
		usage();
		scanf("%s",command);
	}
	destory_quene();
	return 0;
}
