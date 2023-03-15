#pragma once

#include <string>
#include <utility>

namespace msl
{
namespace error
{

/// @brief Общий класс для ошибок стека
class Error {
public:
    Error()
    : error_("Stack unknown error") {};

    /// @brief конструктор
    /// @param error - сообщение об ошибке для записи
    explicit Error(std::string error)
            : error_(std::move(error)) {};

    /// @brief конструктор
    /// @param error - сообщение об ошибке для записи
    explicit Error(const char *error)
            : error_(error) {}

    virtual ~Error() = default;

    std::string what() {
        return error_;
    }

private:
    std::string error_;
};


class ErrorStackEmpty : public Error {
public:
    ErrorStackEmpty()
    : Error("Stack empty")
    {};

    /// @brief конструктор
    /// @param error - сообщение об ошибке для записи
    explicit ErrorStackEmpty(const std::string &error)
            : Error(error) {};

    /// @brief конструктор
    /// @param error - сообщение об ошибке для записи
    explicit ErrorStackEmpty(const char *error)
            : Error(error) {};

    ~ErrorStackEmpty() override = default;
};

}
} // namespace msl