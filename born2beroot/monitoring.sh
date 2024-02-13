#!/bin/bash

while true; do
	# Get OS architecture and kernel version
	architecture=$(uname -a)

	# Get the number of physical and virtual CPUs//
	cpu_physical=$(lscpu | grep "Socket(s):" | awk '{print $2}')
	vcpu=$(lscpu | grep "^CPU(s):" | awk '{print $2}')

	# Get memory usage
	mem_usage=$(free -m | awk '/Mem:/ {printf "%d/%dMB (%.2f%%)\n", $3,$2,100*$3/$2}')

	# Get disk usage
	disk_usage=$(df | grep -v ^Filesystem | awk '{total += $2} {used += $3} END {printf "%d/%.1fGb (%d%%)\n", used/1024, total/1024/1024, (used/total)*100}')

	# Get CPU load
	cpu_load=$(top -bn1 | grep '^%Cpu' | sed 's/,/ /g' | awk '{printf "%.1f", (100 - $8)}')

	# Get last boot time
	last_boot=$(who -b | awk '{print $3" "$4}')

	# Check if LVM is in use
	lvm_use=$(lsblk | grep "lvm" | wc -l)
	lvm_use=$(if [ $lvm_use == 0 ]; then echo "no"; else echo "yes"; fi)

	# Get number of active TCP connections
	connections_tcp=$(ss -t | grep -i "estab" | wc -l)

	# Get the number of users logged in
	user_log=$(who | wc -l)

	# Get network IP and MAC addresses
	network_info=$(ip addr | awk '/inet / && !/127.0.0.1/ {split($2, a, "/"); print "IP "a[1]}')
	mac_address=$(ip link | awk '/ether/ {print $2}')

	# Get the number of commands executed with sudo
	sudo_cmds=$(grep -c "COMMAND" /var/log/sudo/sudo.log)

	# Prepare the output
	output="#Architecture: $architecture
	#CPU physical : $cpu_physical
	#vCPU : $vcpu
	#Memory Usage: $mem_usage
	#Disk Usage: $disk_usage
	#CPU load: $cpu_load%
	#Last boot: $last_boot
	#LVM use: $lvm_use
	#Connections TCP : $connections_tcp ESTABLISHED
	#User log: $user_log
	#Network: $network_info ($mac_address)
	#Sudo : $sudo_cmds cmd"

	# Send the output to all logged-in users
	echo "$output" | wall
	# Sleep for 10 minutes
	sleep 600
done
