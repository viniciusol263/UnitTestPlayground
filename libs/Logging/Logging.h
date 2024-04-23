#pragma once

#include <string>
#include <memory>

namespace Logging
{
    enum class LoggingHierarchy : int
    {
        UNKNOWN = 0,
        DEBUG,
        WARN,
        CRITICAL
    };

    std::string LoggingHierarchyToString(const LoggingHierarchy& hierarchy);
    
    class Logging
    {
    public:
        Logging(const std::string& filePath) : 
            m_filePath(filePath) {}

        void Log(const LoggingHierarchy& hierarchy, const std::string& message) noexcept;

    private:
        std::string m_filePath;
    };
    using LoggingPtr = std::shared_ptr<Logging>;
}