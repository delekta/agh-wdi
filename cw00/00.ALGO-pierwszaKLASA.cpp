#include <iostream>
using namespace std;
class Animal
{
private:
    string a_name;
public:
    Animal(string name) : a_name(name){}
    virtual string MakeSound() = 0;
    string GetName()
    {
    return a_name;
    }
};
class Bird:public Animal
{
public:
    //Przekazujemy argumenty konstruktora
    Bird(string name) : Animal(name) {}
    string MakeSound() override
    {
        return "twit, twit!";
    }
};
int main()
{
    Bird bird2=Bird("Twinkle");
    cout<<bird2.GetName()<<" robi: ";
    cout<<bird2.MakeSound()<<endl;
    return 0;
}
