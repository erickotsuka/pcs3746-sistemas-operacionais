#!/bin/bash
assignment=1

if [ ! -z "$1" ]
then
    assignment=$1
fi

docker run -ti --rm -v "$PWD/linux":/home/student/src/linux -v "$PWD/$assignment/initramfs":/home/student/src/initramfs tiagoshibata/pcs3746
