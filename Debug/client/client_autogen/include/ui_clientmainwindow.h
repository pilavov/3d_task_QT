/********************************************************************************
** Form generated from reading UI file 'clientmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTMAINWINDOW_H
#define UI_CLIENTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *choose_location_btn;
    QCommandLinkButton *connect_to_server_btn;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *file_stats;
    QTextBrowser *choose_location_label;
    QLabel *file_size;
    QLabel *label;

    void setupUi(QMainWindow *ClientMainWindow)
    {
        if (ClientMainWindow->objectName().isEmpty())
            ClientMainWindow->setObjectName(QString::fromUtf8("ClientMainWindow"));
        ClientMainWindow->resize(819, 600);
        centralwidget = new QWidget(ClientMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(160, 10, 521, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        choose_location_btn = new QPushButton(verticalLayoutWidget);
        choose_location_btn->setObjectName(QString::fromUtf8("choose_location_btn"));
        QFont font;
        font.setPointSize(14);
        choose_location_btn->setFont(font);

        verticalLayout->addWidget(choose_location_btn);

        connect_to_server_btn = new QCommandLinkButton(verticalLayoutWidget);
        connect_to_server_btn->setObjectName(QString::fromUtf8("connect_to_server_btn"));
        connect_to_server_btn->setFont(font);

        verticalLayout->addWidget(connect_to_server_btn);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        file_stats = new QLabel(verticalLayoutWidget);
        file_stats->setObjectName(QString::fromUtf8("file_stats"));
        file_stats->setFont(font);

        verticalLayout_2->addWidget(file_stats);

        choose_location_label = new QTextBrowser(verticalLayoutWidget);
        choose_location_label->setObjectName(QString::fromUtf8("choose_location_label"));
        choose_location_label->setMaximumSize(QSize(16777215, 60));

        verticalLayout_2->addWidget(choose_location_label);

        file_size = new QLabel(verticalLayoutWidget);
        file_size->setObjectName(QString::fromUtf8("file_size"));
        file_size->setFont(font);

        verticalLayout_2->addWidget(file_size);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);


        verticalLayout->addLayout(verticalLayout_2);

        ClientMainWindow->setCentralWidget(centralwidget);

        retranslateUi(ClientMainWindow);

        QMetaObject::connectSlotsByName(ClientMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientMainWindow)
    {
        ClientMainWindow->setWindowTitle(QApplication::translate("ClientMainWindow", "ClientMainWindow", nullptr));
        choose_location_btn->setText(QApplication::translate("ClientMainWindow", "Choose location to save file", nullptr));
        connect_to_server_btn->setText(QApplication::translate("ClientMainWindow", "Connect to Server", nullptr));
        file_stats->setText(QApplication::translate("ClientMainWindow", "File stats :", nullptr));
        choose_location_label->setHtml(QApplication::translate("ClientMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">File is saved under this location :</span></p></body></html>", nullptr));
        file_size->setText(QApplication::translate("ClientMainWindow", "File size :", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ClientMainWindow: public Ui_ClientMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTMAINWINDOW_H
