#ifndef DATABASE_MYSQL_H
#define DATABASE_MYSQL_H


#include <memory>
#include "iusers_mapper.h"
#include "iscore_mapper.h"
#include "iqquest_mapper.h"
#include "ipquest_mapper.h"
#include "idb_conn.h"
#include "IDB.h"


class pgsql : public IDB {
public:
    pgsql(std::shared_ptr<IDBConn> &_dbConn,
          std::shared_ptr<IUsersMapper> &_userM,
          std::shared_ptr<IScoreMapper> &_scoreM,
          std::shared_ptr<IQQuestMapper> &new_QQuestM,
          std::shared_ptr<IPQuestMapper> &new_PQuestM);

    std::shared_ptr<IUsersMapper> getUserM() override;
    std::shared_ptr<IScoreMapper> getScoreM() override;
    std::shared_ptr<IQQuestMapper> getQQuestM() override;
    std::shared_ptr<IPQuestMapper> getPQuestM() override;


private:
    std::shared_ptr<IDBConn> dbConn = nullptr;
    std::shared_ptr<IUsersMapper> userM = nullptr;
    std::shared_ptr<IScoreMapper> scoreM = nullptr;
    std::shared_ptr<IQQuestMapper> QQuestM = nullptr;
    std::shared_ptr<IPQuestMapper> PQuestM = nullptr;

};


#endif //DATABASE_MYSQL_H
