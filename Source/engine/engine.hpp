#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <TGUI/TGUI.hpp>
#include <utility>

#include "../utility/accumulator.hpp"
#include "../utility/timer.hpp"
#include "window.hpp"
#include "../world/world.hpp"

class cEngine
{
public:
    cAccumulator task;
    cTimer taskTimer;
    sf::Time taskTime;
    cTimer mainTimer;
    cRenderWindow window;
    tgui::Gui gui;
    cWorld world;

private:
    using delegate = std::function<void()>;
    std::vector<delegate> applicationFunctions;
    std::vector<delegate>::const_iterator applicationFunctionsIterator;


public:
    cEngine();
    void run();
    sf::Time getTaskTime() const;
    void addApplicationFunction(const delegate& d);

private:
    void runApplicationFunctions();
    void runProcessors();
};



#endif // ENGINE_HPP_INCLUDED
