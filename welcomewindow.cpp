#include "WelcomeWindow.h"


WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    setupUI();
    setupConnections();

    setWindowTitle("Minesweeper — Welcome");
    setFixedSize(450, 520);
}

void WelcomeWindow::setupUI()
{
    title = new QLabel("Minesweeper", this);
    title->setAlignment(Qt::AlignCenter);

    chooseDiff = new QLabel("Choose Difficulty", this);
    chooseDiff->setAlignment(Qt::AlignCenter);

    begin = new QPushButton("Beginner\n9 × 9  10 mines", this);
    intermed = new QPushButton("Intermediate\n16 × 16  40 mines", this);
    expert = new QPushButton("Expert\n16 × 30  99 mines", this);

    howToPlay = new QPushButton("How To Play", this);
    about = new QPushButton("About", this);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget());
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(title);
    mainLayout->addWidget(chooseDiff);
    mainLayout->addSpacing(25);
    mainLayout->addWidget(begin);
    mainLayout->addWidget(intermed);
    mainLayout->addWidget(expert);
    mainLayout->addSpacing(20);

    QHBoxLayout* bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(howToPlay);
    bottomLayout->addSpacing(20);
    bottomLayout->addWidget(about);

    mainLayout->addLayout(bottomLayout);
}

void WelcomeWindow::setupConnections()
{
    connect(begin, &QPushButton::clicked, this, [this](){
        emit difficultySelected(9, 9, 10);
    });

    connect(intermed, &QPushButton::clicked, this, [this](){
        emit difficultySelected(16, 16, 40);
    });

    connect(expert, &QPushButton::clicked, this, [this](){
        emit difficultySelected(16, 30, 99);
    });

    connect(howToPlay, &QPushButton::clicked, this, [this](){
        QMessageBox::information(this, "How to Play",
                                 "• Click to reveal tiles\n"
                                 "• Right-click to place/remove flags\n"
                                 "• Numbers indicate adjacent mines\n"
                                 "• Clear all non-mine tiles to win\n"
                                 "• Avoid clicking a mine!");
    });

    connect(about, &QPushButton::clicked, this, [this](){
        QMessageBox::about(this, "About Minesweeper",
                           "Minesweeper Qt6\n\nDeveloped by: Alina Babayan");
    });
}

WelcomeWindow::~WelcomeWindow() {}
