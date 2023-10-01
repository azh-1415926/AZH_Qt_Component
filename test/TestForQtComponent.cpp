#include "TestForQtComponent.h"

#include <settingFile.h>
#include <calcMD5.hpp>
#include <collectbutton.h>
#include <clickoptions.h>
#include <QGridLayout>

TestForQtComponent::TestForQtComponent(QWidget* parent)
    : QMainWindow(parent)
{
    initalTestForQtComponent();
}

TestForQtComponent::~TestForQtComponent()
{
    for(QWidget* i: windows)
        delete i;
}

void TestForQtComponent::closeEvent(QCloseEvent *e)
{
    for(QWidget* i: windows)
        i->close();
}

void TestForQtComponent::initalTestForQtComponent()
{
    this->resize(500,500);
    QList<QList<QWidget*>> components=
    {
        {
            new collectButton
        },
        {
            new clickOptions
        }
    };
    for(int i=0;i<components.length();i++)
    {
        QWidget* w=createTestWidget("TestWidget-"+QString::number(i+1));
        for(int j=0;j<components.at(i).length();j++)
        {
            w->layout()->addWidget(components.at(i).at(j));
        }
        windows.push_back(w);
    }
    for(QWidget* i: windows)
        i->show();
}

QWidget *TestForQtComponent::createTestWidget(const QString& windowTitle)
{
    QWidget* w=new QWidget;
    w->setWindowTitle(windowTitle);
    w->resize(500,500);
    w->setLayout(new QGridLayout);
    return w;
}