// ***************************************************************************
// File name:	ContactEntry.h
// Author:		Chadd Williams
// Date:			2/10/2014
// Class:			CS 360
// Assignment: Introduction to Git and Windows
// Purpose:		This class represents a single contact in the contact list
// ***************************************************************************

#include <string>

class ContactEntry
{
public:
	enum Field{FName, LName, Email};

	// empty constructor
	ContactEntry() {};

	ContactEntry(std::string locFname, std::string locLname, std::string locEmail);
	ContactEntry(ContactEntry &entry);
	~ContactEntry();


	/* accessor methods */
	std::string getFname();
	std::string getLname();
	std::string getEmail();

	/* mutator methods */
	void setFname(std::string);
	void setLname(std::string);
	void setEmail(std::string);


	/* Write a line to a CSV file */
	friend std::ostream& operator<<(std::ostream& stream, const ContactEntry &entry);

	/* read a line from a CSV file */
	friend std::istream& operator>>(std::istream& stream, ContactEntry &entry);

private:

	std::string mFname;
	std::string mLname;
	std::string mEmail;

};