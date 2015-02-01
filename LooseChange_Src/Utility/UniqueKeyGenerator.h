#ifndef UNIQUEKEYGENERATOR_H
#define UNIQUEKEYGENERATOR_H

#include <QString>
#include <QList>

class UniqueKeyGenerator
{
public:
    UniqueKeyGenerator();

    ~UniqueKeyGenerator();

    QString GenerateUniqueKey(QList<QString> prevUsedKeys);
};

#endif // UNIQUEKEYGENERATOR_H
