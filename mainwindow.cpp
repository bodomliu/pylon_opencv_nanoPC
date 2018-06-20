#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QMouseEvent>
#include <QWidget>
#include <QPen>
#include <QDebug>
#include <QToolTip>
#include <cmath>
#include <QPixmap>

//camera
#include "pylon/PylonIncludes.h"
using namespace Pylon;
using namespace cv;
//global handle
CInstantCamera camera;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->showimage->setScaledContents(true);

    //setWindowTitle(tr("polygon"));
    //setMouseTracking(true);
    //ui->showimage->installEventFilter(this);
    QPixmap px;
    px.load("D:/1.jpg");
    //ui->showimage->setPixmap(px);

    ui->label->setStyleSheet("background:transparent");
    mouseIsdown = false;
    ui->label->installEventFilter(this);
    labelx1=ui->label->rect().topLeft().x();
    labely1=ui->label->rect().topLeft().y();
    labelx2=ui->label->rect().bottomRight().x();
    labely2=ui->label->rect().bottomRight().y();

    PylonInitialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage Mat2QImage(cv::Mat cvImg)
{
    QImage qImg;
    if(cvImg.channels()==3)                             //3 channels color image
    {

        cv::cvtColor(cvImg,cvImg,CV_BGR2RGB);
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols, cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_RGB888);
    }
    else if(cvImg.channels()==1)                    //grayscale image
    {
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_Indexed8);
    }
    else
    {
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_RGB888);
    }

    return qImg;

}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{

    if(watched == ui->label )
    {
        if(event->type() == QEvent::MouseButtonPress)
        {

            QMouseEvent *mouseEvent=(QMouseEvent *)event;

            if(mouseEvent->buttons()&Qt::LeftButton)
            {
                mouseIsdown = true;

                startPos = limit(mouseEvent->pos());
            }

        }
        if(event->type() == QEvent::MouseMove)
        {
            QMouseEvent *mouseEvent=(QMouseEvent *)event;

            if(mouseIsdown)
            {
                endPos = limit(mouseEvent->pos());
                ui->label->update();
            }
        }

        if(event->type() == QEvent::MouseButtonRelease)
        {
            QMouseEvent *mouseEvent=(QMouseEvent *)event;

            endPos = limit(mouseEvent->pos());
            mouseIsdown = false;

        }
        if(event->type() == QEvent::Paint)
        {

            QPainter painter(ui->label);

            QPen pen = painter.pen();

            pen.setWidth(1);
            pen.setColor(QColor(0, 255, 0));
            //反走样
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setPen(pen);
            // 绘制直线
            //painter.drawLine(startPos, endPos);
            QRectF rectangle(startPos, endPos);
            painter.drawRect(rectangle);
        }
    }
    return QWidget::eventFilter(watched,event);
}

void MainWindow::on_select_clicked()
{
//    int n=image.width();
//    int d=image.height();
//    QPoint s1(lf.x()*n/cols,lf.y()*d/rows);
//    QPoint s2(br.x()*n/cols,br.y()*d/rows);
//    QImage rect=image.copy(s1.x(),s1.y(),s2.x()-s1.x(),s2.y()-s1.y());
//    ui->showimage->setPixmap(QPixmap::fromImage(rect));
}

void MainWindow::on_clear_clicked()
{
    qDebug("clear");
  ui->label->repaint();
}

QPointF MainWindow::limit(QPointF p)
{
    int x1=p.x();
    int y1=p.y();
    int x2,y2;

    if(x1<labelx1)
        x2=labelx1;
    else if(x1>labelx2)
        x2=labelx2;
    else
        x2=x1;

    if(y1<labely1)
        y2=labely1;
    else if(y1>labely2)
        y2=labely2;
    else
        y2=y1;

    QPointF np(x2,y2);
    return np;

}

