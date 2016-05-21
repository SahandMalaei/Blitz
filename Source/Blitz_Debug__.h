#ifndef BLITZ_DEBUG_H
#define BLITZ_DEBUG_H

#include <string>

namespace blitz
{
	namespace __debug
	{
		const std::string &getLogFileAddress();
		void setLogFileAddress(const std::string &address);
		void throwMessage(const std::string &message);
		void throwError(const std::string &message);
		void clearLogFile();
		void flush();
	}
}

#if ((defined _DEBUG) && (!defined _NDEBUG))
	#define ASSERT(expression) (void)(expression || \
		(debug::throwError("Assertion failed : \"" + std::string(#expression) + \
		"\", file \"" + std::string(__FILE__) + "\", line " + \
		std::to_string(unsigned int(__LINE__))), 0))
#else
	#define BLITZ_ASSERT(expression)
#endif

#define __BLITZ_DEBUG_THROW_ERROR(message) (void)(__debug::throwError( \
	std::string(message) + " (File : \"" + std::string(__FILE__) + "\", line " + \
		std::to_string(unsigned int(__LINE__)) + ")"))
#define __BLITZ_DEBUG_THROW_MESSAGE(message) (void)(__debug::throwMessage( \
	std::string(message) + " (File : \"" + std::string(__FILE__) + "\", line " + \
	std::to_string(unsigned int(__LINE__)) + ")"))

#endif