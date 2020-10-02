#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct{
	int data[max];            //the total size of stack will be 10
	int top;
 }STACK;
void push(STACK* S, int v);
void pop(STACK* S, int *v);
void copy(STACK S , STACK *);
int main(){
	int i,val,val2;
	STACK S1, S2;
	S1.top = -1;
	S2.top = -1;
	for(i=0;i<5;i++){           //initialising the values of Stack 1
		printf("Enter Data : ");
		scanf("%d",&val);
		push(&S1, val);	          //pushing the user given values in the Stack
	}
	copy(S1,&S2);               //the Stack is being copied here
	printf("The 2nd Stack Contains :- \n");
	for(i=0;i<5;i++){
		pop(&S2,&val2);
		printf("%d",val2);	
	}
 }
void push(STACK* S, int v){
	if( S->top == max - 1){
		printf("OVERFLOWED!!!!!!!");	
	}
	else{
		S->top++;
		S->data[S->top] = v;	
	}
 }
void pop(STACK* S, int *v){
	if( S->top == -1 ){
		printf("UNDERFLOWED!!!!!");	
	}
	else{
		*v = S->data[S->top];
		S->top--;	
	}
 }
void copy( STACK s1, STACK *s2){
	int i=0,valRetained;
	STACK S3;                     //A temporary Stack is being used to copy the Stack
	S3.top = -1;
	while(s1.top != -1){           //this while loop will terminate when the Stack becomes empty
		pop(&s1,&valRetained);
		push(&S3,valRetained);
	}
	while(S3.top != -1){
		pop(&S3,&valRetained);
		push(s2,valRetained);
	}
 }
