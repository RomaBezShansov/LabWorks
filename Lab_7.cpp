1.Что такое метод ?
Это функция которая определена внутри типа

struct Person
{
	int age;
	std::string_view name;
	void printAge(Person* person) // printAge это метод
	{
		std::cout << person->age;
	}
};

2. Что такое "функция-член" ?
Синоним для метода.
age,name, printAge методы

3. Что такое член класса ?
Метод и поля.

4.Чем отличается instance функция(функция - экземпляр) от статической ?
instance методы работают с обьектами для которого онм были вызваны

void printAge() //person как параметр передаётся но скртно 
{
	std::cout << this->age;
}

static void StaticPrintAge(Person* person) // Передаётся параметр person вручную
{
	std::cout << person->age;
}

5.Какой синтаксис вызова методов ?

struct Person
{
	int age;
	std::string_view name;
	void printAge(Person* person) // printAge это метод
	{
		std::cout << person->age;
	}
};

int main()
{
	Person person;
	person.age = 20;
	person.name = "John";

	Person::printAge(&person); // Вызов статического метода 
	person.printAge(&person);

	person.printAge(); // Вызов instance метод
	return 0;
}

6.Как только объявить метод, а определить его отдельно ?

struct Person
{
	int age;
	std::string_view name;
	void printAge();
};
void Person::printAge()
{
	std::cout << person->age;
}

7.Возможно ли определить метод внутри класса, который будет статический для линкера(определен только для текущего compilation unit - a) ?
Нельзя т.к. класс находится в другом compilation unit
8.