#include "StackAllocator.h"

StackAllocator::StackAllocator(size_t size) {

	static_assert(sizeof(size_t) >= sizeof(void*), "the size of uint must be greater than or equal to the size of a pointer");
	maxSize = size;
	start = malloc(size);
	if (start == NULL) {
		log.Error("StackAll", "Error al asignar memoria");
	}
	marker = (size_t)start;
	prev = marker;
}

void* StackAllocator::alloc(size_t size) {
	//comprobar si la memoria pedida es igual o menor al tamano que queda en el stack
	if (prev + size <= maxSize) {
		prev = marker;
		marker = marker + size;
		//printf("prev %#x\n", prev);
		//printf("marker %#x\n", marker);
		//printf("return %p\n", (void*)prev);
		//regresar el valor de uint a apuntador
		return (void*)prev;
	}
	else return NULL;
}

StackAllocator::Marker StackAllocator::getMarker() {
	return marker;
}

void StackAllocator::freeToMarker(Marker marker) {
}

void StackAllocator::clear() {
	//mover el marcador al inicio del stack
	marker = (size_t)start;
}