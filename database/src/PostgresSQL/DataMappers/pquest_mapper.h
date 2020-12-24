#ifndef DATABASE_PQUESTMAPPER_H
#define DATABASE_PQUESTMAPPER_H


#include <memory>
#include "ipquest_mapper.h"


class PQuestMapper : public IPQuestMapper {
public:
    explicit PQuestMapper(std::shared_ptr<IDBConn> &new_dbConn);
    ProgPuzzle getRandProgPuzzle() override;
};


#endif //DATABASE_PQUESTMAPPER_H
