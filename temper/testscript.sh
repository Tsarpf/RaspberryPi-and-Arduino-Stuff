rrdtool graph testgraph.png \
-w 640 -h 480 -a PNG \
--slope-mode \
--start -604800 --end now \
--font DEFAULT:7: \
--title "Temperature in tsurba's room" \
--watermark "'date'" \
--vertical-label "Temperature in degrees Celsius" \
--lower-limit 0 \
--right-axis 1:0 \
--x-grid MINUTE:10:HOUR:1:MINUTE:120:0:%R \
--alt-y-grid --rigid \
DEF:temps=temps.rrd:temp:MAX \
CDEF:PLNone=temps,0,0,LIMIT,UN,UNKN,INF,IF \
CDEF:PL10=temps,1,10,LIMIT,UN,UNKN,INF,IF \
CDEF:PL25=temps,10,25,LIMIT,UN,UNKN,INF,IF \
CDEF:PL50=temps,25,50,LIMIT,UN,UNKN,INF,IF \
CDEF:PL100=temps,50,100,LIMIT,UN,UNKN,INF,IF \
LINE1:temps#0000FF:"temps(C)" \
GPRINT:temps:LAST:"Cur\: %5.2lf" \
GPRINT:temps:AVERAGE:"Avg\: %5.2lf" \
GPRINT:temps:MAX:"Max\: %5.2lf" \
GPRINT:temps:MIN:"Min\: %5.2lf\t\t\t" \
AREA:PLNone#FFFFFF:"0%":STACK \
AREA:PL10#FFFF00:"1-10%":STACK \
AREA:PL25#FFCC00:"10-25%":STACK \
AREA:PL50#FF8000:"25-50%":STACK \
AREA:PL100#FF0000:"50-100%":STACK
