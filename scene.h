#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QObject>
#include "button.h"
#include "drum.h"
class Scene: public QGraphicsScene
{
    Q_OBJECT
public:
    int start_w;
    int start_h;
    int exit_w;
    int exit_h;
    int x;
    Scene();
    void init();
    void type1();
    void type2();
    void timer();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Button *start_btn;
    Button *exit_btn;
    Drum *drum;

public slots:
    void create();
    void change();
};

#endif // SCENE_H
