#include "axis.hpp"

using namespace plot;

cAxis::cAxis()
{
    majorTicks = 10;
    extents.minimum = 0;
    extents.maximum = 10;
}

/*sf::Drawable* cAxis::getDrawablePtr()
{
    return &drawable;
}*/

void cAxis::setExtents(const float& min, const float& max)
{
    extents.minimum = min;
    extents.maximum = max;
}

const cExtent& cAxis::getExtents() const
{
    return extents;
}

void cAxis::setTicks(const uint32_t major)
{
    majorTicks = major;
}

uint32_t cAxis::getMajorTicks() const
{
    return majorTicks;
}
