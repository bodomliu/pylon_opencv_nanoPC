#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage image;
    QPoint lf,br;
    int m,j;
    int rows,cols;

    cv::Mat frame;
    cv::VideoCapture capture;
    QImage image2;
    QTimer *timer;
    double rate;

    bool mouseIsdown;
    QPointF startPos;
    QPointF endPos;
    int labelx1,labely1,labelx2,labely2;

protected:

    void closeEvent(QCloseEvent *event);
private slots:
    void on_select_clicked();
    void on_clear_clicked();
    int on_opencamera_clicked();
    int on_closecamera_clicked();

    int on_snapshot_clicked();
    int on_btn_continue_clicked();


public slots:
    bool eventFilter(QObject *watched, QEvent *event);
    QPointF limit(QPointF p);

};

QImage Mat2QImage(cv::Mat cvImg);

#endif // MAINWINDOW_H
