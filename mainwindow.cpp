#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("BMR Calculator");
    setFixedSize(400, 300);

    heightInput = new QLineEdit(this);
    heightInput->setPlaceholderText("Height (cm)");
    heightInput->setGeometry(100, 50, 200, 30);

    weightInput = new QLineEdit(this);
    weightInput->setPlaceholderText("Weight (kg)");
    weightInput->setGeometry(100, 100, 200, 30);

    ageInput = new QLineEdit(this);
    ageInput->setPlaceholderText("Age");
    ageInput->setGeometry(100, 150, 200, 30);

    formulaInput = new QComboBox(this);
    formulaInput->addItem("Harris-Benedict");
    formulaInput->addItem("Mifflin-St Jeor");
    formulaInput->setGeometry(100, 200, 200, 30);

    QPushButton *calculateButton = new QPushButton("Calculate", this);
    calculateButton->setGeometry(150, 250, 100, 30);
    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::onCalculateButtonClicked);

    resultLabel = new QLabel("BMR: ", this);
    resultLabel->setGeometry(100, 280, 200, 30);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onCalculateButtonClicked()
{
    float height = heightInput->text().toFloat();
    float weight = weightInput->text().toFloat();
    int age = ageInput->text().toInt();
    QString formula = formulaInput->currentText();

    calculateBMR(height, weight, age, formula);
}

void MainWindow::calculateBMR(float height, float weight, int age, QString formula)
{
    float bmr = 0;
    if (formula == "Harris-Benedict") {
        bmr = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    } else if (formula == "Mifflin-St Jeor") {
        bmr = 10 * weight + 6.25 * height - 5 * age + 5;
    }
    resultLabel->setText("BMR: " + QString::number(bmr));
    saveToFile(bmr, formula);
}

void MainWindow::saveToFile(float bmr, QString formula)
{
    QFile file("bmr_report.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << "BMR calculated using " << formula << " formula: " << bmr;
        file.close();
    }
}
