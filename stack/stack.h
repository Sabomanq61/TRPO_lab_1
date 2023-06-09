#pragma once

#include "error.h"
#include <vector>


namespace msl
{

/// @brief Узел
template <typename T>
struct Node
{
    explicit Node(T&& value, Node* ptr = nullptr)
            : value_(value)
            , next_(ptr)
    {};

    explicit Node(const T& value, Node* ptr = nullptr)
    : value_(value)
    , next_(ptr)
    {}

    T value_;    /// значение
    Node* next_; /// пред. узел
};

template <typename T>
class Stack final
{
public:

    /// @brief конструктор по умолчанию
    Stack() = default;

    /// @brief конструктор копирования
    Stack(const Stack<T>& stack)
    : head_(nullptr)
    , size_(0)
    {
        std::vector<T> nodes;
        nodes.reserve(stack.size_);

        Node<T>* top = stack.head_;

        // обходим весь стек
        while (top)
        {
            nodes.push_back(top->value_);
            top = top->next_;
        }
        // заносим элементы в стек
        for (auto it = nodes.rbegin(); it != nodes.rend(); ++it)
        {
            push(*it);
        }
    }

    /// @brief Конструктор перемещения
    Stack(Stack<T>&& stack)
    : head_(nullptr)
    , size_(0)
    {
        std::swap(head_, stack.head_);
        std::swap(size_, stack.size_);
    }

    /// @brief деструктор
    ~Stack()
    {
        while (head_ != nullptr && size_)
        {
            pop();
        }
    }

    /// @brief Получение размерности стека
    /// @return размер стека
    size_t size() const
    {
        return size_;
    }

    /// @brief Является ли стек пустым
    /// @return true - стек пустой, false - не пуст
    bool empty() const
    {
        return head_ == nullptr;
    }

    /// @brief Добавление значения в стек
    /// @param value - значение
    void push(const T& value) {
        auto* newNode = new Node<T>(value, head_);
        head_ = newNode;
        ++size_;
    }

    /// @brief Добавление значения в стек
    /// @param value - значение
    void push(T&& value) {
        auto* newNode = new Node<T>(value, head_);
        head_ = newNode;
        ++size_;
    }

    /// @brief Удаление последнего значения из стека
    void pop() {
        if(head_)
        {
            Node<T> *newHead = head_->next_;
            delete head_;
            --size_;
            head_ = newHead;
        }
    }

    /// @brief Возвращает последнее значение из стека
    T top()
    {
        if(empty())
        {
            throw error::ErrorStackEmpty();
        }
        return head_->value_;
    }

private:
    Node<T>* head_{};
    size_t   size_{};
};

} // namespace msl