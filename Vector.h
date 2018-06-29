#pragma once

template <typename T>
class Vector
{
private:
	T *vc;
	int nCapacity;
	int nSize;

public:
	Vector(int size = 1)
		: nCapacity(size), nSize(0)
	{
		vc = new T[size];
	}
	~Vector()
	{
		SAFE_DELETE_ARRAY(vc);
	}

	int size()
	{ 
		return nSize;
	}

	bool empty()
	{
		return !nSize;
	}

	void resize(int size)
	{
		nCapacity = size;

		T *tVc = new T[size];
		for (int i = 0; i < nSize; ++i)
			tVc[i] = vc[i];
		SAFE_DELETE_ARRAY(vc);

		vc = tVc;
	}
	void clear()
	{
		SAFE_DELETE_ARRAY(vc);
		nCapacity = 1;
		nSize = 0;

		vc = new T[1];
	}
	void push_back(T value)
	{
		if (nSize == nCapacity)
		{
			nCapacity *= 2;
			resize(nCapacity);
		}

		vc[nSize++] = value;
	}
	void pop_back()
	{
		if (nSize == 0)
			return;

		vc[--nSize] = 0;
	}
	void reverse()
	{
		for (int i = 0; i < nSize * 0.5; ++i)
		{
			T temp = vc[i];
			vc[i] = vc[(nSize - 1) - i];
			vc[(nSize - 1) - i] = temp;
		}
	}
	void operator=(const Vector<T> &tVc)
	{
		nCapacity = tVc.nCapacity;
		nSize = tVc.nCapacity;
		SAFE_DELETE_ARRAY(vc);
		vc = new T[nCapacity];
		for (int i = 0; i < nSize; ++i)
			vc[i] = tVc[i];
	}

	T &operator[](const int &i) const
	{
		return vc[i];
	}
};

