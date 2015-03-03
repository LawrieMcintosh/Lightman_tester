#!/bin/sh

ABSPATH=$(cd "$(dirname "$0")"; pwd)
echo $ABSPATH
cd $ABSPATH
cp tlc_config.h ../libraries/Tlc5940

exit
