#pragma once

#include <string>
#include <memory>

namespace FillAttributes 
{
    class FillAttributes
    {
    public:
        FillAttributes(const std::string& color = "white") : 
            m_color(color) {}

        std::string GetColor() const noexcept;
        void SetColor(const std::string& color) noexcept;
    private:
        std::string m_color;
    };
    using FillAttributesPtr = std::shared_ptr<FillAttributes>;
}