#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#include <math.h>

#define SAMPLE_RATE 44100
#define BLOCK_SIZE 512
float block[BLOCK_SIZE];
float phase = 0.0f;

EMSCRIPTEN_KEEPALIVE
int map_mouse(int a, int b, int w, int h) {
  int dx = a - w / 2;
  int dy = b - h / 2;
  return (int)(1000 * sqrtl(dx * dx + dy * dy) / sqrtl(w * w + h * h) * 2);
}

EMSCRIPTEN_KEEPALIVE
float *generate_block(float freq) {
  const float step = 2.0f * M_PI * freq / SAMPLE_RATE;
  for (int i = 0; i < BLOCK_SIZE; i++) {
    block[i] = sinf(phase);
    phase += step;
    if (phase > 2.0f * M_PI)
      phase -= 2.0f * M_PI;
  }
  return block;
}

EMSCRIPTEN_KEEPALIVE
int block_size() { return BLOCK_SIZE; }
