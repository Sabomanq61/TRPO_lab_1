#include <string>
#include "../stack/stack.h"
#include <memory>
#include <iostream>


namespace msl
{

struct Person
{
    std::string secondName;
    std::string name;
    std::string partomin;
public:
    friend std::ostream& operator<<(std::ostream& ostream, const Person& person);
};

class PersonKeeper
{
public:
    Stack<Person> readPersons(std::string inputFile);

    void writePersons(Stack<Person>& persons, const std::string& outputFile);

    static PersonKeeper& createInstance();

private:
    PersonKeeper() = default;
    PersonKeeper(const PersonKeeper&) = default;
    PersonKeeper& operator=(PersonKeeper&) = default;

private:
};

}
