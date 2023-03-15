#include <iostream>
#include "../person_keeper.h"

using namespace msl;


int main()
{
    PersonKeeper& personKeeper = PersonKeeper::createInstance();

    auto persons = personKeeper.readPersons("/home/saba/Desktop/TRPO/lab1/person_keeper/test/persons");

    personKeeper.writePersons(persons, "output_test.txt");

    return 0;
}

