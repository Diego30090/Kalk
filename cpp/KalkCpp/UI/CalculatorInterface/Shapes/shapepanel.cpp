#include "shapepanel.h"

ShapePanel::ShapePanel(QWidget *parent): QWidget(parent)
{
    mainLayout = new QGridLayout(this);
    left = new CalcButton("", this);
    left->setArrowType(Qt::LeftArrow);
    connect(left, SIGNAL (released()), this, SLOT (PrevPage()));
    left->setMinimumSize(50,50);
    right = new CalcButton("", this);
    right->setArrowType(Qt::RightArrow);
    connect(right, SIGNAL (released()), this, SLOT (NextPage()));
    right->setMinimumSize(50,50);
    mainLayout->addWidget(left, 8,3, Qt::AlignBottom);
    mainLayout->addWidget(right, 8,4, Qt::AlignBottom);
}

ShapePanel::~ShapePanel(){
    while(pages.size()>0){
        delete pages[0];
        pages.pop_front();
    }
}

void ShapePanel::Display(int index)
{
     if(index < 0) return;

    int secondCounter = 1;

    int fromIndex = pages[index]->vIndexStart;
    int toIndex = pages[index]->vIndexEnd;
    int changeRow = 0;

    for(int i = fromIndex; i < toIndex; i++)
    {
        if(i==(buttonsPerPanel/2) + fromIndex)
        {
            secondCounter=1;
        }
        if(buttons[i]){

            if(changeRow > 4){
                 mainLayout->addWidget(buttons[i], 2, secondCounter, Qt::AlignCenter);
            }else{
                 mainLayout->addWidget(buttons[i], 1, secondCounter, Qt::AlignCenter);
            }
            buttons[i]->setVisible(true);
            changeRow++;
        }
        secondCounter++;
    }
}

void ShapePanel::Clear(int index) const
{

    if(index < 0) return;

    int fromIndex = pages[index]->vIndexStart;
    int toIndex = pages[index]->vIndexEnd;

    for(int i = fromIndex; i < toIndex; i++){
        if(buttons[i]){
            mainLayout->removeWidget(buttons[i]);
            buttons[i]->setVisible(false);
        }
    }
}

void ShapePanel::NextPage()
{

    if(currentPage == totalPages - 1)
    {
        return;
    }
    lastPage = currentPage;
    Clear(lastPage);
    currentPage++;
    Display(currentPage);
    UpdateButtons();
}

void ShapePanel::PrevPage()
{

    if(currentPage == 0)
    {
        return;
    }
    lastPage = currentPage;
    Clear(lastPage);
    currentPage--;
    Display(currentPage);
    UpdateButtons();
}

void ShapePanel::UpdateButtons() const
{
    if(currentPage == 0)
    {
        //Cannot go previous page
        left->setEnabled(false);
    }else{
        //Can go previous page
        left->setEnabled(true);
    }
    if(currentPage == totalPages - 1)
    {
        //cannot go next page
        right->setEnabled(false);
    }else{
        //can go next page
        right->setEnabled(true);
    }
}

void ShapePanel::InitCounters(){

    setLayout(mainLayout);

    for(int i = 0; i < buttons.size(); i++)
    {
        buttons[i]->setVisible(false);
    }

    fullPages = buttons.size() / buttonsPerPanel;
    lastPageCount = buttons.size() % buttonsPerPanel;

    int localIndex = 0;
    int i;
    for(i = 0; i < fullPages; i++)
    {
        pages.push_back(new Page(localIndex,localIndex+buttonsPerPanel));
        localIndex += buttonsPerPanel;
    }

    totalPages = pages.size();

    pages.push_back(new Page(localIndex,localIndex+lastPageCount));

    if(lastPageCount > 0)
        totalPages += 1;
}



void ShapePanel::SetButtons(const QVector<CalcButton*>& copy)
{
    while(buttons.size()>0)
    {
        delete buttons[0];
        buttons.pop_front();
    }
    for (QVector<CalcButton*>::const_iterator it = copy.begin() ; it != copy.end(); ++it)
    {
        buttons.push_back(*it);
    }
    InitCounters();
    Display(currentPage);
    UpdateButtons();
}


