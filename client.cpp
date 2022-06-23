#include <iostream>
#include <fstream>
#include "function.h"

using namespace std;
using namespace d;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	cout << "Start" << endl;
	LinkedList list;
	Init(list);
	LLInput(list, ifst);
	ofst << "Filled container." << endl;
	LLOutput(list, ofst);

	MultiMethod(list, ofst);
	ofst << endl;

	Clear(list);
	ofst << "Empty container." << endl;
	LLOutput(list, ofst);
	cout << "Stop" << endl;
	return 0;
}