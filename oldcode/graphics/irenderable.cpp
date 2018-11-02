#include "irenderable.hpp"

iRenderable::iRenderable(entityIdType id)   : id(id)
{
    drawablePtr = NULL;
    transformPtr = NULL;
}

const sf::Drawable& iRenderable::getDrawable() const
{
    return *drawablePtr;
}

const sf::Transform& iRenderable::getTransform() const
{
    return *transformPtr;
}

void iRenderable::setDrawablePtr(const sf::Drawable* drawable)
{
    drawablePtr = drawable;
}

void iRenderable::setTransformPtr(const sf::Transform* transform)
{
    transformPtr = transform;
}

bool iRenderable::drawableIsNull() const
{
    if(drawablePtr == NULL)
        return true;
    else
        return false;
}

bool iRenderable::transformIsNull() const
{
    if(transformPtr == NULL)
        return true;
    else
        return false;
}

const entityIdType& iRenderable::getId() const
{
    return id;
}
