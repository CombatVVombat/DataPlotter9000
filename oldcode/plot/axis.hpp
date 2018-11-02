#ifndef AXIS_HPP_INCLUDED
#define AXIS_HPP_INCLUDED

#include <stdint.h>
#include "axis/extent.hpp"

namespace plot
{
    class cAxis
    {
    public:
    private:
        cExtent extents;
        uint32_t majorTicks;

    public:
        cAxis();
        const cExtent& getExtents() const;
        //sf::Drawable* getDrawablePtr();
        void setExtents(const float& min, const float& max);
        void setTicks(const uint32_t major);
        uint32_t getMajorTicks() const;
    private:
    };
}



#endif // AXIS_HPP_INCLUDED
