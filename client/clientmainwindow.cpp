#include "clientmainwindow.h"
#include "./ui_clientmainwindow.h"

#include <boost/asio.hpp>
#include <fstream>
#include <iostream>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QStandardPaths>
#include <QDebug>

#define PORT 55555
#define BUFFER_SIZE 256


using boost::asio::ip::tcp;


ClientMainWindow::ClientMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientMainWindow)
{
    ui->setupUi(this);
}

ClientMainWindow::~ClientMainWindow()
{
    delete ui;
}


void ClientMainWindow::on_choose_location_btn_clicked()
{
    QString default_path = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString dir_path = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                         default_path,
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
    if (!dir_path.isEmpty())
    {
        this->m_file_path = dir_path + "/response.txt";
                ui->choose_location_label->setText("File will be saved under this location : " + m_file_path);
    }
}

void ClientMainWindow::on_connect_to_server_btn_clicked()
{
    boost::asio::io_context io_context;

    // Create a TCP client
    tcp::socket socket(io_context);
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), PORT));

    // Open the file to be written
    //we take location from m_file_path member
    // if file path was not choosen, than we will save to default location
    std::ofstream file(m_file_path.toStdString(), std::ios::binary);

    // Receive the chunks of data and write them to the file
    char buffer[BUFFER_SIZE];
    boost::system::error_code error;
    size_t bytes_transferred;
    while (true)
    {
        bytes_transferred = socket.read_some(boost::asio::buffer(buffer), error);
        if (error == boost::asio::error::eof) {
            // End of file reached, break out of the loop
            break;
        } else if (error) {
            // An error occurred, handle it
            throw boost::system::system_error(error);
        }
        file.write(buffer, bytes_transferred);
    }


    // Close the file and the socket
    file.close();
    socket.close();

    //add some stats
    change_stats();
}


void ClientMainWindow::change_stats()
{
    ui->file_stats->setText("File Saved Successfully. Here are some stats: ");

    QString app_dir = QCoreApplication::applicationDirPath();
    qDebug() << "Application directory:" << app_dir;

    if (m_file_path == "response.txt")
        ui->choose_location_label->setText("File is saved under this location : " + app_dir + "/" + m_file_path);
    else
        ui->choose_location_label->setText("File is saved under this location : " + m_file_path);


    QFileInfo fileInfo(m_file_path);
    ui->file_size->setText("File size : "+ QString::number(fileInfo.size()) + " Bytes");
}
