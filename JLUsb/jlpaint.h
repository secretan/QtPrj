#ifndef JLPAINT_H
#define JLPAINT_H

#include <QThread>
#include <QPainter>

class JLPaint : public QThread
{
public:
    JLPaint();
    void Histogram(QImage *Image);
public slots:
    bool HistogramUpdate();
private:
    QPainter *mPainter;
};

#endif // JLPAINT_H
