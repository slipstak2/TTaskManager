from os import path

CONFIGS_PATH = path.normpath(path.join(path.dirname(__file__), './configs'))

primitive_types = (bool, int, float, str)
