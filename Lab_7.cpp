1.��� ����� ����� ?
��� ������� ������� ���������� ������ ����

struct Person
{
	int age;
	std::string_view name;
	void printAge(Person* person) // printAge ��� �����
	{
		std::cout << person->age;
	}
};

2. ��� ����� "�������-����" ?
������� ��� ������.
age,name, printAge ������

3. ��� ����� ���� ������ ?
����� � ����.

4.��� ���������� instance �������(������� - ���������) �� ����������� ?
instance ������ �������� � ��������� ��� �������� ��� ���� �������

void printAge() //person ��� �������� ��������� �� ������ 
{
	std::cout << this->age;
}

static void StaticPrintAge(Person* person) // ��������� �������� person �������
{
	std::cout << person->age;
}

5.����� ��������� ������ ������� ?

struct Person
{
	int age;
	std::string_view name;
	void printAge(Person* person) // printAge ��� �����
	{
		std::cout << person->age;
	}
};

int main()
{
	Person person;
	person.age = 20;
	person.name = "John";

	Person::printAge(&person); // ����� ������������ ������ 
	person.printAge(&person);

	person.printAge(); // ����� instance �����
	return 0;
}

6.��� ������ �������� �����, � ���������� ��� �������� ?

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

7.�������� �� ���������� ����� ������ ������, ������� ����� ����������� ��� �������(��������� ������ ��� �������� compilation unit - a) ?
������ �.�. ����� ��������� � ������ compilation unit