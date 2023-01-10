#!/usr/bin/env bash
set -e
[ ! -x ping ]
[ -x configure ]
./configure
sudo make -j
#sudo setcap cap_net_admin,cap_net_raw=eip ping

#rm -rf tags *.o *.d ping *.log *.status *.conf autom4te.cache/
