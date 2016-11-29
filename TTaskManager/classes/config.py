from os import path
from yaml import load, dump
from TTaskManager.classes.settings import CONFIGS_PATH


class Config:
    def __init__(self, name):
        self.name = name
        self.data = self.load()

    def load(self):
        config_path = path.join(CONFIGS_PATH, self.name)
        with open(config_path) as f:
            content = load(f)
        return content

    def __getattr__(self, item):
        return self.data.get(item)
