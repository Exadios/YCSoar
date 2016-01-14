#include "taskedit.h"
#include "ui_taskedit.h"

TaskEdit::TaskEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskEdit)
{
    ui->setupUi(this);
}

TaskEdit::~TaskEdit()
{
    delete ui;
}
