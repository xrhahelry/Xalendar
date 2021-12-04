#include<stdio.h>
#include<time.h>

void main() {
  time_t rawtime;
  struct tm* timeinfo;

  char m[10];
  char y[10];
  char wd[10];
  char md[10];

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(m, 10, "%b", timeinfo);
  strftime(y, 10, "%Y", timeinfo);
  strftime(wd, 10, "%a", timeinfo);
  strftime(md, 10, "%d", timeinfo);

  printf("%s %s %s %s",y,m,md,wd);
}
