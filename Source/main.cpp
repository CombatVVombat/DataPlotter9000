
#include <string>
#include <utility>

#include "application/application.hpp"
#include "engine/engine.hpp"


int main(int argc, char* argv[])
{
    cEngine engine;
    cApplication application(&engine);

    while(engine.window.isOpen())
        engine.run();

    return 0;
}
