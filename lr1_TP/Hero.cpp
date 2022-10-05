#include "Library.h"

using namespace std;

Hero::Hero()
{
	cout << "Constructor Hero was called." << endl;
}

Hero::~Hero()
{
	cout << "Destructor Hero was called." << endl;
}

Hero::Hero(const Hero& Hero_copy)
{
	name = Hero_copy.name;
	level = Hero_copy.level;
	weapon = Hero_copy.weapon;
	health = Hero_copy.health;
	armor = Hero_copy.armor;
	cout << "Copy constructor Hero was called." << endl;
}

Hero::Hero(string name)
{
	this->name = name;
	cout << "Constructor Hero was called." << endl;
}

string Hero::get_name() const { return name; };
string Hero::get_level() const { return level; };
string Hero::get_weapon() const { return weapon; }
string Hero::get_health() const { return health; }
string Hero::get_armor() const { return armor; }
void Hero::set_name(string name_ch) { name = name_ch; }
void Hero::set_level(string level_ch) { level = level_ch; }
void Hero::set_weapon(string weapon_ch) { weapon = weapon_ch; }
void Hero::set_health(string health_ch) { health = health_ch; }
void Hero::set_armor(string armor_ch) { armor = armor_ch; }

void Hero::show()
{
	cout << "------------------------------------" << endl;
	cout << "Character: HERO" << endl;
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Weapon: " << weapon << endl;
	cout << "Health: " << health << endl;
	cout << "Armor: " << armor << endl;
	cout << "------------------------------------" << endl;
}

void Hero::rewrite()
{
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Character: HERO" << endl;
	cout << "Input new name: ";
	getline(cin, name);
	cout << "Input new level: ";
	getline(cin, level);
	cout << "Input new weapon: ";
	getline(cin, weapon);
	cout << "Input new health: ";
	getline(cin, health);
	cout << "Input new armor: ";
	getline(cin, armor);
	cout << "------------------------------------" << endl;
}

void Hero::saving()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile)
	{
		throw "Error opening!";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << 1 << endl << name << endl << level << endl << weapon << endl << health << endl << armor << endl;
		outfile.close();
	}
}

void Hero::redact_str(int num_str, string red_str)
{
	switch (num_str)
	{
	case 1:
		this->name = red_str;
		break;
	case 2:
		this->level = red_str;
		break;
	case 3:
		this->weapon = red_str;
		break;
	case 4:
		this->health = red_str;
		break;
	case 5:
		this->armor = red_str;
		break;
	default:
		throw "Incorrect number of string!";
		break;
	}
}