#!/bin/bash
while true
do
    ./hunter_srv "logfile log.txt"
    nowtime=$(date +"%Y-%m-%d_%H：%M：%S")
    mv log.txt log-$nowtime.txt
    mkdir log
    mv ./log-$nowtime.txt ./log
done
