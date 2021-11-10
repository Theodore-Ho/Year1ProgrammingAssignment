/*This C language program is about check 4 digits code,
which is the exam replacement assignment of Programming module of DT228 Technological University Dublin 2019-2020.
This program is worked by Yuhong He C19326053.
This program contains main() function and other five functions named code(), encrypt(), compare(), decrypt(), display().
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 4

																				/*define structure
																				*/
struct code_counter
{
	int correct_code;
	int wrong_code;
};
struct code_counter count_compare;												// global declaration of structure

																				/*code() function
																				*/
int *code()
{
	system("cls");
	static int array[SIZE];
	int i=0;
	char choose;
	
	printf("Would you like input your own code (enter A) or generate a random code (enter B)?\n");
	scanf("%s", &choose);
	
	if(choose=='A'||choose=='a')												//option A
    {
    	printf("Start input your code, press ENTER after each entry.\n");
    	while(i<SIZE)
		{
			int temp;
        	scanf("%d", &temp);													//input code
        	if(temp<0||temp>9)													//check code value
        	{
        		printf("You can only choose code from 0 to 9, enter this code again.\n");
			}//end if
			
        	else
        	{
        		array[i]=temp;													//store code in an array
        		i++;
			}//end else
    	}//end while
    	
    	printf("You entered the code:\n");										//display your own code
    	for(i=0;i<SIZE;i++)
    	{
    		printf("%d ", array[i]);
		}//end for
	}//end if, the option A
	
	else if(choose=='B'||choose=='b')											//option B
	{
		srand((unsigned)time(NULL));											//make sure the random code executed each time is different
		for(i=0;i<SIZE;i++)
		{
			array[i]=rand()%10;
		}//end for
		
		printf("The random code is:\n");
    	for(i=0;i<SIZE;i++)
    	{
    		printf("%d ", array[i]);											//display the random code
		}//end for
	}
	
	else																		//invalid choice
	{
		printf("Invalid choosing\n");
	}//end else
    
	printf("\n\nEnter anything back to the menu choose step.\n");
	char backmenu[1];
    scanf("%s", &backmenu);
    
	return array;
}//end code()

																				/*encrypt() function
																				*/
int encrypt(int *a)
{
	system("cls");
	int temp,i;
	
	temp=*(a+0);																//swap the first number with the third number
	*(a+0)=*(a+2);
	*(a+2)=temp;
	
	temp=*(a+1);																//swap the second number with the fourth number
	*(a+1)=*(a+3);
	*(a+3)=temp;
	
	for(i=0;i<SIZE;i++)															//add 1 for each number
	{
		*(a+i)=*(a+i)+1;
		if(*(a+i)==10)															//change 10 to 0
		{
			*(a+i)=0;
		}//end if
	}//end for
	
	printf("The code encrypted successfully:\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d ", *(a+i));
	}//end for
	
	printf("\nEnter anything back to the menu choose step.\n");
	char backmenu[1];
    scanf("%s", &backmenu);
}//end encrypt()

																				/*compare() function
																				*/
int compare(int *a)
{
	system("cls");
	int i,count=0;
	int access_code[SIZE] = {4,5,2,3};
    int *b=access_code;
    
    for(i=0;i<SIZE;i++)
    {
    	if(*(a+i)==*(b+i))														//compare equal or not
    	{
    		count++;
		}//end if
	}//end for
	
	if(count==SIZE)																//correct
	{
		printf("Correct Code entered\n");
		count_compare.correct_code++;
	}//end for
	
	else																		//wrong
	{
		printf("Wrong Code entered\n");
		count_compare.wrong_code++;
	}//end else
	
	printf("\n");
	printf("Enter anything back to the menu choose step.\n");
	char backmenu[1];
    scanf("%s", &backmenu);
}//end compare()

																				/*decrypt() function
																				*/
int decrypt(int *a)
{
	system("cls");
	int temp,i;
	
	for(i=0;i<SIZE;i++)
	{
		*(a+i)=*(a+i)-1;														//subtract 1 for each number
		if(*(a+i)==-1)
		{
			*(a+i)=9;															//change -1 to 9
		}//end if
	}//end for
	
	temp=*(a+0);																//swap the first number with the third number
	*(a+0)=*(a+2);
	*(a+2)=temp;
	
	temp=*(a+1);																//swap the second number with the fourth number
	*(a+1)=*(a+3);
	*(a+3)=temp;
	
	printf("The code decrypted successfully:\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d ", *(a+i));
	}
	
	printf("\nEnter anything back to the menu choose step.\n");
	char backmenu[1];
    scanf("%s", &backmenu);
}//end decrypt()

																				/*display() function
																				*/
