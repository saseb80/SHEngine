#include "Bitacora.h"

Bitacora::Bitacora() {
	myfile.open("Consola.txt");
}
//79 fondo rojo texto blanco
void Bitacora::PruebaColor() {
	for (int i = 0; i < 256;i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		std::cout << "Text Color in use:  " << i<<std::endl;
	}
}

void Bitacora::Info(std::string procedencia, std::string mnsj) {
	time_t now = time(NULL);
	struct tm nowLocal;
	nowLocal = *localtime(&now);
	nowLocal = *localtime(&now);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Info" << "      " << procedencia << "     " << mnsj << std::endl;
	myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Info" << "      " << procedencia << "     " << mnsj << std::endl;

}

void Bitacora::Debug(std::string procedencia, std::string mnsj) {
	time_t now = time(NULL);
	struct tm nowLocal;
	nowLocal = *localtime(&now);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "     " << procedencia << "     " << mnsj << std::endl;
	myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "     " << procedencia << "     " << mnsj << std::endl;
}

void Bitacora::Warning(std::string procedencia, std::string mnsj) {
	time_t now = time(NULL);
	struct tm nowLocal;
	nowLocal = *localtime(&now);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Warning" << "   " << procedencia << "     " << mnsj << std::endl;
	myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Warning" << "   " << procedencia << "     " << mnsj << std::endl;
}

void Bitacora::Error(std::string procedencia, std::string mnsj) {
	time_t now = time(NULL);
	struct tm nowLocal;
	nowLocal = *localtime(&now);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Error" << "     " << procedencia << "     " << mnsj << std::endl;
	myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Error" << "     " << procedencia << "     " << mnsj << std::endl;

}

Bitacora::~Bitacora() {
}
