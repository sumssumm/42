#!/bin/bash

# server 프로세스의 PID 찾기
server_pid=$(ps -e | grep -v "grep" | egrep "./server" | awk '{print $1}')

# PID를 찾지 못했을 경우
if [ -z "$server_pid" ]; then
    echo "Server process not found."
    exit 1
fi

echo "Server PID: $server_pid"
# 랜덤한 100자 문자열 생성
random_string=$(LC_ALL=C tr -dc 'A-Za-z0-9' < /dev/urandom | head -c 1000)


echo "Generated String: $random_string"

# client 실행 및 실행 시간 측정
time ./client $server_pid "$random_string"


