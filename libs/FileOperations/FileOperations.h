#pragma once

#include <string>
#include <vector>

namespace FileOperations
{
    class FileOperations
    {
    public:
        FileOperations() = default;

        static bool AttemptRemove(const std::string& filePath) noexcept;
        static std::string ReadFromFile(const std::string& filePath) noexcept;
        static void WriteBinaryToFile(const std::string& filePath, const std::vector<char>& data, const bool& isAppend = false) noexcept;
    };
}