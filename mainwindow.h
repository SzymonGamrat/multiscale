#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

#include <table.h>
#include <color.h>
#include <grainsettings.h>
#include <grain.h>
#include <graphicsscene.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    GraphicsScene* scene;
    Table* table;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
