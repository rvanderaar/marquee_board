#! /bin/bash

ssh pi@192.168.178.150 killall gdbserver &> /dev/null || true

scp build/src/marquee_board pi@192.168.178.150:/home/pi/marquee_board

ssh pi@192.168.178.150 gdbserver :2000 ./marquee_board &

sleep 1

