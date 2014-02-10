// ***************************************************************************
// File name:	ContactManager.cpp
// Author:		Chadd Williams
// Date:			2/10/2014
// Class:			CS 360
// Assignment: Introduction to Git and Windows
// Purpose:		To provide the driver for the contact manager
// ***************************************************************************

#include <iostream>
#include "Contacts.h"

void printMenu()
{
	std::cout<<"1. Print contacts\n";
	std::cout<<"2. Search contacts\n";
	std::cout<<"3. Add contact\n";
	std::cout<<"4. Delete contact\n";
	std::cout<<"5. Write to file\n";
	std::cout<<"6. Quit\n";
}

// ***************************************************************************
// Function:		main
// Description: The main method for the driver. 
//
// Parameters: none
//
// Returned:		EXIT_SUCCESS on success, anything else on failure
// ***************************************************************************
int main()
{
	Contacts *pContacts;
	const int QUIT = 6;
	int choice=0;
	std::string szFilename;

	pContacts = new Contacts("contacts.txt");


	while(QUIT != choice )
	{
		printMenu();
		std::cin >> choice;

		switch( choice )
		{
		case 1:
			std::cout << *pContacts;
			std::cout << "\n";
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
		case 5:
			std::cout << "Filename: ";
			std::cin >> szFilename;
			pContacts->writeData(szFilename);
			break;
		case 6:
			break;
		}
	}

	delete pContacts;
	return EXIT_SUCCESS;
}