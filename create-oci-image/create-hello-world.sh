#!/bin/bash

# You'll need skopeo to download the image from Docker Hub and jq to
# pretty print the JavaScript

echo "skopeo copy docker://hello-world oci:hello-world"
skopeo copy docker://hello-world oci:hello-world

echo "ls"
ls

echo "ls hello-world"
ls hello-world

echo "jq . < hello-world/oci-layout"
jq . < hello-world/oci-layout

echo "jq . < hello-world/refs/latest"
jq . < hello-world/refs/latest

echo "jq . < hello-world/blobs/sha256/f422e18dae1e99251df03310818cfa7e9c7a7d4fb0227787f7924c9bc8146b4a"
jq . < hello-world/blobs/sha256/f422e18dae1e99251df03310818cfa7e9c7a7d4fb0227787f7924c9bc8146b4a

echo "tar zxf hello-world/blobs/sha256/c04b14da8d1441880ed3fe6106fb2cc6fa1c9661846ac0266b8a5ec8edf37b7c"
tar zxf hello-world/blobs/sha256/c04b14da8d1441880ed3fe6106fb2cc6fa1c9661846ac0266b8a5ec8edf37b7c

echo "ls -l ./hello"
ls -l ./hello

echo "file ./hello"
file ./hello

echo "./hello"
./hello

echo "jq . < hello-world/blobs/sha256/c54a2cc56cbb2f04003c1cd4507e118af7c0d340fe7e2720f70976c4b75237dc"
jq . < hello-world/blobs/sha256/c54a2cc56cbb2f04003c1cd4507e118af7c0d340fe7e2720f70976c4b75237dc

