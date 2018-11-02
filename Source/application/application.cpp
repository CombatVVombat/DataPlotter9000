#include "application.hpp"


cApplication::cApplication(cEngine *engine)  :
    enginePtr(engine),
    serialDialog(&engine->gui),
    serialDialogController(&serialDialog, &serialPort),
    statusDialog(&engine->gui),
    statusDialogController(&statusDialog),
    sampleData()
{
    i = 0;
    std::function<void()> updateFunc = std::bind(cApplication::update, this);
    engine->addApplicationFunction(updateFunc);

    /// Test making an entity
    cEntityHandle bob = engine->world.createEntity();

    /// Test making a component manager
    cComponentManager<cComponent<int>> aComponentManagerOfInt;

    /// Test creating a component
    cComponent<int> intComponent;
    aComponentManagerOfInt.addComponent(bob, intComponent);

    /// Test getting a handle to the component
    //cComponentHandle<cComponent<int>> handle = aComponentManagerOfInt.getHandle(bob);

    //intComponent.aTestMethod();
    //handle.getPtr()->aTestMethod();









}


void cApplication::update()
{
    //statusDialogController.updateRenderTime(enginePtr->renderer.getRenderTime());
    statusDialogController.updateUpdateTime(enginePtr->getTaskTime());
    sampleData.generateSinDataPoint(i, 100);
    //plot.updateData(sampleData.data);
    i+=0.02f;
}
