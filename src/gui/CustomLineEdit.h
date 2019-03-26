#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QWidget>

class QLineEdit;
class QPushButton;

class CustomLineEdit : public QWidget
{
    Q_OBJECT

    QLineEdit *lineEdit;
    QPushButton *button;

    QString originalText;

    QString GetMMValue();

public:
    explicit CustomLineEdit(bool enableUnitButton, QWidget *parent = nullptr);

    void SetText(QString text);

    QString GetText();

signals:

public slots:

private slots:
    void UpdateUnitText(bool checked);
};

#endif // CUSTOMLINEEDIT_H
