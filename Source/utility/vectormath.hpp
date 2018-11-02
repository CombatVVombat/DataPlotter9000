#ifndef VECTORMATH_HPP_INCLUDED
#define VECTORMATH_HPP_INCLUDED

#include <math.h>
#include <SFML/System/Vector2.hpp>

float length(const sf::Vector2f& v);
sf::Vector2f& normalize(sf::Vector2f& v);
sf::Vector2f normalized(const sf::Vector2f& v);
sf::Vector2f leftNormal(const sf::Vector2f& v);
sf::Vector2f rightNormal(const sf::Vector2f& v);



#endif // VECTORMATH_HPP_INCLUDED
