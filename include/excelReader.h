#ifndef EXCEL_READER_H
#define EXCEL_READER_H

#include <QObject>

#ifdef _WIN32
    #include <QAxObject>
#endif

class excelReader : public QObject
{
    Q_OBJECT

    protected:
        int rows;
        int columns;
        int readFlag;
        int reloadFlag;
        QString path;
        #ifdef _WIN32
        QAxObject* excel;
        #endif
        QVector<QVector<QString>> data;

    public:
        explicit excelReader(QObject* parent=nullptr);
        virtual ~excelReader();
        /* 判定是否已读取 excel 文件 */
        inline bool isRead() const { return readFlag==1; }
        /* 判定当前是否重新读取过 excel 文件 */
        inline bool isReload() const { return reloadFlag==1; }
        /* 返回数据数组的常引用 */
        inline const QVector<QVector<QString>>& getData() const { return this->data; };
        /* 返回数据的行数 */
        inline int getRows() const { return rows; }
        /* 返回数据的列数 */
        inline int getColumns() const { return columns; }

    public slots:
        void readExcel(const QString& pathOfExcel);

    signals:
        void readed();
        void reload();

    private:
        #ifdef _WIN32
            void initalExcel();
        #endif
};

#endif