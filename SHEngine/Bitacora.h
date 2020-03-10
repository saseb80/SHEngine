#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>

enum LogType
{
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
	Bitacora();
	void PruebaColor();
template <typename var>
	void ImprimirConsola(var v);
	void Mensaje(LogType tipo, std::string procedencia, std::string mnsj);
	~Bitacora();
};

template<typename var>
inline void Bitacora::ImprimirConsola(var v) {
	std::cout << v <<std::endl;
	myfile << v << std::endl;
}
