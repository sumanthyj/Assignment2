/* -------------------------------
Name: Jaya Sumanth Yelamanchili
Student number: 150249183
Email: jsyelamanchili@myseneca.ca
Section: SKK
Date:
----------------------------------
Assignment: 2
Milestone:  4
---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include "contactHelpers.h"
#include"contacts.h"
#define MAXCONTACTS 5
// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:



//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{

	while (getchar() != '\n');

}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}


// getInt: Empty function definition goes here:
int getInt(void)
{
	int value = 0;
	char NL = 'x';
	scanf("%d%c", &value, &NL);
	while (NL != '\n')
	{
		if (NL != '\n')
		{
			clearKeyboard();
		}
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &value, &NL);
	}
	while (value < 0)
	{
		printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		
		scanf("%d", &value);
		clearKeyboard();
	}

	return value;
	
}


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
	int num;
	num = getInt();
	while (num > max || num < min)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		num = getInt();
	}
	return num;
}


// yes: Empty function definition goes here:

int yes(void)
{
	char NL = 'x';
	char choice;
	int reValue = 0;
	scanf("%c%c", &choice, &NL);

	while ((choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N') && NL != '\n')
	{
		if (NL != '\n')
		{
			clearKeyboard();
		}
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &choice, &NL);
	}
	if (choice == 'y' || choice == 'Y')
		reValue = 1;
	else if (choice == 'n' || choice == 'N')
		reValue = 0;

	return reValue;
}


// menu: Empty function definition goes here:
int menu(void)
{
	int option;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	option = getIntInRange(0, 6);
	return option;
}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	int flag = 0;
	struct Contact contact[MAXCONTACTS]= { { { "Rick", {'\0'}, "Grimes" },
{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
{ "4161112222", "4162223333", "4163334444" } },
{
{ "Maggie", "R.", "Greene" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9051112222", "9052223333", "9053334444" } },
{
{ "Morgan", "A.", "Jones" },
{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
{ "7051112222", "7052223333", "7053334444" } },
{
{ "Sasha", {'\0'}, "Williams" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9052223333", "9052223333", "9054445555" } },
	};
	while (!flag)
	{
		int select = menu();
		switch (select)
		{
		case 1:
			displayContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");

			if (yes() == 1)
			{
				printf("\n");
				printf("Contact Management System: terminated\n");
				flag = 1;
			}
			else
			{
				printf("\n");
			}
		}

	}
}
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
		

	int needInput = 1;
	int i;
	int Count = 0;
	char telnum[11];
	while (needInput == 1) {
		scanf("%10s", telnum);
		clearKeyboard();
		if (strlen(telnum) == 10)
		{
			for (i = 0;i < 10;i++)
			{
				if (telnum[i] >= '0'&&telnum[i] <= '9') {
					Count += 1;
				}
			}
		}
		if (Count == 10) {
			needInput = 0;
			strcpy(phoneNum, telnum);
		}
		else {
			Count = 0;
			printf("Enter a 10-digit phone number: ");

		}
	}

	return;
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	int position = -1;
	for (i = 0;i < size;i++)
	{
		if (strcmp(cellNum, contacts[i].numbers.cellPhone) == 0)
		{
			position = i;
		}
	}
	
	return position;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int length)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", length);
}



// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
	printf(" %s", contact->name.firstName);

	if (contact->name.middleInitial[0] != '\0')
	{
		printf( " %s", contact->name.middleInitial);
	}
else
{
printf( "%s", contact->name.middleInitial);
}
	printf(" %s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cellPhone, contact->numbers.homePhone, contact->numbers.busPhone);
	printf("       %u %s, ",contact->address.strNo,contact->address.strName);

	if (contact->address.aptNo != 0)
	{
		printf("Apt# %d, ", contact->address.aptNo);
			}

		printf("%s, %s\n", contact->address.cityName, contact->address.PostCode);

	
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contact[], int size)
{
	{
		int i;
		int count = 0;
		displayContactHeader();

		for (i = 0;i < size;i++)
		{
			if (*contact[i].numbers.cellPhone > 0)
			{
				displayContact(&contact[i]);
				count++;
			}
		}
		displayContactFooter(count);
	}
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contact[], int size)
{
	char phone[11];
	int match;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phone);
	match = findContactIndex(contact, size, phone);

	if (match != -1)
	{
		printf("\n");
		displayContact(&contact[match]);
		printf("\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contact[], int size)
{
	int i, min=0 ,max = 0;
	for (i = 0;i < size;i++)
	{
		if (strlen(contact[i].numbers.cellPhone) == 0)
		{
			min=i;
			
		}
		else
		{
			max++;
		}
	}
	if (max == size)
	{
		printf("\n*** ERROR: The contact list is full! ***\n\n");
	}
	else {
		printf("\n");
		getContact(&contact[min]);
		printf("--- New contact added! ---\n\n");
	}
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contact[], int size)
{
	char cell[11];
	int update;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cell);

	update = findContactIndex(contact, MAXCONTACTS, cell);
	if (update == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contact[update]);
		printf("\nDo you want to update the name? (y or n): ");
		if (yes() == 1)
		{
			getName(&contact[update].name);
			clearKeyboard();
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1)
		{
			getAddress(&contact[update].address);
			
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1)
		{
			getNumbers(&contact[update].numbers);
			//clearKeyboard();
		}

		printf("--- Contact Updated! ---\n\n");
	}
}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contact[], int size)
{
	char cell[11];
	int delete;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cell);

	delete = findContactIndex(contact, MAXCONTACTS, cell);
	if (delete == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contact[delete]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");

		if (yes() == 1)
		{
			*contact[delete].numbers.cellPhone = '\0';
			*contact[delete].name.firstName = '\0';
			 contact[delete].address.aptNo = 0;
			 printf("--- Contact deleted! ---\n");
		}
	}
printf("\n");

}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contact[], int size)
{
	int i, j;
	struct Contact temp;


	for (i = size - 1;i > 0;i--)
	{
		for (j = 0;j < size - 1;j++)
		{
			if (strcmp(contact[j].numbers.cellPhone, contact[j + 1].numbers.cellPhone) > 0)
			{
				temp = contact[j];
				contact[j] = contact[j + 1];
				contact[j + 1] = temp;
			}
		}
	}
	printf("\n--- Contacts sorted! ---\n\n");
}
