#include <emscripten/emscripten.h>
#include <math.h>

EMSCRIPTEN_KEEPALIVE
int map_mouse(int a, int b, int w, int h) {
  int dx = a - w / 2;
  int dy = b - h / 2;
  return (int)(1000 * sqrtl(dx * dx + dy * dy) / sqrtl(w * w + h * h) * 4);
}
