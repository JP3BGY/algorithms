#!/usr/bin/env python3
import subprocess
program_path="./a.out"
fuzzer_path="./fuzzer.py"
times=1000
command=fuzzer_path+" | "+program_path
for i in range(times):
    subprocess.call(command,shell=True)
