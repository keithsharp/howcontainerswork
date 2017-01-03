#!/bin/bash

echo "sudo ip link del veth0"
sudo ip link del veth0

echo "sudo ip link list"
sudo ip link list

echo "sudo ip netns del test"
sudo ip netns del test

echo "sudo ip netns list"
sudo ip netns list
