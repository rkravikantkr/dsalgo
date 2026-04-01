#!/bin/bash

# create output dir if it doesn't exist
mkdir -p output

# timestamp for unique filename
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
FILENAME="output/image_${TIMESTAMP}.ppm"

# compile
g++ src/main.cpp -std=c++17 -o build/main

# run only if compile succeeded
if [ $? -eq 0 ]; then
    ./build/main > "$FILENAME"
    echo "Saved to $FILENAME"
else
    echo "Compile failed."
fi
