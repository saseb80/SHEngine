#include "Bitacora.h"

Bitacora::Bitacora() {
	CSimpleIniA ini;
	ini.LoadFile("C:\\Tareas\\Septimo\\SHEngine\\cfg.ini");
	std::string ruta = ini.GetValue("CONSOLE", "ub", "");
	std::string language = ini.GetValue("LANGUAGE", "language", "");
	std::string verbosity = ini.GetValue("VERBOSITY", "verbosity", "");

	myfile.open(ruta);
	if (verbosity == "low")
	level = 1;
	else if (verbosity == "mid")
	level = 2;
	else if (verbosity == "high")
	level = 3;

	if (language == "eng")
		esp = false;
	else
		esp = true;
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	if (level == 1) {
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min <<"]" << " " << "Info" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << "]" << " " << "Info" << "      " << procedencia << "     " << mnsj << std::endl;
	}
	else if(level == 2){
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Info" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Info" << "      " << procedencia << "     " << mnsj << std::endl;
	}
	else if (level == 3) {
		std::cout << "[" <<nowLocal.tm_mday<<"/"<< nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Info" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_mday <<"/"<<nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Info" << "      " << procedencia << "     " << mnsj << std::endl;
	}

}

void Bitacora::Debug(std::string procedencia, std::string mnsj) {
	time_t now = time(NULL);
	struct tm nowLocal;
	nowLocal = *localtime(&now);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	if (level == 1) {
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << "]" << " " << "Debug" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << "]" << " " << "Debug" << "      " << procedencia << "     " << mnsj << std::endl;
	}
	else if (level == 2) {
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "      " << procedencia << "     " << mnsj << std::endl;
	}
	else if (level == 3) {
		std::cout << "[" << nowLocal.tm_mday << "/" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_mday << "/" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Debug" << "      " << procedencia << "     " << mnsj << std::endl;
	}
	
}

void Bitacora::Warning(std::string procedencia, std::string mnsj) {
	time_t now = time(NULL);
	struct tm nowLocal;
	nowLocal = *localtime(&now);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	if (level == 1) {
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << "]" << " " << "Warning" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << "]" << " " << "Warning" << "      " << procedencia << "     " << mnsj << std::endl;
	}
	else if (level == 2) {
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Warning" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Warning" << "      " << procedencia << "     " << mnsj << std::endl;
	}
	else if (level == 3) {
		std::cout << "[" << nowLocal.tm_mday << "/" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Warning" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_mday << "/" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Warning" << "      " << procedencia << "     " << mnsj << std::endl;
	}
}

void Bitacora::Error(std::string procedencia, std::string mnsj) {
	time_t now = time(NULL);
	struct tm nowLocal;
	nowLocal = *localtime(&now);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	if (level == 1) {
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << "]" << " " << "Error" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << "]" << " " << "Error" << "      " << procedencia << "     " << mnsj << std::endl;
	}
	else if (level == 2) {
		std::cout << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Error" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Error" << "      " << procedencia << "     " << mnsj << std::endl;
	}
	else if (level == 3) {
		std::cout << "[" << nowLocal.tm_mday << "/" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Error" << "      " << procedencia << "     " << mnsj << std::endl;
		myfile << "[" << nowLocal.tm_mday << "/" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << "]" << " " << "Error" << "      " << procedencia << "     " << mnsj << std::endl;
	}
}

Bitacora::~Bitacora() {
}
