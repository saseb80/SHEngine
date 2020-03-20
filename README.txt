Antes de usar en platform poner la coordenada de donde se localiza el cfg.ini
ejemplo: C:\\SHengine\\cfg.ini

Este engine contiene lo siguiente:
-Diagramas UML que explican la arquitectura del Engine y de el Game Object Model
-StackAllocator de terceros para manejar la memoria
-Lectura de INI de terceros que contiene 5 configuraciones:
	Resolucion de pantalla
	Nivel de verbosidad
	Idioma
	Ubicacion de la Consola
	Memoria dedicada al programa
-Bitacora o logging con consola  y comandos de color
	El nivel de verbosidad controla que tan especifico es con cada comando
-Clase String
-GameObjectModel
-Lua como subsistema de scripting
-----------------
Detalles sobre el engine
Dibujo de primitivas: Cuadrado
Consola con archivo Consola.txt donde se guarda la consola
-----------------------
INI
los niveles de verbosidad para el ini son low, mid y high

