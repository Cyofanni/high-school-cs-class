#include <stdio.h>
#include <string.h>

/* size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream); */

/* size_t fwrite(const void *ptr, size_t size, size_t nmemb, */
/*                      FILE *stream); */

/* int fseek(FILE *stream, long offset, int whence); */

/* char *fgets(char *s, int size, FILE *stream); */

typedef struct patient {
  unsigned int id;
  char name[20];
  char surname[20];
  char residence_city[20];
  unsigned int num_exams;
} patient;

int main() {
  FILE *f_ptr = fopen("patients", "r");
  int input_id;
  char input_name[20] = {};
  char input_surname[20] = {};
  char input_residence_city[20] = {};
  unsigned int input_num_exams;

  printf("enter a record (id, name, surname, city, number_of_exams): ");
  putchar('\n');
  printf(" id: ");
  fscanf(stdin, "%d", &input_id);

  printf(" name: ");
  fscanf(stdin, "%s", input_name);

  printf(" surname: ");
  fscanf(stdin, "%s", input_surname);

  printf(" residence city: ");
  fscanf(stdin, "%s", input_residence_city);

  printf(" number of exams: ");
  fscanf(stdin, "%d", &input_num_exams);

  patient p = {};

  while (input_id != -1) {
    p.id = input_id;
    strncpy(p.name, input_name, 20);
    strncpy(p.surname, input_surname, 20);
    strncpy(p.residence_city, input_residence_city, 20);
    p.num_exams = input_num_exams;

    fwrite(&p, sizeof(patient), 1, f_ptr);

    printf("enter a record (id, name, surname, city, number_of_exams): ");
    putchar('\n');
    printf(" id: ");
    fscanf(stdin, "%d", &input_id);

    printf(" name: ");
    fscanf(stdin, "%s", input_name);

    printf(" surname: ");
    fscanf(stdin, "%s", input_surname);

    printf(" residence city: ");
    fscanf(stdin, "%s", input_residence_city);

    printf(" number of exams: ");
    fscanf(stdin, "%d", &input_num_exams);
  }

  //read the file
  int i = 1;
  int id;
  char n[20] = {};
  char s[20] = {};
  char r[20] = {};
  int n_e;

  rewind(f_ptr);
  printf("%-4s%-20s%-20s%-20s%-4s\n", "id", "name", "surname", "residence city", "number of exams");
  while (i <= 2) {
    fread(&id, sizeof(int), 1, f_ptr);
    fread(n, sizeof(char), 20, f_ptr);
    fread(s, sizeof(char), 20, f_ptr);
    fread(r, sizeof(char), 20, f_ptr);
    fread(&n_e, sizeof(int), 1, f_ptr);

    printf("%-4d%-20s%-20s%-20s%-4d\n", id, n, s, r, n_e);

    fseek(f_ptr, sizeof(patient) * i, SEEK_SET);
    i++;
  }
}
