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
    void on_SetScene_clicked();

    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_export_2_clicked();

    void on_import_2_clicked();

    void on_Inclusion_stateChanged(int arg1);

    void on_pushButton_4_clicked();

    void on_InclusionSize_valueChanged(int arg1);




    void on_Circular_button_toggled(bool checked);

    void on_Square_button_toggled(bool checked);

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_spinBox_2_valueChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_radioButton_3_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_pushButton_3_clicked();

    void on_spinBox_3_valueChanged(int arg1);

    void on_radioButton_5_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
