#include "UniqueKeyGenerator.h"

UniqueKeyGenerator::UniqueKeyGenerator()
{

}

UniqueKeyGenerator::~UniqueKeyGenerator()
{

}

QString UniqueKeyGenerator::GenerateUniqueKey(QList<QString> prevUsedKeys)
{
    QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    int randomStringLength = 30;

    bool done = false;
    QString randomString;
    while(!done)
    {
        randomString = "";
        for(int i = 0; i < randomStringLength; i++)
        {
            int index = qrand() % possibleCharacters.length();
            QChar nextChar = possibleCharacters.at(index);
            randomString.append(nextChar);
        }
        if(!prevUsedKeys.contains(randomString))
        {
            done = true;
        }
    }
    return randomString;
}
