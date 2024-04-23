#include <vector>
#include <format>
#include <chrono>
#include <iostream>

#include "Logging.h"
#include "FileOperations.h"

namespace Logging
{
    std::string LoggingHierarchyToString(const LoggingHierarchy& hierarchy)
    {
        switch(hierarchy)
        {
            case LoggingHierarchy::DEBUG: return "DEBUG";
            case LoggingHierarchy::WARN: return "WARN";
            case LoggingHierarchy::CRITICAL: return "CRITICAL";
            default: return "UNKNOWN";
        }
    }

    void Logging::Log(const LoggingHierarchy& hierarchy, const std::string& message) noexcept
    {   
        std::chrono::zoned_time zonedTime{std::chrono::current_zone(), std::chrono::system_clock::now()};
        auto debugMessage =  std::format(" {0:%F}T{0:%T}] ", zonedTime.get_local_time());
        debugMessage = "[" + LoggingHierarchyToString(hierarchy) + debugMessage + message + "\n";
        auto debugMessageVec = std::vector<char>(debugMessage.begin(), debugMessage.end());
        FileOperations::FileOperations::WriteBinaryToFile(m_filePath, debugMessageVec, true);
    }

}
 