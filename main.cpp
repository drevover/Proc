#include <iostream>
#include <fstream>
#include "function.h"

d::zamena* d::ZamenaInput(zamena& obj, ifstream& ifst) {
	obj.pair = new char[100];
	ifst >> obj.text >> obj.encrypt >> obj.pair;
	return &obj;
}
void d::ZamenaOutput(zamena* obj, ofstream& ofst) {
	ofst << "It is Cipher of replace: Open text is " << obj->text << ", encrypted text is " << obj->encrypt << ", massive of pair " << obj->pair <<< endl;
}
d::sdvig* d::SdvigInput(sdvig& obj, ifstream& ifst) {
	ifst >> obj.text >> obj.encrypt >> obj.n;
	return &obj;
}
void d::SdvigOutput(sdvig* obj, ofstream& ofst) {
	ofst << "It is Cipher of shift: Open text is " << obj->text << ", encrypted text is " << obj->encrypt << ", sdvig on " << obj->n << endl;
}
d::shifr* d::ShifrInput(ifstream& ifst) {
	shifr* sr = new shifr;
	zamena* z;
	sdvig* sd;
	int key;
	ifst >> key;
	switch (key) {
		case 1:
			z = new zamena;
			sr->k = shifr::sh::ZAMENA;
			sr->o = (void*)ZamenaInput(*z,ifst);
			return sr;
		case 2:
			sd = new sdvig;
			sr->k = shifr::sh::SDVIG;
			sr->o = (void*)SdvigInput(*sd,ifst);
			return sr;
		default:
			return 0;
	}
}
void d::ShifrOutput(shifr& obj, ofstream &ofst) {
	switch (obj.k) {
	case shifr::sh::ZAMENA:
		ZamenaOutput((zamena*)obj.o, ofst);
		break;
	case shifr::sh::SDVIG:
		SdvigOutput((sdvig*)obj.o, ofst);
		break;
	default:
		ofst << "Incorrect type of cypher" << endl;
		return;
	}
}
void d::Init(LinkedList& obj) {
	obj.first = NULL;
	obj.last = obj.first;
	obj.sizelist = 0;
}
void d::Clear(LinkedList& obj) {
	Node* Temp = NULL;
	while (obj.sizelist > 1)
	{
		Temp = obj.last->perv;
		delete obj.last;
		obj.last = Temp;
		obj.sizelist--;
	}
	if (obj.sizelist == 1)
		delete obj.first;
	obj.sizelist--;
}
void d::LLInput(LinkedList& obj, ifstream& ifst) {
	Node* Temp;

	while (!ifst.eof())
	{
		Temp = new Node;
		Temp->next = NULL;
		Temp->s = ShifrInput(ifst);

		if (Temp->s == NULL)
			break;

		if (obj.first == NULL)
		{
			obj.first = obj.last = Temp;
			Temp->perv = Temp;
			Temp->next = obj.first;
		}
		else
		{
			Temp->perv = obj.last;
			obj.last->next = Temp;
			Temp->next = obj.first;
			obj.last = Temp;
		}
		obj.sizelist++;
	}
}
void d::LLOutput(LinkedList& obj, ofstream& ofst) {
	Node* Temp = obj.first;
	ofst << "Container contains " << obj.sizelist << " elements." << endl;

	for (size_t i = 0; i < obj.sizelist; i++)
	{
		ofst << i + 1 << ": ";
		ShifrOutput(*Temp->s, ofst);
		Temp = Temp->next;
	}
	ofst << endl;
}
void d::MultiMethod(LinkedList& obj, ofstream& ofst) {
	Node* current_first = obj.first;
	Node* current_second = current_first->next;

	ofst << "MultiMethod." << endl;
	for (int i = 0; i < obj.sizelist - 1; i++)
	{
		for (int j = i + 1; j < obj.sizelist; j++)
		{
			switch (current_first->s->k)
			{
			case shifr::sh::ZAMENA:
				switch (current_second->s->k)
				{
				case shifr::sh::ZAMENA:
					ofst << "Zamena and Zamena" << endl;
					break;
				case shifr::sh::SDVIG:
					ofst << "Zamena and Sdvig" << endl;
					break;
				default:
					ofst << "Unknown type" << endl;
					break;
				}
				break;
			case shifr::sh::SDVIG:
				switch (current_second->s->k)
				{
				case shifr::sh::ZAMENA:
					ofst << "Sdvig and Zamena" << endl;
					break;
				case shifr::sh::SDVIG:
					ofst << "Sdvig and Sdvig" << endl;
					break;
				default:
					ofst << "Unknown type" << endl;
					break;
				}
				break;
			default:
				ofst << "Unknown type" << endl;
				break;
			}
			ShifrOutput(*current_first->s, ofst);
			ShifrOutput(*current_second->s, ofst);
			current_second = current_second->next;
		}
		current_first = current_first->next;
		current_second = current_first->next;
	}
}