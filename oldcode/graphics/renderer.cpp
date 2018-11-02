#include "renderer.hpp"

cRenderer::cRenderer(sf::RenderWindow& target)  : window(&target)
{
}

void cRenderer::draw()
{
    renderTime = timer.getElapsed();
    timer.update();
    for(renderableListIterator = renderableListBegin; renderableListIterator != renderableListEnd; ++renderableListIterator)
    {
        window->draw((*renderableListIterator)->getDrawable(), (*renderableListIterator)->getTransform());
    }
}

sf::Time cRenderer::getRenderTime() const
{
    return renderTime;
}

void cRenderer::addRenderable(const iRenderable* renderable)
{
    if((!renderable->drawableIsNull() && !renderable->transformIsNull()))
    {
        renderableList.push_back(renderable);
        renderableListBegin = renderableList.begin();
        renderableListEnd = renderableList.end();
    }
    #ifdef DEBUG
    else
    {
        std::cout << "drawable or transform NULL.\n";
    }
    #endif // DEBUG

}
