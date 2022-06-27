#pragma once
#ifndef function_h
#define function_h
using namespace std;

namespace d {
	struct zamena {
		enum class sh {
			ZAMENA,
			SDVIG,
			NUMBER,
		};
		sh k;
		char* pair;
		string encrypt;
		string name;
		string text;
	};
	zamena* ZamenaInput(zamena& obj, ifstream& ifst);
	void ZamenaOutput(zamena* obj, ofstream& ofst);
	int Characters(zamena* obj);
	struct sdvig {
		enum class sh {
			ZAMENA,
			SDVIG,
			NUMBER,
		};
		sh k;
		int n;
		string encrypt;
		string name;
		string text;
	};
	sdvig* SdvigInput(sdvig& obj, ifstream& ifst);
	void SdvigOutput(sdvig* obj, ofstream& ofst);
	int Characters(sdvig* obj);
	struct number {
		enum class sh {
			ZAMENA,
			SDVIG,
			NUMBER,
		};
		sh k;
		string text;
		string name;
		int encrypt;
		char* pair;
	};
	number* NumberInput(number& obj, ifstream& ifst);
	void NumberOutput(number* obj, ofstream& ofst);
	int Characters(number* obj);
	struct shifr {
		enum class sh {
			ZAMENA,
			SDVIG,
			NUMBER,
		};
		sh k;
		string text;
		string name;
		void* o;
	};
	shifr* ShifrInput(ifstream& ifst);
	void ShifrOutput(shifr& obj, ofstream& ofst);
	int Characters(shifr* obj);
	void OnlyZamena(shifr& s, ofstream& ofst);
	struct Node {
		shifr* s;
		Node* perv;
		Node* next;
	};
	struct LinkedList {
		Node* last;
		Node* first;
		size_t sizelist;
	};
	void Init(LinkedList& obj);
	void Clear(LinkedList& obj);

	void LLInput(LinkedList& obj, ifstream& ifst);
	void LLOutput(LinkedList& obj, ofstream& ofst);

	void MultiMethod(LinkedList& obj, ofstream& ofst);

	void Sort(LinkedList& obj);
	bool Compare(shifr* first, shifr* second);
	void Swap(Node* first, Node* second);
}
#endif
