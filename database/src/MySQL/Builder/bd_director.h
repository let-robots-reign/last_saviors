#ifndef DATABASE_BDDIRECTOR_H
#define DATABASE_BDDIRECTOR_H

#include <memory>
#include "idb_builder.h"
#include "db_server_info.h"

class BDDirector {
public:
    ~BDDirector();

    bool setDirector(IDBBuilder *builder);

    GameDB *buildDataBase(DBServerInfo *info);

private:
    std::unique_ptr<IDBBuilder> builder;
};


#endif //DATABASE_BDDIRECTOR_H
