#ifndef DB_DBBUILDER_H
#define DB_DBBUILDER_H


#include <memory>
#include "IDB.h"

class DBBuilder {
public:
    DBBuilder();

    std::shared_ptr<IDB> buildAllDB();
};


#endif //DB_DBBUILDER_H
