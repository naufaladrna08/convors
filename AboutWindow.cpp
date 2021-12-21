#include "AboutWindow.hpp"

AboutWindow::AboutWindow() {
  setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
  m_title = new QLabel(tr("Convors v0.0.1"));
  m_description = new QTextBrowser;
  m_description->append("Convors is a free and lightweight video converter made with C++ and Qt5. \n\nBy Naufal Adriansyah");
  m_close = new QPushButton(tr("Close"));

  QVBoxLayout* vertical = new QVBoxLayout;
  QHBoxLayout* hbox0 = new QHBoxLayout;
  QHBoxLayout* hbox1 = new QHBoxLayout;
  QHBoxLayout* hbox2 = new QHBoxLayout;

  hbox0->addWidget(m_title);
  hbox1->addWidget(m_description);
  hbox2->addWidget(m_close);

  vertical->addLayout(hbox0);
  vertical->addLayout(hbox1);
  vertical->addLayout(hbox2);

  setLayout(vertical);

  connect(m_close, &QPushButton::pressed, this, &AboutWindow::onClose);
}

AboutWindow::~AboutWindow() {
  delete m_title;
  delete m_description;
}

void AboutWindow::onClose() {
  close();
}
