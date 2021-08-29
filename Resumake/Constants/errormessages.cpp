#include "errormessages.h"

ErrorMessages::ErrorMessages()
{

}


QString ErrorMessages::getErrorMessage(int messageNum){
    return *errorMessages[messageNum];
}
