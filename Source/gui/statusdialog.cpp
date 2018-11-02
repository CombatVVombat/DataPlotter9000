#include "statusdialog.hpp"

cStatusDialog::cStatusDialog(tgui::Gui* gui)    :
    guiPtr(gui)
{
    tgui::Theme theme{"TGUI/themes/Black.txt"};
    tgui::Panel::Ptr panel = tgui::Panel::create();
    panel->setRenderer(theme.getRenderer("Panel"));
    panel->setPosition(215,458);
    panel->setSize(200,300);
    guiPtr->add(panel, "statusDialogPanel");

    tgui::Label::Ptr renderTimeLabel = tgui::Label::create();
    renderTimeLabel->setRenderer(theme.getRenderer("Label"));
    renderTimeLabel->setPosition(10, 10);
    renderTimeLabel->setSize(75, 25);
    renderTimeLabel->setText("Render: ");
    renderTimeLabel->setTextSize(14);
    renderTimeLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Right);
    renderTimeLabel->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
    panel->add(renderTimeLabel, "renderTimeLabel");
    tgui::Label::Ptr renderTimeValue = tgui::Label::create();
    renderTimeValue->setRenderer(theme.getRenderer("Label"));
    renderTimeValue->setPosition("renderTimeLabel.right + 10" ,"renderTimeLabel.top");
    renderTimeValue->setSize(75,25);
    renderTimeValue->setText("XX");
    renderTimeValue->setTextSize(14);
    renderTimeValue->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Right);
    renderTimeValue->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
    panel->add(renderTimeValue, "renderTimeValue");

    tgui::Label::Ptr updateTimeLabel = tgui::Label::create();
    updateTimeLabel->setRenderer(theme.getRenderer("Label"));
    updateTimeLabel->setPosition(10, "renderTimeLabel.bottom + 10");
    updateTimeLabel->setSize(75,25);
    updateTimeLabel->setText("Update: ");
    updateTimeLabel->setTextSize(14);
    updateTimeLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Right);
    updateTimeLabel->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
    panel->add(updateTimeLabel, "updateTimeLabel");

    tgui::Label::Ptr updateTimeValue = tgui::Label::create();
    updateTimeValue->setRenderer(theme.getRenderer("Label"));
    updateTimeValue->setPosition("updateTimeLabel.right + 10" ,"updateTimeLabel.top");
    updateTimeValue->setSize(75,25);
    updateTimeValue->setText("XX");
    updateTimeValue->setTextSize(14);
    updateTimeValue->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Right);
    updateTimeValue->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
    panel->add(updateTimeValue, "updateTimeValue");


}
