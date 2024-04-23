#include "FillAttributes.h"

namespace FillAttributes
{
    std::string FillAttributes::GetColor() const noexcept
    {
        return m_color;
    }

    void FillAttributes::SetColor(const std::string& color) noexcept
    {
        if(m_color != color)
        {
            m_color = color;
        }
    }
}