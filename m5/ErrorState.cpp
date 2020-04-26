#include <iostream>
#include <cstring>
#include "ErrorState.h"
using namespace std;
using namespace AMA;

namespace AMA
{
	ErrorState::ErrorState(const char* err_message) {
		if (err_message == nullptr) {
			m_message = nullptr;
		}
		else {
			m_message = new char[strlen(err_message) + 1];
			strcpy(m_message, err_message);
		}
	}
	
	ErrorState::~ErrorState() {
		delete[] m_message;
		m_message = nullptr;
	}

	void ErrorState::clear() {
		delete[] this->m_message;
		m_message = nullptr;
	}
	
	bool ErrorState::isClear() const {
		return (this->m_message == nullptr) ? true : false;
	}
	
	void ErrorState::message(const char * str)
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
	const char * ErrorState::message() const
	{
		return m_message;
	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& em) {
		if (!em.isClear()) {
			os << em.message();
		}
		return os;
	}
}