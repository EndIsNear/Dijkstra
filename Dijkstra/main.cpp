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
}

void inputGraph(Graph& gr)
{
	int from, to, n, weigth;
	cout << "Vavedete broi varhove:";
	cin >> n;
	gr.addNodes(n);
	cout << "Vavedete broi rebra:";
	cin >> n;
	while (n > 0)
	{
		cout << "Ot:";
		cin >> from;
		cout << "kam:";
		cin >> to;
		cout << "Teglo:" ;
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
	cout << "Startova poziciq:" << endl;
	cin >> n;

	dijkstra(gr, n);

	return 0;
}