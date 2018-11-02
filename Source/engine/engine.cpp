#include "engine.hpp"

cEngine::cEngine() :
    task(100),
    window(sf::VideoMode(1024,768), "Data Plotter 9000"),
    gui(window)
{
}

void cEngine::run()
{
    mainTimer.update();
    task.update(mainTimer.getCurrent());

    while(task.isTimeToRun())
    {
        taskTime = taskTimer.getElapsed();
        taskTimer.update();
        while(window.pollEvent(window.event))
        {
            window.handleEvent(window.event);
            gui.handleEvent(window.event);
        }
        runApplicationFunctions();
        task.hasRun();
    }

    window.clear(sf::Color::White);
    gui.draw();
    window.display();
}

void cEngine::addApplicationFunction(const delegate& d)
{
    applicationFunctions.push_back(d);
}

void cEngine::runApplicationFunctions()
{
    for(applicationFunctionsIterator = applicationFunctions.begin(); applicationFunctionsIterator != applicationFunctions.end(); applicationFunctionsIterator++)
    {
        (*applicationFunctionsIterator)();
    }
}

sf::Time cEngine::getTaskTime() const
{
    return taskTime;
}
