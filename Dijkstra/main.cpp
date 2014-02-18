#include "heap.hpp"
#include "graph.hpp"

void inputGraph(Graph& gr)
{
	int from, to, n, weigth;
	cout << "Vavedete broi varhove:" << endl;
	cin >> n;
	gr.addNodes(n);
	cout << "Vavedete broi rebra:" << endl;
	cin >> n;
	while (n > 0)
	{
		cout << "Ot:" << endl;
		cin >> from;
		cout << "kam:" << endl;
		cin >> to;
		cout << "Teglo:" << endl;
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

	return 0;
}