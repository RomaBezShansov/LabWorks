struct Leg
{
    int length;
};

struct Arm
{
    int power;
};

struct Person
{
    std::array<Leg, 2> legs; // Типы  1) person.legs[0].length 2) person.legs[1].length 3) Leg person.legs[0] 4) Leg person.legs[1] 
                             //          5) Обьекты person.legs 6) person.arms[0].power 7) person.arms[1].power 8) Arm person.arms[0] 9) Arm person.arms[1] 10) Person person
    Arm arms[2];
};

int main()
{
    Person person;
}