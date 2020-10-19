#include <iostream>
#include <math.h>
#ifndef _MY_VECTOR_
#define _MY_VECTOR_
#define MIN(a,b)(a>b?b:a)
#define MAX(a,b)(a>b?a:b)
using namespace std;

template <class ValType>
class TVector {
protected:
	ValType* pVector;
	int size;
	int StartIndex;
public:
	TVector();
	TVector(int s);
	TVector(int s, int si);
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
	void Resize(int s);
};

template<class ValType>
TVector<ValType>::TVector() {
	int size = 1;
	pVector = new ValType[1];
}

template<class ValType>
TVector<ValType>::TVector(int s) {
	if (s > 0) {
		size = s;
		StartIndex = 0;
		pVector = new ValType[s];
		for (int i = StartIndex; i < s; i++)
			Resize(i + 1);
		size = s;
	}
	else throw logic_error("Input error: invalide value of Vector length in constructor");
}

template<class ValType>
TVector<ValType>::TVector(int s, int si) {
	if (s > 0 && si > 0) {
		pVector = new ValType[s];
		for (int i = si; i < s; i++)
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
	pVector = new ValType[size];
	for (int i = StartIndex; i < size; i++)
		pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>::~TVector() {
	size = 0;
	if (pVector != 0)
		delete[] pVector;
	pVector = nullptr;
}

template <class ValType>
ValType& TVector<ValType>::operator[] (int pos) {
	if (pos >= 0 && pos < GetStartIndex() + GetSize())
		return pVector[pos];
	else throw logic_error("Input error: invalide value of Vector length in indexing");
}

template<class ValType>
int TVector<ValType>::operator==(const TVector<ValType>& v) {
	if (size == v.size) {
		for (int i = StartIndex; i < size; i++) {
			if ((*this).pVector[i] != v.pVector[i])
				return 0;
		}
		return 1;
	}
	return 0;
}

template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector<ValType>& v) {
	if (this == &v)
		return *this;
	delete[] pVector;
	size = v.size;
	StartIndex = v.StartIndex;
	pVector = new ValType[size];
	for (int i = StartIndex; i < size; i++)
		pVector[i] = v.pVector[i];
	return *this;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v) {
	if (size == v.size) {
		TVector<ValType> tmp;
		tmp.size = size;
		tmp.pVector = new ValType[tmp.size];
		for (int i = tmp.StartIndex; i < tmp.size; i++)
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
		tmp.pVector = new ValType[tmp.size];
		for (int i = tmp.StartIndex; i < tmp.size; i++)
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
		tmp.pVector = new ValType[tmp.size];
		for (int i = tmp.StartIndex; i < tmp.size; i++)
			tmp.pVector[i] = pVector[i] * v.pVector[i];
		return tmp;
	}
	else throw logic_error("Input error: invalide value of Vector length in multiplication");
}

template <class ValType1>
istream& operator>> (istream& in, TVector<ValType1>& v) {
	for (int i = 0; i < v.size; i++) {
		in >> v.pVector[i];
	}
	return in;
}

template <class ValType1>
ostream& operator<< (ostream& out, const TVector<ValType1>& v) {
	for (int i = 0; i < v.size; i++) {
		out << v.pVector[i] << endl;
	}
	return out;
}

template<class ValType>
void TVector<ValType>::Resize(int s)
{
	if (s > 0) {
		TVector<ValType> tmp(*this);
		if (pVector != 0)
			delete[] pVector;
		pVector = 0;
		size = s;
		pVector = new ValType[size];
		for (int i = 1; i < size; i++)
			pVector[i] = tmp.pVector[0];
	}
	else throw logic_error("Input error: invalide value of Vector length in Resize");
}

#endif