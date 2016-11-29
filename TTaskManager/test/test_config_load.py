import unittest
from TTaskManager.classes.config import Config


class TestConfigLoad(unittest.TestCase):
    def testSimpleLoad(self):
        cfg = Config('db/config-test-db.yaml')
        self.assertEqual(cfg.db['host'], 'localhost')
        self.assertEqual(cfg.db['user'], 'root')
        self.assertEqual(cfg.db['passwd'], 'password')
        self.assertEqual(cfg.db['db'], 'database_name')
        #TODO: should be cfg.a.b.c == value
        self.assertEqual(cfg.a['b']['c'], 'value')


