#pragma once


class Person
{
private:
	String m_strName;
	int m_nAge;
public:
	Person() { m_nAge = 0; } // Default constructor
	Person(const String& strName, int nAge);
	String GetName() { return m_strName; }
	int GetAge() { return m_nAge; }

	bool operator == (Person p) const; // operator ==
	Person(const Person& p); // Copy constructor
	const Person& operator=(const Person& p); // operator =
};



