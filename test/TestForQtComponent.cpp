#include "TestForQtComponent.h"

#include <settingFile.h>
#include <calcMD5.hpp>
#include <collectbutton.h>
#include <clickoptions.h>

TestForQtComponent::TestForQtComponent(QWidget* parent)
    : QMainWindow(parent)
{
    this->resize(600,800);
    collectButton* btn=new collectButton(this);
    clickOptions* option=new clickOptions(this);
    labelOfTest1=new QLabel("label",this);
    labelOfTest1->setGeometry(100,0,50,50);
    option->setGeometry(200,0,200,400);
    connect(btn,&collectButton::collected,this,[&]()
    {
        labelOfTest1->setText("已收藏");
    });
    connect(btn,&collectButton::uncollected,this,[&]()
    {
        labelOfTest1->setText("取消收藏");
    });
}

TestForQtComponent::~TestForQtComponent()
{
    delete labelOfTest1;
}