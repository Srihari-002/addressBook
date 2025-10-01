/* NAME : AMRUTHAPURI SRIHARI
   DATE : 19/ 08/ 2025 
   DESCRIPTION : 

    Project_1: Address Book
    --------------------------------------
    This C program is a contact management system
    that stores contacts with name, phone number, and email.
       It allows:
           - Adding new contacts (with validation and duplicate checks)
           - Listing all contacts (sorted by name)
           - Searching for a contact
           - Editing existing contact details
           - Deleting contacts
           - Saving contacts to a file   
   */



#include <stdio.h>
#include "contact.h"

int main() 
{
    int choice;
    int sortchoice;
    AddressBook addressBook;
    initialize(&addressBook);

    do {
        printf("\n\033[0;33mAddress Book Menu:\033[0m\n");
        printf("\033[0;34m---------------------\033[0m\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("\033[0;34m---------------------\033[0m\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                printf("---------------------\n");
                createContact(&addressBook);
            
                break;
            case 2:
                printf("---------------------\n");
                searchContact(&addressBook);
                break;
            case 3:
                printf("---------------------\n");
                editContact(&addressBook);
                break;
            case 4:
                printf("---------------------\n");
                deleteContact(&addressBook);
                break;
            case 5:         
                listContacts(&addressBook,sortchoice );
                break;
            case 6:
                saveContactsToFile(&addressBook);
                printf("\033[0;32m[✓]\033[0mContacts saved successfully.\n");
                break;
             case 7:
                printf("Do you want to save contacts before exiting? (y/n): ");
                char saveChoice;
                scanf(" %c", &saveChoice);
                if (saveChoice == 'y' || saveChoice == 'Y')
                {
                    saveContactsToFile(&addressBook);
                    printf("\033[0;32m[✓]\033[0mContacts saved successfully.\n");
                }
                printf("\033[0;33mExit from the program...\033[0m\n\n");
                break;
     

            default:
                printf("---------------------\n");
                printf("\033[0;31m [x]\033[0m Invalid choice. Please try again !!!\n");
        }
        
    } while (choice != 7);
    
       return 0;
}
