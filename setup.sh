#!/bin/bash
git submodule init && git submodule update && rm -rf build && mkdir build && cd build && cmake .. && make && cd .. && clear