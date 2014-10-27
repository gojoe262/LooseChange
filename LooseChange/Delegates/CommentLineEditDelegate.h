#ifndef COMMENTLINEEDITDELEGATE_H
#define COMMENTLINEEDITDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QLineEdit>

class CommentLineEditDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    CommentLineEditDelegate(QObject *parent = 0);
    ~CommentLineEditDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;


    void setEditorData(QWidget *editor, const QModelIndex &index); //const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:
    void ValueChanged(QString comment, QModelIndex index) const;

};

#endif // COMMENTLINEEDITDELEGATE_H
