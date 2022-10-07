#pragma once
#include "Library.h"

using namespace std;

class Keeper
{
private:
	int m_size = 0;
	Elem* head = NULL;

public:
	Keeper();
	Keeper(int size);
	~Keeper();

	Character* operator[] (int index);

	int get_size();
	void insert(Character* n_data); //добавление в массив перед индексом
	void remove(int index);
	void save(); //сохранить в файл
	void load(); //чтение из файла
};