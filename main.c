#include <string.h>
#include <stdio.h>
#include <stdlib.h> //hmmmm this one is new

// getchar() just allows me to control what is output on the terminal so that the entire program doesn't get executed/printed at the onset.

int main(int argc, char** argv) {
  printf("Files Basic I/O Recitation\n");
  printf("Date: 11/20/2020\n\n");

  // open the file
  char* filename = NULL;
  filename = argv[1];
  printf("Opening file: \"%s\"\n", filename);
  FILE* read_file;
  read_file = fopen(filename, "r");
  printf("Printing read_file: %s\n", filename);

  // getchar();

  // read the lines in the file
  // char *fgets(char *str, int n, FILE *stream)
  char current_string[100];
  printf("\nReading the lines in the file.\n");
  // printf("Current string: %s\n", fgets(current_string, 100, read_file));

  while(fgets(current_string, 100, read_file)){
    printf("Current line: %s", current_string);
  }

  // getchar();

  // try and write to a read-only file
  int s = 0xCADE;
  size_t size = 4; // what value should we use here?
  size_t nmemb = 1; // what value should we use here?
  // size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
  printf("Writing to a read-only file: %lu\n", fwrite(&s, size, nmemb, read_file));


  // getchar();

  char write_string[] = "Writing this line to a file";
  // write to a write file
  FILE* write_file = fopen("write_file.txt", "w");
  // writing the integer
  printf("Writing a number: %lu\n", fwrite(&s, size, nmemb, write_file));

  // getchar();

  printf("Writing a string: %lu\n", fwrite(write_string, 1, sizeof(write_string), write_file));
  fclose(write_file);
  // getchar();



  // this isn't printing out the binary representation of the 255. But that's how you'll use strtol
  char t[] = "255 hello";
  char* ptr;
  unsigned int value = strtol(t, &ptr, 2);
  printf("%u\n", value);
  return (0);
}



// To access this repo from your device
// git init
// git remote add origin https://github.com/jerall24/files_recitation.git
// git branch -M main
// git pull -u origin main


// to push to this repo
// git add .
// git commit -m "message"
// git push -u origin main

// tips for this homework
// completely do one function before attempting the others
  // i.e. don't create skeletons for other functions until you know what each requires
// create a function to parse the register. You'll call this in other functions and save a lot of time
// instructions will follow a flow. Draw this flow out to visualize the path. Will help a lot.
// strtol function with a base of 2
