#!/bin/sh

set -xe
clang++ -O2 -o app "$1"
./app
