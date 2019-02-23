#ifndef WIDGET_H
#define WIDGET_H

#include <QTreeView>
#include <QMap>
#include <QIcon>
#include <QStandardItemModel>

class Widget : public QObject
{
    Q_OBJECT
    
public:
    explicit Widget(QObject *parent = 0);
    ~Widget();
    void initTree();

    bool addRootTree(QStandardItemModel* model,QMap<QString, QString> &root);
    bool addNodeItem(QMap<QString, QString> &node );
private slots:
    void on_pushButton_clicked();
    //QStandardItem* getCurrentSelItem();
    void on_pushButton_2_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    QStandardItem* getTopParent(QStandardItem* item);
    QModelIndex getTopParent(QModelIndex itemIndex);
    void on_pushButton_3_clicked();

    void on_treeWidget_clicked(const QModelIndex &index);
    void treeItemChanged(QStandardItem * item);
    void treeItem_checkAllChild(QStandardItem * item,bool check = true);
    void treeItem_checkAllChild_recursion(QStandardItem * item,bool check = true);
    Qt::CheckState checkSibling(QStandardItem * item);
    void treeItem_CheckChildChanged(QStandardItem * item);


private:
    Ui::Widget *ui;
    QStandardItem* rootProject;
    QMap<QString,QIcon> m_publicIconMap;///< 存放公共图标
};

#endif // WIDGET_H
