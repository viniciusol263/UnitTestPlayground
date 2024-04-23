#include "ExceptionHandler.h"

namespace ExceptionHandler
{
    std::string ExceptionHandler::GetMsg() const noexcept
    {
        auto msgToReturn = "[EXCEPTION CAUGHT:" + std::string(m_file) + ":" + std::to_string(m_line) + ":" + m_exceptionMsg + "]"; 
        return msgToReturn;
    }
}