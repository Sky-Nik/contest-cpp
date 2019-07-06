#!/usr/bin/env python
import shutil
import os


def split_dir_names():
    print(f'split_dir_names called in {os.getcwd()}')
    recurse_to_dirs = []

    for smth in os.listdir():
        if os.path.isdir(smth):
            if len(smth) > 1:
                recurse_to_dirs.append(smth[0])
                if smth[0] not in os.listdir():
                    os.mkdir(smth[0])
                shutil.move(smth, smth[0] + "\\" + smth[1:])
            else:
                recurse_to_dirs.append(smth)

    for to_dir in recurse_to_dirs:
        os.chdir(to_dir)
        split_dir_names()
        os.chdir('..')


if __name__ == "__main__":
    split_dir_names()
