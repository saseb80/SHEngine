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

void Bitacora::Mensaje(LogType tipo, std::string procedencia, std::string mensaje) {
	if (tipo == 0) {
		nowLocal = *localtime(&now);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " "<<"Info" <<"      "<< procedencia <<"     "<<mensaje <<std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " "<< "Info" <<"      "<< procedencia <<"     "<<mensaje <<std::endl;
	}
	if (tipo == 1) {
		nowLocal = *localtime(&now);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "     " << procedencia << "     " << mensaje << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "     " << procedencia << "     " << mensaje << std::endl;
	}
	if (tipo == 2) {
		nowLocal = *localtime(&now);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Warning" << "   " << procedencia << "     " << mensaje << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Warning" << "   " << procedencia << "     " << mensaje << std::endl;
	}
	if (tipo == 3) {
		nowLocal = *localtime(&now);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Error" << "     " << procedencia << "     " << mensaje << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Error" << "     " << procedencia << "     " << mensaje << std::endl;
	}
}

Bitacora::~Bitacora() {
}
