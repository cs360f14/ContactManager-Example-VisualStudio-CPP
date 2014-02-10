// ***************************************************************************
// File name:	ContactEntry.cpp
// Author:		Chadd Williams
// Date:			2/10/2014
// Class:			CS 360
// Assignment: Introduction to Git and Windows
// Purpose:		The implementation for the ContactEntry
// ***************************************************************************

#include "ContactEntry.h"


// ***************************************************************************
// Constructor: 
//
// Description: construct an object using the three parameters to completely 
//							specify the data.
//
// Parameters:	locFname - the first name
//							locLname - the last name
//							locEmail - the email address
//
// Returned:		none
// ***************************************************************************
ContactEntry::ContactEntry(std::string locFname, std::string locLname, std::string locEmail)
{
	mFname = locFname;
	mLname = locLname;
	mEmail = locEmail;
}

// ***************************************************************************
// Constructor: 
//
// Description: construct an object using the ContactEntry provided
//
// Parameters:	entry - the entry to cpy
//
// Returned:		none
// ***************************************************************************
ContactEntry::ContactEntry(ContactEntry &entry)
{
	mFname = entry.mFname;
	mLname = entry.mFname;
	mEmail = entry.mEmail;
}

// ***************************************************************************
// Destructor: 
//
// Description: deconstruct an object
//
// Parameters:	none
//
// Returned:		none
// ***************************************************************************
ContactEntry::~ContactEntry()
{
}


// ***************************************************************************
// Method:			getFname
//
// Description:	retrieve the first name
//
// Parameters:	none
//
// Returned:		string - the first name
// ***************************************************************************
std::string ContactEntry::getFname()
{
	return mFname;
}

// ***************************************************************************
// Method:			getLname
//
// Description:	retrieve the last name
//
// Parameters:	none
//
// Returned:		string - the last name
// ***************************************************************************
std::string ContactEntry::getLname()
{
	return mLname;
}

// ***************************************************************************
// Method:			getEmail
//
// Description:	retrieve the email address
//
// Parameters:	none
//
// Returned:		string - the email address
// ***************************************************************************
std::string ContactEntry::getEmail()
{
	return mEmail;
}

// ***************************************************************************
// Method:			setFname
//
// Description:	set the first name
//
// Parameters:	string - the first name
//
// Returned:		none
// ***************************************************************************
void ContactEntry::setFname(std::string fname)
{
	mFname = fname;
}

// ***************************************************************************
// Method:			setLname
//
// Description:	set the last name
//
// Parameters:	string - the last name
//
// Returned:		none
// ***************************************************************************
void ContactEntry::setLname(std::string lname)
{
	mLname = lname;
}
// ***************************************************************************
// Method:			setEmail
//
// Description:	set the email address
//
// Parameters:	string - theemail address
//
// Returned:		none
// ***************************************************************************
void ContactEntry::setEmail(std::string email)
{
	mEmail = email;
}

// ***************************************************************************
// Method:			operator<<
//
// Description:	Output operator, output a CSV line includeing newline
//
// Parameters:	stream - the ostream to write to
//							entry - the ContactEntry to write
//
// Returned:		ostream - the stream written to.
// ***************************************************************************

std::ostream& operator<<(std::ostream& stream, const ContactEntry &entry)
{
	stream << entry.mFname << "," << entry.mLname << "," << entry.mEmail<< "\n";
	return stream;
}

// ***************************************************************************
// Method:			operator>>
//
// Description:	Input operator to read a CSV line
//
// Parameters:	stream - the istream to read from
//							entry - the ContactEntry to fill with data
//
// Returned:		istream - the stream read from
// ***************************************************************************

std::istream& operator>>(std::istream& stream, ContactEntry &entry)
{
	std::string line;
	int startToken=0, endToken;

	stream >> line;

	// the first comma marks the end of the fname
	endToken = line.find(",");
		entry.mFname = line.substr(startToken, (endToken)-startToken);
	startToken = endToken+1;

	// the second comman marks the end of the lname
	endToken = line.find(",",startToken);
	entry.mLname = line.substr(startToken, (endToken)-startToken);
	startToken = endToken+1;

	// continue to end of line
	entry.mEmail = line.substr(startToken, line.length()-startToken);
	
	return stream;
}
