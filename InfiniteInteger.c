#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

//function prototypes provided
int add(element * h1, element * h2, element ** hAnswer);
void equalize_length(char * s);
void buffFirst(int diff);
void buffSecond(int diff);
void printNormalizedFile();
void noBuff();

//when going over the print function retrieve the values
//with an integer pointer
int int_to_pass_in;
int *pointer;
char input[30];
int firstIsNegative = 0;
int secondIsNegative = 0;
int bothNegative = 0;





int main(){

//string for the input of the textfile name to be read
char temp;
int test_count = 0;
int operator = 0;
element **dblptr1;
element **dblptr2;
element **dblptrAnswer;
//dealing with negatives




//will be 1 when reading the first infinite integer
//will be 2 when reading the second integer
int number_selector = 1;

//declare a head for the first value
element * head1 = NULL;
head1 = malloc(sizeof(element));

//declare head for the second value
element * head2 = NULL;
head2 = malloc(sizeof(element));

//declare a head for the answer value
element * head_answer = NULL;
head_answer = malloc(sizeof(element));


//declare your double pointers
dblptr1 = &head1;
dblptr2 = &head2;
dblptrAnswer = &head_answer;

printf("welcome to the infinite integer app by Daniel Nestor. Please enter the name of the text file to read with the equation\n");
scanf("%s", input);
equalize_length(input);
printf("Length Equalized\n");
printNormalizedFile();



//open up the Normalized text file for reading
FILE * fp = fopen("equalizedeq.txt","r+");

//add markers to the begining of the file
addValueToBegining(dblptr1, 666);
addValueToBegining(dblptr2, 666);


short temp_count = 0;
//run over the text file reading the individual characters
while(!feof(fp)){
temp = fgetc(fp);


//subtract from the char value read to get values in int form
temp = temp - 48;
//printf("%d\n", temp);


//checking to see what the temp value is
 //printf("the operator value is %d, and the symbol is %c:\n",temp,temp);

//break the loop once the nulls are reached
if(temp <  -30){
break;

}
 

//if the opertation indicator is found then increase the selector
//skip over the adding the operator to the list
if(temp < -1){
    //set the value of temp to check the operator
    //then set operator to the value of temp
    temp = temp + 48;
    operator = temp;

number_selector++;
goto operation_skip;
}

//if a null is not reached then add to the first linked list if the selector = 1
if(number_selector == 1){

addValueToBegining(dblptr1, temp);

}


if(number_selector == 2){
addValueToBegining(dblptr2,temp);

}

operation_skip:
test_count++;
temp_count++;

}




//once done being loaded decide what to do based on the operator code
if(operator == 0){
    printf("No Operator Provided\n");
}
if(operator == 43){
    //for testing purposes both booleans will be set to false here
   // firstIsNegative = 0;
  //  secondIsNegative = 0;
   // printf("Addition Operator Found\n");
    
   add(head1,head2,dblptrAnswer);
}






//delete the normalized file
//system("rm equalizedeq.txt");
print(head_answer);
printToFile(head_answer);


return 0;
}



