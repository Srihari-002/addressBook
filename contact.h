#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void loadContactsFromFile(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
void initialize(AddressBook *);
void getValidName(char *name);
void getValidphone(AddressBook *addressbook,char *s1);
void getValidEmail(AddressBook *addressBook,char *s2);
int searchByName(AddressBook *addressBook,char *search);
int searchByPhone(AddressBook *addressBook,char *search);
int searchByEmail(AddressBook *addressBook,char *search);
int duplicate(AddressBook *addressBook, const char *s1);
int duplicates(AddressBook *addressBook, const char *s2);



#endif
