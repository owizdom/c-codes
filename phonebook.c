#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define a contact structure
typedef struct {
    char name[50];
    char phone[20];
} Contact;

Contact phonebook[MAX_CONTACTS];
int contactCount = 0;

// Function to add a contact
void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phonebook is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", phonebook[contactCount].name); // Read string with spaces
    printf("Enter phone number: ");
    scanf(" %[^\n]", phonebook[contactCount].phone);
    contactCount++;
    printf("Contact added successfully!\n");
}

// Function to search for a contact
void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Found: %s - %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to delete a contact
void deleteContact() {
    char name[50];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phonebook[j] = phonebook[j + 1]; // Shift left
            }
            contactCount--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to display all contacts
void displayContacts() {
    if (contactCount == 0) {
        printf("Phonebook is empty.\n");
        return;
    }
    printf("\nPhonebook:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
    printf("\n");
}

// Main function
int main() {
    int choice;
    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: searchContact(); break;
            case 3: deleteContact(); break;
            case 4: displayContacts(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}