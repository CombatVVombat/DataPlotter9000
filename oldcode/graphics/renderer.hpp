#ifndef RENDERER_HPP_INCLUDED
#define RENDERER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "irenderable.hpp"
#include "../timer.hpp"


class cRenderer
{
public:
private:
    sf::RenderWindow* window;
    sf::Time renderTime;
    cTimer timer;
    std::vector<const iRenderable*> renderableList;
    std::vector<const iRenderable*>::const_iterator renderableListIterator;
    std::vector<const iRenderable*>::const_iterator renderableListBegin;
    std::vector<const iRenderable*>::const_iterator renderableListEnd;

public:
    cRenderer(sf::RenderWindow& target);
    void draw();
    sf::Time getRenderTime() const;
    void addRenderable(const iRenderable* renderable);
private:
};


#endif // RENDERER_HPP_INCLUDED
