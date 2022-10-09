#pragma once
//2
#include "Library.h"
using namespace std;

class Villain : public Character
{
private:
	string name;
	string level;
	string weapon;
	string guilt;
	string place;
	string health;
	string armor;

public:
	Villain();
	~Villain();
	Villain(const Villain& Villain_copy);
	Villain(string name);

	string get_name() const;
	void set_name(string name_ch);
	string get_level() const;
	void set_level(string level_ch);
	string get_weapon() const;
	void set_weapon(string weapon_ch);
	string get_guilt() const;
	void set_guilt(string guilt_ch);
	string get_place() const;
	void set_place(string place_ch);
	string get_health() const;
	void set_health(string health_ch);
	string get_armor() const;
	void set_armor(string armor_ch);

	virtual void show(); //будет переопределен для каждого наследника
	virtual void rewrite(); //перезапись данных (удаление + вставка)
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
};