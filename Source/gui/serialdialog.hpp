#ifndef SERIALDIALOG_HPP_INCLUDED
#define SERIALDIALOG_HPP_INCLUDED

#include <TGUI/TGUI.hpp>
#include <utility>

class cSerialDialog
{
public:
    cSerialDialog(tgui::Gui* gui);
    tgui::Gui* guiPtr;
};



#endif // SERIALDIALOG_HPP_INCLUDED
