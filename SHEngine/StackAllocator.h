#ifndef  StackAllocator_H
#define  StackAllocator_H


#include <cstdlib>
#include <iostream>
#include "Bitacora.h"

class StackAllocator
{
public:
	typedef size_t Marker;
	StackAllocator(size_t size);
	void* alloc(size_t size);
	Marker getMarker();
	void freeToMarker(Marker marker);
	Bitacora log;
	void clear();

private:
	int maxSize;
	void* start;
	Marker marker;
	Marker prev;
};

#endif // ! StackAllocator_H