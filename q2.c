#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;


void add(int val){

    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = val;
    if(top==NULL){
        p->next = NULL;
        top = p;
    }
    else{
    	p->next = top;
  	top = p;  	
    }   
}

int check(int val){

    struct Node *p;
    p=top;
    
    if(!top){
    	printf("!!!UNDERFLOW... LIST IS EMPTY!!!\n");
    	return 0;
    }
    else{	
	 while(p){
	    if(p->data==val)
	        return 1;
   	    p=p->next;
	 }
    }
    return 0;
}

void Display(){
	
    struct Node *p;
    p=top;
    if(!top)
    {	printf("\n!!!LIST IS EMPTY!!!\n");
    	return;
    }
    while(p){
    	printf("%d ",p->data);
    	p=p->next;
    }
    printf("\n");
}

void main(){
    
    int val, i;
    char c;
    
    do{
    	printf("\nDo you want to add an item(0) or check it's presence(1)? \nEnter 2 to DIsplay the list.\n");
    	scanf("%d",&i);
    	switch(i){
    	
    	    case 0:{
	    	        printf("Enter the list item to be added = ");
			scanf("%d",&val);
		    	add(val);
			break;	
    	   }
    	    	   
    	   case 1:{
			printf("Enter value to be checked = ");
			scanf("%d",&val);
			if(check(val))
			    printf("Found");
			else
			    printf("NOT Found");
	   
    	   		break;
    	   }
    	   
    	   case 2:{
    	   		Display();
    	   		break;
    	   }    	   	
    	   default:{   printf("\nWrong Input");  
    	   	 	break;
   	   }
    	}
    
    	printf("\nDo u want to continue(Y/N) = ");
    	scanf("%s",&c);
    	
    }while(c=='Y'||c=='y');
}


