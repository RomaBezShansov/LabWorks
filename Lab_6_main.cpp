
//int hello(int number); // Объявление функции. Тела функции нет и по этой причине выдаётся ошибка.
int hello(int a);

int hello(int a)
{
	return a;
}

int main()
{
	hello(2);
	return 0;
}