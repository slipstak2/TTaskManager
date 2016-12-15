import unittest
from TTaskManager.classes.database import db

# https://solovyov.net/blog/2011/basic-sqlalchemy/
# http://docs.sqlalchemy.org/en/latest/
class TestDatabase(unittest.TestCase):
    def testSetSimple(self):
        db.load_test_dump()