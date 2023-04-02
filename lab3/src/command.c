#include "command.h"
#include "coder.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
int encode_file(const char *in_file_name, const char *out_file_name) {
  FILE *in;
  FILE *out;

  in = fopen(in_file_name, "r");
  if (!in) {
    return -1;
  }

  out = fopen(out_file_name, "wb");

  if (!out) {
    return -1;
  }
  uint32_t code_point; // то, что нужно закодировать
  CodeUnit code_unit;
  while (fscanf(in, "%" SCNx32, &code_point) == 1) {
    printf("%" PRIx32, code_point);

    if (encode(code_point, &code_unit) < 0) {
      printf("\nFailed to encode"); // TODO: Напсить четкий error
      return -1;
    }
    write_code_unit(out, &code_unit);
  }

  fclose(in);
  fclose(out);

  return 0;
}

int decode_file(const char *in_file_name, const char *out_file_name) {
  FILE *in;
  FILE *out;

  in = fopen(in_file_name, "wb");
  if (!in) {
    return -1;
  }

  out = fopen(out_file_name, "r");

  if (!out) {
    return -1;
  }

  uint8_t code_point;
  CodeUnit code_unit;
  while (read_code_unit(in, &code_unit) == 0) {
    printf("%" PRIx32, code_point);
    while () //Подсчитывать code_unit->length
    {
      code_unit->length++;
    }
    if (decode(&code_unit) < 0) {
      printf("\nFailed to decode"); // TODO: Напсить четкий error
      return -1;
    }
  }

  fclose(in);
  fclose(out);

  return 0;
}