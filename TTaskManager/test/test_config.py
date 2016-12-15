import unittest
from TTaskManager.classes.config import Config


class TestConfig(unittest.TestCase):
    def setUp(self):
        self.cfg = Config('db/config-test-db.yaml')

    def testDbParam(self):
        self.assertEqual(self.cfg.db.host, 'localhost')
        self.assertEqual(self.cfg.db.user, 'root')
        self.assertEqual(self.cfg.db.passwd, 'password')
        self.assertEqual(self.cfg.db.db, 'database_name')

    def testSeveralMaps(self):
        self.assertEqual(self.cfg.a.b.c, 'value')

    def testArray(self):
        self.assertEqual(self.cfg.array[0], 1)
        self.assertEqual(self.cfg.array[1], 0.57)
        self.assertEqual(self.cfg.array[2], 'second')
        self.assertEqual(self.cfg.array[3], True)

    def testArrayInMap(self):
        self.assertEqual(self.cfg.map.array[0], 'first')
        self.assertEqual(self.cfg.map.array[1], 2)
        self.assertEqual(self.cfg.map.array[2].map_in_array.key0, 'value0')

    def testMapInMap(self):
        self.assertEqual(self.cfg.map.submap.key1, 'value1')
        self.assertEqual(self.cfg.map.submap.key2, 'value2')
