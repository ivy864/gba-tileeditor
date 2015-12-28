/* main.cpp
 * main function for the tile editor GUI */

#include <stdio.h>
#include <QMouseEvent>
#include <QMessageBox>
#include <QFileDialog>
#include "editorwindow.h"
#include "newdialog.h"
#include "ui_mainwindow.h"
#include "ui_newmap.h"

/* main entry point */
int main(int argc, char** argv) {
    /* pass flags to QT */
    QApplication app(argc, argv);

    /* load the main window ui from the one QT generates from the ui file */ 
    EditorWindow* window = new EditorWindow(&app);
    Ui_MainWindow ui;
    ui.setupUi(window);

    /* set up all the triggers */
    window->setup_triggers(&ui);

    /* set up the graphics areas */ 
    QGraphicsScene* map = new QGraphicsScene(window);
    QGraphicsScene* palette = new QGraphicsScene(window);
    window->setAreas(map, palette);

    /* set all of the icons */
    ui.actionNew->setIcon(QIcon(":/icons/new.png"));
    ui.actionOpen->setIcon(QIcon(":/icons/open.png"));
    ui.actionSave->setIcon(QIcon(":/icons/save.png"));
    ui.actionSave_As->setIcon(QIcon(":/icons/save-as.png"));
    ui.actionChange_Properties->setIcon(QIcon(":/icons/change-properties.png")); 
    ui.actionQuit->setIcon(QIcon(":/icons/quit.png"));
    ui.actionCopy->setIcon(QIcon(":/icons/copy.png"));
    ui.actionCut->setIcon(QIcon(":/icons/cut.png"));
    ui.actionPaste->setIcon(QIcon(":/icons/paste.png"));
    ui.actionUndo->setIcon(QIcon(":/icons/undo.png"));
    ui.actionRedo->setIcon(QIcon(":/icons/redo.png"));
    ui.actionShow_Grid->setIcon(QIcon(":/icons/show-grid.png"));
    ui.actionZoom_In->setIcon(QIcon(":/icons/zoom-in.png"));
    ui.actionZoom_Out->setIcon(QIcon(":/icons/zoom-out.png"));

    /* set up the scenes */
    ui.map_view->setScene(map);
    ui.map_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui.palette_view->setScene(palette);
    ui.palette_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    /* set to grey for now */
    map->addText("MAP", QFont("Arial", 20));

    /* show the window */
    window->show();

    /* set the backgrounds to gray */
    map->setBackgroundBrush(Qt::lightGray);
    palette->setBackgroundBrush(Qt::lightGray);

    /* start the program */
    return app.exec();
}

