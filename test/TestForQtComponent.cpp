#include "TestForQtComponent.h"

#include <settingFile.h>

TestForQtComponent::TestForQtComponent(QWidget* parent)
    : QMainWindow(parent)
{
    settingFile setting;
    setting.add("test",123);
    setting.save("test.json");
}

TestForQtComponent::~TestForQtComponent()
{
}