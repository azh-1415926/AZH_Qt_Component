#pragma once
#include <QMainWindow>

class TestForQtComponent : public QMainWindow {
    Q_OBJECT

public:
    TestForQtComponent(QWidget* parent = nullptr);
    ~TestForQtComponent();
};