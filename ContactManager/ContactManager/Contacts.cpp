// ***************************************************************************
// File name:	Contacts.cpp
// Author:		Chadd Williams
// Date:			2/10/2014
// Class:			CS 360
// Assignment: Introduction to Git and Windows
// Purpose:		The implementation for the Contacts. This is how the Contacts
//						are exposed to the user.
// ***************************************************************************

#include "Contacts.h"
#include <fstream>
#include <iostream>

// ***************************************************************************
// Constructor
//
// Description:	Allocate the array to 10 elements and setup the integer counters
//
// Parameters:	none
//
// Returned:		none
// ***************************************************************************
Contacts::Contacts()
{
	pDataStore = new ContactDataStore();
}

// ***************************************************************************
// Constructor
//
// Description:	Read a CSV file to initialize the data
//
// Parameters:	fname - the file name
//
// Returned:		none
// ***************************************************************************
Contacts::Contacts(std::string fname)
{
	
	pDataStore = new ContactDataStore();
	readData(fname);
}

// ***************************************************************************
// Destructor
//
// Description:	Deallocate all dynamic memory
//
// Parameters:	none
//
// Returned:		none
// ***************************************************************************
Contacts::~Contacts()
{
	delete  pDataStore;
}

// ***************************************************************************
// Method:			readData
//
// Description:	Read a CSV file.  If there are contacts in the data store, the
//							data is the file is appended to the existing data.
//
// Parameters:	fname - the file name
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************
int Contacts::readData(std::string fname)
{
	std::ifstream theFile;

	theFile.open(fname.c_str());

	if( !theFile )
	{
		return 0;
	}

	theFile >> *this;

	theFile.close();

	return 1;
}


// ***************************************************************************
// Method:			writeData
//
// Description:	Write a CSV file
//
// Parameters:	fname - the file name
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************

int Contacts::writeData(std::string fname)
{
	std::ofstream theFile;

	theFile.open(fname.c_str());

	if( !theFile )
	{
		return 0;
	}

	theFile << *this;

	theFile.close();

	return 1;
}


// ***************************************************************************
// Method:			sortData
//
// Description:	Sort the data based on the given field
//
// Parameters:	sortType - which field to sort on
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************
int Contacts::sortData(ContactEntry::Field sortType)
{
	return 1;
}

// ***************************************************************************
// Method:			addContact
//
// Description:	Add a contact at the end of the list
//
// Parameters:	pEntry - the entry to add
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************

int Contacts::addContact(ContactEntry *pEntry)
{
	return pDataStore->addEntry(pEntry);
}

// ***************************************************************************
// Method:			deleteContact
//
// Description:	Delete the contact at the given index
//
// Parameters:	index - the item to delete
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************
int Contacts::deleteContact(int index)
{
	ContactEntry dummy;
	getContact(&dummy,index);

	return pDataStore->deleteEntry();
}

// ***************************************************************************
// Method:			getContact
//
// Description:	Get the contact at the given index
//
// Parameters:	pEntry - the entry to fill
//							index - the item to delete
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************

int Contacts::getContact(ContactEntry *pEntry, int index)
{
	pDataStore->first(pEntry);
	for(int i=0;i<index;i++)
	{
		pDataStore->next(pEntry);
	}

	return 1;
}

// ***************************************************************************
// Method:			searchData
//
// Description:	
//
// Parameters:	szPattern - the pattern to match
//							field - the field to search
//							pResults - an array of ints containing the indexes that 
//								contain matching entries. This array is allocated by the
//								user and passed into the function.
//							maxResults - the maximum number of results provided 
//								(the size of the pResults array)
//
// Returned:		The number of results found (0 to maxResults)
// ***************************************************************************
int Contacts::searchData(std::string szPattern, ContactEntry::Field field, 
	int *pResults, int maxResults)
{
	return 0;
}

// ***************************************************************************
// Method:			visitEachContact
//
// Description:	Call func on each contact. func may not update
//							the entries
//
// Parameters:	func - the function to call on each entry;
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************

int Contacts::visitEachContact(VisitFunction func)
{
	ContactEntry entry;
	pDataStore->first(&entry);

	while(  pDataStore->current(&entry) )
	{
		func(&entry);
		pDataStore->next(&entry);
	}

	return 1;
}

// ***************************************************************************
// Method:			getNumberOfContacts
//
// Description:	Get the number of contacts in the data store
//
// Parameters:	none
//
// Returned:		the number of contacts
// ***************************************************************************

int Contacts::getNumberOfContacts()
{
	return pDataStore->getNumberOfContacts();
}


// write a CSV file
std::ostream& operator<< (std::ostream& os, Contacts &data)
{
	os << *(data.pDataStore);
	return os;
}


// read a CSV file
std::istream& operator>> (std::istream& is, Contacts &data)
{
	is >> *(data.pDataStore);
	return is;
}

	