int add(element * h1, element * h2, element ** hAnswer){




//case where both adds are positive

    int x = 0;
    int y = 0;
    int total = 0;
    int add_test_count = 0;
    int carry_over = 0;


printf("The value of fin is %d and the value of sin is %d\n",firstIsNegative,secondIsNegative);
//case where both are negative
if(firstIsNegative == 1 && secondIsNegative == 1){
//put a minus sign at the begining
bothNegative = 1;
while(1){
//the case where both numbers are positive
    if(firstIsNegative == 1 && secondIsNegative == 1){
       x = getHeadValue(h1);
	//printf("The Value of Head1 = %d\n",x);
      y = getHeadValue(h2);
      //  printf("The Value of Head2 = %d\n",y);


	if(x == 666 || y == 666){
		break;		
	}        



	//manipulate values here
	total = x + y + carry_over;
	if(total > 9){
		carry_over = 1;
                total = total - 10;
		
	}
	else{
		carry_over = 0;
	}
        
        printf("The value of total is %d: \n", total);
	//add values to the third linked list to store the thing
	addValueToBegining(hAnswer,total);
        
        h1 = moveHeadForward(h1);
	h2 = moveHeadForward(h2);

	

    }
add_test_count++;
  }  








}
addValueToBegining(hAnswer,-3);
return 0;
    //in the case that both element h1 and h2 are positive
while(1){
//the case where both numbers are positive
    if(firstIsNegative == 0 && secondIsNegative == 0){
       x = getHeadValue(h1);
	//printf("The Value of Head1 = %d\n",x);
      y = getHeadValue(h2);
      //  printf("The Value of Head2 = %d\n",y);


	if(x == 666 || y == 666){
		break;		
	}        



	//manipulate values here
	total = x + y + carry_over;
	if(total > 9){
		carry_over = 1;
                total = total - 10;
		
	}
	else{
		carry_over = 0;
	}
        
        printf("The value of total is %d: \n", total);
	//add values to the third linked list to store the thing
	addValueToBegining(hAnswer,total);
        
        h1 = moveHeadForward(h1);
	h2 = moveHeadForward(h2);

	

    }
add_test_count++;
  }  


  return 0;  
    
    

    
    
 //a dummy statement so the compiler does not complain
 //whenever I jump to this pointer
 x++;
 
    
}














//helper functions start here

void equalize_length(char * s){
    //open up 2 files the original to be read to 
    //and the other to be deleted from
    FILE * fp = fopen(s,"r+");
    int operator1_length = 0;
    int operator2_length = 0;
    int operator_count = 1;
    int difference = 0;
    char hold;
    int count = 0;
    //read over the string and determine the lengths of both of the strings.
    while(1){
        
        hold = fgetc(fp);
        hold = hold - 48;
        //break once the null terminal is reached
       printf("hold value = %d:\n", hold);

//check here to see if the first value is a negative
	if(count == 0 && hold == -3){
		firstIsNegative = 1;
		operator1_length--;
		printf("First is Negative\n");
	}

        if(hold < -30){
            break;
        }
        
        //check to see if the value of the tempval is an operator
        if(hold < 0 && hold != -3){
            operator_count++;
        }
        
        //loop over the file to balance out the file
        if(operator_count == 1){
            operator1_length++;
        }
         if(operator_count == 2){
            operator2_length++;
        }
        
     count++; 
     hold++;
        
        
    }
    
    
    //subtract the excess off of operator 2
    operator2_length--;
    
    printf("The length of the first operator is %d:\n", operator1_length);
    printf("The length of the second operator is %d:\n", operator2_length);

	if(operator1_length == operator2_length){
		printf("Normalized Skipped\n");

		noBuff();
		goto normalize_skip;
	}
    
    //get the value of the difference of the two values
    if(operator1_length > operator2_length){
        difference = operator1_length - operator2_length;
    }
    if(operator2_length > operator1_length){
        difference = operator2_length - operator1_length;
    }
    
   // difference--;
    //now based on which value is smaller decide which one needs a zero buff
    if(operator1_length < operator2_length){
        buffFirst(difference);
        
    }
    else if(operator1_length > operator2_length){
        buffSecond(difference);
        
    }
    
    normalize_skip:
	hold++;
    
}



//extra helper functions below here

