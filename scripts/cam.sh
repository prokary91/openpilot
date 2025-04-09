#!/usr/bin/env bash

(
  cd /home/batman/openpilot/tools/camerastream
  ./compressed_vipc.py 192.168.61.123 --cam $1 &

  cd /home/batman/openpilot/selfdrive/ui
  ./watch3 $1 &

  wait
);

trap 'pkill -9 -f compressed_vipc.py; pkill -9 -f watch3; exit 1' SIGINT
