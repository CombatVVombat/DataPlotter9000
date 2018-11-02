#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <utility>

#include "../engine/engine.hpp"
#include "sampledata.hpp"
#include "serialport.hpp"
#include "../gui/serialdialog.hpp"
#include "../gui/serialdialogcontroller.hpp"
#include "../gui/statusdialog.hpp"
#include "../gui/statusdialogcontroller.hpp"


/// TEMP
#include "../components/component.hpp"
#include "../components/componentmanager.hpp"

class cApplication
{
public:
    float i;
private:
    cEngine* enginePtr;
    cSerialPort serialPort;
    cSerialDialog serialDialog;
    cSerialDialogController serialDialogController;
    cStatusDialog statusDialog;
    cStatusDialogController statusDialogController;
    cSampleData sampleData;

public:
    cApplication(cEngine *engine);
    void addEntity();
private:
    void update();
};


#endif // APPLICATION_HPP_INCLUDED
