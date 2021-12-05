#include<stdio.h>
#include<time.h>

int main() {
  time_t rawtime;
  struct tm* timeinfo;

  char m[10];
  char y[10];
  char wd[10];
  char md[10];
  char date[16];

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(m, 10, "%b", timeinfo);
  strftime(y, 10, "%Y", timeinfo);
  strftime(wd, 10, "%a", timeinfo);
  strftime(md, 10, "%d", timeinfo);
  strftime(date, 16, "%Y %b %d %a", timeinfo);

  puts(date);
}
