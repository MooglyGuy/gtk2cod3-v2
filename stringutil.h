#pragma once

#include <string>
#include <stdarg.h>

class string_util {
private:
	static const size_t BUF_SIZE = 32768;
public:
	static std::string format(const char *message, ...) {
		va_list v;
		char buf[BUF_SIZE];
		va_start(v, message);
#ifdef _MSC_VER
		vsprintf_s(buf, BUF_SIZE, message, v);
#else
		vsprintf(buf, message, v);
#endif
		va_end(v);
		return std::string(buf);
	}
};