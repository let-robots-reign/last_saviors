#ifndef DATABASE_BDDIRECTOR_H
#define DATABASE_BDDIRECTOR_H

#include <memory>
#include "IDBBuilder.h"
#include "DBServerInfo.h"

class BDDirector {
public:
    ~BDDirector();

    bool setDirector(IDBBuilder *builder);

    GameDB *buildDataBase(DBServerInfo *info);

private:
    std::unique_ptr<IDBBuilder> builder;
};


#endif //DATABASE_BDDIRECTOR_H
