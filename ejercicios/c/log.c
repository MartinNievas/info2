#include <stdio.h>
#include <math.h>
int main(void){
  float num;
  do{
    printf("Num: ");
    scanf("%f", &num);
    printf("= %.2f\n", log(num));
  }while (num != 0);
 
	return 0;
}
