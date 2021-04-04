#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void instructions();
    void quit();
    void about();

private:
    void createActions();
    void createMenus();

    QMenu *helpMenu;
    QMenu *quitMenu;
    QAction *instructionsAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *quitAct;
};

#endif // MAINWINDOW_H
