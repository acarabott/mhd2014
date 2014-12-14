#!/bin/bash

mv ~/Downloads/output.txt ./js.txt;
cp ../cpp/results/out ./cpp.txt;
vimdiff js.txt cpp.txt
