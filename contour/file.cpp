#include "file.h"

File file;

void File::setFileString(QString fileString)
{
    this->FileString=fileString;
}

QString File::getFileString()
{
    return FileString;
}
