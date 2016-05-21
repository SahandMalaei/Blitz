#include "Blitz_Debug__.h"
/* ------------------------------------------------------------------------------------ */
#include <list>
#include <fstream>
#include <time.h>
/* ------------------------------------------------------------------------------------ */
namespace
{
	std::string logFileAddress;
	std::list<std::string> messageList;
}
namespace blitz
{
	namespace __debug
	{
		const std::string &getLogFileAddress()
		{
			return logFileAddress;
		}
		void setLogFileAddress(const std::string &address)
		{
			logFileAddress = address;
		}
		void throwMessage(const std::string &message)
		{
			std::string outputMessage = "	Message : " + message;
			messageList.push_back(outputMessage);
		}
		void throwError(const std::string &message)
		{
			std::string errorMessage = "	Error : " + message;
			messageList.push_back(errorMessage);
			flushLog();
			exit(1);
		}
		void clearLogFile()
		{
			std::fstream file;
			file.open(logFileAddress, std::ios::out);
			if (file.bad())
			{
				return;
			}
			file.close();
		}
		void flushLog()
		{
			std::fstream file;
			file.open(logFileAddress, std::ios::out | std::ios::app | std::ios::ate);
			if (file.bad())
			{
				return;
			}
			if (int(file.tellg()) != 0)
			{
				file.write("\n\n", 2);
			}
			time_t currentTimeMilliseconds = time(0);
			tm currentTime;
			localtime_s(&currentTime, &currentTimeMilliseconds);
			char timeStringBuffer[128];
			asctime_s(timeStringBuffer, &currentTime);
			std::string timeString = "Time : " + std::string(timeStringBuffer);
			file.write(timeString.c_str(), timeString.length() - 1);
			for (auto listIterator = messageList.begin(); listIterator != messageList.end(); ++listIterator)
			{
				file.write("\n", 1);
				file.write(listIterator->c_str(), listIterator->length());
			}
			file.close();
		}
	}
}