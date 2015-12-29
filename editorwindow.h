/* main.h
 * contains the class declarations
 * this has to be in a header file for QT to function */

#ifndef MAIN_H
#define MAIN_H

#include "ui_mainwindow.h"
#include "map.h"

#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>

class EditorWindow : public QMainWindow {
    Q_OBJECT

    private:
        /* pointer to the main app so we can close it */
        QApplication* app;

        /* pointers to the map and palette area */
        QGraphicsScene* map_scene;
        QGraphicsScene* palette_scene;

        /* the image used as the tile sheet */
        bool tiles_loaded;
        QImage tiles;

        /* pointer to the actual map data */
        Map* map; 

        /* the filename, and whether it is valid at all */
        bool filename_valid;
        QString  filename;

        /* used for saving stuff */
        QString get_save_name();
        void save_to_file();

    public:
        EditorWindow(QApplication* app);
        void setAreas(QGraphicsScene* map, QGraphicsScene* palette);
        void setup_triggers(Ui_MainWindow* ui);

        public slots:
            /* actions for the main window */
            void on_new( );
        void on_open( );
        void on_save( );
        void on_save_as( );
        void on_change_properties( );
        void on_quit( );
        void on_undo( );
        void on_redo( );
        void on_cut( );
        void on_copy( );
        void on_paste( );
        void on_grid( );
        void on_zoom_in( );
        void on_zoom_out( );
};

#endif
