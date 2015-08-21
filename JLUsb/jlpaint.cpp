#include "jlpaint.h"

#define HIST_DEEPLEVEL_MAX 4096

JLPaint::JLPaint()
{
    mPainter = new QPainter();
}

void JLPaint::Histogram(QImage *Image)
{
    int cols = Image->height();
    int rows = Image->width();
    unsigned short *hist = (unsigned short*)malloc(HIST_DEEPLEVEL_MAX);
    unsigned short tmp = 0;

    memset(hist,0,HIST_DEEPLEVEL_MAX);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            QRgb lPixel = Image->pixel(j,i);
            tmp = lPixel&0x00ff;
            hist[tmp] = hist[tmp]+1;
        }
    }
    for (int i = 0; i < HIST_DEEPLEVEL_MAX; i++)
    {
        mPainter->drawLine(i,0,i,hist[i]);
    }
}
