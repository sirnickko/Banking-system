
//

#include "Banking system.h"
#include <stdio.h>


//structure to store account information
struct Account 
{ int accountNumber; 
  char name[100]; 
  char password[50]; 
  float balance;
};
 // structure to store multiple accounts
struct Account accounts[100];
int accountsnumb= 0;

//function prototypes
void createAccount();
void login();
void transfermoney();
void checkbalance();
void displaymenu();




int main()
{
    int choice;
    do{
        displaymenu();
        printf("What do you want to do");
        scanf("%d",&choice);

         switch (choice) {
            case 1: createAccount(); break;
            case 2: login(); break;
            case 3: transfermoney(); break;
            case 4: checkbalance(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    }
	
	while (choice != 5);

	

	return 0;
}
void displaymenu() {
    printf("\nBank Management System\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. Transfer Money\n");
    printf("4. Check Amount\n");
    printf("5. Exit\n");
}

void createAccount(){
    struct Account newaccount;
    char name;
    char password;


    printf("create an account to store you money");
    printf("Enter your name please\n:");
    scanf("%s",&name);
    printf("enter your password");
    scanf("%s",&password);
}

void login (){
    int accountnumber;
    char password;
    int found = 0; // flag to see if the account is found
    
    printf("login into your account/n:");

    //prompt user for account number
    printf("enter your account number");
    scanf("%d",&accountnumber);

    //prompt user to enter password
    printf("enter your password");
    scanf("%s",&password);
    


}

void transfermoney(){
    int senderaccount,recieveraccount;
    float Amount;
    int senderindex = -1,receiverindex = -1;

    //get senders account number
    printf("Enter your account number");
    scanf("%d",&senderaccount);

    //search for senders acccount using a for loop

    for(int i = 0; i<accountsnumb;i++){
        if(accounts[i].accountNumber == senderaccount){
            senderindex = i;
            break;
        }
    }
    if(senderindex == -1){
        printf("Senders account not found.\n");
        return;
    }
    //search for recievers account
    for(int i = 0; i<accountsnumb;i++){
        if(accounts[i].accountNumber == recieveraccount){
            receiverindex = i;
            break;
        }
    }
    if(senderindex == -1){
        printf("Recivers account not found.\n");
        return;
    }
    //ask user for amount to transfer
    printf("Enter the amount to transfer.\n");
    scanf("%f",&Amount);

    //confirm if the sender has enough balance
    if(Amount<=0){
        printf("Invalid amount.\n");
        return;
    }
    if(accounts[senderindex].balance<Amount){
        printf("Not enough balance.\n");
        return;
    }
    //perfom the transfer

    accounts[senderindex].balance-=Amount;
    accounts[receiverindex].balance+=Amount;

    printf("\nTransfer successful\n");
    printf("New balance for %s:%f\n");





    printf("how much money do you want to transfer");

}