#ifndef SERIALDIALOGCONTROLLER_HPP_INCLUDED
#define SERIALDIALOGCONTROLLER_HPP_INCLUDED

#include <map>

#include "serialdialog.hpp"
#include "../application/serialport.hpp"


class cSerialDialogController
{
public:
    cSerialDialogController(cSerialDialog *serialDialog, cSerialPort *serialPort);

    void connectToggle() const;
    void setSelectedPort() const;
    void queryPorts() const;
    void setBaudrate() const;
    void setByteSize() const;
    void setParity() const;
    void setStopBits() const;
    void setDTR() const;

private:
    cSerialDialog *serialDialog;
    cSerialPort *serialPort;

    // Widget pointers for easier access/lookups
    tgui::Button::Ptr connectButton;
    tgui::Button::Ptr queryPortsButton;
    tgui::ComboBox::Ptr portsList;
    tgui::ComboBox::Ptr baudList;
    tgui::ComboBox::Ptr byteSizeList;
    tgui::ComboBox::Ptr parityList;
    tgui::ComboBox::Ptr stopBitsList;
    tgui::ComboBox::Ptr dtrList;
};

#endif // SERIALDIALOGCONTROLLER_HPP_INCLUDED
