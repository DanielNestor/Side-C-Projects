#include <stdio.h>
 
typedef struct Node{
	short value;
	struct Node * next;

} element;





void addValue(element * head, int x){

//declare a new node for the list at the head
element * current = head;


	while(current->next != NULL){
		current = current->next;
	}

//add the variable
current->next = malloc(sizeof(element));
current->next->value = x;
current->next->next = NULL;

}




void addValueToBegining(element ** head, int x){
    element * tempnode;
    tempnode = malloc(sizeof(element));
    
    tempnode->value = x;
    tempnode->next = *head;
    *head = tempnode;
    
    
}

int getHeadValue(element * head){
    return head->value;
    
}


element * moveHeadForward(element * head){
    head = head->next;
    return head;
    
}

void print(element * head){
	//declare the head
	element * current = head;
	
//run over the list and print
	while (current->next != NULL){
		printf("%d", current->value);
		current = current->next;

	}
printf("\n");

}


void printToFile(element * head){
	//declare the head
	element * current = head;
        char temp;
        FILE * fp;
        fp = fopen("answer.txt", "w+");
	
//run over the list and print
	while (current->next != NULL){
                temp = current->value;
                temp = temp + 48;
		printf("The temp Value in Print to file is %c \n", temp);
                fputc(temp,fp);
		current = current->next;
                //fflush(fp);
	}
	
	//fputc('\0',fp);
printf("\n");
fclose(fp);
}