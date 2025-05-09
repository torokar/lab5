﻿#include <iostream>
#include <fstream>
#include "list.h"
#include "save_data.h"

void removePeopleId(List<data<int>>& empList, int ID)
{
	bool found = false;
	for (int i = 0; i < empList.GetSize(); i++)
	{
		if (empList[i].id == ID)
		{
			found = true;
			if (i == 0)
			{
				empList.pop_front();  
				std::cout << "Сотрудник с ID " << ID << " удалён.\n";
			}
			else if (i == empList.GetSize() - 1)
			{
				empList.pop_back(); 
				std::cout << "Сотрудник с ID " << ID << " удалён.\n";
			}
			else
			{
				empList.erase(i);
				std::cout << "Сотрудник с ID " << ID << " удалён.\n";
			}

			break;
		}
	}

	if (!found)
	{
		std::cout << "Сотрудник с таким ID не найден.\n";
	}
}



void openFile(std::string fileName, List<data<int>>& empList)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		throw std::runtime_error("Ошибка! Не удалось открыть файл " + fileName + "\n");
	}
	else
	{
		std::string space;
		while (std::getline(file, space))
		{
			data<int> emp;
			emp.id = std::stoi(space);

			std::getline(file, emp.name);

			std::getline(file, emp.second_name);

			std::getline(file, space);
			emp.salary = std::stoi(space);

			std::getline(file, space);
			emp.experience = std::stoi(space);

			empList.push_front(emp);
		}
	}
	
	file.close();
}




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string path = "data\\Data_Employ.txt";
	List<data<int>> empList;
	int choice = 0;
	std::cout << "\n\t\t** ВАЖНО! Для корректной работы с файлами необходимо изменить кодировку текстового документа! **\n\n"
		<< "\t1. Перейдите в папку, где установлена программа.\n"
		<< "\t2. Откройте папку 'data' -> файл 'Data_Employ.txt'\n"
		<< "\t3. В текстовом редакторе нажмите: 'Файл' -> 'Сохранить как...'\n"
		<< "\t4. Внизу окна в поле 'Кодировка' выберите 'ANSI'\n"
		<< "\t5. Сохраните файл и перезапустите программу.\n\n";
	while (true)
	{
		std::cout << "Выберите действие:\n";
		std::cout << "1. Ввод данных с консоли\n";
		std::cout << "2. Ввод данных из файла\n";
		std::cout << "3. Удалить сотрудника по ID\n";
		std::cout << "4. Вывести список сотрудников\n";
		std::cout << "0. Выход\n--> ";
		std::cin >> choice;

		while (true)
		{
			if (std::cin.fail() || choice < 0)
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cerr << "Ошибка ввода!\nЧисло должно быть положительным(Н: 0, 1, 2, 3)\n--> ";
				std::cin >> choice;
			}
			if (!std::cin.fail())
			{
				break;
			}

		}
		switch (choice)
		{
		case 1:
		{
			int countPeople = 0;
			system("cls");
			std::cout << "Введите количество сотрудников\n--> ";
			std::cin >> countPeople;

			for (int i = 0; i < countPeople; i++)
			{
				data<int> emp;
				std::cout << "Введите данные " << i + 1 << " сотрудника:\n";
				std::cout << "ID:\n--> ";
				std::cin >> emp.id;

				std::cout << "Имя:\n--> ";
				std::cin >> emp.name;

				std::cout << "Фамилия:\n--> ";
				std::cin >> emp.second_name;

				std::cout << "Зарплата:\n--> ";
				std::cin >> emp.salary;

				std::cout << "Стаж работника:\n--> ";
				std::cin >> emp.experience;

				empList.push_front(emp);
			}
			break;
		}

		case 2:
		{
			// Ввод данных из файла
			try
			{
				openFile(path, empList);
			}
			catch (const std::exception& ex)
			{
				std::cerr << ex.what() << std::endl;
			}

			break;
		}
		case 3:
		{
			// Удалить сотрудника по ID
			int ID;
			std::cout << "Введите ID сотрудника, которого хотите убрать\n--> ";
			std::cin >> ID;
			removePeopleId(empList, ID);
			break;
		}
		case 4:
		{
			system("cls");
			std::cout << std::endl;
			for (int i = 0; i < empList.GetSize(); i++)
			{
				std::cout << "ID: " << empList[i].id
					<< ", Имя: " << empList[i].name
					<< ", Фамилия: " << empList[i].second_name
					<< ", Зарплата: " << empList[i].salary
					<< ", Стаж: " << empList[i].experience << std::endl;
			}
			std::cout << std::endl << std::endl;
			break;
		}

		case 0:
		{
			system("cls");
			std::cout << "\nВыход из программы!\n";
			return 0;
		}
		default:
			std::cout << "Некорректный выбор!\n";
		}
	}
		return 0;
	}
