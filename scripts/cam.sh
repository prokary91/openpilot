#!/usr/bin/env bash

cleanup() {
  pkill -9 -f compressed_vipc.py
  pkill -9 -f watch3
  ssh comma@192.168.61.123 'pkill -f -9 bridge'
  ssh comma@192.168.61.123 'pkill -f -9 encoderd'
  ssh comma@192.168.61.123 'pkill -f -9 camerad'
  pkill -9 -f '/data/cam.sh'
}

trap cleanup SIGINT

(
  ssh comma@192.168.61.123 'nohup /data/cam.sh &' &

  cd /home/batman/openpilot/tools/camerastream
  ./compressed_vipc.py 192.168.61.123 --cam $1 &

  cd /home/batman/openpilot/selfdrive/ui
  ./watch3 $1 &

  wait
);
