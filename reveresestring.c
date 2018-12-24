#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*character buffer size*/
#define Max_Size 100


/*a link: https://www.youtube.com/watch?v=3vVQlP3asXc */ 

/*typedef stack initialisation*/
typedef struct stack {
	char data[Max_Size];
	int top;
}stack;

stack* s;//a pointer to stack struct

/*function prototype*/
void stack_init(void);
void push(char);
char pop(void);
void display(void);
/*a function to initialise stack*/
void stack_init(void)
{
	s=(stack*)malloc(sizeof(stack));
	s->top=-1;
}

int main (int argc, char* argv[])
{
	char name[Max_Size];
	int i=0;
	char ch;

	/*ask a user to enter the name, and put it one by one inside a stack*/
	stack_init();
	printf("\nplease enter the string: ");
	gets(name);
	

	while(name[i]!='\0')
	{
		ch=name[i];
		push(ch);
		i++;
	}
	printf("\nstring: ");
	display();
	
	/*use pop function to reverse a string*/
	i=0;
	while(s->top>=0)
	{
		name[i]=pop();
		i++;
	}
	printf("\nthe reverse strinng is: ");
	puts(name);
	display();

	return 0;
}

/*push character inside the stack*/
void push (char ch)
{
	if (s->top==Max_Size-1)
	{
		return;
	}
	s->top++;
	s->data[s->top]=ch;
}

/* a function to pop an element from stack*/
char pop(void)
{
	if (s->top==-1)
	{
		return '\0';
	}
	char stack_out=s->data[s->top];
	s->top --;
	return stack_out;
}

/*a function to display all the elements of the stack*/
void display()
{
	if (s->top==-1)
	{
		printf("\nstack is empty!\n");
		return;
	}
	int i;
	for(i=0;i<=(s->top);i++)
	{
		printf("%c",s->data[i]);
	}
	printf("\n");
}
