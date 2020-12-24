#include "ConnPool.h"
#include "pg_conn_pool.h"
#include "iusers_mapper.h"
#include "iqquest_mapper.h"
#include "ipquest_mapper.h"
#include "user_mapper.h"
#include "score_mapper.h"
#include "qquest_mapper.h"
#include "pquest_mapper.h"
#include "DBBuilder.h"
#include "idb_conn.h"
#include "pgsql_conn.h"
#include "pgsql.h"


DBBuilder::DBBuilder() {

}

std::shared_ptr<IDB> DBBuilder::buildAllDB() {
    std::shared_ptr<ConnPool> connP = std::make_shared<PGConnPool>();
    std::shared_ptr<IDBConn> connector = std::make_shared<PDBConn>(connP);
    std::shared_ptr<IUsersMapper> userM = std::make_shared<UsersMapper>(connector);
    std::shared_ptr<IScoreMapper> scoreM = std::make_shared<ScoreMapper>(connector);

    std::shared_ptr<IQQuestMapper> QQuestM = std::make_shared<QQuestMapper>(connector);
    std::shared_ptr<IPQuestMapper> PQuestM = std::make_shared<PQuestMapper>(connector);

    std::shared_ptr<IDB> MyDB = std::make_shared<pgsql>(connector, userM, scoreM, QQuestM, PQuestM);

    return MyDB;
}
