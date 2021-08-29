#include "guiconstants.h"

GUIConstants::GUIConstants()
{

}


QSize GUIConstants::getDimensions(){
    QSize * size = new QSize(this->WIDTH, this->HEIGHT);

    return *size;
}
