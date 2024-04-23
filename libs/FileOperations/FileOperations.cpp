#include <filesystem>
#include <fstream>
#include <iostream>

#include "FileOperations.h"
#include "ExceptionHandler.h"

namespace FileOperations
{
    bool FileOperations::AttemptRemove(const std::string& filePath) noexcept
    {
        try
        {
            std::filesystem::remove(filePath);
            return true;
        }
        catch(const std::filesystem::filesystem_error& err)
        {
            ThrowException(err.what())
        }
    }

    std::string FileOperations::ReadFromFile(const std::string& filePath) noexcept
    {
        std::ifstream fileHandler;
        std::string readData;

        fileHandler.exceptions(std::ifstream::badbit);
        try
        {
            fileHandler.open(filePath, std::ios::in);
            while(fileHandler.rdbuf()->in_avail() > 0)
            {
                readData.push_back(fileHandler.rdbuf()->sbumpc());
            }
            fileHandler.close();
        }
        catch(const std::ifstream::failure& err)
        {
            ThrowException(err.what())
        }

        return readData;
    }

    void FileOperations::WriteBinaryToFile(const std::string& filePath, const std::vector<char>& data, const bool& isAppend) noexcept
    {
        std::ofstream fileHandler;

        auto openmode = std::ios::out | std::ios::binary;
        if(isAppend)
            openmode |= std::ios::app;

        fileHandler.exceptions(std::ifstream::badbit);
        try
        {
            fileHandler.open(filePath, openmode);
            
            for(auto &byte : data)
            {
                fileHandler.rdbuf()->sputc(byte);
            }

            fileHandler.close();
        }
        catch(const std::ofstream::failure& err)
        {
            ThrowException(err.what())
        }
    }


}