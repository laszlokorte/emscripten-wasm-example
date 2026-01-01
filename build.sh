#!/usr/bin/env sh

emcc main.c \
  -O2 \
  -s WASM=1 \
  -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap", "HEAPF32"]' \
  -o build/main.js
