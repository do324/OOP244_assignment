///DOYEON KIM
//139766166
//2018/07/23
#include <iostream>
#include <cstring>
#include "ErrorState.h"
using namespace std;

namespace AMA {
	ErrorState::ErrorState(const char* errorMessage) {
		
		if (errorMessage == nullptr) {
		
			m_message = nullptr;
		
		} else {
			
			m_message = new char[strlen(errorMessage) + 1];
			
			strcpy(m_message, errorMessage);
		}
	}
	
	ErrorState::~ErrorState() {
		
		delete[] m_message;
	
	}
	
	void ErrorState::clear() {
		
		delete[] m_message;
		
		m_message = nullptr;
	}
	
	bool ErrorState::isClear() const {
		
		return (m_message == nullptr) ? true : false;
	
	}
	
	void ErrorState::message(const char* str) {
		
		delete[] m_message;
		
		m_message = new char[strlen(str) + 1];
		
		strcpy(m_message, str);
	}
	
	const char* ErrorState::message() const {
		
		return m_message;
	
	}
	std::ostream& operator<<(std::ostream& ostr, const ErrorState& obj) {
		
		if (!obj.isClear()) {
		
			ostr << obj.message();
		}
		return ostr;
	}
}