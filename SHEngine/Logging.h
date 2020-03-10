#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <Windows.h>
#include <string>
#include <iostream>

class Logging
{
private:
	time_t now = time(NULL);
	struct tm nowLocal;
	int atributo;
	std::string mensaje;
public:
	Logging();
	void PruebaColor();
	void Mensaje(std::string tipo, std::string procedencia, std::string mnsj);
	~Logging();

};

