#!/usr/bin/env bash
set -e
[ ! -x ping ]
[ -x configure ]
./configure
make -j

#rm -rf tags *.o *.d ping *.log *.status *.conf autom4te.cache/
