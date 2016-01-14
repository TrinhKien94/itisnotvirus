#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main(){
	FILE *f = fopen("test.c","w"),*g;
	char s[256];
	fprintf(f,"#include <stdio.h>\n#include <stdlib.h>\nint main(){\nprintf(\"Hello Boss\\n\")}");
	fclose(f);
	system("gcc -o test test.c > yzsa");
	system("./test > result");
	f=fopen("result","r");
	while(1){
		fgets(s,256,f);
		if(feof(f))
			break;
		printf("%s",s);
	}
}
