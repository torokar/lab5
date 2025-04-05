#include <iostream>
#include "list.h"
#include "save_data.h"

double cal_average_salary(const int &size, const int &exp,const double &sal)
{
	double totalSal = 0;
	if (size == 0)
	{
		std::cerr << "Список работников пуст!\n";
		return 0;
	}
	
	return sal;
}

void removePeopleId(List<data<int>>& empList, int ID)
{
	bool found = false;
	for (int i = 0; i < empList.GetSize(); i++)
	{
		if (empList[i].id == ID)
		{
			empList.erase(i); 
			found = true;
			std::cout << "Сотрудник с ID " << ID << " удалён.\n";
			break;
		}
	}

	if (!found)
	{
		std::cout << "Сотрудник с таким ID не найден.\n";
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int countPeople = 0;
	List<data<int>> empList;
	std::cout << "Введите количество сотрудников\n--> ";
	std::cin >> countPeople;
	for (int i = 0; i < countPeople; i++)
	{
		data<int> emp;
		std::cout << "Введите данные " << i + 1 << " сотрудника:\n";
		std::cout << "ID:\n--> ";
		std::cin >> emp.id;
		std::cin.ignore();

		std::cout << "Имя:\n--> ";
		std::cin >> emp.name;
		std::cin.ignore();

		std::cout << "Фамилия:\n--> ";
		std::cin >> emp.second_name;
		std::cin.ignore();

		std::cout << "Зарплата:\n--> ";
		std::cin >> emp.salary;
		std::cin.ignore();

		std::cout << "Cтаж работника:\n--> ";
		std::cin >> emp.experience;
		std::cin.ignore();

		empList.push_front(emp);
	}

	int ID;
	std::cout << "Введите ID сотрудника, которого хотите убрать\n--> ";
	std::cin >> ID;
	empList.erase(ID);


	int index = 0;
	for (int i = 0; i < empList.GetSize(); i++)
	{
		int count = 0;
		if (empList[i].experience >= 12)
		{
			count++;
			index = i;
		}
		else
		{
			continue;
		}
		int exp = 0;
		double sal = 0;
		data<int>& emp = empList[i];
		exp = empList[i].experience;
		sal = empList[i].salary;

		cal_average_salary(count, exp, sal);

		std::cout << "\n\n**Сотрудники со стажем больше 12 лет**\n\n";
		while (true)
		{
			data<int>& emp = empList[i];
			std::cout << "\nID: " << emp.id
				<< "\nИмя: " << emp.name
				<< "\nФамилия: " << emp.second_name
				<< "\nЗарплата: " << emp.salary
				<< "\nСтаж работы: " << emp.experience;
			break;
		}
	}

	std::cout << "\nСписок сотрудников:\n";
	for (int i = 0; i < empList.GetSize(); ++i) {
		data<int>& emp = empList[i];
		std::cout << "ID: " << emp.id
			<< ", Имя: " << emp.name
			<< ", Зарплата: " << emp.salary
			<< ", Опыт: " << emp.experience << " лет\n";
	}

	return 0;
}