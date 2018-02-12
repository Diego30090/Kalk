#ifndef SHAPEPANEL_H
#define SHAPEPANEL_H

#include <QWidget>
#include <QVector>
#include "../../Utils/calcbutton.h"
#include <QGridLayout>

/**
 * @brief The ShapePanel class is a powerful panel, made to contains an infinite number of calcbutton (we use them to create new shapes).
 * It divide the buttons in pages, every page is made to contains 10 buttons, then the user can use right and left button to change page.
 */
class ShapePanel : public QWidget
{
    Q_OBJECT

private:
    struct Page
    {
        int vIndexStart;
        int vIndexEnd;

        Page(int vs, int ve)
        {
            vIndexStart = vs;
            vIndexEnd = ve;
        }
    };

    QVector<CalcButton*> buttons;
    QVector<Page*> pages;
    QGridLayout* mainLayout;
    CalcButton* right;
    CalcButton* left;

    int buttonsPerPanel = 10;

    int fullPages = 0;
    int lastPageCount = 0;
    int currentPage = 0;
    int lastPage = 0;
    int index = 0;
    int totalPages = 0;

    void Clear(int page) const;
    void Display(int page);
    void InitCounters();
    void UpdateButtons() const;

private slots:
    void NextPage();
    void PrevPage();
protected:
    virtual ~ShapePanel() = 0;
public:
    ShapePanel(QWidget *parent = nullptr);
    void SetButtons(const QVector<CalcButton*>&);
};

#endif // SHAPEPANEL_H
