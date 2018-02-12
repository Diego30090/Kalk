#ifndef CALCMAININTERFACE_H
#define CALCMAININTERFACE_H
#include <QWidget>
#include <QTabWidget>

/**
 * @brief The CalculatorMainInterface class is the main UI window, it create the others panel putting them in a QTabWidget
 * It also manage the Menu, so the creation of the quit/guide and others options...
 */
class CalculatorMainInterface : public QWidget
{
    Q_OBJECT
public:
    CalculatorMainInterface();

private:
    QTabWidget* TabWidget;

    static const std::string currentDateTime();
public:
    static std::string osName();
    static void PrintLog(const std::string& log);
    static QString PersonalFontName;
    static QFont getMainFont();
private slots:
    void Menu_Options();
    void Menu_Quit();
    void Menu_Guide();
    void Menu_Info();
};

#endif // CALCMAININTERFACE_H
