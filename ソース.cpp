#include <stdio.h>
#include <stdint.h>

#include "Vector.h"

struct Binary {
	//type T = NULL;
	typedef uint8_t T;
	Vector<uint8_t> Data;
};

template<class T>
Binary ConstructBinary<T>() {
	Binary B;
	B.Data = ConstructVector<uint8_t>(16);
	//B.T = T;

	return B;
}
template<class T>
T* ReadOne(Binary& In,size_t P) {
	//return Index(In.Data, P * sizeof(B.T));
	return Index(In.Data, P * sizeof(T));
}
template<class T>
bool WriteOne(Binary& In, T& B) {
	for (size_t i = 0; i < sizeof(T); i++) {
		Push(In.Data, ((uint8_t)(&B))[i]);
	}
	return 0;
}
template<class T>
Vector<T> Read(Binary& In, size_t S, size_t L) {//return value is need Free();
	Vector<T> R;
	for (size_t i = S * sizeof(T); i < Size(In.Data) / sizeof(T); i += sizeof(T)) {
		if (Index(In.Data, i) == NULL) { break; }
		Push(R, *((T*)Index(In.Data, i)));
	}

	return R;
}
template<class T>
bool Write(Binary& In,Vector<T>& B,size_t S,size_t L){
	for (size_t i = S; i < Size(B); i++) {
		for (size_t j = 0; j < sizeof(T); j++) {
			Push(In.Data, ((uint8_t)(&B[i]))[j]);
		}
	}
	return true;
}
template<class T>
bool Write(Binary& In, T* B, size_t N, size_t Start, size_t Len) {
	for (size_t i = Start; i <L; i++) {
		for (size_t j = 0; j < sizeof(T); j++) {
			Push(In.Data, ((uint8_t)(&B[i]))[j]);
		}
	}
	return true;
}
template<class T>
T* Index(Binary& In, size_t P) {
	return Index(In.Data, P * sizeof(T));
}
size_t RawSize(Binary& In) {
	return Size(In.Data);
}
template<class T>
size_t Size(Binary& In) {
	return Size(In.Data)/sizeof(T);
//	return Size(In.Data)/sizeof(In.T);
}