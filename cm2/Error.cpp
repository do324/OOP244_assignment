// milestone2
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <error.cpp>
#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;

namespace aid {
	Error::Error(const char* errorMessage) {
		
		if (errorMessage == nullptr || errorMessage[0] == '\0') {
		
			m_message = nullptr;
		
		} else {
			
			m_message = new char[strlen(errorMessage) + 1];
			
			strcpy(m_message, errorMessage);

			m_message[strlen(errorMessage)] = '\0';

		}
	}
	
	Error::~Error() {
		
		delete[] m_message;
	
	}
	
	void Error::clear() {
		
		delete[] m_message;
		
		m_message = nullptr;
	}
	
	bool Error::isClear() const {
		
		return (m_message == nullptr || m_message[0] == '\0') ? true : false;
	
	}
	
	void Error::message(const char* str) {
		
		delete[] m_message;

		if (str == nullptr || str[0] == '\0') {
			m_message = nullptr;
		}
		else{
			m_message = new char[strlen(str) + 1];

			strcpy(m_message, str);
			
		}
	}
	
	const char* Error::message() const {
		
		return m_message;
	
	}
	std::ostream& operator<<(std::ostream& ostr, const Error& obj) {
		
		if (!obj.isClear()) {
		
			ostr << obj.message();
		}
		return ostr;
	}
}