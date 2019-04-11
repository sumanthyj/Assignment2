/* -------------------------------
Name: Jaya Sumanth Yelamanchili
Student number: 150249183
Email: jsyelamanchili@myseneca.ca
Section: SKK
Date:
----------------------------------
Assignment: 2
Milestone:  2
---------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include "contacts.h"
#include "contactHelpers.h"
// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

struct Name userName;
struct Address userAddress;
struct Numbers userNum;
char value;
void clear()
{
	while (getchar() != '\n');
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name)
{
	printf("Please enter the contact's first name: ");
	scanf("%31[^\n]", name->firstName);
	clear();
	printf("Do you want to enter a middle initial(s)? (y or n): ");

	if(yes()==1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		clearKeyboard();
	}
	else
	{
		name->middleInitial[0] = 0;
	}
	printf("Please enter the contact's last name: ");
	scanf("%31[^\n]", name->lastName);
	//clear();
}

// getAddress:
void getAddress(struct Address *address)
{
	printf("Please enter the contact's street number: ");
	address->strNo = getInt();
	
	printf("Please enter the contact's street name: ");
	scanf("%41[^\n]", address->strName);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	
	if (yes() == 1)
	{
		printf("Please enter the contact's apartment number: ");
		int value;
		char NL = 'x';
		scanf("%d%c", &value, &NL);
address->aptNo = value;

		while (NL != '\n')
		{
			if (NL != '\n')
			{
				clearKeyboard();
				
			}
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			
			scanf("%d%c", &value, &NL);
			break;
		}
		
		while (value < 0)
		{
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			scanf("%d", &value);
			clearKeyboard();
			address->aptNo = value;
			
		}

	}

	//clearKeyboard();
	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", address->PostCode);
	clearKeyboard();
	printf("Please enter the contact's city: ");
	scanf("%41[^\n]", address->cityName);
	clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers *numbers)
{
	// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
	
		printf("Please enter the contact's cell phone number: ");
		getTenDigitPhone(numbers->cellPhone);
		//clearKeyboard();
	


	printf("Do you want to enter a home phone number? (y or n): ");
	
	
	if (yes() == 1)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->homePhone);
		
	}
	else {
		strcpy(numbers->homePhone, "\0");
	}


	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes() == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->busPhone);
	}
	else {
		strcpy(numbers->busPhone, "\0");
	}
}



// getContact:
// Define Empty function definition below:

void getContact(struct Contact *contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);

}
