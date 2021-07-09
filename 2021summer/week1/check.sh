#! /bin/zsh

g++ $1
./a.out < in > tmp
diff tmp out