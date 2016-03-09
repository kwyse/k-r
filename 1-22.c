// 1.22 Fold

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void splitline(char str[], uint8_t splitlen) {
  bool ins = false;
  uint32_t offset = 0;
  
  for (size_t i = 0; i < strlen(str) - 1; i++) {
    if (ins && str[i] == ' ') {
      str[i] = '\n';
      ins = false;
      offset = i % splitlen;
    }
    
    if ((i - offset) % splitlen == 0 && str[i] != '\n') {
      for (size_t j = i; (int) j >= 0; j--) {
	if (str[j] == '\n') {
	  ins = true;
	  break;
	}

	if (str[j] == ' ') {
	  str[j] = '\n';
	  break;
	}
      }
    }
  }
}

int main() {
  char str[] = "This is a very long line and it must be shrunk! Yes it very well must I say! Yess yes yess!\n";
  puts(str);
  splitline(str, 20);
  puts(str);

  char str2[] = "This is a very loooooooooooooooooooooooooooong line and it must be shrunk! Yes it very well must I say! Yess yes yess!\n";
  puts(str2);
  splitline(str2, 20);
  puts(str2);

  char str3[] = "This is a very loooooooooooooooooooooooooooong line with a newline!\nHow's about them muffins, eh? Whatcha gonna do now?\nHmmmmmm???\n";
  puts(str3);
  splitline(str3, 20);
  puts(str3);
}
