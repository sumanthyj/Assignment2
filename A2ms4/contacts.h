
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

#ifndef CONTACTS_H_
#define CONTACTS_H_
//--------------------------------
// Structure Types
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[31];
};

// Structure type Address declaration
struct Address {

	unsigned int strNo;
	
	char strName[41];
	int aptNo;
	char PostCode[8];
	char cityName[41];
};


// Structure type Numbers declaration
struct Numbers {
	char cellPhone[11];
	char homePhone[11];
	char busPhone[11];
};


// Structure type Contact declaration
// NOTE:  Make sure the structure name does not have an 's' on the end!
struct Contact {

	struct Name name;
	struct Address address;
	struct Numbers numbers;
};



//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Get and store from standard input the values for Name, Address, Numbers
void getName(struct Name *name);
void getAddress(struct Address *address);
void getNumbers(struct Numbers *numbers);

// Get and store from standard input the values for a Contact (NOT: Contacts)
// NOTE:  Make sure the structure Contact does not have an 's' on the end!
// Put function prototype below:
void getContact(struct Contact *contact);

#endif // !CONTACTS_H_