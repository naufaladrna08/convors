#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QtWidgets/QWidget>
#include <QtCore/QProcess>
#include <string>
class QPushButton;
class QTextBrowser;
class QLabel;
class QFileDialog;
class QComboBox;

class MainWidget : public QWidget {
  Q_OBJECT

  public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

  private slots:
    void onButtonReleased();  
    void onCaptureProcessOutput();  
    void onOpenFile();  

  private:
    QFileDialog* m_file_dialog;
    QComboBox* m_bitrate;
    QComboBox* m_extension;
    QPushButton* m_start;
    QPushButton* m_open;
    QTextBrowser* m_txtbrowser;
    QTextBrowser* m_srcfile;
    QLabel* m_label;
    QProcess m_process;
};

#endif // __MAINWINDOW_H__