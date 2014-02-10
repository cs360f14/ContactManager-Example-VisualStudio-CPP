// ***************************************************************************
// File name:	ContactDataStore.h
// Author:		Chadd Williams
// Date:			2/10/2014
// Class:			CS 360
// Assignment: Introduction to Git and Windows
// Purpose:		This class represents the data store holding all the contacts
//						This implementation uses a dynamic array to store the contacts.
//						The user provides allocated memory but this class reallocates
//						all data.  It is not the responsiblity of the user to deallocate
//						any data not explicitly allocated by the user.
//				
//						Subclass this class to provide a different backing store.
// ***************************************************************************

#include "ContactEntry.h"
#include <iostream>

class ContactDataStore
{
public:


	ContactDataStore();
	~ContactDataStore();

	int addEntry(ContactEntry *pEntry);
	int deleteEntry();

	int getEntry(ContactEntry *pEntry, int index);
	int editEntry(ContactEntry *pEntry);
	
	int getNumberOfContacts();

	int first(ContactEntry *pEntry);
	int next(ContactEntry *pEntry);
	int current(ContactEntry *pEntry);

	// input and output operations for CSV files
	friend std::ostream& operator<<(std::ostream &os, ContactDataStore &ds);
	friend std::istream& operator>>(std::istream &is, ContactDataStore &ds);

private:
	// an array of pointers
	ContactEntry **mpArray;

	int mNumberOfUsedContacts;
	int mNumberOfAllocatedContacts;
	int mCurrent;
};