#!/bin/bash
./compile.sh tema1
./runtests.sh tema1 5
./compile.sh CautareLiniara
./runtests.sh CautareLiniara 3
rm tema1.out
rm tema1.in
rm CautareLiniara.out
rm CautareLiniara.in