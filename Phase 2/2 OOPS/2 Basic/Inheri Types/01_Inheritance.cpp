#include <bits/stdc++.h>
using namespace std;

class animal
{
public:
    int weight;
    int age;

    animal()
    {
        this->weight = 0;
        this->age = 0;
    }

    void setAge(int age) { this->age = age; }
    void setWeight(int weight) { this->weight = weight; }
    int getAge() const { return this->age; }
    int getWeight() const { return this->weight; }
};

class dog : public animal
{
};

int main()
{
    cout << sizeof(animal) << endl;
    cout << sizeof(dog) << endl;

    return 0;
}