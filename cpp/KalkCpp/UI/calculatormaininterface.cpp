#include "calculatormaininterface.h"
#include <iostream>
#include <QBoxLayout>
#include <QMenuBar>
#include <QMessageBox>
#include <QCoreApplication>
#include "CalculatorInterface/calculatordrawinterface.h"
#include "CalculatorInterface/calculatorinterface2d.h"
#include "CalculatorInterface/calculatorinterface3d.h"
#include <QFontDatabase>
#include "OtherWindows/settingswindow.h"
#include "OtherWindows/aboutuswindow.h"
#include "OtherWindows/guidewindow.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>

QString CalculatorMainInterface::PersonalFontName = "Roboto";

CalculatorMainInterface::CalculatorMainInterface()
{
    //---------------------------------------------------------------------
    PrintLog("START MainInterface INITIALIZATION");
    int id = QFontDatabase::addApplicationFont(":/fonts/Roboto");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    PrintLog("ADDED FONT FAMILY:"+family.toStdString());
    QFont r_font = QFont(family);
    //---------------------------------------------------------------------

    TabWidget = new QTabWidget();
    TabWidget->setFont(r_font);
    TabWidget->resize(200,200);

    CalculatorInterface2D* ref_2d = new CalculatorInterface2D(this);
    CalculatorDrawInterface* draw_ref = new CalculatorDrawInterface(this);
    ref_2d->SetDrawInterfaceRef(draw_ref);
    TabWidget->addTab(ref_2d,QIcon(QPixmap(":/icons/2d")), "2D");
    TabWidget->addTab(new CalculatorInterface3D(this),QIcon(QPixmap(":/icons/3d")), "3D");
    TabWidget->addTab(draw_ref,QIcon(QPixmap(":/icons/2d")), "2D Draw");

    TabWidget->setCurrentIndex(0);
    //--------------------------------------------------------------------
    QMenuBar* menu = new QMenuBar(this);
    menu->setFont(r_font);
    QMenu* under_menu = new QMenu("File", this);
    under_menu->setFont(r_font);
    QAction* Options_Menu = new QAction("Opzioni", under_menu);
    Options_Menu->setFont(r_font);
    QAction* Quit_Menu = new QAction("Esci", under_menu);
    Quit_Menu->setFont(r_font);
    QMenu* info_menu = new QMenu("?", this);
    info_menu->setFont(r_font);
    QAction* tutorial_Menu = new QAction("Guida", info_menu);
    tutorial_Menu->setFont(r_font);
    QAction* about_Menu = new QAction("Informazioni", info_menu);
    about_Menu->setFont(r_font);
    under_menu->addAction(Options_Menu);
    under_menu->addAction(Quit_Menu);
    connect(Options_Menu, SIGNAL (triggered()), this, SLOT (Menu_Options()));
    connect(Quit_Menu, SIGNAL (triggered()), this, SLOT (Menu_Quit()));
    connect(tutorial_Menu, SIGNAL (triggered()), this, SLOT (Menu_Guide()));
    connect(about_Menu, SIGNAL (triggered()), this, SLOT (Menu_Info()));
    menu->addMenu(under_menu);
    info_menu->addAction(tutorial_Menu);
    info_menu->addAction(about_Menu);
    menu->addMenu(info_menu);
    //---------------------------------------------------------------------
    QBoxLayout* layout = new QBoxLayout(QBoxLayout::Direction::TopToBottom,this);

    layout->addWidget(menu);
    layout->addWidget(TabWidget);
    //---------------------------------------------------------------------
    setLayout(layout);
    std::string os = osName();
    PrintLog("OS FOUND: "+os);
    if(os=="linux" || os=="unix"){
        setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //block resize
        QSize size = QSize(width()+200, height()+80);
        setMinimumSize(size);
        setMaximumSize(size);
    }else{
        if(os=="windows"){
            setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //block resize
        }else{
            PrintLog("OS UNKNOWN");
        }
    }
    //Adjust window size and position
    adjustSize();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));
    //Title and icon
    setWindowTitle("Kalk - Geometry Calculator");
    setWindowIcon(QIcon(QPixmap(":/icons/program_icon")));
}
//---------------------------------------------------------------------
void CalculatorMainInterface::Menu_Options()
{
    SettingsWindow* settW = new SettingsWindow(this);
    settW->show();
}
void CalculatorMainInterface::Menu_Quit()
{
    //let's put it in a class
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Esci", "Sei sicuro?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        PrintLog("MainInterface - Quitting");
        QCoreApplication::quit();
    }
}
void CalculatorMainInterface::Menu_Guide()
{
    GuideWindow* guideW = new GuideWindow(this);
    guideW->show();
}

void CalculatorMainInterface::Menu_Info()
{
    AboutUsWindow* aboutW = new AboutUsWindow(this);
    aboutW->show();
}

//---------------------------------------------------------------------
std::string CalculatorMainInterface::osName()
{
#if defined(Q_OS_MACOS)
return "macos";
#elif defined(Q_OS_WIN)
return "windows";
#elif defined(Q_OS_LINUX)
return "linux";
#elif defined(Q_OS_UNIX)
return "unix";
#else
return "unknown";
#endif
}
//---------------------------------------------------------------------
// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string CalculatorMainInterface::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
QFont CalculatorMainInterface::getMainFont(){
    return QFont(PersonalFontName);
}
//---------------------------------------------------------------------
void CalculatorMainInterface::PrintLog(const std::string& log)
{
    std::cout<<currentDateTime()<<"-->"<<log<<std::endl;
}
//---------------------------------------------------------------------
