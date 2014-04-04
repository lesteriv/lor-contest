#!/bin/sh

./contest -s "debug" -t ""
./contest -s "debugfs" -t "debugfs"
./contest -s "debug=1" -t "debug=1"
./contest -s "systemd.debug" -t "systemd.debug"
./contest -s "debug 123 debug 456" -t "123 456"

