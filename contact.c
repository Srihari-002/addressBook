#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
int i;
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    if (addressBook->contactCount == 0)  
   {
        printf("\n No contacts to display.\n");
        return;
    }

    /* Bubble sort */
    for (int i = 0; i < addressBook->contactCount - 1; i++) {
        for (int j = 0; j < addressBook->contactCount - i - 1; j++) {
            int compare = 0;

            if (  strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0 )
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }
     int i = 0;
    /*Display sorted contacts */
    printf("--------------------------------\033[0;33mContacts list\033[0m-----------------------------------\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("|SI.NO  | %-20s|  %-15s| %-30s|\n", "NAME", "PHONE", "EMAIL");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("| %3d.  | %-20s| %-15s | %-30s|\n",i + 1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    printf("---------------------------------------------------------------------------------\n");
   
}
   
    
void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}




void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    printf("Contacts saved. existing.\n");
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char name[20];
    char s1[11];
    char s2[30];

    getValidName(name); 
    getValidphone(addressBook,s1);
    getValidEmail(addressBook,s2);
    
    strcpy(addressBook -> contacts[addressBook -> contactCount].name,name);
    strcpy(addressBook -> contacts[addressBook -> contactCount].phone,s1);
    strcpy(addressBook -> contacts[addressBook -> contactCount].email,s2);
    printf("\033[0;32m[✓] Contcat created successfully.\033[0m\n ");

    addressBook -> contactCount++;

}         
     /* get valid name */
    
    void getValidName(char *name)
    {
        while(1)
        {
        printf("Enter name         :");
        scanf(" %[^\n]",name);
        int i;
   
       if(name[0] == '.')
        {
            printf("\033[0;31m!!!\033[0m first letter contains alphabets only\n");
            continue;
        }
        int valid = 1;
        for (i = 0; name[i]!= '\0'; i++)
       {
          if(!((name[i] >= 'a' && name[i] <='z') || name[i] == ' ' || name[i] =='.' || (name[i] >= 'A' && name[i] <= 'Z')  ))
           {
                printf(" \033[0;31m[x]\033[0m Name not contains digits  %c ,contains only alphabets\n ",name[i]);
                valid = 0;
                break;
            }
        }
        if(valid)
        break;
        }
    }
       /* get valid phone number */   
       
    int duplicate(AddressBook *addressBook, const char *s1) 
    {
      for (int i = 0; i < addressBook->contactCount; i++) 
       {
         /*duplicate found*/
          if (strcmp(addressBook->contacts[i].phone, s1) == 0) 
            {
                return 1; 
            }
        }
        return 0;    // duplicate not found
    }


   
     /* get valid phone number */  
    void getValidphone(AddressBook *addressBook,char *s1)
    {
        while(1)
        {

        int i ;
        printf("Enter phone Number :");
        scanf(" %[^\n]",s1);
       
        /* check phone number contains  10 numbers or not */
        if(strlen(s1) != 10)
        {
            printf(" \033[0;31m[x]\033[0m phone number must be exactly 10 numbers !!!\n");
            continue;
        }
        int valid = 1;
        for(i = 0; s1[i] !='\0'; i++)
        {
            /* contains only numbers 0 to 9 */
            if(!(s1[i] >= '0' && s1[i] <= '9')  )
            {   
                valid = 0;
                printf("* \033[0;31m[x] \033[0mInvalid phone number : only digits can allowed  *\n");
                break;
                
            }
        }
        if (!valid) continue;
        /* check condition for dupliacte phone numbers*/
        if (duplicate(addressBook, s1)) 
        {
            printf(" \033[0;31m!!!\033[0m Phone number already exists for another contact \n");
            continue;
        }

        break;
        }
    } 
    
         /*   get valid Email  */ 
    int duplicates(AddressBook *addressBook, const char *s2) 
    {
      for (int i = 0; i < addressBook->contactCount; i++) 
       {
          /* dupliactes found */
          if (strcmp(addressBook->contacts[i].email, s2) == 0) 
            {
                return 1;
            }
        }
        return 0; // Not found
    }
    void  getValidEmail(AddressBook *addressBook,char *s2)
    {
        while(1)
        {
        printf("Enter Email        :");
        scanf(" %[^\n]",s2);
        int len = strlen(s2);
        int valid = 1;
        int count = 0;
        int i;
        
        /* mail contains first letter has alphabets only*/
        if(!(s2[0]>= 'a' && s2[0] <='z') || (s2[0] >='A' && s2[0] <= 'Z'))
        {
            printf(" * \033[0;31m!!!\033[0m fisrt letter contains alphabets *\n");
            continue;
        }
        /* validation of Email by the entered characters*/
        for(i = 0; s2[i] != '\0' ; i++)
        {
            if(!((s2[i] >='a' && s2[i] <= 'z') ||(s2[i] >='A' && s2[i] <= 'Z')|| s2[i] == '@' || s2[i] == '.' ||(s2[i] >='0' && s2[i] <='9') || s2[i] =='_' ))
            {
                printf("  \033[0;31m mail not valid \033[0m\n");
                valid = 0;
                break; 
            }
            /* check consecutive dots */
            if(i > 0 && s2[i] == '.' &&  s2[i - 1] == '.')
            {
                printf(" \033[0;31m[x] \033[0mEmail contains consecutive dots \n");
                valid = 0;
                break;
        
            }
            /* check the @ in Email*/
            if(s2[i] == '@')
            {
              count++;
            }
            
        }
        if (!valid || count != 1)
        {
            if (count != 1) 
            {
               printf(" \033[0;31m[x] \033[0m Email must contain exactly one '@' symbol \n");
               continue;
            }
        }
        
        if(valid)
       {
           char *domain = strchr(s2, '@');
           if (!domain || *(domain + 1) == '.' || *(domain + 1) == '\0') 
          {
            printf(" \033[0;31mInvalid domain after '@'dot\033[0m\n");
            continue;

          }
          else
        {
            domain++;
            /* domain can't start or end with dot */
            int domain_len = strlen(domain);
            if(domain[0] == '.' || domain[domain_len - 1] == '.')
            {
                printf(" \033[0;31m!!!\033[0m domain can't start or end with dot  \n");
                continue;
            }

            /* domain end with TLD */

            if(!(strstr(domain,".com") || strstr(domain,".in") || strstr(domain,".net") || strstr(domain,".edu") ||strstr(domain,".org") ) )
            {
                printf("| \033[0;31m[x]\033[0m Domain must end with .com, .org, .net, .edu, or .in  |\n");
                continue;
            }
        } 
        }
        
        
        if(!valid) continue;

        if (duplicates(addressBook,s2)) 
        {
            printf(" \033[0;31mEmail already exists for another contact\033[0m \n");
            continue;
        }

        break;
        
      }
    }


    
