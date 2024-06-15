#include "widget.h"
#include "ui_widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpacerItem>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QGridLayout *mainGridLayout = new QGridLayout();
    QHBoxLayout *buttonHBoxLayout = new QHBoxLayout();
    QVBoxLayout *paraVBoxLayout = new QVBoxLayout();
    QFormLayout *infoFormLayout = new QFormLayout();

    QLabel *infoLabel = new QLabel();
    infoLabel->setText(QString::fromUtf8("个人信息"));
    QFont font("Microsoft YaHei", 10, 50);
    infoLabel->setFont(font);

    QLineEdit *nameLineEdit = new QLineEdit();
    QLineEdit *sexLineEdit = new QLineEdit();
    QLineEdit *ageLineEdit = new QLineEdit();
    QLineEdit *phoneLineEdit = new QLineEdit();
    QLineEdit *emailLineEdit = new QLineEdit();

    infoFormLayout->addRow(QString::fromUtf8("姓名"), nameLineEdit);
    infoFormLayout->addRow(QString::fromUtf8("性别"), sexLineEdit);
    infoFormLayout->addRow(QString::fromUtf8("年龄"), ageLineEdit);
    infoFormLayout->addRow(QString::fromUtf8("电话"), phoneLineEdit);
    infoFormLayout->addRow(QString::fromUtf8("邮箱"), emailLineEdit);
    infoFormLayout->setSpacing(50);
    infoFormLayout->setContentsMargins(10, 10, 40, 30);

    QLabel *paraLabel = new QLabel();
    paraLabel->setText(QString::fromUtf8("测量参数"));
    paraLabel->setFont(font);

    QCheckBox *tempCheckBox = new QCheckBox();
    QCheckBox *nibpCheckBox = new QCheckBox();
    QCheckBox *ecgCheckBox = new QCheckBox();
    QCheckBox *respCheckBox = new QCheckBox();
    QCheckBox *spo2CheckBox = new QCheckBox();

    tempCheckBox->setText(QString::fromUtf8("体温"));
    nibpCheckBox->setText(QString::fromUtf8("血压"));
    ecgCheckBox->setText(QString::fromUtf8("心电"));
    respCheckBox->setText(QString::fromUtf8("呼吸"));
    spo2CheckBox->setText(QString::fromUtf8("血氧"));

    paraVBoxLayout->addWidget(tempCheckBox);
    paraVBoxLayout->addWidget(nibpCheckBox);
    paraVBoxLayout->addWidget(ecgCheckBox);
    paraVBoxLayout->addWidget(respCheckBox);
    paraVBoxLayout->addWidget(spo2CheckBox);
    paraVBoxLayout->setSpacing(50);
    paraVBoxLayout->setContentsMargins(10, 10, 40, 30);

    QSpacerItem *verticalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *okButton = new QPushButton();
    QPushButton *cancelButton = new QPushButton();

    okButton->setText(QString::fromUtf8("确定"));
    cancelButton->setText(QString::fromUtf8("取消"));

    buttonHBoxLayout->addWidget(okButton);
    buttonHBoxLayout->addWidget(cancelButton);

    mainGridLayout->addWidget(infoLabel, 0, 0, 1, 1);
    mainGridLayout->addWidget(paraLabel, 0, 1, 1, 1);
    mainGridLayout->addLayout(infoFormLayout, 1, 0, 5, 1);
    mainGridLayout->addLayout(paraVBoxLayout, 1, 1, 5, 1);
    mainGridLayout->addItem(verticalSpacer, 6, 0, 1, 2);
    mainGridLayout->addLayout(buttonHBoxLayout, 7, 0, 1, 2);

    setWindowTitle("LayoutTest");
    setLayout(mainGridLayout);
}

Widget::~Widget()
{
    delete ui;
}
