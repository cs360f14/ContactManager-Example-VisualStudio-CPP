// ***************************************************************************
// File name:	Contacts.h
// Author:		Chadd Williams
// Date:			2/10/2014
// Class:			CS 360
// Assignment: Introduction to Git and Windows
// Purpose:		This class represents the contacts and provides all the 
//						high level functions exposed to the user. This class contains
//						a ContactDataStore and only access the contacts through the
//						ContactDataStore interface.  This allows the backing
//						store to change as long as the interface is enforced.
// ***************************************************************************

#include "ContactDataStore.h"

typedef void*(*VisitFunction)(ContactEntry *);


class Contacts
{
public:

	
	Contacts();
	Contacts(std::string fname);

	~Contacts();

	int readData(std::string fname);
	int writeData(std::string fname);

	int sortData(ContactEntry::Field sortType);

	int addContact(ContactEntry *pEntry);
	int deleteContact(int index);
	int getContact(ContactEntry *pEntry, int index);

	int searchData(std::string szPattern, ContactEntry::Field field, int *pResults, int maxResults);

	int visitEachContact(VisitFunction);

	int getNumberOfContacts();


	friend std::ostream& operator<< (std::ostream& os, Contacts &data);
	friend std::istream& operator>> (std::istream& is, Contacts &data);
	
private:
	ContactDataStore *pDataStore;
};