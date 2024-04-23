#pragma once

#include <memory>
#include <array>

#include "Point/Point.h"

namespace Components
{
    class Line
    {
    public:
        Line(const PointPtr& startPoint, const PointPtr& endPoint) :
            m_line({startPoint, endPoint}) {}

        float GetLength() const noexcept;
        PointPtr GetPoint(const int& position) const noexcept;
    private:
        std::array<PointPtr, 2> m_line;
    };

    using LinePtr = std::shared_ptr<Line>;
}