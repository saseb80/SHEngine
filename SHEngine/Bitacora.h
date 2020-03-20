#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include "SimpleIni.h"

enum LogType{
	Info,
	Debug,
	Warning,
	Error,
};

class Bitacora
{
private:
	time_t now = time(NULL);
	struct tm nowLocal;
	std::ofstream myfile;

public:
	int level;
	bool esp;
	Bitacora();
	void PruebaColor();
template <typename var>
	void ImprimirConsola(var v);
	void Info(std::string procedencia, std::string mnsj);
	void Debug(std::string procedencia, std::string mnsj);
template <typename var>
	void DebugVar(std::string procedencia, var v);
template <typename var>
	void DebugVarText(std::string procedencia, std::string mnsj, var v);
	void Warning(std::string procedencia, std::string mnsj);
	void Error(std::string procedencia, std::string mnsj);
	~Bitacora();
};

template<typename var>
inline void Bitacora::ImprimirConsola(var v) {
	std::cout << v <<std::endl;
	myfile << v << std::endl;
}

template<typename var>
inline void Bitacora::DebugVar(std::string procedencia, var v) {
	nowLocal = *localtime(&now);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "      " << procedencia << "     " << v << std::endl;
	myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "      " << procedencia << "     " << v << std::endl;
}

template<typename var>
inline void Bitacora::DebugVarText(std::string procedencia, std::string mnsj ,var v) {
	nowLocal = *localtime(&now);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "      " << procedencia << "     " << mnsj << v << std::endl;
	myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "      " << procedencia << "     " << mnsj << v <<std::endl;
}