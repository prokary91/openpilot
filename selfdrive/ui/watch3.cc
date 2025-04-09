#include <QApplication>
#include <QtWidgets>

#include "selfdrive/ui/qt/qt_window.h"
#include "selfdrive/ui/qt/util.h"
#include "selfdrive/ui/qt/widgets/cameraview.h"

int main(int argc, char *argv[]) {
  initApp(argc, argv);
  int value = std::stoi(argv[1]);

  QApplication a(argc, argv);
  QWidget w;
  setMainWindow(&w);

  QVBoxLayout *layout = new QVBoxLayout(&w);
  layout->setMargin(0);
  layout->setSpacing(0);

  {
    QHBoxLayout *hlayout = new QHBoxLayout();
    layout->addLayout(hlayout);
    if (value == 1) {
      hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_DRIVER));
    } else if (value == 2) {
      hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_WIDE_ROAD));
    } else {
      hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_ROAD));
    }
  }

  /*
  {
    QHBoxLayout *hlayout = new QHBoxLayout();
    layout->addLayout(hlayout);
    hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_DRIVER));
    hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_WIDE_ROAD));
  }
  */

  return a.exec();
}
