#include "CustomLineEdit.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>

CustomLineEdit::CustomLineEdit(bool enableUnitButton, QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->setMargin( 0 );

    lineEdit = new QLineEdit("filechooser_lineedit", this);
    layout->addWidget( lineEdit );

    if(!enableUnitButton)
    {
        return;
    }

    button = new QPushButton( "mm", this);
    button->setFixedWidth(button->fontMetrics().width( "  mm  " ) );
    button->setCheckable(true);
    connect( button, SIGNAL(toggled(bool)), this, SLOT( UpdateUnitText(bool)));
    layout->addWidget( button );
}

void CustomLineEdit::SetText(QString text)
{
    originalText = text;
    lineEdit->setText(text);
}

QString CustomLineEdit::GetText()
{
    return GetMMValue();
}

void CustomLineEdit::UpdateUnitText(bool checked)
{
    double value = lineEdit->text().toDouble();

    if(checked)
    {
        button->setText("mil");

        lineEdit->setText(QString::number(value * 0.0254));
    }
    else
    {
        button->setText("mm");

        lineEdit->setText(QString::number(value * 39.37008));
    }
}

QString CustomLineEdit::GetMMValue()
{
    QString result = lineEdit->text();

    if(button->isChecked())
    {
        double value = result.toDouble();
        result = QString::number(value * 39.37008);
    }

    return result;
}
