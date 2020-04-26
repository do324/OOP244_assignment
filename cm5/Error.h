// milestone5
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <error.h>
#ifndef aid_ERROR_H
#define aid_ERROR_H

#include <iostream>

namespace aid
{
	class Error
	{
		char* m_message;
	public:
		explicit Error(const char* errorMessage = nullptr);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
		virtual ~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};

	std::ostream& operator<<(std::ostream& os, const Error& em);
}
#endif 
