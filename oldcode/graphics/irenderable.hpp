#ifndef IRENDERABLE_HPP_INCLUDED
#define IRENDERABLE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "../entityid.hpp"

class iRenderable
{
public:
private:
    entityIdType id;
    const sf::Drawable* drawablePtr;
    const sf::Transform* transformPtr;

public:
    iRenderable(entityIdType id);
    const sf::Drawable& getDrawable() const;
    const sf::Transform& getTransform() const;
    void setDrawablePtr(const sf::Drawable* drawable);
    void setTransformPtr(const sf::Transform* transform);
    bool drawableIsNull() const;
    bool transformIsNull() const;
    const entityIdType& getId() const;
private:
};



#endif // IRENDERABLE_HPP_INCLUDED
