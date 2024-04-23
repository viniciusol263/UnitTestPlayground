#include "Point.h"

namespace Components
{
    PointType Point::GetPosition() const noexcept 
    {
        return {m_x, m_y};
    }

}