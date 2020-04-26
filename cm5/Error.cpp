// milestone5
// Name: <doyeon kim>
// Student #: <Your Student 139766166>
// Course: OOP244 Fall 2018
// File: <error.cpp>
#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;
using namespace aid;

namespace aid
{
	Error::Error(const char* err_message) {
		if (err_message == nullptr) {
			m_message = nullptr;
		}
		else {
			m_message = new char[strlen(err_message) + 1];
			strcpy(m_message, err_message);
		}
	}
	
	Error::~Error() {
		delete[] m_message;
		m_message = nullptr;
	}

	void Error::clear() {
		delete[] this->m_message;
		m_message = nullptr;
	}
	
	bool Error::isClear() const {
		return (this->m_message == nullptr) ? true : false;
	}
	
	void Error::message(const char * str)
	{
		int length = strlen(str);

		delete[] m_message;
		m_message = nullptr;

		m_message = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			m_message[i] = str[i];
		}
		m_message[length] = '\0';
	}
	const char * Error::message() const
	{
		return m_message;
	}

	std::ostream& operator<<(std::ostream& os, const Error& em) {
		if (!em.isClear()) {
			os << em.message();
		}
		return os;
	}
}