#pragma once

#include <memory>
#include <array>
#include <vector>
#include <exception>
#include <algorithm>
#include <string>

#include "Line/Line.h"
#include "FillAttributes.h"
#include "Logging.h"

namespace Components
{
    class Triangle
    {
    public:
        Triangle(const LinePtr& firstLine, const LinePtr& secondLine, const LinePtr& thirdLine, const FillAttributes::FillAttributesPtr& fillAttr, const Logging::LoggingPtr& logger);
        float GetArea() const noexcept;
        LinePtr GetLine(const int& line) const noexcept;
        
        void SetColor(const std::string& color) noexcept;
        std::string GetColor() const noexcept;

        std::string ReadFile(const std::string& filePath) noexcept;
        void WriteFile(const std::string& filePath, const std::vector<char>& data) noexcept;

        Logging::LoggingPtr GetLogger() const noexcept;

    private:
        std::array<LinePtr, 3> m_triangle;
        FillAttributes::FillAttributesPtr m_fillAttr;
        Logging::LoggingPtr m_logger;
    };
    using TrianglePtr = std::shared_ptr<Triangle>;
}