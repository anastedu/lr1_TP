#pragma warning( disable : 6386 )
#pragma warning( disable : 26451 )
#include "Library.h"

using namespace std;

Keeper::Keeper() : m_size(0), head(nullptr) {}
Keeper::Keeper(int size) : head(nullptr) { this->m_size = size; }
Keeper::~Keeper()
{
	if (head != NULL)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Character();
			delete(buffer);
		}
		head->m_data->~Character();
		delete(head);
	}
}

Character* Keeper::operator[] (const int index)
{
	if ((index >= m_size) || (index < 0))
	{
		throw "Incorrect index!";
	}
	else
	{
		Elem* buffer = head;
		for (int i = 0; i < m_size - index - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->m_data);
	}
}

int Keeper::get_size() { return m_size; }

void Keeper::insert(Character* n_data)
{
	Elem* tmp;
	tmp = new Elem;

	if (m_size == 0)
	{
		tmp->m_data = n_data;
		tmp->next = 0;
		++m_size;
	}
	else
	{
		tmp->m_data = n_data;
		tmp->next = head;
		++m_size;
	}

	head = tmp;
}

void Keeper::remove(int index)
{
	if (m_size == 0)
	{
		throw "There's nothing to delete!";
		system("pause");
	}
	int counter = 0;
	while (counter < index - 1)
	{
		head = head->next;
		counter++;
	}

	Elem* prev = head;
	prev->next->m_data->~Character();
	prev->next->next;
	delete(prev->next);
	--m_size;
}

void Keeper::save()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile);
	if (!outfile)
	{
		throw "Error opening file!";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << m_size << endl;
		outfile.close();
	}

	Elem* buffer = head;
	for (int i = 0; i < m_size; i++)
	{
		buffer->m_data->saving();
		buffer = buffer->next;
	}
}

void Keeper::load()
{
	if (m_size != 0)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Character();
			delete(buffer);
		}
		head->m_data->~Character();
		delete(head);
	}


	ifstream infile;
	int read_size, num_character; //переменная читки размера и персонажа
	string a, b, c, d, e, f, g; //считываемые строки
	string initfile = "data.txt";
	Character* characters;

	infile.open(initfile);
	if (!infile)
	{
		throw "Error opening!";
		system("pause");
		exit(1);
	}

	infile >> read_size; //читаем кол-во персонажей

	for (int i = 0; i < read_size; i++)
	{
		infile >> num_character; //читаем номер персонажа
		infile.ignore(32767, '\n');

		if (num_character == 1) //перед нами герой
		{
			//infile >> a >> b >> c >> d >> e;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			Hero* hero;
			hero = new Hero;
			hero->set_name(a);
			hero->set_level(b);
			hero->set_weapon(c);
			hero->set_health(d);
			hero->set_armor(e);
			characters = hero;
			insert(characters);
		}

		if (num_character == 2) //перед нами злодей
		{
			//infile >> a >> b >> c >> d >> e >> f >> g;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			getline(infile, f);
			getline(infile, g);
			Villain* villain;
			villain = new Villain;
			villain->set_name(a);
			villain->set_level(b);
			villain->set_weapon(c);
			villain->set_guilt(d);
			villain->set_place(e);
			villain->set_health(f);
			villain->set_armor(g);
			characters = villain;
			insert(characters);
		}

		if (num_character == 3) //перед нами монстр
		{
			//infile >> a >> b >> c;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			Monster* monster;
			monster = new Monster;
			monster->set_name(a);
			monster->set_level(b);
			monster->set_description(c);
			characters = monster;
			insert(characters);
		}
	}
}