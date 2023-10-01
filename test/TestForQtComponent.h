#pragma once
#include <QMainWindow>
#include <QLabel>

class TestForQtComponent : public QMainWindow {
    Q_OBJECT

private:
    QList<QWidget*> windows;

public:
    TestForQtComponent(QWidget* parent = nullptr);
    ~TestForQtComponent();

protected:
    void closeEvent(QCloseEvent* e) override;

private:
    void initalTestForQtComponent();
    QWidget* createTestWidget(const QString& windowTitle="");
};