//this function is used in the case where we do not need to buff anything
void noBuff(){
		char hold;
	    FILE * fp = fopen(input,"r+");
    		FILE * fp2 = fopen("equalizedeq.txt","w+");
	

	//in the case that the first is negative move the readhead forward
	if(firstIsNegative == 1){
		hold = fgetc(fp);
	}

 while(1){
   
loop_top_return_noBuff:
     
         hold = fgetc(fp);

	//check to see if the character after found plus is negative sign
	if(hold == 43){
		//put the plus into the normalized file
		fputc(hold,fp2);

		hold = fgetc(fp);
		if(hold == 45){
			printf("second is negative\n");
			secondIsNegative == 1;
			fputc('0',fp2);
			goto loop_top_return_noBuff;
		}
		else{
			//in this case we have to put the character back into the file;
			fputc(hold,fp2);
			goto loop_top_return_noBuff;
		}

	}


	  if(hold < 0){
                break;
                }
         


	fputc(hold,fp2);
	
}
fclose(fp);
fclose(fp2);
}



void buffFirst(int diff){
    
    FILE * fp = fopen(input,"r+");
    FILE * fp2 = fopen("equalizedeq.txt","w+");
    char hold;
    
   //in the case that the first is negative move the readhead forward
	if(firstIsNegative == 1){
		hold = fgetc(fp);
	}
    
    
    //buff the file
     while(diff > 0){
         diff--;
         fputc('0',fp2);
         
    }
     
     //write the rest back
     while(1){
        loop_top_return_buffFirst:
         hold = fgetc(fp);

//check to see if the character after found plus is negative sign
	if(hold == 43){
		printf("Operator Found in BuffFirst\n");

		//put the plus into the normalized file
		fputc(hold,fp2);

		hold = fgetc(fp);
		if(hold == 45){
			printf("second is negative\n");
			secondIsNegative = 1;
			fputc('0',fp2);
			goto loop_top_return_buffFirst;
		}
		else{
			//in this case we have to put the character back into the file;
			fputc(hold,fp2);
			goto loop_top_return_buffFirst;
		}

	}

         
          


          
       //   printf("hold value in normalize = %d:\n", hold);
            if(hold < 0){
                break;
                }
         
         
         fputc(hold,fp2);
    }
   // fputc('\0',fp2);
    fclose(fp);
    fclose(fp2);
    
    
}

void buffSecond(int diff){
    
    FILE * fp = fopen(input,"r+");
    FILE * fp2 = fopen("equalizedeq.txt","w+");
    char hold;

//in the case that the first is negative move the readhead forward
	if(firstIsNegative == 1){
		hold = fgetc(fp);
	}
    
    //write up to the operator
     while(1){
        
         hold = fgetc(fp);
         
          
          fputc(hold,fp2);
          
          
          printf("hold value in normalize = %d:\n", hold);
            if(hold < 47){
                break;
                }
         
    }
    
    //add the zeros to the second one
    //buff the file
     while(diff > 0){
         diff--;
         fputc('0',fp2);
         
    }
    
    //then add to the end of the file
     while(1){

loop_top_return_buffSecond:
        
         hold = fgetc(fp);
	    

          //check to see if the character after found plus is negative sign
	if(hold == 43){
		//put the plus into the normalized file
		fputc(hold,fp2);

		hold = fgetc(fp);
		if(hold == 45){
			printf("second is negative\n");
			secondIsNegative = 1;
		}
		else{
			//in this case we have to put the character back into the file;
			fputc(hold,fp2);
			goto loop_top_return_buffSecond;
		}

	}

         
          
          
       //   printf("hold value in normalize = %d:\n", hold);
            if(hold < 20){
                break;
                }
          fputc(hold,fp2);
    }
    fclose(fp);
    fclose(fp2);

    
}




//a test function for seeing if the normalized file is good
void printNormalizedFile(){
    FILE * fp;
    fp = fopen("equalizedeq.txt","r+");
    char normchar;
    int count = 0;
    printf("Printing out equalized file\n\n");
    
    while(1){
        
        normchar = fgetc(fp);
       // normchar = normchar - 48;
        
      //  printf("The char in the Normalized File is: %d\n", normchar);
        
        //now check to see what's inside of the normchar
        if(normchar == -1){
            break;
        }
       
      
    }
 //   printf("Equalized loop passed\n");
    fclose(fp);
    
}






