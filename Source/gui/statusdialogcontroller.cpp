#include "statusdialogcontroller.hpp"

cStatusDialogController::cStatusDialogController(cStatusDialog* statusDialog)    :
    statusDialog(statusDialog)
{
    renderTimeValue = statusDialog->guiPtr->get<tgui::Label>("renderTimeValue");
    updateTimeValue = statusDialog->guiPtr->get<tgui::Label>("updateTimeValue");
}

void cStatusDialogController::updateRenderTime(const sf::Time& time)
{
    std::string value = std::to_string(time.asMicroseconds()) + " us";
    renderTimeValue->setText(value);
}

void cStatusDialogController::updateUpdateTime(const sf::Time& time)
{
    std::string value = std::to_string(time.asMicroseconds()) + " us";
    updateTimeValue->setText(value);
}
