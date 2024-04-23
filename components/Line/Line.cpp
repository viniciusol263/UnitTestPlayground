#include <cmath>

#include "Line.h"

namespace Components
{
    float Line::GetLength() const noexcept
    {
        auto [startX, endX] = m_line[0]->GetPosition();
        auto [startY, endY] = m_line[1]->GetPosition(); 
        return std::sqrt(std::pow(std::abs(startY - startX), 2) + std::pow(std::abs(endY - endX), 2));
    }

    PointPtr Line::GetPoint(const int& point) const noexcept
    {
        return m_line[point];
    }

}