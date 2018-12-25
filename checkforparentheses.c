/*a compiler program to check the number of paranthese and ...*/
#include <stdio.h>
#include <stdlib.h>

/*create character stack*/
#define Max_Size 300
#define n_array (sizeof (array) / sizeof (const char *))


/*character buffer */
typedef struct stack
{
	char data[Max_Size];
	int top;
}stack ;
stack *s; 

void Stack_Init(void)
{
	s=(stack*)malloc(sizeof(stack));// allocate a memory to stack pointer
	s->top=-1;// initialise stack with pointing to the bottom of stack
	
}



/*function prototype*/
void Stack_Init(void);
void push (char);
char pop();
void display();
int match (char ,char );
int checkforparentheses(char User_Str[]);
int main (int argc,char *argv[])
{
	
	Stack_Init();
	const char * testcases[] = {
		"{([])}",
		"()",
		"([]",
		};
	int i;
	for(i=0;i<3;i++){
		printf("\n%s", testcases[i]);
		if (checkforparentheses(testcases[i])==1) 
			printf("Balanced \n"); 
			else
				printf("Not Balanced \n");
				}
	   
	return 0; 
} 
	
/*check for parantheses*/
int checkforparentheses(char User_Str[]){
          int i=0;// index for while loop
 
          while(User_Str[i]!='\0')
          {
		  if (User_Str[i]=='{' || User_Str[i]=='(' || User_Str[i]=='[')                 {
                         push(User_Str[i]);
                 }
                 if (User_Str[i]=='}' || User_Str[i]==')' || User_Str[i]==']')
                 {
                         /*check if the stack is empty*/
                         if(s->top==-1)
                         {
                                 return 0;
			/*pop one element from the stack*/
			/*after pop check if it is matching!*/ 
                         }else if(match(pop(),User_Str[i])==0)
                         {
                                  return 0;
                         }
                  }
		  i++;
 
          }
          if (s->top==-1)
          {
                  return 1;
          }
		  return 0;
}
/*check for pair function*/
int match (char ch1, char ch2)
{
	if (ch1 == '(' && ch2 == ')') 
		return 1; 
		else if (ch1 == '{' && ch2 == '}') 
			return 1; 
			else if (ch1 == '[' && ch2 == ']') 
				return 1; 
				 else
					 return 0; 
	
}

/*Function to push elements into the stack*/
void push (char ch)
{
	if (s->top==Max_Size-1)
	{
		return;
	}
	s->top++;
	s->data[s->top]=ch;
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
/*Function to pop elements from stack*/
char pop()
{
	if(s->top==-1)
	{
		return '\0';//return NULL
	}
	char Stack_Out=s->data[s->top];
	s->top--;
	return Stack_Out;
}
