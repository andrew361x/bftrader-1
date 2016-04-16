#ifndef NOFOCUSDELEGATE_H
#define NOFOCUSDELEGATE_H

#include <QStyledItemDelegate>
#include <QTableWidget>
#include <QHeaderView>

class NoFocusDelegate : public QStyledItemDelegate{
    Q_OBJECT

public:
    explicit NoFocusDelegate(QObject *parent = Q_NULLPTR):QStyledItemDelegate(parent){}
    ~NoFocusDelegate(){}
    void paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex &index) const Q_DECL_OVERRIDE {
       QStyleOptionViewItem itemOption(option);
       if (itemOption.state & QStyle::State_HasFocus){
          itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
       }
       QStyledItemDelegate::paint(painter, itemOption, index);
    }
};

void bfAdjustTableWidget(QTableWidget* tableWidget);


#endif // NOFOCUSDELEGATE_H
