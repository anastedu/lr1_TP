#pragma once
//1
#include "Library.h"
using namespace std;

class Hero : public Character
{
private:
	string name;
	string level;
	string weapon;
	string health;
	string armor;

public:
	Hero();
	~Hero();
	Hero(const Hero& Hero_copy);
	Hero(string name);

	string get_name() const;
	void set_name(string name_ch);
	string get_level() const;
	void set_level(string level_ch);
	string get_weapon() const;
	void set_weapon(string weapon_ch);
	string get_health() const;
	void set_health(string health_ch);
	string get_armor() const;
	void set_armor(string armor_ch);

	virtual void show(); //будет переопределен для каждого наследника
	virtual void rewrite(); //перезапись данных (удаление + вставка)
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
};