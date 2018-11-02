#include "node.hpp"

using namespace transform;

cNode::cNode()
{
    parent = NULL;
    local = sf::Transform::Identity;
    world = sf::Transform::Identity;
}

void cNode::addChild(cNode*const child)
{
    children.push_back(child);
    child->parent = this;
    childrenIteratorBegin = children.begin();
    childrenIteratorEnd = children.end();
}

void cNode::setLocal(const sf::Transform& t)
{
    local = t;
    update();
}

void cNode::translate(const sf::Vector2f& v)
{
    local.translate(v);
    update();
}

void cNode::update()
{
    if(parent)
    {
        world = parent->getWorld() * local;
    }
    else
    {
        world = local;
    }

    for(std::vector<cNode*>::iterator child = childrenIteratorBegin; child != childrenIteratorEnd; ++child)
    {
        (*child)->update();
    }
}

sf::Transform& cNode::getWorld()
{
    return world;
}
