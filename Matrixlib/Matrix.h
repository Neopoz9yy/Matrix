#pragma once
#include"Vector.h"
#include <iostream>
using namespace std;
const int MAX_MATRIX_SIZE = 100;
template <class ValType>
class TMatrix : public TVector <TVector<ValType> > {
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix<ValType>& mt);
	virtual ~TMatrix();
	TMatrix<ValType>& operator==(const TMatrix<ValType>& mt);
	TMatrix<ValType>& operator=(const TMatrix<ValType>& mt);
	TMatrix<ValType> operator+(const TMatrix<ValType>& mt);
	TMatrix<ValType> operator-(const TMatrix<ValType>& mt);
	template <class ValType1>
	friend ostream& operator<< (ostream& out, const TMatrix<ValType1>& mt);
	template <class ValType1>
	friend istream& operator>> (istream& in, TMatrix<ValType1>& mt);
}; 

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s) {
	if (s > 0 && s <= MAX_MATRIX_SIZE) {
		for (int i = 0; i < this->size - this->StartIndex; i++)
			TVector<ValType> tmp(s - i, i);
	}
	else throw logic_error("Input error: invalide value of Matrix length in constructor");
}


template<class ValType>
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) : TVector<TVector<ValType> >(mt) {
	for (int i = this->StartIndex; i < this->size; i++) {
		TVector<ValType> tmp(mt.size-i, i);
		this->pVector[i] = tmp;
	}
}


template<class ValType>
TMatrix<ValType>::~TMatrix() {
	if (pVector > 0) {
		delete[] pVector;
		pVector = nullptr;
	}

}

template<class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) {
	if (this == &mt)
		return 1;
	if(this->size == mt.size && this->StartIndex = mt.StartIndex)
	for (int i = mt.StartIndex; i < mt.size; i++) {
		if (this->pVector[i] != mt.pVector[i])
			return 0;
	}
	return 1;
}


template<class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt) {
	if (this != &mt) {
		if (size != mt.size) {
			delete[]pVector;
			this->size = mt.size;
			pVector = new TVector<ValType>[mt.size - mt.StartIndex];
		}
		this->StartIndex = mt.StartIndex;
		for (int i = mt.StartIndex; i < mt.size; i++)
			this->pVector[i] = mt.pVector[i];
	}
	return *this;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt) {
	if (this->size == mt.size && this->StartIndex == mt.StartIndex) {
		TMatrix<ValType> tmp(*this);
		for (int i = tmp.StartIndex; i < tmp.size; i++)
				tmp.pVector[i] = this->pVector[i] + mt.pVector[i];
		return tmp;
	}
	else throw logic_error("Input error: invalide value of Matrix length in sum");
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt) {
	if (this->size == mt.size && this->StartIndex == mt.StartIndex) {
		TMatrix<ValType> tmp(*this);
		for (int i = tmp.StartIndex; i < tmp.size; i++)
			tmp.pVector[i] = this->pVector[i] - mt.pVector[i];
		return tmp;
	}
	else throw logic_error("Input error: invalide value of Matrix length in subtraction");
}


template<class ValType1>
ostream& operator<< (ostream& out, const TMatrix<ValType1>& mt) {
	for (int i = 0; i < mt.size; i++)
		out << mt.pVector[i] << endl;
	return out;
}

template<class ValType1>
istream& operator>> (istream& in, TMatrix<ValType1>& mt) {
	for (int i = 0; i < mt.size; i++)
		in >> mt.pVector[i];
	return in;
}