void display(int *a)
{
	system("cls");
	int i;
	
	for(i=0;i<SIZE;i++)															//This for loop is just use to "using" the array in display() function, otherwise the program can't execute after display.
	{
		*(a+i)=*(a+i);
	}//end for
	
    printf("Correct times: %d \n", count_compare.correct_code);
    printf("Wrong times: %d \n", count_compare.wrong_code);

	printf("\nEnter anything back to the menu choose step.\n");
	char backmenu[1];
    scanf("%s", &backmenu);
}//end display()

int main()
{
    int forever;
	forever==0;
	count_compare.correct_code=0;
	count_compare.wrong_code=0;
	while(forever!=1)															//make sure the program could continue run without exit
	{
		system("cls");
    	printf("*** MENU ***\n");
    	printf("A. Enter a code.\n");
    	printf("B. Encrypt the code.\n");
    	printf("C. Compare with access code.\n");
    	printf("D. Decrypt the code.\n");
    	printf("E. Display correct/worng times.\n");
    	printf("F. Exit program.\n\n");
    
    	int *array;
    	char choose;
    	char backmenu[1];
    	int check, checkencrypt, checkcompare;
    	
    	scanf("%s", &choose);
    	if(choose=='A'||choose=='a')											//option A
    	{
			array=code();
			check=1;															//if the player choose option A to enter code, "check" value change to 1, allowed choose other option
			checkencrypt=0;
		}//end if, option A
		
		else if(choose=='B'||choose=='b')										//option B
		{
			if(check==1)														//check code has been inputted or not
			{
				if(checkencrypt==0)												//check code has been encrypted or not
				{
					encrypt(array);
					checkencrypt=1;												//if the player choose option B to encrypt code, "checkencrypt" value change to 1, allowed choose option C and D
				}//end inner if
				
				else
				{
					system("cls");
					printf("You have encrypted your code already.\n\n");
					printf("Enter anything back to the menu choose step.\n");
    				scanf("%s", &backmenu);
				}//end inner else
			}//end outer if
			
			else
			{
				system("cls");
				printf("You should input your code first!!!\n\n");
				printf("Enter anything back to the menu choose step.\n");
    			scanf("%s", &backmenu);
			}//end outer else
		}//end else if, option B
		
		else if(choose=='C'||choose=='c')										//option C
		{
			if(check==1)														//check code has been inputted or not
			{
				if(checkencrypt==1)												//check code has been encrypted or not
				{
					compare(array);
					checkcompare=1;												//if the player choose option C to compare code, "checkcompare" value change to 1, allowed choose option E
				}//end inner if
				
				else
				{
					system("cls");
					printf("You should encrypt your code first.\n\n");
					printf("Enter anything back to the menu choose step.\n");
   					scanf("%s", &backmenu);
				}//end inner else
			}//end outer if
			
			else
			{
				system("cls");
				printf("You should input your code first!!!\n\n");
				printf("Enter anything back to the menu choose step.\n");
    			scanf("%s", &backmenu);
			}//end outer else
		}//end else if, option C
		
		else if(choose=='D'||choose=='d')										//option D
		{
			if(check==1)														//check code has been inputted or not
			{
				if(checkencrypt==1)												//check code has been encrypted or not
				{
					decrypt(array);
					checkencrypt=0;												//let "checkencrypt" value be 0, this allowed program execute option B again in this round
				}//end inner if
				
				else
				{
					system("cls");
					printf("You should encrypt your code first.\n\n");
					printf("Enter anything back to the menu choose step.\n");
   					scanf("%s", &backmenu);
				}//end inner else
			}//end outer if
			
			else
			{
				system("cls");
				printf("You should input your code first!!!\n\n");
				printf("Enter anything back to the menu choose step.\n");
    			scanf("%s", &backmenu);
			}//end outer else
		}//end else if, option D
		
		else if(choose=='E'||choose=='e')										//option E
		{
			if(check==1)														//check code has been inputted or not
			{
				if(checkcompare==1)												//check code has been compared or not
				{
					display(array);
				}//end inner if
				
				else
				{
					system("cls");
					printf("You should compare your code first!!!\n\n");
					printf("Enter anything back to the menu choose step.\n");
    				scanf("%s", &backmenu);
				}//end inner else
			}//end if
			
			else
			{
				system("cls");
				printf("You should input your code first!!!\n\n");
				printf("Enter anything back to the menu choose step.\n");
    			scanf("%s", &backmenu);
			}//end outer else
		}//end else if, option E
		
		else if(choose=='F'||choose=='f')										//option F
		{
			exit(0);
		}//end else if, option F
		
		else																	//invalid option
		{
			system("cls");
			printf("Invalid choose.\n\n");
			printf("Enter anything back to the menu choose step.");
			char backmenu[1];
			scanf("%s", &backmenu);
		}//end else, other choosing
	}//end while
	return 0;
}//end main()



