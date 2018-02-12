#ifndef GUIDEWINDOW_H
#define GUIDEWINDOW_H

#include <QWidget>

/**
 * @brief The GuideWindow class is a simple window to show a guide about how to use the UI.
 */
class GuideWindow : public QWidget
{
public:
    GuideWindow(QWidget *parent = nullptr);
};

#endif // GUIDEWINDOW_H
