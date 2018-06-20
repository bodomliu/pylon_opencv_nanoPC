/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *showimage;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *locate_x;
    QLineEdit *line_x;
    QLabel *locate_y;
    QLineEdit *line_y;
    QPushButton *select;
    QPushButton *clear;
    QPushButton *opencamera;
    QPushButton *closecamera;
    QPushButton *snapshot;
    QPushButton *btn_continue;
    QLabel *label;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1178, 768);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        showimage = new QLabel(centralWidget);
        showimage->setObjectName(QStringLiteral("showimage"));
        showimage->setGeometry(QRect(0, 0, 800, 600));
        showimage->setFrameShape(QFrame::Box);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(840, 10, 311, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        locate_x = new QLabel(horizontalLayoutWidget);
        locate_x->setObjectName(QStringLiteral("locate_x"));

        horizontalLayout->addWidget(locate_x);

        line_x = new QLineEdit(horizontalLayoutWidget);
        line_x->setObjectName(QStringLiteral("line_x"));
        line_x->setReadOnly(true);

        horizontalLayout->addWidget(line_x);

        locate_y = new QLabel(horizontalLayoutWidget);
        locate_y->setObjectName(QStringLiteral("locate_y"));

        horizontalLayout->addWidget(locate_y);

        line_y = new QLineEdit(horizontalLayoutWidget);
        line_y->setObjectName(QStringLiteral("line_y"));
        line_y->setReadOnly(true);

        horizontalLayout->addWidget(line_y);

        select = new QPushButton(centralWidget);
        select->setObjectName(QStringLiteral("select"));
        select->setGeometry(QRect(840, 200, 151, 41));
        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(1000, 200, 151, 41));
        opencamera = new QPushButton(centralWidget);
        opencamera->setObjectName(QStringLiteral("opencamera"));
        opencamera->setGeometry(QRect(840, 250, 151, 41));
        closecamera = new QPushButton(centralWidget);
        closecamera->setObjectName(QStringLiteral("closecamera"));
        closecamera->setGeometry(QRect(1000, 250, 151, 41));
        snapshot = new QPushButton(centralWidget);
        snapshot->setObjectName(QStringLiteral("snapshot"));
        snapshot->setGeometry(QRect(840, 300, 151, 41));
        btn_continue = new QPushButton(centralWidget);
        btn_continue->setObjectName(QStringLiteral("btn_continue"));
        btn_continue->setGeometry(QRect(1000, 300, 151, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 800, 600));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1178, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        showimage->setText(QApplication::translate("MainWindow", "show image", Q_NULLPTR));
        locate_x->setText(QApplication::translate("MainWindow", "X:", Q_NULLPTR));
        locate_y->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        select->setText(QApplication::translate("MainWindow", "select", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "clear", Q_NULLPTR));
        opencamera->setText(QApplication::translate("MainWindow", "open camera", Q_NULLPTR));
        closecamera->setText(QApplication::translate("MainWindow", "close camera", Q_NULLPTR));
        snapshot->setText(QApplication::translate("MainWindow", "snapshot", Q_NULLPTR));
        btn_continue->setText(QApplication::translate("MainWindow", "continue", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
