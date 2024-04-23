#include "GeometricShapes.h"

namespace GeometricShapes
{
    GeometricShapes::GeometricShapes()
    {
        try
        {
            auto pointA1 = std::make_shared<Components::Point>(2.0, 5.0);
            auto pointA2 = std::make_shared<Components::Point>(6.0, 3.0);
            auto lineA = std::make_shared<Components::Line>(pointA1, pointA2);

            auto pointB1 = std::make_shared<Components::Point>(6.0, 3.0);
            auto pointB2 = std::make_shared<Components::Point>(13.0, 15.0);
            auto lineB = std::make_shared<Components::Line>(pointB1, pointB2);

            auto pointC1 = std::make_shared<Components::Point>(13.0, 15.0);
            auto pointC2 = std::make_shared<Components::Point>(2.0, 5.0);
            auto lineC = std::make_shared<Components::Line>(pointC1, pointC2);

            m_fillAttributes = std::make_shared<FillAttributes::FillAttributes>();
            m_logger = std::make_shared<Logging::Logging>("log.txt");

            Components::Triangle t(lineA, lineB, lineC, m_fillAttributes, m_logger);
            std::cout << "Triangle area is " << t.GetArea() << " Fill color is: " << t.GetColor() << std::endl;
            std::cout << "Read file is " << t.ReadFile("tst.txt") << std::endl;
        }
        catch(const ExceptionHandler::ExceptionHandler& err)
        {
            m_logger->Log(Logging::LoggingHierarchy::CRITICAL, err.GetMsg());
        }
    }
}