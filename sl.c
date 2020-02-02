/*========================================
 *    sl.c: SL version 5.03
 *        Copyright 1993,1998,2014-2015
 *                  Toyoda Masashi
 *                  (mtoyoda@acm.org)
 *        Last Modified: 2014/06/03
 *========================================
 */
// The OG ^...lots of code is gone. Cat is now a train.
// His name is Jimmy.

#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include "sl.h"

int add_CAT(int x, int c);
int my_mvaddstr(int y, int x, char *str);

int my_mvaddstr(int y, int x, char *str) {
    for ( ; x < 0; ++x, ++str)
        if (*str == '\0')  return ERR;
    for ( ; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)  return ERR;
    return OK;
}

int main(int argc, char *argv[]) {
    int x;
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);

    for (x = COLS - 1; ; --x) {
      if (x % 7 == 0) {
        if (add_CAT(x,0) == ERR) break;
      }
      else {
        if (add_CAT(x,1) == ERR) break;
      }

      refresh();
      usleep(50000);
      if (x == COLS/3) {
        sleep(1);
        for (int i = 2; i <= 4; ++i) {
          if (add_CAT(x,i) == ERR) break;
          refresh();
          sleep(2);
        }
      }

    }

    mvcur(0, COLS - 1, LINES - 1, 0);
    endwin();

    return 0;
}

int add_CAT(int x, int c) {
    static char *CAT[CATPATTERNS][CATHEIGHT]
        = {{CATSTR1, CATSTR2, CATSTR3, CATSTR4, CATSTR5, CATSTR6, CATSTR7, CATSTR8},
           {CATSTR1, CATSTR2, CATSTR3, CATSTR4, CATSTR5, CATSTR6A, CATSTR7A, CATSTR8A},
           {CATSTR01, CATSTR02, CATSTR03, CATSTR04, CATSTR05, CATSTR06, CATSTR07, CATSTR08},
           {CATSTR11, CATSTR12, CATSTR13, CATSTR14, CATSTR15, CATSTR16, CATSTR17, CATSTR18},
           {CATSTR21, CATSTR22, CATSTR23, CATSTR24, CATSTR25, CATSTR26, CATSTR27, CATSTR28}};

    int y, i = 0;

    if (x < - CATLENGTH)  return ERR;
    y = LINES / 2 - 5;

    for (i = 0; i < CATHEIGHT; ++i) {
      my_mvaddstr(y + i, x, CAT[c][i]);
    }
    return OK;
}
