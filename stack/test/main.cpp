#include <iostream>
#include <cassert>
#include "../stack.h"


using namespace msl;
int main()
{
    Stack<int> stack;

    std::cout << "Tests for stack" << std::endl;
    std::cout << "Test 1: push to stack values 10, 20 and check its size" << std::endl;
    stack.push(10);
    stack.push(20);
    assert(stack.size() == 2);

    std::cout << "Stack size is 2" << std::endl;

    std::cout << "Test 2: Get all stack elements" << std::endl;
    auto node = stack.top();
    assert(node == 20);
    stack.pop();
    assert(stack.size() == 1);

    std::cout << node << std::endl;
    node = stack.top();
    assert(node == 10);
    stack.pop();
    std::cout << node << std::endl;

    std::cout << "Test 3. Stack is empty" << std::endl;
    assert(stack.empty());
    std::cout << "Test 3. Passed" << std::endl;

    std::cout << "Test 4: Catch stack exception 'Stack is empty'" << std::endl;
    try {
        stack.top();
    }
    catch(error::ErrorStackEmpty& err)
    {
        std::cout << err.what() << std::endl;
    }

    std::cout << "Stack test end" << std::endl;
    return 0;

}

