#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <graphics.h>
#include <time.h>
#include <dos.h>

void secondPoints(int xr, int midx, int midy, int x[60], int y[60]);
void findPoints(int angleRad, int midx, int midy, int x[12], int y[12]);
	
int main() {
  int gd = DETECT, gm, err, tmp;
  initgraph( & gd, & gm, "C:\\tc\\bgi");

  int i, j, midx, midy, angleRad, hr, min, sec;
  int x[12], y[12], minx[60], miny[60];
  int hrx[12], hry[12], secx[60], secy[60];
  int secx1, secy1;
  char label[256];
  time_t t1;
  struct tm * data;

  midx = getmaxx() / 2;
  midy = getmaxy() / 2;

  angleRad = 200;

  findPoints(angleRad - 30, midx, midy, x, y);
  findPoints(angleRad - 90, midx, midy, hrx, hry);

  secondPoints(angleRad - 50, midx, midy, minx, miny);
  secondPoints(angleRad - 70, midx, midy, secx, secy);

  while (!kbhit()) {
    setlinestyle(SOLID_LINE, 1, 3);
    settextstyle(SANS_SERIF_FONT, 0, 3);

    circle(midx, midy, angleRad);

    for (i = 0; i < 12; i++) {
      if (i == 0) {
        sprintf(label, "%d", 12);
      } else {
        sprintf(label, "%d", i);
      }
      settextjustify(CENTER_TEXT, CENTER_TEXT);
      moveto(x[i], y[i]);
      outtext(label);
    }

    t1 = time(NULL);
    data = localtime( & t1);

    sec = data -> tm_sec % 60;
    line(midx, midy, secx[sec], secy[sec]);

    min = data -> tm_min % 60;
    line(midx, midy, minx[min], miny[min]);

    hr = data -> tm_hour % 12;
    line(midx, midy, hrx[hr], hry[hr]);
    delay(1000);
    cleardevice();
  }

  getch();
  closegraph();
  return 0;
}

void secondPoints(int xr, int midx, int midy, int x[60], int y[60]) {
  int j = 45;
  for (int i = 360; i >= 0; i -= 6) {
    x[j] = midx - (xr * cos((i * 3.14) / 180));
    y[j] = midy - (xr * sin((i * 3.14) / 180));
    j--;
	if( j == -1 )
    	j = 59;
  }
  return;
}

void findPoints(int angleRad, int midx, int midy, int x[12], int y[12]) {
  int x1, y1;
  x[0] = midx, y[0] = midy - angleRad;
  x[6] = midx, y[6] = midy + angleRad;
  x[3] = midx + angleRad, y[3] = midy;
  x[9] = midx - angleRad, y[9] = midy;

  x1 = (int)((angleRad / 2) * sqrt(3));
  y1 = (angleRad / 2);
  x[2] = midx + x1, y[2] = midy - y1;
  x[4] = midx + x1, y[4] = midy + y1;
  x[8] = midx - x1, y[8] = midy + y1;
  x[10] = midx - x1, y[10] = midy - y1;

  x1 = angleRad / 2;
  y1 = (int)((angleRad / 2) * sqrt(3));
  x[1] = midx + x1, y[1] = midy - y1;
  x[5] = midx + x1, y[5] = midy + y1;
  x[7] = midx - x1, y[7] = midy + y1;
  x[11] = midx - x1, y[11] = midy - y1;
  return;
}