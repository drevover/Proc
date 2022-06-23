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
	if (!ifst) {
		cout << "No input file found!" << endl;
		return 0;
	}
	ofstream ofst(argv[2]);
	if (!ofst) {
		cout << "No output file found!" << endl;
		return 0;
	}
	cout << "Start" << endl;
	LinkedList list;
	Init(list);
	LLInput(list, ifst);
	ofst << "Filled container." << endl;
	LLOutput(list, ofst);
	ofst << "Sorted container." << endl;
	Sort(list);
	LLOutput(list, ofst);
	Clear(list);
	ofst << "Empty container." << endl;
	LLOutput(list, ofst);
	cout << "Stop" << endl;
	return 0;
}