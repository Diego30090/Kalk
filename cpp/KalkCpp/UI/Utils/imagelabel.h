#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QWidget>
#include <QLabel>

/**
 * @brief The ImageLabel class is an extension of the classic QLabel, useful to create a label with an image faster.
 * It contains also methods to update the label icon.
 */
class ImageLabel: public QLabel
{
public:
    ImageLabel(const QString &text, const QString &ImagePath="", QWidget *parent=nullptr, const QSize& size = QSize(-1,-1));

    void change_image(const QString &ImagePath, const QSize& size = QSize(-1,-1));
    void change_image(const QPixmap &Image, const QSize& size = QSize(-1,-1));

    std::string GetImagePathString() const;
private:
    std::string img_path;
};

#endif // IMAGELABEL_H
