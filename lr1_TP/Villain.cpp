#include "Library.h"

using namespace std;

Villain::Villain()
{
	cout << "Constructor Villain was called." << endl;
}

Villain::~Villain()
{
	cout << "Destructor Villain was called." << endl;
}

Villain::Villain(const Villain& Villain_copy)
{
	name = Villain_copy.name;
	level = Villain_copy.level;
	weapon = Villain_copy.weapon;
	guilt = Villain_copy.guilt;
	place = Villain_copy.place;
	health = Villain_copy.health;
	armor = Villain_copy.armor;
	cout << "Copy constructor Villain was called." << endl;
}

Villain::Villain(string name)
{
	this->name = name;
	cout << "Constructor Villain was called." << endl;
}

string Villain::get_name() const { return name; };
string Villain::get_level() const { return level; };
string Villain::get_weapon() const { return weapon; }
string Villain::get_guilt() const { return guilt; }
string Villain::get_place() const { return place; }
string Villain::get_health() const { return health; }
string Villain::get_armor() const { return armor; }
void Villain::set_name(string name_ch) { name = name_ch; }
void Villain::set_level(string level_ch) { level = level_ch; }
void Villain::set_weapon(string weapon_ch) { weapon = weapon_ch; }
void Villain::set_guilt(string guilt_ch) { guilt = guilt_ch; }
void Villain::set_place(string place_ch) { place = place_ch; }
void Villain::set_health(string health_ch) { health = health_ch; }
void Villain::set_armor(string armor_ch) { armor = armor_ch; }

void Villain::show()
{
	cout << "------------------------------------" << endl;
	cout << "Character: VILLAIN" << endl;
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Weapon: " << weapon << endl;
	cout << "Guilt: " << guilt << endl;
	cout << "Place: " << place << endl;
	cout << "Health: " << health << endl;
	cout << "Armor: " << armor << endl;
	cout << "------------------------------------" << endl;
}

void Villain::rewrite()
{
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Character: VILLAIN" << endl;
	cout << "Input new name: ";
	getline(cin, name);
	cout << "Input new level: ";
	getline(cin, level);
	cout << "Input new weapon: ";
	getline(cin, weapon);
	cout << "Input new guilt: ";
	getline(cin, guilt);
	cout << "Input new place: ";
	getline(cin, place);
	cout << "Input new health: ";
	getline(cin, health);
	cout << "Input new armor: ";
	getline(cin, armor);
	cout << "------------------------------------" << endl;
}

void Villain::saving()
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
	outfile << 2 << endl << name << endl << level << endl << weapon << endl << guilt << endl << place << endl << health << endl << armor << endl;
	outfile.close();
}

void Villain::redact_str(int num_str, string red_str)
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
		this->guilt = red_str;
		break;
	case 5:
		this->place = red_str;
		break;
	case 6:
		this->health = red_str;
		break;
	case 7:
		this->armor = red_str;
		break;
	default:
		throw "Incorrect number of string!";
		break;
	}
}