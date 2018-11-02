#include "serialdialog.hpp"

cSerialDialog::cSerialDialog(tgui::Gui* gui) :
    guiPtr(gui)
{
    tgui::Theme theme{"TGUI/themes/Black.txt"};

    tgui::Panel::Ptr panel = tgui::Panel::create();
    panel->setRenderer(theme.getRenderer("Panel"));
    panel->setPosition(10,458);
    panel->setSize(200,300);
    guiPtr->add(panel, "serialDialogPanel");

    tgui::Button::Ptr queryPortsButton = tgui::Button::create();
    queryPortsButton->setRenderer(theme.getRenderer("Button"));
    queryPortsButton->setPosition(10, 10);
    queryPortsButton->setSize(180, 25);
    queryPortsButton->setText("Query Ports");
    panel->add(queryPortsButton, "queryPortsButton");

    tgui::ComboBox::Ptr comboBox = tgui::ComboBox::create();
    comboBox->setRenderer(theme.getRenderer("ComboBox"));
    comboBox->setPosition(10, "queryPortsButton.bottom + 5");
    comboBox->setSize(180,25);
    panel->add(comboBox, "portsList");

    tgui::Button::Ptr connectButton = tgui::Button::create();
    connectButton->setRenderer(theme.getRenderer("Button"));
    connectButton->setPosition(10, "parent.size - 35");
    connectButton->setText("Connect");
    connectButton->setSize(180,25);
    panel->add(connectButton, "connectButton");

    tgui::Label::Ptr baudLabel = tgui::Label::create();
    baudLabel->setRenderer(theme.getRenderer("Label"));
    baudLabel->setPosition(10, "portsList.bottom + 5");
    baudLabel->setSize(80,25);
    baudLabel->setText("Baudrate");
    baudLabel->setTextSize(14);
    baudLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Right);
    baudLabel->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
    panel->add(baudLabel, "baudrateLabel");
    tgui::ComboBox::Ptr baudBox = tgui::ComboBox::create();
    baudBox->setRenderer(theme.getRenderer("ComboBox"));
    baudBox->setPosition(100, "portsList.bottom + 5");
    baudBox->setSize(90, 25);
    baudBox->addItem("4800");
    baudBox->addItem("9600");
    baudBox->addItem("14400");
    baudBox->addItem("19200");
    baudBox->addItem("38400");
    baudBox->addItem("56000");
    baudBox->addItem("115200");
    baudBox->addItem("256000");
    baudBox->addItem("512000");
    baudBox->setSelectedItem("9600");
    panel->add(baudBox, "baudrateList");

    tgui::Label::Ptr byteLabel = tgui::Label::create();
    byteLabel->setRenderer(theme.getRenderer("Label"));
    byteLabel->setPosition(10, "baudrateLabel.bottom + 5");
    byteLabel->setSize(80,25);
    byteLabel->setText("ByteSize");
    byteLabel->setTextSize(14);
    byteLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Right);
    byteLabel->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
    panel->add(byteLabel, "byteSizeLabel");
    tgui::ComboBox::Ptr byteBox = tgui::ComboBox::create();
    byteBox->setRenderer(theme.getRenderer("ComboBox"));
    byteBox->setPosition(100, "baudrateLabel.bottom + 5");
    byteBox->setSize(90, 25);
    byteBox->addItem("8");
    byteBox->setSelectedItem("8");
    panel->add(byteBox, "byteSizeList");

    tgui::Label::Ptr parityLabel = tgui::Label::create();
    parityLabel->setRenderer(theme.getRenderer("Label"));
    parityLabel->setPosition(10, "byteSizeLabel.bottom + 5");
    parityLabel->setSize(80,25);
    parityLabel->setText("Parity");
    parityLabel->setTextSize(14);
    parityLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Right);
    parityLabel->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
    panel->add(parityLabel, "parityLabel");
    tgui::ComboBox::Ptr parityBox = tgui::ComboBox::create();
    parityBox->setRenderer(theme.getRenderer("ComboBox"));
    parityBox->setPosition(100, "byteSizeLabel.bottom + 5");
    parityBox->setSize(90, 25);
    parityBox->addItem("NONE");
    parityBox->addItem("EVEN");
    parityBox->addItem("ODD");
    parityBox->addItem("MARK");
    parityBox->addItem("SPACE");
    parityBox->setSelectedItem("NONE");
    panel->add(parityBox, "parityList");

    tgui::Label::Ptr stopBitsLabel = tgui::Label::create();
    stopBitsLabel->setRenderer(theme.getRenderer("Label"));
    stopBitsLabel->setPosition(10, "parityLabel.bottom + 5");
    stopBitsLabel->setSize(80,25);
    stopBitsLabel->setText("Parity");
    stopBitsLabel->setTextSize(14);
    stopBitsLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Right);
    stopBitsLabel->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
    panel->add(stopBitsLabel, "stopBitsLabel");
    tgui::ComboBox::Ptr stopBitsBox = tgui::ComboBox::create();
    stopBitsBox->setRenderer(theme.getRenderer("ComboBox"));
    stopBitsBox->setPosition(100, "parityLabel.bottom + 5");
    stopBitsBox->setSize(90, 25);
    stopBitsBox->addItem("1");
    stopBitsBox->addItem("1.5");
    stopBitsBox->addItem("2");
    stopBitsBox->setSelectedItem("1");
    panel->add(stopBitsBox, "stopBitsList");

    tgui::Label::Ptr dtrLabel = tgui::Label::create();
    dtrLabel->setRenderer(theme.getRenderer("Label"));
    dtrLabel->setPosition(10, "stopBitsLabel.bottom + 5");
    dtrLabel->setSize(80,25);
    dtrLabel->setText("DTR Flow");
    dtrLabel->setTextSize(14);
    dtrLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Right);
    dtrLabel->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
    panel->add(dtrLabel, "dtrLabel");
    tgui::ComboBox::Ptr dtrBox = tgui::ComboBox::create();
    dtrBox->setRenderer(theme.getRenderer("ComboBox"));
    dtrBox->setPosition(100, "stopBitsLabel.bottom + 5");
    dtrBox->setSize(90, 25);
    dtrBox->addItem("Disable");
    dtrBox->addItem("Enable");
    dtrBox->addItem("Handshake");
    dtrBox->setSelectedItem("Disable");
    panel->add(dtrBox, "dtrList");
}
