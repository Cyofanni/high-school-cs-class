#include <stdio.h>
#include <string.h>

/* size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream); */

/* size_t fwrite(const void *ptr, size_t size, size_t nmemb, */
/*                      FILE *stream); */

/* int fseek(FILE *stream, long offset, int whence); */

typedef struct patient {
  unsigned int id;
  char name[20];
  char surname[20];
  char residence_city[20];
  unsigned int num_exams;
} patient;

int main() {
  FILE *f_ptr = fopen("patients", "w+");
  patient p1 = {5, "john", "smith", "washington", 4};
  patient p2 = {9, "jack", "white", "washington", 6};
  patient p3 = {10, "joseph", "wright", "san francisco", 4};

  fwrite(&p1, sizeof(patient), 1, f_ptr);
  fwrite(&p2, sizeof(patient), 1, f_ptr);
  fwrite(&p3, sizeof(patient), 1, f_ptr);

  unsigned int id;
  rewind(f_ptr);

  fread(&id, sizeof(int), 1, f_ptr);
  printf("%d\n", id);
  fseek(f_ptr, sizeof(patient), SEEK_SET);

  fread(&id, sizeof(int), 1, f_ptr);
  fprintf(stdout, "%d\n", id);
  fseek(f_ptr, sizeof(patient)*2, SEEK_SET);

  fread(&id, sizeof(int), 1, f_ptr);
  fprintf(stdout, "%d\n", id);
}
