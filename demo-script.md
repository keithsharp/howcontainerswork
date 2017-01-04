# Demo Script
The commands you need to run for the various demos in the presentation.

## Using fork to create a new process
```
cd fork-example
cat fork-example.c
gcc -o fork-example fork-example.c
cd ..
```

## PID Namespace example
```
cd pid-namespaces
cat pid-namespaces.c
gcc -o pid-namespaces pid-namespaces.c
./pid-namespaces
cd ..
```

## UTS Namespace CLI example
In your first terminal:
```
cd utsns-cli-example
uname -n
sudo ushare -u /bin/bash
uname -n
sudo hostname ubuntu.example.com
uname -n
echo $$
exit
cd ..
```
In the second terminal:
```
cd utsns-cli-example
uname -n
sudo nsenter -t <PID> -u /bin/bash
uname -n
exit
cd ..
```

## Network namespace CLI example
```
cd netns-cli-example
sudo ip netns list
sudo ip netns add test
sudo ip link list
sudo ip link add veth0 type veth peer name veth1
sudo ip link list
sudo ip link set veth1 netns test
sudo ip link list
sudo ip netns exec test ip link list
cd ..
```

## Seccomp example
```
cd seccomp-example
less seccomp-example.c
gcc -o seccomp-example seccomp-example.c -lseccomp
./seccomp-example
cd ..
```

## OverlayFS example
```
cd overlayfs-example
mkdir shopping vegetables fruits
touch vegetables/carrots vegetables/potatoes
ls vegetables
touch fruits/apples fruits/pears
ls fruits
ls shopping
sudo mount -t overlay -olowerdir=vegetables:fruits none shopping
ls shopping
touch fruits/oranges
ls fruits
ls shopping
touch shopping/beer
cd ..
```

## OCI Image example
```
cd create-oci-image
ls
ls hello-world
jq . < hello-world/oci-layout
jq . < hello-world/refs/latest
jq . < hello-world/blobs/sha256/f422e18dae1e99251df03310818cfa7e9c7a7d4fb0227787f7924c9bc8146b4a
tar zxf hello-world/blobs/sha256/c04b14da8d1441880ed3fe6106fb2cc6fa1c9661846ac0266b8a5ec8edf37b7c
ls -l ./hello
file ./hello
./hello
jq . < hello-world/blobs/sha256/c54a2cc56cbb2f04003c1cd4507e118af7c0d340fe7e2720f70976c4b75237dc
cd ..
```

## RunC example
Still need to do this!