void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int option;
    char search[100];
    printf("Select search mode :\n1) Name\n2) Phone\n3) Email\nEnter choice  : ");
    scanf("%d", &option);

    if (option == 1) 
    {
        printf("Enter full name or search term (partial name Accepted)   : ");
    } else if (option == 2) 
    {
        printf("Enter phone Number  : ");
    } else if (option == 3) 
    {
        printf("Enter Email   : ");
    } else 
    {
        printf("\033[0;31m Invalid option.\033[0m\n");
        return;
    }
    scanf(" %[^\n]",search);
    
    int index = -1;
    switch(option) {
        case 1:
            index = searchByName(addressBook,search);
            break;
        case 2:
            index = searchByPhone(addressBook,search);
            break;
        case 3:
            index =searchByEmail(addressBook,search);
            break;
        default:
            printf("\033[0;31mInvalid option.\033[0m\n");
    }
    Contact *found= &addressBook->contacts[index];
    if (index >= 0) 
    {
        int count = 1;
        printf("\033[0;33mEntered details matched to conatct of \033[0m\033[0;32m '%s'\033[0m:-\n",found->name);
        printf("--------------------------------------------------------------------------------\n");
        printf("|SI.NO | %-20s|  %-15s| %-30s|\n", "NAME", "PHONE", "EMAIL");
        printf("--------------------------------------------------------------------------------\n");
        printf("|  %d.  | %-20s|  %-15s| %-30s|\n",count++,found->name, found->phone, found->email);
        printf("--------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\033[0;31mNo contact found with given details.\033[0m\n");
    }    
}

int chooseContact(AddressBook *book, int matches[], int count)
 {
    printf("\n\033[0;33m%d\033[0m\033[0;34m contacts found. Select by serail number or enter phone number directly :\033[0m ", count);
    char s[50];
    scanf(" %[^\n]",s);

    // serail number
    int num = atoi(s);
    if (num >= 1 && num <= count) 
    {
        return matches[num - 1];
    }

    // phone number
    for (int i = 0; i < count; i++) 
    {
        Contact *found = &book->contacts[matches[i]];
        if (strcmp(found->phone, s) == 0) {
            return matches[i];
        }
    }

    printf("Invalid selection.\n");
    return -1;
}
int searchByName(AddressBook *addressBook, char *search)
{
    int matches[100];
    int count = 0;
    int n =strlen(search);
    for (i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcasestr(addressBook->contacts[i].name, search) == addressBook->contacts[i].name)
        {
            
            matches[count++] = i;
        }
        
    }
    if (count == 0)
        {
          return -1;
        }

    int selected;
    if(count == 1) 
    {
        return matches[0];
    }
       /* Display all matching contacts for user to choose */
        printf("\033[0;33mconatcts list on searched name :\033[0m\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("|sl.No | %-20s|  %-15s| %-30s|\n", "Name", "Phone", "Email");
        printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) 
    {
        Contact *found = &addressBook->contacts[matches[i]];
        
        printf("|  %d.  | %-20s|  %-15s| %-30s|\n",i + 1,found->name, found->phone, found->email);
        printf("--------------------------------------------------------------------------------\n");
   
    }
       
    // Let user choose one
    return chooseContact(addressBook, matches, count);

}
    /* logic for seachByphone  */
