#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int days[42] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

char my[19], md[10], date[16], y[5], mn[3];
int current_day, month_first_day, current_year, current_month, month_days;
bool leap = false;

void timeinfo();
int dayofdate(int d, int m, int y);
void leapp();
void month_dayss();
void calendar_arr();
void xalendar();
void bgdefault();
void bgwhite();

/*
     month year
su mo tu we th fr sa
** ** ** ** ** ** **
** ** ** ** ** ** **
** ** ** ** ** ** **
** ** ** ** ** ** **
** ** ** ** ** ** **
** ** ** ** ** ** **
*/

void main() {
  bgdefault();
  timeinfo();
  current_day = atoi(md);
  current_year = atoi(y);
  current_month = atoi(mn);
  month_first_day = dayofdate(1, current_month, current_year);
  leapp();
  month_dayss();
  calendar_arr();
  xalendar();
  puts("\n");
}

void timeinfo() {
  time_t rawtime;
  struct tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(my, 19, "    %B %Y", timeinfo);
  strftime(y, 5, "%Y", timeinfo);
  strftime(md, 10, "%d", timeinfo);
  strftime(mn, 3, "%m", timeinfo);
  // strftime(date, 16, "%Y %b %d %a", timeinfo);
}

int dayofdate(int d, int m, int y) {
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

void leapp() {
  if (current_year % 100 == 0) {
    if (current_year % 400 == 0) {
      leap = true;
    }
  } else {
    if (current_year % 4 == 0) {
      leap = true;
    }
  }
}

void month_dayss() {
  int days_noleap[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int days_leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int cmn = current_month - 1;

  if (!leap) {
    month_days = days_noleap[cmn];
  } else {
    month_days = days_leap[cmn];
  }
}

void calendar_arr() {
  int day = month_first_day;
  for (int i = 1; i <= month_days; i++) {
    days[day] = i;
    day++;
  }
}

void xalendar() {
  int wd = month_first_day - 2;
  puts(my);
  printf("Su Mo Tu We Th Fr Sa\n");
  for (int i = 0; i < 42; i++) {
    if (days[i] == 0) {
      printf("  ");
    } else if (days[i] < 10) {
      if (days[i] == current_day) {
        bgwhite();
        printf(" %d", days[i]);
        bgdefault();
      } else {
        printf(" %d", days[i]);
      }
    } else {
      if (days[i] == current_day) {
        bgwhite();
        printf("%d", days[i]);
        bgdefault();
      } else {
        printf("%d", days[i]);
      }
    }
    printf(" ");
    if (wd > 6) {
      printf("\n");
      wd = 0;
    }
    wd++;
  }
}

void bgdefault() {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                          FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |
                              FOREGROUND_INTENSITY);
}
void bgwhite() {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                          BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN |
                              BACKGROUND_INTENSITY);
}
