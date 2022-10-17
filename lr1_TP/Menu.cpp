#include "Library.h"
using namespace std;
void Menu::main_menu()
{
	while (exit == 1)
	{
		switch (show_options())
		{
		case 1:
			show_all_characters();
			break;
		case 2:
			change_data();
			break;
		case 3:
			add_new();
			break;
		case 4:
			save_to_file();
			break;
		case 5:
			load_from_file();
			break;
		case 6:
			delete_character();
			break;
		default:
			exit_from_programm();
			break;
		}
	}
}

int Menu::show_options()
{
	int c1;
	cout << "\nWhat do you want to do?" << endl;
	cout << "1 - Show all characters" << endl;
	cout << "2 - Change data of character" << endl;
	cout << "3 - Add new character" << endl;
	cout << "4 - Save all changes to the file" << endl;
	cout << "5 - Load data from the file" << endl;
	cout << "6 - Delete a character" << endl;
	cout << "0 - Exit" << endl;
	cout << "->  ";
	cin >> c1;
	return c1;
}

void Menu::show_all_characters()
{
	system("cls");
	try
	{
		if (list.get_size() == 0)
		{
			throw "There's nothing to show.";
		}
		for (int i = 0; i < list.get_size(); i++)
		{
			list[i]->show();
		}
	}
	catch (const char* ex) { cout << ex << endl; }
	system("pause");
}

void Menu::change_data()
{
	int c2, c3;
	system("cls");
	try
	{
		cout << "What character do you want to change (from 1 to " << list.get_size() << ")?" << endl;
		cin >> c2;

		if (c2 < 1 || c2 > list.get_size())
		{
			throw "Incorrect number!";
		}

		list[c2 - 1]->show();
		cout << "What string do you want to change (except Character)?" << endl;
		cout << "->  ";
		cin >> c3;
		cin.ignore(32767, '\n');
		cout << "What do you want to put in this string?" << endl;
		cout << "->  ";
		getline(cin, redact);
		list[c2 - 1]->redact_str(c3, redact);
		cout << "The string was redacted." << endl;

	}
	catch (const char* ex) { cout << ex << endl; }
	system("pause");
}

void Menu::add_new()
{
	int c2;
	system("cls");
	cout << "\nWhat character do you want to add?" << endl;
	cout << "1 - Hero" << endl;
	cout << "2 - Villain" << endl;
	cout << "3 - Monster" << endl;
	cout << "0 - Go back" << endl;
	cout << "->  ";
	cin >> c2;

	switch (c2)
	{
	case 1:
		Hero * hero;
		hero = new Hero;
		characters = hero;
		hero->rewrite();
		list.insert(characters);
		cout << "The new character was added." << endl;
		break;
	case 2:
		Villain * villain;
		villain = new Villain;
		characters = villain;
		villain->rewrite();
		list.insert(characters);
		cout << "The new character was added." << endl;
		break;
	case 3:
		Monster * monster;
		monster = new Monster;
		characters = monster;
		monster->rewrite();
		list.insert(characters);
		cout << "The new character was added." << endl;
		break;
	default:
		break;
	}
	system("pause");
}

void Menu::save_to_file()
{
	system("cls");
	try
	{
		if (list.get_size() == 0)
		{
			throw "There's nothing to save.";
		}
		list.save();
		cout << "The data was saved to the file." << endl;
	}
	catch (const char* ex) { cout << ex << endl; }
	system("pause");
}

void Menu::load_from_file()
{
	system("cls");
	try
	{
		list.load();
		cout << "The data was loaded from file." << endl;
	}
	catch (const char* ex) { cout << ex << endl; }
}

void Menu::delete_character()
{
	int c2;
	system("cls");
	cout << "What character do you want to change (from 1 to " << list.get_size() << ")?" << endl;
	for (int i = 0; i < list.get_size(); i++)
	{
		list[i]->show();
	}
	cout << "->  ";
	cin >> c2;

	if (c2 < 1 || c2 > list.get_size())
	{
		throw "Incorrect number!";
	}

	list.remove(c2 - 1);
	cout << "The chosen character was deleted." << endl;
	system("pause");
}

void Menu::exit_from_programm()
{
	exit = 0;
}