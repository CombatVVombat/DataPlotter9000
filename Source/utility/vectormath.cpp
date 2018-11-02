#include "vectormath.hpp"

float length(const sf::Vector2f& v)
{
    return sqrtf(v.x*v.x + v.y*v.y);
}

sf::Vector2f& normalize(sf::Vector2f& v)
{
    float l = length(v);
    v.x /= l;
    v.y /= l;
    return v;
}

sf::Vector2f normalized(const sf::Vector2f& v)
{
    sf::Vector2f result;
    float l = length(v);
    result.x = v.x / l;
    result.y = v.y / l;
    return result;
}

sf::Vector2f leftNormal(const sf::Vector2f& v)
{
    sf::Vector2f result;
    result.x = -v.y;
    result.y = v.x;
    normalize(result);
    return result;
}

sf::Vector2f rightNormal(const sf::Vector2f& v)
{
    sf::Vector2f result;
    result.x = v.y;
    result.y = -v.x;
    normalize(result);
    return result;
}
