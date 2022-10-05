#pragma once
//BASE abstract
//Ѕазовый класс ѕерсонаж, в котором ообъ€влено только им€ (это общий элменет дл€ будущих трех наследников)
#include "Library.h"

using namespace std;

class Character
{
public:
	Character() {};
	virtual ~Character() {};

	virtual void show() = 0; //будет переопределен дл€ каждого наследника
	virtual void rewrite() = 0; //перезапись данных (удаление + вставка)
	virtual void saving() = 0; //сохран€ем тот или иной наследник
	virtual void redact_str(int num_str, string red_str) = 0; //отредактировать строку
};

typedef struct Elem
{
	Character* m_data;
	Elem* next;
} Elem;