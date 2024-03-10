#ifndef CLICK_LABEL_H
#define CLICK_LABEL_H

#include <QLabel>

class clickLabel : public QLabel
{
    Q_OBJECT

    private:
        ;

    public:
        explicit clickLabel(QWidget* parent = nullptr);
        virtual ~clickLabel();

    protected:
        bool eventFilter(QObject* obj,QEvent* e) override;

    public slots:
        ;

    signals:
        void clicked(const clickLabel*);
        void hover(const clickLabel*);

    private:
        #ifdef __ANDROID__
            bool touchBeginEventProcess(QEvent *e);
            bool touchUpdateEventProcess(QEvent *e);
            bool touchEndEventProcess(QEvent *e);
        #else
            bool mousePressEventProcess(QEvent* e);
        #endif
};

#endif