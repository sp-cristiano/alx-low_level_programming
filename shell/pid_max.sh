#!/bin/bash

file_pid_max="/proc/sys/kernel/pid_max"

if [ -f "$file_pid_max" ]; then
	pid_max=$(cat "$file_pid_max")
	echo "MAXIMUM PID VALUE: $pid_max"
else
	echo "Error: $file_pid_max not found."
fi
