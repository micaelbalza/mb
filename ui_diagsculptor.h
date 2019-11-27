#ifndef UI_DIAGSCULPTOR_H
#define UI_DIAGSCULPTOR_H


#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class ui_diagsculptor
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nxLabel;
    QSpinBox *nxSpinBox;
    QLabel *nyLabel;
    QSpinBox *nySpinBox;
    QLabel *nzLabel;
    QSpinBox *nzSpinBox;
    QLabel *label;

    void setupUi(QDialog *Diagsculptor)
    {
        if (Diagsculptor->objectName().isEmpty())
            Diagsculptor->setObjectName(QStringLiteral("Diagsculptor"));
        Diagsculptor->resize(427, 183);
        buttonBox = new QDialogButtonBox(Diagsculptor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 140, 371, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(Diagsculptor);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 381, 111));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nxLabel = new QLabel(formLayoutWidget);
        nxLabel->setObjectName(QStringLiteral("nxLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nxLabel);

        nxSpinBox = new QSpinBox(formLayoutWidget);
        nxSpinBox->setObjectName(QStringLiteral("nxSpinBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nxSpinBox);

        nyLabel = new QLabel(formLayoutWidget);
        nyLabel->setObjectName(QStringLiteral("nyLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, nyLabel);

        nySpinBox = new QSpinBox(formLayoutWidget);
        nySpinBox->setObjectName(QStringLiteral("nySpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nySpinBox);

        nzLabel = new QLabel(formLayoutWidget);
        nzLabel->setObjectName(QStringLiteral("nzLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, nzLabel);

        nzSpinBox = new QSpinBox(formLayoutWidget);
        nzSpinBox->setObjectName(QStringLiteral("nzSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, nzSpinBox);

        label = new QLabel(Diagsculptor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 0, 261, 17));

        retranslateUi(Diagsculptor);
        QObject::connect(buttonBox, SIGNAL(accepted()), Diagsculptor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Diagsculptor, SLOT(reject()));

        QMetaObject::connectSlotsByName(Diagsculptor);
    } // setupUi

    void retranslateUi(QDialog *DialogCreateSculpt)
    {
        DialogCreateSculpt->setWindowTitle(QApplication::translate("DialogCreateSculpt", "Dialog", Q_NULLPTR));
        nxLabel->setText(QApplication::translate("DialogCreateSculpt", "nx", Q_NULLPTR));
        nyLabel->setText(QApplication::translate("DialogCreateSculpt", "ny", Q_NULLPTR));
        nzLabel->setText(QApplication::translate("DialogCreateSculpt", "nz", Q_NULLPTR));
        label->setText(QApplication::translate("DialogCreateSculpt", "Dimens\303\265es da escultura", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Diagsculptor: public ui_diagsculptor {

    };
}

QT_END_NAMESPACE


#endif // UI_DIAGSCULPTOR_H
