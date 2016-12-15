from sqlalchemy import create_engine
from TTaskManager.classes.config import Config


class db:
    @staticmethod
    def load_test_dump():
        #cfg = Config('db/config-test-db.yaml')
        cfg = Config('db/config-local-db.yaml')
        e = create_engine('mysql://{user}:{passwd}@{host}/{db}'.format(
            user=cfg.db.user,
            passwd=cfg.db.passwd,
            host=cfg.db.host,
            db=cfg.db.db
        ))
        for row in e.execute('select * from task'):
            print row['name']


import sqlalchemy

print sqlalchemy.__version__