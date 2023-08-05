#include <stdlib.h>
#include <stdio.h> 
#include "foo.h"
#include "bar.h"

int main(void)
{
  printf("Foo call: %s\n", foo());
  printf("Bar call: %s\n", bar());
}