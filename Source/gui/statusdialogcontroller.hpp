#ifndef STATUSDIALOGCONTROLLER_HPP_INCLUDED
#define STATUSDIALOGCONTROLLER_HPP_INCLUDED

#include "statusdialog.hpp"

class cStatusDialogController
{
public:
    cStatusDialogController(cStatusDialog *statusDialog);

    void updateRenderTime(const sf::Time& time);
    void updateUpdateTime(const sf::Time& time);

private:
    cStatusDialog* statusDialog;

    tgui::Label::Ptr renderTimeValue;
    tgui::Label::Ptr updateTimeValue;
};



#endif // STATUSDIALOGCONTROLLER_HPP_INCLUDED