int MainWindow::on_opencamera_clicked()
{
//    if (capture.isOpened())
//    {
//        qDebug("camera release");
//        capture.release();
//    }

//    capture.open(0);
//    qDebug("camera will be opened.");
//    if (capture.isOpened())
//    {
//        ui->opencamera->setEnabled(false);
//         qDebug("camera open success.");
//        rate = capture.get(CV_CAP_PROP_FPS);
//          qDebug("%f",rate);
//    }
//    else
//    {
//       qDebug("camera opened failed.");
//    }


    // The exit code of the sample application.
    int exitCode = 0;

    try
    {
        camera.Attach(CTlFactory::GetInstance().CreateFirstDevice());

        // Print the model name of the camera.
        qDebug()<< "Using device " << camera.GetDeviceInfo().GetModelName() << endl;

        camera.Open();
        qDebug() << camera.IsOpen() << endl;
        // The parameter MaxNumBuffer can be used to control the count of buffers
        // allocated for grabbing. The default value of this parameter is 10.
        camera.MaxNumBuffer = 5;

        ui->opencamera->setEnabled(false);
        ui->closecamera->setEnabled(true);

    }
    catch (const GenericException &e)
    {
        // Error handling.
        qDebug() << "An exception occurred." << endl<< e.GetDescription() << endl;
        exitCode = 1;
    }

    return exitCode;
}

int MainWindow::on_closecamera_clicked()
{
//    //ui->showimage->clear();
//    if (capture.isOpened())
//    {
//        capture.release();
//        ui->opencamera->setEnabled(true);
//    }
    camera.Close();
    camera.DestroyDevice();
    qDebug() << camera.IsPylonDeviceAttached() << endl;

    ui->opencamera->setEnabled(true);
    ui->closecamera->setEnabled(false);
    return 0;
}

int MainWindow::on_snapshot_clicked()
{    
//    capture >> frame;
//    if (!frame.empty())
//    {
//        image = Mat2QImage(frame);
//        //draw
//        QPixmap pixmap = QPixmap::fromImage(image.scaled(size(),Qt::KeepAspectRatio));
//        ui->showimage->setPixmap(pixmap);
////        QPainter painter(this);
////        QImage p =pixmap.toImage();
////        painter.drawImage(0,0,p);
//    }
//    else
//    {
//        qDebug("capture failed.");
//    }

        // The exit code of the sample application.
        int exitCode = 0;
        int c_countOfImagesToGrab = 1;

        //Mat opencvImage;

        try
        {
            qDebug() << "Using device " << camera.GetDeviceInfo().GetModelName() << endl;
            // Start the grabbing of c_countOfImagesToGrab images.
            // The camera device is parameterized with a default configuration which
            // sets up free-running continuous acquisition.
            camera.StartGrabbing(c_countOfImagesToGrab);

            // This smart pointer will receive the grab result data.
            CGrabResultPtr ptrGrabResult;

            // Camera.StopGrabbing() is called automatically by the RetrieveResult() method
            // when c_countOfImagesToGrab images have been retrieved.
            while (camera.IsGrabbing())
            {
                // Wait for an image and then retrieve it. A timeout of 5000 ms is used.
                camera.RetrieveResult(5000, ptrGrabResult, TimeoutHandling_ThrowException);


                // Image grabbed successfully?
                if (ptrGrabResult->GrabSucceeded())
                {
                    // Access the image data.
                    const uint8_t *pImageBuffer = (uint8_t *)ptrGrabResult->GetBuffer();

                    // Display the grabbed image by pylon viewer.
                    //Pylon::DisplayImage(1, ptrGrabResult);

                    CImageFormatConverter formatConverter;
                    //define output pixel type
                    formatConverter.OutputPixelFormat = PixelType_RGB8packed;

                    //display by QImage
                    //calculate the size of  image
                    int sizeofImage = ptrGrabResult->GetWidth() * ptrGrabResult->GetHeight() * 4;

                    //define image pointer
                    uchar* imgPtr =new uchar[sizeofImage];

                    //convert image into the defined Pixel format
                    formatConverter.Convert(imgPtr, sizeofImage, ptrGrabResult);

                    //convert the pylon image to the Qimage
                    QImage m_QimageShow = QImage(imgPtr, ptrGrabResult->GetWidth(), ptrGrabResult->GetHeight(), QImage::Format_RGB888);

                    //show the image
                    ui->showimage->setPixmap(QPixmap::fromImage(m_QimageShow));


                    //for match template
                    Mat opencvImage;
                    CPylonImage pylonImage;
                    //convert image into the defined Pixel format
                    formatConverter.Convert(pylonImage, ptrGrabResult);
                    opencvImage = cv::Mat(ptrGrabResult->GetHeight(), ptrGrabResult->GetWidth(), CV_8UC3, pylonImage.GetBuffer());

                    namedWindow("Display window", WINDOW_KEEPRATIO); // Create a window for display.
                    imshow("Display window", opencvImage); // Show our image inside it.

                    //empty the ptr
                    delete imgPtr;

                }
                else
                {
                     qDebug(ptrGrabResult->GetErrorDescription());
                }

            }

            camera.StopGrabbing();

        }
        catch (const GenericException &e)
        {
            // Error handling.
            qDebug() << "An exception occurred." << endl<< e.GetDescription() << endl;
            exitCode = 1;
        }

        return exitCode;
}

