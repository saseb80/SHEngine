//#include "String.h"
//#include <codecvt>
//#include <io.h>
//#include <fcntl.h>
//#include <comdef.h>
//
//bool String::operator==(String& compare) {
//	try {
//		if (wString == compare.GetWString())
//			return true;
//		throw(false);
//	}
//	catch (bool b) {
//	}
//}
//
//void String::operator=(String add) {
//	wString = add.GetWString();
//}
//
//void String::operator=(const string& add) {
//	wString = convert(add);
//}
//
//void String::operator=(const std::wstring& add) {
//	wString = add;
//}
//
//void String::operator=(const char* add) {
//	wString = convert(string(add));
//}
//
//void String::operator+=(const string& s) {
//	wString += convert(s);
//}
//
//String String::operator+(const string& s) {
//	return String(wString += convert(s));
//}
//
//String String::operator+(String& s) {
//	return String(wString += s.GetWString());
//}
//
//
//String String::operator+(const wstring& s) {
//	return String(wString += s);
//}
//
//String String::operator+(const char* s) {
//	return String(wString += convert(string(s)));
//}
//
//
//std::wstring String::convert(const string& toConvert) {
//	try {
//		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//		return converter.from_bytes(toConvert);
//	}
//	catch (std::range_error & e) {
//		size_t length = toConvert.length();
//		std::wstring result;
//		result.reserve(length);
//		for (size_t i = 0; i < length; i++) {
//			result.push_back(toConvert[i] & 0xFF);
//		}
//		return result;
//	}
//}
//
//
//String::String() {
//	_setmode(_fileno(stdout), _O_U8TEXT);
//	wString = L"";
//}
//
//String::String(string str) {
//	_setmode(_fileno(stdout), _O_U8TEXT);
//	wString = convert(str);
//}
//
//String::String(std::wstring& wstr) {
//	_setmode(_fileno(stdout), _O_U8TEXT);
//	wString = wstr;
//}
//
//String::String(const char* c) {
//	_setmode(_fileno(stdout), _O_U8TEXT);
//	wString = convert(c);
//}
//String::~String() {
//}
//
//std::wstring String::GetWString() {
//	return wString;
//}
//
//void String::setWString(const wstring& string) {
//	wString = string;
//}
