#ifndef CLIENTMAINWINDOW_H
#define CLIENTMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientMainWindow; }
QT_END_NAMESPACE

class ClientMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClientMainWindow(QWidget *parent = nullptr);
    ~ClientMainWindow();

private slots:
    void on_choose_location_btn_clicked();

        //connects and reads from server
    void on_connect_to_server_btn_clicked();

private:
    Ui::ClientMainWindow *ui;

    QString m_file_path = "response.txt";

    void change_stats ();

};
#endif // CLIENTMAINWINDOW_H
