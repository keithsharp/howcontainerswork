#!/bin/bash

# Commands to create a network namespace, create veth pair, add one end
# of the veth pair to the new namespace.

echo "sudo ip netns list"
sudo ip netns list

echo "sudo ip netns add test"
sudo ip netns add test

echo "sudo ip link list"
sudo ip link list

echo "sudo ip link add veth0 type veth peer name veth1"
sudo ip link add veth0 type veth peer name veth1

echo "sudo ip link list"
sudo ip link list

echo "sudo ip link set veth1 netns test"
sudo ip link set veth1 netns test

echo "sudo ip link list"
sudo ip link list

echo "sudo ip netns exec test ip link list"
sudo ip netns exec test ip link list

