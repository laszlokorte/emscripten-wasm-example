#!/usr/bin/env sh

emcc main.c \
  -O2 \
  -s WASM=1 \
  -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' \
  -o main.js
