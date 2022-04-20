#pragma once
#ifndef function_h
#define function_h
using namespace std;

namespace d {
	struct zamena {
		enum class sh {
			ZAMENA,
			SDVIG,
		};
		sh k;
		char *pair;
		char encrypt[50];
		char text[50];
	};
	zamena* ZamenaInput(zamena& obj, ifstream& ifst);
	void ZamenaOutput(zamena* obj, ofstream& ofst);
	struct sdvig {
		enum class sh {
			ZAMENA,
			SDVIG,
		};
		sh k;
		int n;
		char encrypt[50];
		char text[50];
	};
	sdvig* SdvigInput(sdvig& obj, ifstream& ifst);
	void SdvigOutput(sdvig* obj, ofstream& ofst);
	struct shifr {
		enum class sh {
			ZAMENA,
			SDVIG,
		};
		sh k;
		char text[50];
		void* o;
	};
	shifr* ShifrInput(ifstream& ifst);
	void ShifrOutput(shifr& obj, ofstream& ofst);
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