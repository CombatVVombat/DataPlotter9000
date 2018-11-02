#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <vector>
#include <SFML/Graphics/Transform.hpp>

namespace transform
{
    class cNode
    {
    public:
    private:
        sf::Transform local;
        sf::Transform world;
        cNode* parent;
        std::vector<cNode*> children;
        std::vector<cNode*>::iterator childrenIteratorBegin;
        std::vector<cNode*>::iterator childrenIteratorEnd;
    public:
        cNode();
        void addChild(cNode*const child);
        void setLocal(const sf::Transform& t);
        void setParent(cNode* parent);
        void translate(const sf::Vector2f& v);
        void update();
        sf::Transform& getWorld();
    private:
    };
}



#endif // NODE_HPP_INCLUDED
