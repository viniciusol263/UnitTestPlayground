#pragma once

#include <exception>
#include <string>
#include <memory>


#define ThrowException(msg) throw ExceptionHandler::ExceptionHandler(msg, __FILE__, __LINE__);

namespace ExceptionHandler
{
    class ExceptionHandler : public std::exception
    {
    public:
        ExceptionHandler(const std::string& exceptionMsg, const char* file, int line) : 
            m_exceptionMsg(exceptionMsg), m_file(file), m_line(line) {}

        std::string GetMsg() const noexcept;
    private:
        std::string m_exceptionMsg;
        const char* m_file;
        int m_line;
    };
    using ExceptionHandlerPtr = std::shared_ptr<ExceptionHandler>;
}