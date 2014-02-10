// ***************************************************************************
// File name:	ContactDataStore.cpp
// Author:		Chadd Williams
// Date:			2/10/2014
// Class:			CS 360
// Assignment: Introduction to Git and Windows
// Purpose:		The implementation for the ContactDataStore
// ***************************************************************************

#include "ContactDataStore.h"


// ***************************************************************************
// Constructor
//
// Description:	Allocate the array to 10 elements and setup the integer counters
//
// Parameters:	none
//
// Returned:		none
// ***************************************************************************
ContactDataStore::ContactDataStore()
{
	mpArray = new ContactEntry*[10];
	mNumberOfUsedContacts = 0;
	mNumberOfAllocatedContacts = 10;
	mCurrent = -1;
}

// ***************************************************************************
// Destructor
//
// Description:	Deallocated all the dynamic memory. Rely on the ContactEntry
//							destructor to work properly.
//
// Parameters:	none
//
// Returned:		none
// ***************************************************************************
ContactDataStore::~ContactDataStore()
{
	for(mCurrent = 0; mCurrent < mNumberOfUsedContacts; mCurrent++)
	{
		delete mpArray[mCurrent];
	}
	delete [] mpArray;
}

// ***************************************************************************
// Method:			addEntry
//
// Description:	add and entry to the list of contacts. reallocate the array
//							if necessary;
//
// Parameters:	pEntry - the entry to add
//
// Returned:		int, 1 on success, 0 on failure
// ***************************************************************************
int ContactDataStore::addEntry(ContactEntry *pEntry)
{
	ContactEntry **pLocArray;

	if ( mNumberOfUsedContacts+1 >= mNumberOfAllocatedContacts )
	{
		pLocArray = new ContactEntry*[mNumberOfAllocatedContacts*2];

		for(int i = 0; i< mNumberOfUsedContacts; i++)
		{
			pLocArray[i] = mpArray[i];
		}

		// allocate only the array, no the items pointed to
		delete [] mpArray;

		mpArray = pLocArray;

		mNumberOfAllocatedContacts *= 2;
	}

	mpArray[mNumberOfUsedContacts++] = new ContactEntry(*pEntry);

	return 1;
}

// ***************************************************************************
// Method:			deleteEntry
//
// Description:	delete the current entry.  The new current entry is the first.
//
// Parameters:	none
//
// Returned:		int - 1 on success, 0 on failure
// ***************************************************************************
int ContactDataStore::deleteEntry()
{
	if( mCurrent >= 0 && mCurrent < mNumberOfUsedContacts )
	{
		delete mpArray[mCurrent];

		for(int i=mCurrent;i<mNumberOfUsedContacts-1;i++)
		{
			mpArray[i] = mpArray[i+1];
		}
		return 1;
	}

	return 0;
}

// ***************************************************************************
// Method:			getEntry
//
// Description:	get the entry at the specified address. 
//
// Parameters:	pEntry - the already allocated entry to fill
//							index - the index of the entry
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************
int ContactDataStore::getEntry(ContactEntry *pEntry, int index)
{
	if( index >= 0 && index < mNumberOfUsedContacts)
	{
		pEntry->setEmail(mpArray[index]->getEmail());
		pEntry->setFname(mpArray[index]->getFname());
		pEntry->setLname(mpArray[index]->getLname());

		return 1;
	}
	return 0;
}


// ***************************************************************************
// Method:			editEntry
//
// Description:	edit the current entry
//
// Parameters:	pEntry - the data to store in the current entry
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************
int ContactDataStore::editEntry(ContactEntry *pEntry)
{
	if( mCurrent >= 0 && mCurrent < mNumberOfUsedContacts)
	{
		mpArray[mCurrent]->setEmail(pEntry->getEmail());
		mpArray[mCurrent]->setFname(pEntry->getLname());
		mpArray[mCurrent]->setLname(pEntry->getFname());
		return 1;
	}
	return 0;
}

// ***************************************************************************
// Method:			getNumberOfContacts
//
// Description:	retrieve the number of contacts in the datastore
//
// Parameters:	none
//
// Returned:		int, the number of contacts
// ***************************************************************************
int ContactDataStore::getNumberOfContacts()
{
	return mNumberOfUsedContacts;
}

// ***************************************************************************
// Method:			first
//
// Description:	set the current element to the first item in the list
//
// Parameters:	pEntry - where to return the data in the first entry
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************
int ContactDataStore::first(ContactEntry *pEntry)
{
	mCurrent = 0;
	
	return getEntry(pEntry, mCurrent);
}



// ***************************************************************************
// Method:			next
//
// Description:	advance the current pointer and retrieve the new entry
//
// Parameters:	pEntry - where to return the data in the first entry
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************
int ContactDataStore::next(ContactEntry *pEntry)
{
	mCurrent ++;
	return getEntry(pEntry, mCurrent);
}

// ***************************************************************************
// Method:			current
//
// Description:	retrieve the curren entry
//
// Parameters:	pEntry - where to return the data in the first entry
//
// Returned:		1 on success, 0 on failure
// ***************************************************************************
int ContactDataStore::current(ContactEntry *pEntry)
{
	return getEntry(pEntry, mCurrent);
}

// ***************************************************************************
// Method:			operator<<
//
// Description:	Output operator, output a CSV file
//
// Parameters:	stream - the ostream to write to
//							entry - the ContactDataStore to write
//
// Returned:		ostream - the stream written to.
// ***************************************************************************
std::ostream& operator<<(std::ostream &os, ContactDataStore &ds)
{
	for(int i=0; i < ds.mNumberOfUsedContacts ; i++)
	{
		os << *(ds.mpArray[i]);
	}
	return os;
}

// ***************************************************************************
// Method:			operator>>
//
// Description:	Input operator to read a CSV line.  If the datastore is not
//							empty, the data in the stream is appended to the datastore.
//
// Parameters:	stream - the istream to read from
//							ds - the ContactDataStore to fill with data
//
// Returned:		istream - the stream read from
// ***************************************************************************
std::istream& operator>>(std::istream &is, ContactDataStore &ds)
{
	ContactEntry entry;

	while ( is >> entry)
	{
		
		ds.addEntry(&entry);
	}
	return is;
}
