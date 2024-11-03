#pragma once
#include <stdio.h>
#include <stdint.h>

#include "Vector.h"

struct Binary {
	//type T = NULL;
	typedef uint8_t T;
	Vector<uint8_t> Data;
};

template<class T> Binary ConstructBinary<T>();
template<class T> T* ReadOne(Binary& In, size_t P);
template<class T> bool WriteOne(Binary& In, T& B);
template<class T> Vector<T> Read(Binary& In, size_t S, size_t L);
template<class T> bool Write(Binary& In, Vector<T>& B, size_t S, size_t L);
template<class T> bool Write(Binary& In, T* B, size_t N, size_t Start, size_t Len);
template<class T> T* Index(Binary& In, size_t P);
size_t RawSize(Binary& In);
template<class T> size_t Size(Binary& In);