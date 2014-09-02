#ifndef TYPE_H
#define TYPE_H

enum Type
{
    IN = 0,
    OUT = 1
};

class Type
{
public:
    Type ();
    Type(int inTransactionTypeCode);

private:
    int transactionTypeCode;
};






#endif // TYPE_H
