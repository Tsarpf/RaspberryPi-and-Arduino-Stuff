rrdtool create temps.rrd \
    --step 60 \
    DS:temp:GAUGE:120:0:100 \
    RRA:MAX:0.5:1:10140 \
