#include "serialdialogcontroller.hpp"

cSerialDialogController::cSerialDialogController(cSerialDialog *serialDialog, cSerialPort *serialPort)  :
    serialDialog(serialDialog), serialPort(serialPort)
{
    connectButton = serialDialog->guiPtr->get<tgui::Button>("connectButton");
    queryPortsButton = serialDialog->guiPtr->get<tgui::Button>("queryPortsButton");
    portsList = serialDialog->guiPtr->get<tgui::ComboBox>("portsList");
    baudList = serialDialog->guiPtr->get<tgui::ComboBox>("baudrateList");
    byteSizeList = serialDialog->guiPtr->get<tgui::ComboBox>("byteSizeList");
    parityList = serialDialog->guiPtr->get<tgui::ComboBox>("parityList");
    stopBitsList = serialDialog->guiPtr->get<tgui::ComboBox>("stopBitsList");
    dtrList = serialDialog->guiPtr->get<tgui::ComboBox>("dtrList");

    connectButton->connect("pressed", &cSerialDialogController::connectToggle, this);
    queryPortsButton->connect("pressed", &cSerialDialogController::queryPorts, this);
    portsList->connect("itemselected", &cSerialDialogController::setSelectedPort, this);
    baudList->connect("itemselected", &cSerialDialogController::setBaudrate, this);
    byteSizeList->connect("itemselected", &cSerialDialogController::setByteSize, this);
    parityList->connect("itemselected", &cSerialDialogController::setParity, this);
    stopBitsList->connect("itemselected", &cSerialDialogController::setStopBits, this);
    dtrList->connect("itemselected", &cSerialDialogController::setDTR, this);
}

void cSerialDialogController::connectToggle() const
{
    if(serialPort->isConnected())
    {
        serialPort->disconnect();
        connectButton->setText("Connect");
        queryPortsButton->setEnabled(true);
        portsList->setEnabled(true);
        baudList->setEnabled(true);
        byteSizeList->setEnabled(true);
        parityList->setEnabled(true);
        stopBitsList->setEnabled(true);
        dtrList->setEnabled(true);
    }
    else
    {
        serialPort->connect();
        if(serialPort->isConnected())
        {
            connectButton->setText("Disconnect");
            queryPortsButton->setEnabled(false);
            portsList->setEnabled(false);
            baudList->setEnabled(false);
            byteSizeList->setEnabled(false);
            parityList->setEnabled(false);
            stopBitsList->setEnabled(false);
            dtrList->setEnabled(false);
        }
    }
}

void cSerialDialogController::setSelectedPort() const
{
    serialPort->setPortName(portsList->getSelectedItem());
    std::cout << "Selected Port set to " << std::string(portsList->getSelectedItem()) << "\n";
}

void cSerialDialogController::queryPorts() const
{
    serialPort->queryPorts();
    portsList->removeAllItems();

    for(std::vector<std::string>::const_iterator iter = serialPort->getAvailablePorts().begin(); iter != serialPort->getAvailablePorts().end(); iter++)
        portsList->addItem(*iter);
}

void cSerialDialogController::setBaudrate() const
{
    std::string baudString = baudList->getSelectedItem();
    std::map<std::string, uint32_t> baudLookup;
    baudLookup["4800"] = 4800;
    baudLookup["9600"] = 9600;
    baudLookup["14400"] = 14400;
    baudLookup["19200"] = 19200;
    baudLookup["38400"] = 38400;
    baudLookup["56000"] = 56000;
    baudLookup["115200"] = 115200;
    baudLookup["256000"] = 256000;
    baudLookup["512000"] = 512000;
    uint32_t baudrate = baudLookup.find(baudString)->second;
    std::cout << "Baudrate set to " << baudrate << "\n";
    serialPort->setBaudRate(baudrate);
}

void cSerialDialogController::setByteSize() const
{
    std::string byteSizeString = byteSizeList->getSelectedItem();
    std::map<std::string, uint32_t> byteSizeLookup;
    byteSizeLookup["8"] = 8;
    uint32_t byteSize = byteSizeLookup.find(byteSizeString)->second;
    std::cout << "ByteSize set to " << byteSize << "\n";
    serialPort->setByteSize(byteSize);
}

void cSerialDialogController::setParity() const
{
    std::string parityString = parityList->getSelectedItem();
    std::map<std::string, uint32_t> parityLookup;
    parityLookup["NONE"] = 0;
    parityLookup["ODD"] = 1;
    parityLookup["EVEN"] = 2;
    parityLookup["MARK"] = 3;
    parityLookup["SPACE"] = 4;
    uint32_t parity = parityLookup.find(parityString)->second;
    std::cout << "Parity set to mode " << parity << " (" << parityString << ")\n";
    serialPort->setParity(parity);
}

void cSerialDialogController::setStopBits() const
{
    std::string stopBitsString = stopBitsList->getSelectedItem();
    std::map<std::string, uint32_t> stopBitsLookup;
    stopBitsLookup["1"] = 0;
    stopBitsLookup["1.5"] = 1;
    stopBitsLookup["2"] = 2;
    uint32_t stopBits = stopBitsLookup.find(stopBitsString)->second;
    std::cout << "StopBits set to mode " << stopBits << " (" << stopBitsString << " stop bits)\n";
    serialPort->setStopBits(stopBits);
}

void cSerialDialogController::setDTR() const
{
    std::string dtrString = dtrList->getSelectedItem();
    std::map<std::string, uint32_t> dtrLookup;
    dtrLookup["Disable"] = 0;
    dtrLookup["Enable"] = 1;
    dtrLookup["Handshake"] = 2;
    uint32_t dtr = dtrLookup.find(dtrString)->second;
    std::cout << "DTR Flow Control set to mode " << dtr << " (" << dtrString << ")\n";
    serialPort->setDTR(dtr);
}
