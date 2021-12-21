#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QtWidgets/QWidget>
#include <QtCore/QProcess>
#include "AboutWindow.hpp"
#include <string>
class QPushButton;
class QTextBrowser;
class QLabel;
class QFileDialog;
class QComboBox;
class QMenuBar;
class QMenu;
class QAction;

class MainWindow : public QWidget {
  Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private slots:
    void onButtonReleased();  
    void onCaptureProcessOutput();  
    void onOpenFile();  
    void onExit();
    void onAbout();

  private:
    void createActionMenu();
    void createMenu();

    QFileDialog* m_file_dialog;
    QComboBox* m_bitrate;
    QComboBox* m_extension;
    QPushButton* m_start;
    QPushButton* m_open;
    QTextBrowser* m_txtbrowser;
    QTextBrowser* m_srcfile;
    QLabel* m_label;
    QProcess m_process;

    QMenuBar* m_menu;
    QMenu* m_fileMenu;
    QMenu* m_helpMenu;
    QAction* m_actionExit;
    QAction* m_actionAbout;

    AboutWindow* mw_about;
};

#endif // __MAINWINDOW_H__