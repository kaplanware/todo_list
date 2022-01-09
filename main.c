#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listWorks()
{
	FILE *todo = fopen("todo.txt", "r");
    char ch;

    while((ch = fgetc(todo)) != EOF)
        putchar(ch);
}

void addWork(char *work[]){
	FILE *todo = fopen("todo.txt", "a");
		    
	fprintf(todo, "%s\n", work);
	
	fclose(todo);
}

void deleteWork(int line)
{
	printf("%d", line);
	
	FILE *todo = fopen("todo.txt", "r");
	FILE *temp = fopen("temp.tmp", "w");
    char buffer[999999];
  

    while ((fgets(buffer, 999999, todo)) != NULL)
    {
        fputs(buffer, temp);
    }
    
    fclose(todo);
    fclose(temp);
    
    remove("todo.txt");
    rename("temp.tmp", "todo.txt");
}

int main( int argc, char *argv[] )  {
	
	printf("\n#############\n\n");
	printf("Parametreler : \n");
	printf("Todo kayitlarini acmak icin : todolist l \n");
	printf("Yeni kayit icin : todolist a \"yeni kayit\" \n");
	printf("Kayit silmek icin : todolist d 2 \n \n########### \n\n");
	
	
   if( argc == 2 ) {
      	if(argv[1][0] == 'l'){
      		listWorks();
		}
		else
			printf("Gecersiz parametre.");
   }
   else if( argc > 2 ) {
   		
   		if(argv[1][0] == 'a'){
   			
			addWork(argv[2]);
			
			printf("Dosyaya yeni deger eklendi. \n");
			printf("Eklenen deger : %s", argv[2]);
		}
		else if(argv[1][0] == 'd'){
		   	deleteWork(argv[2]);
		   	printf("\n Satýr silindi.");
		}
		else
			printf("Gecersiz parametre.");
	}  
}
   

