#include <iostream>
#include <math.h>
#ifndef _MY_VECTOR_
#define _MY_VECTOR_
const int MAX_VECTOR_SIZE = 10;
using namespace std;

template <class ValType>
class TVector {
protected:
	ValType* pVector;
	int size;
	int StartIndex;
public:
	TVector(int s=1, int si=0);
	TVector(const TVector<ValType>& v);
	~TVector();

	int GetSize() {
		return size;
	}
	int GetStartIndex() {
		return StartIndex;
	}

	ValType& operator[](int pos);
	int operator==(const TVector<ValType>& v);
	TVector<ValType>& operator=(const TVector<ValType>& v);
	TVector<ValType> operator+(const TVector<ValType>& v);
	TVector<ValType> operator-(const TVector<ValType>& v);
	TVector<ValType> operator*(const TVector<ValType>& v);

	template <class ValType1>
	friend istream& operator>>(istream& in, TVector<ValType1>& v);
	template <class ValType1>
	friend ostream& operator<<(ostream& out, const TVector<ValType1>& v);
};


template<class ValType>
TVector<ValType>::TVector(int s, int si) {
	if (s >= 0 && si >= 0 && s <= MAX_VECTOR_SIZE && si <= MAX_VECTOR_SIZE - 1) {
		pVector = new ValType[s];
		for (int i = 0; i < s; i++)
			pVector[i] = 0;
		size = s;
		StartIndex = si;
	}
	else throw logic_error("Input error: invalide value of Vector length in constructor");
}

template <class ValType>
TVector<ValType>::TVector(const TVector<ValType>& v) {
	size = v.size;
	StartIndex = v.StartIndex;
	pVector = new ValType[size - StartIndex];
	for (int i = 0; i < size - StartIndex; i++)
		pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>::~TVector() {
	size = 0;
	if (pVector != 0) {
		delete[] pVector;
		pVector = nullptr;
	}
}

template <class ValType>
ValType& TVector<ValType>::operator[] (int pos) {
	if (pos >= 0 && pos <= size && pos >= StartIndex )
		return pVector[pos - StartIndex];
	else throw logic_error("Input error: invalide value of Vector length in indexing");
	
}

template<class ValType>
int TVector<ValType>::operator==(const TVector<ValType>& v) {
	if (size == v.size && StartIndex == v.StartIndex) {
		for (int i = 0; i < size - StartIndex; i++) {
			if (this->pVector[i] != v.pVector[i])
				return 0;
		}
		return 1;
	}
	return 0;
}

template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector<ValType>& v) {
	if (this != &v) {
		if (size != v.size) {
			delete[] pVector;
			size = v.size;
			pVector = new ValType[size - StartIndex];
		}
		StartIndex = v.StartIndex;
		for (int i = 0; i < size - StartIndex; i++)
			pVector[i] = v.pVector[i];
	}
	return *this;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v) {
	if (size == v.size) {
		TVector<ValType> tmp;
		tmp.size = size;
		tmp.StartIndex = StartIndex;
		tmp.pVector = new ValType[size - StartIndex];
		for (int i = 0; i < size - StartIndex; i++)
			tmp.pVector[i] = pVector[i] + v.pVector[i];
		return tmp;
	}
	else throw logic_error("Input error: invalide value of Vector length in sum");
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v) {
	if (size == v.size) {
		TVector<ValType> tmp;
		tmp.size = size;
		tmp.StartIndex = StartIndex;
		tmp.pVector = new ValType[size - StartIndex];
		for (int i = 0; i < size - StartIndex; i++)
			tmp.pVector[i] = pVector[i] - v.pVector[i];
		return tmp;
	}
	else throw logic_error("Input error: invalide value of Vector length in subtraction");
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator*(const TVector<ValType>& v) {
	if (size == v.size) {
		TVector<ValType> tmp;
		tmp.size = size;
		tmp.StartIndex = StartIndex;
		tmp.pVector = new ValType[size - StartIndex];
		for (int i = 0; i < size- StartIndex; i++)
			tmp.pVector[i] = pVector[i] * v.pVector[i];
		return tmp;
	}
	else throw logic_error("Input error: invalide value of Vector length in multiplication");
}

template <class ValType1>
istream& operator>> (istream& in, TVector<ValType1>& v) {
	for (int i = 0; i < v.size - v.StartIndex; i++) 
		in >> v.pVector[i];
	return in;
}

template <class ValType1>
ostream& operator<< (ostream& out, const TVector<ValType1>& v) {
	for (int i = 0; i < v.size - v.StartIndex; i++) 
		out << v.pVector[i] << endl;
	return out;
}



#endif