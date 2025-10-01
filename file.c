#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fp = fopen("contacts.csv", "w");
    if (fp == NULL) 
    {
    perror("Error:");
    return;
}
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n", addressBook->contacts[i].name, 
                                  addressBook->contacts[i].phone,
                                  addressBook->contacts[i].email);
    }
    fclose(fp);
    
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fp = fopen("contacts.csv", "r");
    if (fp == NULL) 
    {
    perror("Error:");
    return;
    }

    addressBook->contactCount = 0;
    while (addressBook->contactCount < MAX_CONTACTS) 
    {
        Contact *c = &addressBook->contacts[addressBook->contactCount];
        int read = fscanf(fp," %20[^,],%11[^,],%30[^\n]\n",c->name, c->phone, c->email);
        if (read != 3) 
        {
            break;
        }
        addressBook->contactCount++;
    }
    fclose(fp);
    
}
