#include "Logging.h"

Logging::Logging() {

}
//79 fondo rojo texto blanco
void Logging::PruebaColor() {
	for (int i = 0; i < 256;i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		std::cout << "Text Color in use:  " << i<<std::endl;

	}
}

void Logging::Mensaje(std::string tipo, std::string procedencia, std::string mensaje) {
	if (tipo == "Info") {
		nowLocal = *localtime(&now);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " "<<tipo <<"      "<< procedencia <<"     "<<mensaje <<std::endl;
	}
	if (tipo == "Debug") {
		nowLocal = *localtime(&now);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << tipo << "     " << procedencia << "     " << mensaje << std::endl;
	}
	if (tipo == "Warning") {
		nowLocal = *localtime(&now);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << tipo << "   " << procedencia << "     " << mensaje << std::endl;
	}
	if (tipo == "Error") {
		nowLocal = *localtime(&now);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << tipo << "     " << procedencia << "     " << mensaje << std::endl;
	}
}

Logging::~Logging() {
}
