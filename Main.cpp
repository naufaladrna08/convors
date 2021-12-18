#include <cstdio>
#include <QtWidgets/QtWidgets>
#include "mainWidget.hpp"

int main(int argc, char** argv) {
  QApplication a(argc, argv);

  MainWidget w;
  w.show();

  return a.exec();
}