int MainWindow::on_btn_continue_clicked()
{
    if(ui->btn_continue->text()=="continue")
    {
        qDebug("continue");
        ui->btn_continue->setText("stop");

        // The exit code of the sample application.
        int exitCode = 0;

        //Mat opencvImage;

        try
        {

            // Start the grabbing of c_countOfImagesToGrab images.
            // The camera device is parameterized with a default configuration which
            // sets up free-running continuous acquisition.
            camera.StartGrabbing(GrabStrategy_OneByOne,GrabLoop_ProvidedByUser);

            // This smart pointer will receive the grab result data.
            CGrabResultPtr ptrGrabResult;

            // Camera.StopGrabbing() is called automatically by the RetrieveResult() method
            // when c_countOfImagesToGrab images have been retrieved.
            while (camera.IsGrabbing())
            {
                // Wait for an image and then retrieve it. A timeout of 5000 ms is used.
                camera.RetrieveResult(5000, ptrGrabResult, TimeoutHandling_ThrowException);

                // Image grabbed successfully?
                if (ptrGrabResult->GrabSucceeded())
                {
                    // Access the image data.
                    const uint8_t *pImageBuffer = (uint8_t *)ptrGrabResult->GetBuffer();

                    CImageFormatConverter formatConverter;

                    //define output pixel type
                    formatConverter.OutputPixelFormat = PixelType_RGB8packed;

                    //calculate the size of image
                    int sizeofImage = ptrGrabResult->GetWidth() * ptrGrabResult->GetHeight() * 4;

                    //define image pointer
                    uchar* imgPtr = new uchar[sizeofImage];

                    //convert image into the defined Pixel format
                    formatConverter.Convert(imgPtr, sizeofImage, ptrGrabResult);

                    QCoreApplication::processEvents();
                    //convert the pylon image to the Qimage
                    QImage m_QimageShow = QImage(imgPtr, ptrGrabResult->GetWidth(), ptrGrabResult->GetHeight(), QImage::Format_RGB888);

                    //show the image
                    ui->showimage->setPixmap(QPixmap::fromImage(m_QimageShow));

                    //empty the ptr
                    delete imgPtr;


                }
                else
                {
                    qDebug(ptrGrabResult->GetErrorDescription());
                }
            }
        }
        catch (const GenericException &e)
        {
            // Error handling.
            qDebug() << "An exception occurred." << endl << e.GetDescription() << endl;
            exitCode = 1;
        }
        return exitCode;
    }
    else
    {

        camera.StopGrabbing();

        qDebug("Stop");
        ui->btn_continue->setText("continue");

        return 0;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //Releases all pylon resources.
    PylonTerminate();
}
