#include "formatterfactory.h"

FormatterFactory::FormatterFactory()
{

}


PdfFormatter * FormatterFactory::getFormatter(int id){
    PdfFormatter * f;
    if(id==0){
        f= new DefaultFormatter();
    }else if(id==1){
        f= new ElegantFormatter();
    }else if (id==2) {
        f= new TechFormatter();
    }else if(id==3){
        f= new FancyFormatter();
    }
    else{
        f= new DefaultFormatter();
    }
    return f;
}
