#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//string Max length
#define MAX_LENGTH 260
//if arg is null,this is default path
#define DEFAULT_PATH "~/save.dat"
//link table base node structure
typedef struct __node__
{
	//index for node
	int              index;
	//node date pointer
	void*            date;
	//next node,if null,
	//this value is 0
	struct __node__* next;
} NODE;

//functions declare
//create ande init this link table
NODE*    init_link_table(void){
	NODE* head = (NODE*)malloc(sizeof(NODE));
	if(head == 0)
		//fail to alloc memory
		return 0;
	head->index = 0; //head node ,the index is zero
	head->date = NULL;
	head->next = NULL; //this is empty link table
	return head; //return this head node
}

//callback function to used for release node date
typedef void (*RELEASE_MEMORY)(void*);
//for destory link table
int     destory_link_table(NODE* head,RELEASE_MEMORY free_date){
	//if free_date function is pointer nothing,we use default moted 
	//to release memory,free function
	NODE* now_head = head;
	int flag = free_date != NULL;
	NODE* next_node = head->next;
	while(now_head != NULL)
	{
		if(now_head->date != NULL)
		{
			if(flag)
			{
				if(now_head->date != NULL)
					free_date(now_head->date);
				now_head->date = NULL;
			}
			else
			{
				if(now_head->date != NULL)
					free(now_head->date);
				now_head->date = NULL;
			}
		}
		free(now_head);
		now_head = next_node;
		if(now_head != NULL)
			next_node = now_head->next;
	}
	return 0;
}
//release node with index
int    release_node(NODE* head,int index,RELEASE_MEMORY free_date){
	int flag = free_date != NULL;
	NODE* prev_node = NULL;
	NODE* now_head = head;
	//start search for index
	while(now_head != NULL)
	{
		if(now_head->index == index)
		{
			if(prev_node == NULL) return -1;
			prev_node->next = now_head->next;
			if(flag) free_date(now_head->date);
			else free(now_head->date);
			free(now_head);
			now_head = prev_node->next;
			return 0;
		}
		prev_node = now_head;
		now_head = now_head->next;
	}
	return -1;
}
//search node with index
NODE*   search_node(NODE* head,int index){
	NODE* now_head = head;
	while(now_head != NULL)
	{
		if(now_head->index == index)
			return now_head;
		now_head = now_head->next;
	}
	return NULL;
}
//enum link table node and opt this
typedef int (*ENUM_NODE_PROC)(NODE*);
//start enum
int     enum_node(NODE* head,ENUM_NODE_PROC proc){
	if(proc == NULL) return -1;
	NODE* now_head = head->next;
	while(now_head != NULL)
	{
		if(!proc(now_head)) return 0;
		now_head = now_head->next;
	}
	return 0;
}
//enum instance
int my_enum_node(NODE* node){
	printf("index:%d,date:%d\n",node->index,*(int*)node->date);
	if(node->index == 0)
	{
		printf("this index is 0\n");
	}
	return 1;
}

int add_node(NODE* head,void* date){
	NODE* now_head = head;
	//move to end
	NODE* prev = NULL;
	int index;
	while(now_head != NULL)
	{
		index = now_head->index;
		prev = now_head;
		now_head = now_head->next;
	}
	if(prev != NULL)
	{
		NODE* new_node = (NODE*)malloc(sizeof(NODE));
		if(new_node != NULL)
		{
			new_node->index = index + 1;
			new_node->date = date;
			new_node->next = NULL;
			prev->next = new_node;
			return 0;
		}
		else
		{
			printf("new node malloc fail\n");
			return -1;
		}
	}
	else
	{
		printf("prev node bed\n");
		return -2;
	}
}
//print usage
void print_usage(void)
{
	printf("0 is exit this program\n");
	printf("1 is print now date\n");
	printf("2 is add a string to link table\n");
	printf("3 is remove a string from link table\n");
	printf("4 is search a index date\n");
}

//entry point
int main(int argc,char* args[]){
	int flag = -1;
	int index = -1;
	NODE* head1 = init_link_table();
	NODE* head2 = init_link_table();
	if(head1 == NULL)
	{
		printf("link table init fail\n");
		return -1;
	}
	if(head2 == NULL)
	{
		printf("link table init fail\n");
		return -1;
	}
	printf("下面输入第一组数，以#结束:");
	int* input = (int*)malloc(sizeof(int));
	while(scanf("%d",input))
	{
		add_node(head1,input);
		input = (int*)malloc(sizeof(int));
	}
	getchar(); // to delete the # input
	printf("下面输入第二组数值,以#结束:");
	while(scanf("%d",input))
	{
		add_node(head2,input);
		input = (int*)malloc(sizeof(int));
	}
	free(input);
	enum_node(head1,my_enum_node);
	enum_node(head2,my_enum_node);
	destory_link_table(head1,NULL);
	destory_link_table(head2,NULL);
	return 0;
}
