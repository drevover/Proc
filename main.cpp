#include <iostream>
#include <fstream>
#include "function.h"
#include <string>
#define WRONG_SHIFR 0

d::zamena* d::ZamenaInput(zamena& obj, ifstream& ifst) {
	obj.pair = new char[100];
	ifst >> obj.text >> obj.encrypt >> obj.pair >> obj.name;
	return &obj;
}
void d::ZamenaOutput(zamena* obj, ofstream& ofst){
	ofst << "It is Cipher of replace: Open text is " << obj->text << ", encrypted text is " << obj->encrypt << ", massive of pair " << obj->pair << ", name of own - " << obj->name << endl;
}
d::sdvig* d::SdvigInput(sdvig& obj, ifstream& ifst) {
	ifst >> obj.text >> obj.encrypt >> obj.n >> obj.name;
	return &obj;
}
void d::SdvigOutput(sdvig* obj, ofstream& ofst) {
	ofst << "It is Cipher of shift: Open text is " << obj->text << ", encrypted text is " << obj->encrypt << ", sdvig on " << obj->n << ", name of own - " << obj->name << endl;
}
d::number* d::NumberInput(number& obj, ifstream& ifst) {
	obj.pair = new char[50];
	ifst >> obj.text >> obj.encrypt >> obj.pair >> obj.name;
	return &obj;
}
void d::NumberOutput(number* obj, ofstream& ofst) {
	ofst << "It is Cipher of change-to-number: Open text is " << obj->text << ", encrypted text is " << obj->encrypt << ", massive of change " << obj->pair << ", name of own - " << obj->name << endl;
}
int d::Characters(zamena* obj) {
	return size(obj->text);
}
int d::Characters(sdvig* obj) {
	return size(obj->text);
}
int d::Characters(number* obj) {
	return size(obj->text);
}
d::shifr* d::ShifrInput(ifstream& ifst) {
	shifr* sr = new shifr;
	zamena* z;
	sdvig* sd;
	number* n;
	string tmp;
	int key;
	ifst >> tmp;
	if (tmp == "\0")
		return 0;
	if (!isdigit(int(tmp.front())) || tmp.length() > 1)
		key = WRONG_SHIFR;
	else
		key = stoi(tmp);
	switch (key) {
		case 1:
			z = new zamena;
			sr->k = shifr::sh::ZAMENA;
			sr->o = (void*)ZamenaInput(*z, ifst);
			return sr;
		case 2:
			sd = new sdvig;
			sr->k = shifr::sh::SDVIG;
			sr->o = (void*)SdvigInput(*sd, ifst);
			return sr;
		case 3:
			n = new number;
			sr->k = shifr::sh::NUMBER;
			sr->o = (void*)NumberInput(*n, ifst);
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
	case shifr::sh::NUMBER:
		NumberOutput((number*)obj.o, ofst);
		break;
	default:
		ofst << "Incorrect type of cypher" << endl;
	}
}
int d::Characters(shifr* obj) {
	switch (obj->k)
	{
	case shifr::sh::ZAMENA:
		return Characters((zamena*)obj->o);
	case shifr::sh::SDVIG:
		return Characters((sdvig*)obj->o);
	case shifr::sh::NUMBER:
		return Characters((number*)obj->o);
	default:
		break;
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
		ofst << "Characters on text = " << Characters(Temp->s) << endl;
		Temp = Temp->next;
	}
	ofst << endl;
	for (int i = 0; i < obj.sizelist; i++)
	{
		OnlyZamena(*(Temp->s), ofst);
		Temp = Temp->next;
	}
	ofst << endl;
}
bool d::Compare(shifr* first, shifr* second) 
{
	return Characters(first) > Characters(second);
}
void d::Sort(LinkedList& obj) {
	if (obj.sizelist < 2) {
		return;
	}
	Node* current = obj.first;
	bool flag = false;
	do
	{
		current = obj.first;
		flag = false;
		for (int i = 0; i < (obj.sizelist - 1); ++i)
		{
			if (Compare(current->s, current->next->s))
			{
				swap(current, current->next);
				flag = true;
			}
			else
			{
				current = current->next;
			}
		}
	} while (flag);
}
void d::Swap(Node* first, Node* second) {
	shifr* tmp;
	tmp = first->s;
	first->s = second->s;
	second->s = tmp;
	return;
}
void d::OnlyZamena(shifr& s, ofstream& ofst) {
	switch (s.k) {
	case shifr::sh::ZAMENA:
		ZamenaOutput((zamena*)s.o, ofst);
		break;
	default:
		return;
	}
}