#include <cmath>
#include <iostream>

#include "Triangle.h"
#include "FileOperations.h"
#include "ExceptionHandler.h"

namespace Components
{
    Triangle::Triangle(const LinePtr& firstLine, const LinePtr& secondLine, const LinePtr& thirdLine, const FillAttributes::FillAttributesPtr& fillAttr, const Logging::LoggingPtr& logger) :
        m_triangle({firstLine, secondLine, thirdLine}),
        m_fillAttr(std::move(fillAttr)),
        m_logger(std::move(logger))
    {
        if(fillAttr == nullptr || logger == nullptr)
        {
            ThrowException("Null injection attempt!")
        }

        if(*(m_triangle[0]->GetPoint(1)) != *((m_triangle[1]->GetPoint(0))) || 
            *(m_triangle[1]->GetPoint(1)) != *(m_triangle[2]->GetPoint(0)) || 
            *(m_triangle[2]->GetPoint(1)) != *(m_triangle[0]->GetPoint(0))) 
                ThrowException("Not continuous!")
            

        std::sort(m_triangle.begin(), m_triangle.end(), [this](const LinePtr& lineA, const LinePtr& lineB){
            return lineA->GetLength() < lineB->GetLength();
        });

        if(m_triangle[2]->GetLength() > (m_triangle[1]->GetLength() + m_triangle[0]->GetLength()))
            ThrowException("Not a triangle !")
    }

    float Triangle::GetArea() const noexcept // Heron's Formula for determining Triangle area
    {
        auto lengthA = m_triangle[0]->GetLength();
        auto lengthB = m_triangle[1]->GetLength();
        auto lengthC = m_triangle[2]->GetLength();
        float semiPerimeter = (lengthA + lengthB + lengthC)/2.0;

        return std::sqrt(semiPerimeter*(semiPerimeter - lengthA)*(semiPerimeter - lengthB)*(semiPerimeter - lengthC));
    }

    LinePtr Triangle::GetLine(const int& line) const noexcept
    {
        return m_triangle[line];
    }

    void Triangle::SetColor(const std::string& color) noexcept
    {
        m_fillAttr->SetColor(color);
    }

    std::string Triangle::GetColor() const noexcept
    {
        return m_fillAttr->GetColor();
    }

    std::string Triangle::ReadFile(const std::string& filePath) noexcept
    {
        return FileOperations::FileOperations::ReadFromFile(filePath);
    }

    void Triangle::WriteFile(const std::string& filePath, const std::vector<char>& data) noexcept
    {
        FileOperations::FileOperations::WriteBinaryToFile(filePath, data);
    }

    Logging::LoggingPtr Triangle::GetLogger() const noexcept
    {
        return m_logger;
    }



}