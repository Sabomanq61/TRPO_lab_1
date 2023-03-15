//
// Created by saba on 05.03.23.
//

#include <fstream>
#include <sstream>

#include "person_keeper.h"


namespace msl
{

std::ostream& operator<<(std::ostream& ostream, const Person& person)
{
    ostream << person.secondName << " " << person.name << " " << person.partomin;
    return ostream;
}

Stack<Person> PersonKeeper::readPersons(std::string file)
{
    std::ifstream input(file);

    // объект ifstream является невалидным
    // считывание невозможно
    if (!input)
    {
        throw std::runtime_error("readPersons::Open file error");
    }

    // определяем стек для хранения ФИО людей
    Stack<Person> stackPerson;

    while (!input.eof())
    {
        std::array<std::string, 3> fio;
        std::string str;
        std::getline(input, str);

        std::stringstream ss(str);
        for(auto& s : fio)
        {
            std::getline(ss, s, ' ');
        }

        stackPerson.push(Person{fio[0], fio[1], fio[2]});
    }

    return stackPerson; // возращаем стек
}

void PersonKeeper::writePersons(Stack<Person>& persons, const std::string& outputFile)
{
    std::ofstream ofstream(outputFile);

    // объект ofstream является невалидным
    // считывание невозможно
    if (!ofstream)
    {
        throw std::runtime_error("writePersons::Open file error.");
    }

    while(!persons.empty())
    {
        ofstream << persons.top() << std::endl;
        persons.pop();
    }
    ofstream.close();
}

PersonKeeper& PersonKeeper::createInstance()
{
    static PersonKeeper personKeeper;
    return personKeeper;
}

}