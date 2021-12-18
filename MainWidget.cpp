#include <QtWidgets/QtWidgets>
#include <QtCore/QDebug>
#include <unordered_map>
#include <string.h>
#include "MainWidget.hpp"

// Constructor for main widget
MainWidget::MainWidget(QWidget *parent) :
  QWidget(parent) {
  m_start = new QPushButton(tr("Start"));
  m_open = new QPushButton(tr("Open"));
  m_srcfile = new QTextBrowser();
  m_txtbrowser = new QTextBrowser();
  m_label = new QLabel(tr("Log: "));
  m_file_dialog = new QFileDialog(this);
  m_bitrate = new QComboBox();
  m_extension = new QComboBox();

  m_file_dialog->setFileMode(QFileDialog::AnyFile);
  m_srcfile->setMaximumHeight(26);
  m_srcfile->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  m_start->setDisabled(true);

  QVBoxLayout *vertical   = new QVBoxLayout;
  QHBoxLayout *row0 = new QHBoxLayout;
  QHBoxLayout *row1 = new QHBoxLayout;
  QHBoxLayout *row2 = new QHBoxLayout;
  QHBoxLayout *row3 = new QHBoxLayout;

  row0->addWidget(m_srcfile);
  row0->addWidget(m_open);
  row1->addWidget(m_bitrate);
  row1->addWidget(m_extension);
  row1->addWidget(m_start);
  row2->addWidget(m_label);
  row3->addWidget(m_txtbrowser);

  vertical->addLayout(row0);
  vertical->addLayout(row1);
  vertical->addLayout(row2);
  vertical->addLayout(row3);

  /* Bit rates */
  m_bitrate->addItem("300 kbps"); 
  m_bitrate->addItem("500 kbps"); 
  m_bitrate->addItem("1000 kbps"); 
  m_bitrate->addItem("1500 kbps"); 
  m_bitrate->addItem("2250 kbps"); 
  m_bitrate->addItem("3000 kbps");

  m_extension->addItem("mp4");
  m_extension->addItem("mkv");
  m_extension->addItem("avi");

  setLayout(vertical);
  setWindowTitle(tr("Kuring nanaonan sih?"));
  setFixedWidth(640);

  /* Connect the Button "released" signal to onButtonReleased */
  connect(m_start, SIGNAL(released()), this, SLOT(onButtonReleased()));
  connect(&m_process, SIGNAL(started()), this, SLOT(onCaptureProcessOutput()));
  connect(m_open, SIGNAL(released()), this, SLOT(onOpenFile()));
}

// Destructor
MainWidget::~MainWidget() {
  delete m_start;
  delete m_open;
  delete m_file_dialog;
  delete m_bitrate;
  delete m_extension;
  delete m_txtbrowser;
  delete m_srcfile;
  delete m_label;
}

void MainWidget::onButtonReleased() {
  /* Clear the text in Text browser */
  m_txtbrowser->clear();
  m_txtbrowser->append(tr("Running command: "));

  std::unordered_map<char*, char*> data;
  data["input"] = m_srcfile->toPlainText().toLocal8Bit().data();
  data["output"] = "ouput.mkv";
  // strcat(data["file_output"], m_extension->currentText().toLocal8Bit().data());
  data["bitrate"] = "300";

  char command[1024];
  strcpy(command, "ffmpeg -i ");
  strcat(command, data["input"]);
  strcat(command, " -vcodec libx264 -crf 20 ");
  strcat(command, data["output"]);
  strcat(command, " -b ");
  strcat(command, data["bitrate"]);
  m_txtbrowser->append(tr(command));

  /* Set up process to write to stdout and run command */
  m_process.setCurrentWriteChannel(QProcess::StandardOutput);
  m_process.start(command);

} 


void MainWidget::onCaptureProcessOutput() {
  /*
   * Determine whether the object that sent the signal was 
   * pointer to a process. 
   */
  QProcess* process = qobject_cast<QProcess*>(sender());

  bool returnBool = false;
  int i = -100;
  while (returnBool == false) {
    returnBool = process->waitForFinished(10);
    QString outputStdOut = process->readAllStandardOutput();
    QString outputStdErr = process->readAllStandardError();

    // m_txtbrowser->append(outputStdOut);
    // m_txtbrowser->append(outputStdErr);
    m_txtbrowser->append("Jalan");
    qInfo("%i", i);
    i++;
  }
}

void MainWidget::onOpenFile() {
  m_srcfile->setText(QFileDialog::getOpenFileName(this, tr("Select video file"), "/home", tr("Video Files (*)")));
  m_start->setDisabled(false);
}