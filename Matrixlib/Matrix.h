#pragma once
#include"Vector.h"
#include <iostream>
using namespace std;

template <class ValType>
class TMatrix : public TVector <TVector<ValType> >
{
public:
	TMatrix();
	TMatrix(int Size);
	TMatrix(const TMatrix<ValType>& mt);
	virtual ~TMatrix();
	TMatrix<ValType>& operator==(const TMatrix<ValType>& mt);
	TMatrix<ValType>& operator=(const TMatrix<ValType>& mt);
	TMatrix<ValType> operator+(const TMatrix<ValType>& mt);
	TMatrix<ValType> operator-(const TMatrix<ValType>& mt);
	TMatrix<ValType> operator*(const TMatrix<ValType>& mt);
	template <class ValType1>
	friend ostream& operator<< (ostream& out, const TMatrix<ValType1>& mt);
	template <class ValType1>
	friend istream& operator>> (istream& in, TMatrix<ValType1>& mt);
};

template <class ValType>
TMatrix<ValType>::TMatrix() {
	pVector = new TVector<ValType>[1];
	pVector[i].Resize(1);
	size = 1;
}

template <class ValType>
TMatrix<ValType>::TMatrix(int Size) {
	if (Size > 0) {
		pVector = new TVector<ValType>[Size];
		for (int i = 0; i < Size; i++)
			pVector[i].Resize(i + 1);
		size = Size;
	}
	else throw logic_error("Input error: invalide value of Matrix length in constructor");
}


template<class ValType>
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) {
	size = mt.size;
	pVector = new TVector<ValType>[size];
	for (int i = 0; i < size; i++)
		pVector[i].Resize(i + 1);
	for (int i = 0; i < size; i++)
		pVector[i] = mt.pVector[i];
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
	if (this->GetSize() != mt.GetSize())
		return 0;
	for (int i = 0; i < mt.GetSize(); i++)
		for (int j = 0; j < mt.GetSize(); j++) {
			if (i >= j)
				if ((*this).pVector[i][j] != mt.pVector[i][j])
					return 0;
		}
	return 1;
}


template<class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt) {
	if (this == &mt)
		return *this;
	else throw logic_error("Input error: invalide value of Matrix length in comparison");
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt) {
	if (this->GetSize() == mt.GetSize()) {
		TMatrix<ValType> tmp(*this);
		for (int i = 0; i < tmp.GetSize(); i++)
			for (int j = 0; j < tmp.GetSize(); j++)
				tmp.pVector[i][j] = (*this).pVector[i][j] + mt.pVector[i][j];
		return tmp;
	}
	else throw logic_error("Input error: invalide value of Matrix length in sum");
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt) {
	if (this->GetSize() == mt.GitSize()) {
		TMatrix<ValType> tmp(*this);
		for (int i = 0; i < tmp.GetSize(); i++)
			tmp.pVector[i] = (*this).pVector[i] - mt.pVector[i];
		return tmp;
	}
	else throw logic_error("Input error: invalide value of Matrix length in subtraction");
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix<ValType>& mt) {
	if (this->GetSize() == mt.GetSize()) {
		TMatrix<ValType> tmp(mt.GetSize());
		for (int i = 0; i < tmp.GetSize(); i++)
			for (int j = 0; j < tmp.GetSize(); j++) {
				if (i >= j) {
					tmp[i][j] = 0;
					for (int k = j; k < i + 1; k++)
						tmp.pVector[i][j] = tmp.pVector[i][j] + ((*this).pVector[i][k] * mt.pVector[k][j]);
				}
			}
		return tmp;
	}
	else throw logic_error("Input error: invalide value of Matrix length in multiplication");
}

template<class ValType1>
ostream& operator<< (ostream& out, const TMatrix<ValType1>& mt) {
	for (int i = 0; i < mt.GetSize(); i++)
		out << mt.pVector[i] << endl;
	return out;
}

template<class ValType1>
istream& operator>> (istream& in, TMatrix<ValType1>& mt) {
	for (int i = 0; i < mt.GetSize(); i++)
		in >> mt.pVector[i];
	return in;
}