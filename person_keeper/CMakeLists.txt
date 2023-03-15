project(person_keeper)

add_library(${PROJECT_NAME} person_keeper.h person_keeper.cpp)

add_subdirectory(test)