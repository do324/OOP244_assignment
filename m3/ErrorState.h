#ifndef AMA_ERROR_STATE_H
#define AMA_ERROR_STATE_H
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

namespace AMA {
	class ErrorState {
		char* m_message_adress;
	public:
		explicit ErrorState(const char* err_message = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	}
	;
	std::ostream& operator << (std::ostream& os, const ErrorState& em);
}
#endif
