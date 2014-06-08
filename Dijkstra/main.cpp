#include "heap.hpp"
#include "graph.hpp"
#include <limits.h>

void dijkstra(Graph& gr, int start)
{
	size_t size = gr.GetSize();
	int* dist = new int[size];

	Heap<int> heap;
	heap.Push(start, 0);
	
	for (size_t cnt = 0; cnt < size; ++cnt)
	{
		dist[cnt] = INT_MAX;
	}
	dist[start] = 0;

	while (!heap.IsEmpty())
	{
		int crnWeight = heap.GetTopWeight();
		int crnElem = heap.Pop();
		for (int cnt = 0; cnt < size; ++cnt)
		{
			if (gr.hasEdge(crnElem, cnt))
			{
				if (dist[cnt] > crnWeight + gr.hasEdge(crnElem, cnt))
				{
					dist[cnt] = crnWeight + gr.hasEdge(crnElem, cnt);
					heap.Push(cnt, dist[cnt]);
				}
			}
		}
	}

	//print result
	for (int i = 0; i < size; ++i)
	{
		cout << "From node[" << start << "] to [" << i << "]:" << dist[i] << endl;
	}
	delete[] dist;
}

void inputGraph(Graph& gr)
{
	int from, to, n, weigth;
	cout << "Number of nodes:";
	cin >> n;
	gr.addNodes(n);
	cout << "Number of edges:";
	cin >> n;
	while (n > 0)
	{
		cout << "From:";
		cin >> from;
		cout << "To:";
		cin >> to;
		cout << "Wieght:" ;
		cin >> weigth;

		gr.addEdge(from, to, weigth);
		--n;
	}
}

int main()
{
	Graph gr;
	inputGraph(gr);
	gr.print();

	int n;
	cout << "Start node:" << endl;
	cin >> n;

	dijkstra(gr, n);

	return 0;
}