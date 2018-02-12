#ifndef CALCBUTTON_H
#define CALCBUTTON_H

#include <QToolButton>
#include <QWidget>

/**
 * @brief The CalcButton class is an extension of QToolButton, it's useful to create a button with an image faster.
 * It contains also methods to update or resize the button icon.
 */
class CalcButton: public QToolButton
{
private:
    QPixmap* pixmap_ref = nullptr;
public:
    CalcButton(const QString &text, const QString &ImagePath, QWidget *parent, const QSize& size = QSize(-1,-1));
    CalcButton(const QString &ImagePath, QWidget *parent, const QSize& size);
    CalcButton(const QString &text, QWidget *parent = nullptr);

    ~CalcButton();

    void resize_icon(const QSize& size);
    QPixmap* getPixmapRef() const;
    void update_icon(const QString &ImagePath, const QSize& size = QSize(-1,-1));
    void update_icon(const QPixmap* PixmapRef, const QSize& size = QSize(-1,-1));
};

#endif // CALCBUTTON_H
