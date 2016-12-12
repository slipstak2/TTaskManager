from os import path
from yaml import load, dump
from TTaskManager.classes.settings import CONFIGS_PATH
from collections import OrderedDict
from settings import primitive_types


class ConfigItem(object):
    def __init__(self, data):
        if type(data) is dict:
            self.childs = OrderedDict()
            for key, val in data.items():
                self.childs[key] = ConfigItem._get(val)
        elif type(data) is list:
            self.childs = list()
            for item in data:
                self.childs.append(ConfigItem._get(item))
        else:
            assert False, 'unsupport configItem type'

    @staticmethod
    def _get(data):
        if isinstance(data, primitive_types):
            return data
        return ConfigItem(data)

    def __getattr__(self, item):
        return self.childs.get(item)

    def __getitem__(self, key):
        return self.childs[key]


class Config:
    def __init__(self, name):
        self.name = name
        self._root = ConfigItem._get(self._load())

    def _load(self):
        config_path = path.join(CONFIGS_PATH, self.name)
        with open(config_path) as f:
            content = load(f)
        return content

    def __getattr__(self, item):
        return self._root.__getattr__(item)
