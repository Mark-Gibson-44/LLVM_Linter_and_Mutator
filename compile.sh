#/bin/bash

clang++ -S -emit-llvm $1 -o out.ll
clang++ -S -emit-llvm $1 -O3 -o opt.ll

echo "Unoptimised code"
./run out.ll

echo ""
echo ""
echo ""


echo "Optimised code"
./run opt.ll