int searchByPhone(AddressBook *addressBook, char *search) 
{
    for (i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].phone, search) == 0) 
        {
            return i;  // contact found
        }
    }
    return -1;//No contact found
    

}
  /* logic for seachByEmail  */
int searchByEmail(AddressBook *addressBook, char *search)
 {
    for (i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].email, search) == 0)
        {
            return i; // conatct found
        }
    }
    return -1; // No contact found
    
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int option;
    char search[100];
    printf("Select Edit mode :\n1) Name\n2) Phone\n3) Email\nEnter choice  : ");
    scanf("%d", &option);

    if (option == 1) 
    {
        printf("Enter full name or search term (partial name Accepted)   : ");
    } else if (option == 2) 
    {
        printf("Enter phone Number   : ");
    } else if (option == 3) 
    {
        printf("Enter email   : ");
    } else 
    {
        printf("\033[0;31mInvalid option.\033[0m\n");
        return;
    }
    scanf(" %[^\n]",search);
    
    int index = -1;
    switch(option) 
    {
        case 1:
            index = searchByName(addressBook,search);
            break;
        case 2:
            index = searchByPhone(addressBook,search);
            break;
        case 3:
            index = searchByEmail(addressBook,search);
            break;
        default:
            printf("\033[0;31mInvalid option.\033[0m\n");
    }
       if (index == -1)
       {
          printf("\033[0;31m * Contact NOT found *\033[0m\n");
          return;
        }

    Contact *contact = &addressBook->contacts[index];

     // contact before editing
    printf("\n\033[0;33m Matched contact details:\033[0m\n");
    printf("---------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-30s |\n", "Name", "Phone", "Email");
    printf("---------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-30s |\n", contact->name, contact->phone, contact->email);
    printf("---------------------------------------------------------------------------\n");

    char newValue[100];

    char confirm;
    do
    {
        printf("Do you want to edit this contact? (\033[0;32m Y\033[0m / \033[0;31mN\033[0m ): ");
        scanf(" %c", &confirm);
    } while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N');

    if (confirm != 'y' && confirm != 'Y') 
    {
        printf("\033[0;32m Edit cancelled.\033[0m\n");
        return;
    }


    if (option == 1)
    {  
        
        getValidName(newValue);
        strncpy(contact->name, newValue, sizeof(contact->name) - 1);
        contact->name[sizeof(contact->name) - 1] = '\0';
    } 
    else if (option == 2) 
    {  
        getValidphone(addressBook,newValue);
        strncpy(contact->phone, newValue, sizeof(contact->phone) - 1);
        contact->phone[sizeof(contact->phone) - 1] = '\0';
    } 
    else 
    {
        getValidEmail(addressBook,newValue);
        strncpy(contact->email, newValue, sizeof(contact->email) - 1);
        contact->email[sizeof(contact->email) - 1] = '\0';
    }
    
    
    printf("\033[0;32m[✓]\033[0m Contact Edited successfully.\n");

   
}
    


void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */

    if (addressBook->contactCount == 0) {
        printf("Address book is empty. Nothing to delete.\n");
        return;
    }

    int option;
    char search[100];
    printf("Select delete mode:\n1) Name\n2) Phone\n3) Email\nEnter choice : ");
    scanf("%d", &option);
    
    if (option == 1) 
    {
        printf("Enter full name or search term (partial name Accepted)       : ");
    } else if (option == 2) 
    {
        printf("Enter phone Number : ");
    } else if (option == 3) 
    {
        printf("Enter Email      : ");
    } else 
    {
        printf("Invalid option.\n");
        return;
    }
    scanf(" %[^\n]", search);

    int index = -1;
    switch (option)
    {
        case 1:
            index = searchByName(addressBook, search);
            break;
        case 2:
            index = searchByPhone(addressBook, search);
            break;
        case 3:
            index = searchByEmail(addressBook, search);
            break;
        default:
            printf("Invalid option.\n");
            return;
    }

    if (index < 0)
    {
        printf("\033[0;31m!!! \033[0mNo matching contact found.\n");
        return;
    }

    Contact *contact = &addressBook->contacts[index];

     // contact before delete
    printf("\n\033[0;33m Current contact details:\033[0m\n");
    printf("---------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-30s |\n", "Name", "Phone", "Email");
    printf("---------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-30s |\n", contact->name, contact->phone, contact->email);
    printf("---------------------------------------------------------------------------\n");
    
     /*confirmation from the user */
    char confirm;
    do
    {
        printf("Do you want to delete this contact? (\033[0;32m Y\033[0m / \033[0;31mN\033[0m ): ");
        scanf(" %c", &confirm);
    } while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N');

    if (confirm != 'y' && confirm != 'Y') 
    {
        printf("\033[0;32m Deletion cancelled.\033[0m\n");
        return;
    }
     for (int i = index; i < addressBook->contactCount - 1; i++) 
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contactCount--;
    printf("\033[0;32m[✓]\033[0mContact deleted successfully.\n");

}


   

