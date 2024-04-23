#pragma once

#include "Triangle/Triangle.h"
#include "FillAttributes.h"
#include "Logging.h"
#include "ExceptionHandler.h"

namespace GeometricShapes
{
    class GeometricShapes
    {
    public:
        GeometricShapes();
        
    private:
        FillAttributes::FillAttributesPtr m_fillAttributes;
        Logging::LoggingPtr m_logger;
    };
}