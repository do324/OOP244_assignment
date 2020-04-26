#include <iostream>
#include <cstring>
#include <string>
#include "ErrorState.h"
using namespace std;

namespace AMA {
	ErrorState::ErrorState(const char* err_message) {
		if (err_message == nullptr) {
			m_message_adress = nullptr;
		}
		else {
			m_message_adress = new char[strlen(err_message) + 1];
			strcpy(m_message_adress, err_message);
		}
	}
	ErrorState::~ErrorState() {
		delete[] m_message_adress;
		m_message_adress = nullptr;
	}
	void ErrorState::clear() {
		delete[] this->m_message_adress;
		m_message_adress = nullptr;
	}
	bool ErrorState::isClear() const {
		return (this->m_message_adress == nullptr) ? true : false;
	}
	void ErrorState::message(const char* str) {
		int strLength = strlen(str);
		m_message_adress = new char[strLength + 1];
		strncpy(m_message_adress, str, strLength);
		m_message_adress[0] = '\0';
	}
	const char* ErrorState::message() const {
		return this->m_message_adress;
	}
	std::ostream& operator<<(std::ostream& os, const ErrorState& em) {
		if (!em.isClear()) {
			os << em.message();
		}
		return os;
	}
}