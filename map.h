/* map.h
 * the actual map model which stores the tile information */

#include <QImage>
#include <QPixmap>
#include <string>

class Map {
    private:
        int width, height;
        int* tiles;

    public:
        Map(int width, int height);
        QPixmap getPixmap(QImage* tiles);
        void write(const std::string& filename);
};


