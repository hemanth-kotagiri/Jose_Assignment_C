#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
# define total_friends 150 // You can change this value to as much as you can to add as many friends as you want. for now, you can add 150.


// this function is used to print the menu to ask the user for the input.

void print_menu(){
  printf("------------ MENU -------------\n");
  printf("1. Add new friend.\n");
  printf("2. Display contact information.\n");
  printf("3. Exit.\n");
}

// This function is used to show the *current* saved contacts in this *current* execution only.
// after you close the program, the contents will be saved to a file and a new list will be created.

void show (char array[total_friends][3][256], int i){
	int temp = 0;
	printf("\n ----- Contact info ----- \n");
	FILE *fp = fopen("friends.txt","r");
	char c;
	if(fp == NULL) goto other;
	do{
		c = fgetc(fp);
		if(feof(fp)){
			break;
		}
		printf("%c",c);
	}while(1);
	
	other:
		printf("\nNAME \t\tPhone No. \tEMAIL\n");
		while(temp != i){
			printf("%s\t\t",array[temp][0]);
			printf("%s\t",array[temp][1]);
			printf("%s\n",array[temp][2]);
			temp += 1;
		}
		printf("\n");
}

// This function is used to add friends to the array.

void add_friend(char array[total_friends][3][256], int i){
	printf("\n------------ New Friend Info -------------\n");
	printf("Name : ");
	scanf("%s",array[i][0]);
	
	printf("Phone-No : ");
	
	scanf("%s",array[i][1]);
	
	printf("Email : ");
	
	scanf("%s",array[i][2]);
	
	printf("\n");
}


int main(){
	// You can clearly ignore these, from line 53 to 59 as these are used to get the current date and time of execution to write to file later.
	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);
    char time_and_date[50] = "Saved contacts on : ";
    strcat(time_and_date,asctime(timeinfo));
    
    
    int choice = 0,friends = 0;
    char array[total_friends][3][256];

	// you could also use a switch case statement here. But I prefer this. :)
    while(choice!=3){
        print_menu();
        printf("Enter your choice : ");
        scanf("%d",&choice);                        
        if(choice == 1){
        	add_friend(array,friends);
		}
		
		else if(choice == 2){
			show(array,friends);
		}
		if(friends == total_friends-1){
			// This happens when you have saved 150 contacts fully used. To add more, change the macro.
			printf("\n");
			printf("No more memory available to store more friends\n");
			printf("Please change the macro - total_friends to large value to store more friends");
			choice = 3;
		}
		friends += 1;
    }
    if(friends == 0) exit(0);
    
    // storing your friends in a file.
    FILE *fp;
    fp = fopen("friends.txt","a");
    int i;
    if(fp == NULL){
		printf("Error in creating/reading file!!");
		return -1;
	}
	fputs(time_and_date,fp); // this is to write to the file of the contents at line 59 of variable time_and_date.
	fputs("\nName\t\tPhone.No\t\tEmail\n",fp);
	fputs("------------------------------------------------\n",fp);
    for(i = 0; i < friends; i++){
		fputs(array[i][0],fp);
		fputs("\t\t",fp);
		fputs(array[i][1],fp);
		fputs("\t\t",fp);
		fputs(array[i][2],fp);
		fputs("\n",fp);
	}
	
	
  return 0;
}
