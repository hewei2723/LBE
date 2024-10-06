#include <stdio.h>
int main(){
int num=1234;
int thousand, ten, hundred, unit;
thousand = num / 1000;
hundred = (num % 1000) / 100;
ten = (num % 100) / 10;
unit = num % 10;
}