#include <iostream>
#include "../person_keeper.h"

using namespace msl;


int main()
{
    PersonKeeper& personKeeper = PersonKeeper::createInstance();

    auto persons = personKeeper.readPersons("/home/saba/Desktop/TRPO/TRPO_lab_1/person_keeper/test/input_test.txt");

    personKeeper.writePersons(persons, "output_test.txt");

    return 0;
}

