#pragma once

#include <iostream>
#include <memory>
#include <tuple>

namespace Components
{
    using PointType = std::tuple<float,float>;
    class Point
    {
    public:
        Point(const float& x, const float& y) :
         m_x(x), m_y(y) 
         {}

        bool operator==(const Point& other) const = default;

        PointType GetPosition() const noexcept;
    private:
        float m_x;
        float m_y;
    };

    using PointPtr = std::shared_ptr<Point>;
}