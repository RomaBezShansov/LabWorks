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

8.Обязателен ли оператор new чтобы создать класс (структуру с методами)?

new не обязателен чтоб создать класс или структуру с методами

9.Влияет ли количество методов класса на то сколько байт будет занимать объект типа этого класса?

Количество методов класса не должно изменять размер объектов этого класса.

10.Занимает ли объект с одним методом больше памяти, чем объект без методов?

Нет, исходя из прошлого вопроса можно понять что не важно сколько методов в обьекте, они будут занимать одинаковый размер.

11.В чем функциональное преимущество использование методов вместо обычных функций, принимающих параметр, подобный параметру this, не скрытно, первым параметром.

this не надо писать перед методом. Компилятор сам понимает по его имени какой метод вызывается

struct Person
{
int age;
std::string_view name;

void printAge()
{
std::cout <<age;
staticPrintAge(this);     //Все 3 вызывают метод
this->staticPrintAge(this);
Person::staticPrintAge(this);
}
static void staticPrintAge(Person* person)
{
std::cout <<person->age;
}
};