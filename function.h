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
		char *pair;
		char encrypt[50];
		string name;
		char text[50];
	};
	zamena* ZamenaInput(zamena& obj, ifstream& ifst);
	void ZamenaOutput(zamena* obj, ofstream& ofst);
	int characters(zamena* obj);
	struct sdvig {
		enum class sh {
			ZAMENA,
			SDVIG,
			NUMBER,
		};
		sh k;
		int n;
		char encrypt[50];
		string name;
		char text[50];
	};
	sdvig* SdvigInput(sdvig& obj, ifstream& ifst);
	void SdvigOutput(sdvig* obj, ofstream& ofst);
	int characters(sdvig* obj);
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
  int characters(number* obj);
	struct shifr {
		enum class sh {
			ZAMENA,
			SDVIG,
			NUMBER,
		};
		sh k;
		char text[50];
		string name;
		void* o;
	};
	shifr* ShifrInput(ifstream& ifst);
	void ShifrOutput(shifr& obj, ofstream& ofst);
	int characters(shifr* obj);
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
}
#endif