#pragma once
//3
#include "Library.h"
using namespace std;

class Monster : public Character
{
private:
	string name;
	string level;
	string description;

public:
	Monster();
	~Monster();
	Monster(const Monster& Monster_copy);
	Monster(string name);

	string get_name() const;
	void set_name(string name_ch);
	string get_level() const;
	void set_level(string level_ch);
	string get_description() const;
	void set_description(string description_ch);

	virtual void show(); //будет переопределен для каждого наследника
	virtual void rewrite(); //перезапись данных (удаление + вставка)
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
};