/* 2017-2 Data Structure 
 * Baekjoon Problem 10828: Stack
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FFLUSH while(getchar()!='\0')

typedef int element;
typedef struct StackNode{
	element data;
	struct StackNode *link;
} StackNode;

typedef struct LinkedStackType{
	StackNode *top;
	int size;
} LinkedStackType;

struct StackNode * new_stack_node(element x){
	struct StackNode *s = (struct StackNode *)malloc(sizeof(struct StackNode));
	s->data = x;
	return s;
}

int stack_empty(LinkedStackType *ls){
	if(ls->top == NULL){
		return 1;
	}
	else return 0;	
}

int stack_size(LinkedStackType *ls){
	return ls->size;	
}

void stack_push(LinkedStackType *ls, StackNode *s){
	s->link = ls->top;
	ls->top = s;
	(ls->size)++;
	return;
}

void stack_pop(LinkedStackType *ls){
	if(stack_empty(ls)){
		perror("Stack is empty!\n");
	}
	else{
		StackNode *tmp = ls->top;
		ls->top = ls->top->link;
		free(tmp);
		(ls->size)--;
	}
	return;
}
StackNode *stack_top(LinkedStackType *ls){
	return ls->top;
}

int main(void){
	int N, i;
	element x;
	char cmd[6];
	LinkedStackType *ls = (LinkedStackType *)malloc(sizeof(LinkedStackType));
	scanf("%d", &N);
	
	for(i=0;i<N;i++){
		scanf("%s", cmd);
		if(!strcmp(cmd, "push")){
			scanf("%d", &x);
			stack_push(ls, new_stack_node(x));	
		}
		else if(!strcmp(cmd, "pop")){
			if(stack_empty(ls)){
				printf("-1\n");
			}
			else{
				printf("%d\n",(stack_top(ls))->data);
				stack_pop(ls);
			}
		}
		else if(!strcmp(cmd, "size")){
			printf("%d\n", ls->size);
		}
		else if(!strcmp(cmd, "empty")){
			if(stack_empty(ls)){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
		else if(!strcmp(cmd, "top")){
			if(stack_empty(ls)){
				printf("-1\n");
			}
			else{
				printf("%d\n", ls->top->data);
			}
		}
	}

	return 0;
}
