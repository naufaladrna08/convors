#ifndef __ABOUTWINDOW_H__
#define __ABOUTWINDOW_H__
#include <QtWidgets/QWidget>
#include <QtWidgets/QtWidgets>
#include <QtCore/QProcess>
#include <string>
class QPushButton;
class QTextBrowser;
class QLabel;

class AboutWindow : public QDialog {
  Q_OBJECT

  public:
    explicit AboutWindow();
    ~AboutWindow();

  private slots:
    void onClose();

  private: 
    QLabel* m_title;
    QTextBrowser* m_description;
    QPushButton* m_close;
};

#endif // __ABOUTWINDOW_H__