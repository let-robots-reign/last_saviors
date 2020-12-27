#include "pquest_mapper.h"


PQuestMapper::PQuestMapper(std::shared_ptr<IDBConn> &new_dbConn) {
    this->dbConn = new_dbConn;
}

ProgPuzzle PQuestMapper::getRandProgPuzzle() {
    return ProgPuzzle();
}
