#include <stdio.h>

int main(){
  int n, factorial=1;
  scanf("%d", &n);
  for (int i=1; i<=n;i++) {
    factorial*=i;
  }
  printf("The result is %d",factorial);
  return 0;
}