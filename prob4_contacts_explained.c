#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define total_friends 150 // You can change this value to as much as you can to add as many friends as you want. for now, you can add 150.

int fileHasContents = 0; // this is to check if the file has contents or not. acts as a boolean variable.

// this function is used to print the menu to ask the user for the input.

void print_menu(){
  printf("------------ MENU -------------\n");
  printf("1. Add new friend.\n");
  printf("2. Display contact information.\n");
  printf("3. Exit.\n");
}


void write_to_file(char array[total_friends][3][256], int i){
	FILE *fp = fopen("friends.txt","a+");
	int temp = 0;
	if(fp == NULL){printf("Error in reading/writing file..\n"); return;}
	if(!fileHasContents){
		fputs("Name\t\tPhone.No\t\tEmail\n",fp);
		fputs("----------------------------------------------------\n",fp);
	}
	while(temp != i){
			fputs(array[temp][0],fp);
			fputs("\t\t",fp);
			fputs(array[temp][1],fp);
			fputs("\t\t",fp);
			fputs(array[temp][2],fp);
			fputs("\n",fp);
			temp += 1;
		}
	
	printf("Contacts have been succesfully added in the file friends.txt. Thank you! :)");
}

// This function is used to show the *current* saved contacts in this *current* execution only.
// after you close the program, the contents will be saved to a file and a new list will be created.

void show (char array[total_friends][3][256], int i){
	printf("\n -------------------- Contact info -------------------- \n");
	int temp = 0, inc=0;
	FILE *fp = fopen("friends.txt","a+");
	char c;
	if(fp == NULL) goto other;
	do{
		c = fgetc(fp);
		if(feof(fp)){
			break;
		}
		inc++;
		if(inc) fileHasContents = 1;
		printf("%c",c);
	}while(1);
	other:
		if(!fileHasContents){
			printf("\nName\t\tPhone.No\t\tEmail\n");
			printf("------------------------------------------------\n");
		}
		while(temp != i){
			printf("%s\t\t",array[temp][0]);
			printf("%s\t\t",array[temp][1]);
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
  
    int choice = 0,friends = 0;
    char array[total_friends][3][256];

	// you could also use a switch case statement here. But I prefer this. :)
    while(choice!=3){
        print_menu();
        printf("Enter your choice : ");
        scanf("%d",&choice);                        
        if(choice == 1){
        	add_friend(array,friends);
        	friends += 1;
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
    }
    if(friends == 0) return 0;
    
    write_to_file(array,friends);
	
	
  return 0;
}
