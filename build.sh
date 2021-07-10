#!/usr/bin/env bash
set -e
[ ! -x ping ]
[ -x configure ]
./configure
make -j
