#ifndef GRAPH_HPP_ICLUDED
#define GRAPH_HPP_ICLUDED

#include <iostream>
#include <iomanip>

using namespace std;

class Graph
{
	int** adjMatr;
	size_t size;
	size_t maxSize;

	void deleteMatr()
	{
		for (size_t cnt = 0; cnt < this->maxSize; ++cnt)
		{
			delete[] this->adjMatr[cnt];
		}
		delete[] this->adjMatr;
	}

	void resize(size_t newSize)
	{
		int ** newMatr;
		copyMatr(this->adjMatr, &newMatr, this->size, newSize);
	}

	void copyMatr(int** src, int*** dest, size_t size, size_t maxSize)
	{
		*dest = new int*[this->maxSize];
		for (size_t cnt = 0; cnt < this->maxSize; ++cnt)
		{
			*dest[cnt] = new int[this->maxSize];
		}
		for (size_t cnt = 0; cnt < this->maxSize; ++cnt)
			for (size_t cnt2 = 0; cnt2 < this->maxSize; ++cnt2)
			{
				if (cnt < size && cnt2 < size)
					*dest[cnt][cnt2] = src[cnt][cnt2];
				else
					*dest[cnt][cnt2] = 0;
			}
	}

public:
	Graph(size_t maxSize = 20)
	{
		this->size = 0;
		this->maxSize = maxSize;
		this->adjMatr = new int*[this->maxSize];
		for (size_t cnt = 0; cnt < this->maxSize; ++cnt)
		{
			this->adjMatr[cnt] = new int[this->maxSize];
			for (size_t cnt2 = 0; cnt2 < this->maxSize; ++cnt2)
			{
				this->adjMatr[cnt][cnt2] = 0;
			}
		}
	}
	Graph(const Graph& src)
	{
		this->copyMatr(src.adjMatr, &this->adjMatr,src.size, src.maxSize);
	}
	~Graph()
	{
		this->deleteMatr();
	}

	void addNodes(int numOfNodes)
	{
		if (this->size + 1 >= this->maxSize)
		{
			resize(this->maxSize * 2);
		}
		this->size += numOfNodes;
	}

	void addEdge(size_t from, size_t to, int weigth)
	{
		if (from < size && to < size)
			this->adjMatr[from][to] = weigth;
	}

	void removeEdge(size_t from, size_t to)
	{
		if (from < size && to < size)
			this->adjMatr[from][to] = 0;
	}

	int hasEdge(size_t from, size_t to)
	{
		if (from < size && to < size)
			return this->adjMatr[from][to];
		return false;
	}

	void print()
	{
		cout << setw(3)<< "  ";
		for (size_t cnt = 0; cnt < this->size; ++cnt)
		{
			cout << setw(3) << cnt;
		}
		cout << endl;
		cout << endl;
		for (size_t cnt = 0; cnt < this->size; ++cnt)
		{
			cout << setw(2)<< cnt << " ";
			for (size_t cnt2 = 0; cnt2 < this->size; ++cnt2)
			{
				cout << setw(3) << this->adjMatr[cnt][cnt2];
			}
			cout << endl;
		}
	}

	size_t GetSize()
	{
		return this->size;
	}

};

#endif //GRAPH_HPP_ICLUDED