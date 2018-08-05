#include <TTVout.h>
#include <fontALL.h>

TTVout TV;

void setup() {
  Serial.begin(115200);
  TV.adjust(0,       // 垂直同期補正
           -9,       // 横表示開始補正
            8        // 縦表示開始補正
            );
  TV.select_font(font6x8);

  TV.begin(SC_448x216);  // 画面解像度 横448ドットｘ縦216ドット
  // 矩形描画テスト(448x216)
  TV.draw_rect(0,0,TV.hres(),TV.vres(),1,0);
  TV.draw_line(0,0,TV.hres()-1,TV.vres()-1,1);
  TV.draw_line(TV.hres()-1,0,0,TV.vres()-1,1);
  TV.set_pixel(0,0,0);
  TV.set_pixel(TV.hres()-1,0,0);
  TV.set_pixel(0,TV.vres()-1,0);
  TV.set_pixel(TV.hres()-1,TV.vres()-1,0);
  TV.set_cursor(TV.hres()/2-21,TV.vres()/2-4);
  TV.print("448x216");
  delay(5000); 
}

void loop() {
}
