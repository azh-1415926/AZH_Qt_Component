#include "TestForQtComponent.h"

#include <settingFile.hpp>
#include <collectbutton.h>
#include <clickoptions.h>
#include <QGridLayout>
#include <QCryptographicHash>

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
            new collectButton,
            new QLabel("status")
        },
        {
            new clickOptions,
            new QLabel("answer")
        }
    };
    for(int i=0;i<components.length();i++)
    {
        QWidget* w=createTestWidget("TestWidget-"+QString::number(i+1));
        for(int j=0;j<components.at(i).length();j++)
        {
            static_cast<QGridLayout*>(w->layout())->addWidget(components.at(i).at(j),0,j);
        }
        windows.push_back(w);
    }
    /* TestWidget-1 */
    collectButton* collectBtn=static_cast<collectButton*>(windows.at(0)->children().at(1));
    QLabel* collectLabel=static_cast<QLabel*>(windows.at(0)->children().at(2));
    connect(collectBtn,&collectButton::collected,[=]()
    {
        collectLabel->setText("已收藏");
    });
    connect(collectBtn,&collectButton::uncollected,[=]()
    {
        collectLabel->setText("未收藏");
    });
    /* TestWidget-2 */
    clickOptions* options=static_cast<clickOptions*>(windows.at(1)->children().at(1));
    QLabel* optionLabel=static_cast<QLabel*>(windows.at(1)->children().at(2));
    connect(options,&clickOptions::selectOption,[=](int i)
    {
        optionLabel->setText(QString(static_cast<char>(i+'A')));
    });
    testCalcMD5("azh40237040");
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

void TestForQtComponent::testCalcMD5(const QString& str)
{
    QString md5 = QCryptographicHash::hash(str.toLatin1(),QCryptographicHash::Md5).toHex();
    qDebug()<<md5;
}