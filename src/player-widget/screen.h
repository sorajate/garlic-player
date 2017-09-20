#ifndef SCREEN_H
#define SCREEN_H

#include <QObject>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QDebug>
#include "logging_categories.h"

class TScreen : public QObject
{
    Q_OBJECT
public:
    explicit TScreen(QObject *parent, QDesktopWidget *dw);
    QPoint   getWholeStartPoint();
    QSize    getWholeSize();
    QPoint   getStartPointFromScreen();
    QSize    getSizeFromScreen();
    int      getActualScreenId() const;
    void     setActualScreenId(int value);
    QRect    getQRectFromScreen();
public slots:

protected:
    QDesktopWidget *desktop_widget;
    QRect           whole_display_geometry;
        int         actual_screen_id = -1;
        void calculateWholeDisplayGeometrie();
        void validateScreenId(int screen_id);
};

#endif // SCREEN_H