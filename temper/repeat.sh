#!/bin/bash

while [ 1 ]
do
    TEMPERATURE=$(./temps)
    echo $TEMPERATURE
    rrdtool update temps.rrd --template temp N:$TEMPERATURE
    sleep 60s
done
