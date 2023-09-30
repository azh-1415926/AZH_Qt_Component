#pragma once
#include <QMainWindow>
#include <QLabel>

class TestForQtComponent : public QMainWindow {
    Q_OBJECT

private:
    QLabel* labelOfTest1;

public:
    TestForQtComponent(QWidget* parent = nullptr);
    ~TestForQtComponent();

private:
    void initalTestForQtComponent();
};