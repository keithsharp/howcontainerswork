#!/bin/bash

echo "mkdir shopping vegetables fruits"
mkdir shopping vegetables fruits

echo "touch vegetables/carrots vegetables/potatoes"
touch vegetables/carrots vegetables/potatoes

echo "touch fruits/apples fruits/pears"
touch fruits/apples fruits/pears

echo "ls vegetables"
ls vegetables

echo "ls fruits"
ls fruits

echo "ls shopping"
ls shopping

echo "sudo mount -t overlay -olowerdir=vegetables:fruits none shopping"
sudo mount -t overlay -olowerdir=vegetables:fruits none shopping

echo "ls shopping"
ls shopping
