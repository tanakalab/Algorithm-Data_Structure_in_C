#include <io.h>

rule* read_rule_list(char* rule_file_name) {
  FILE *fp;
  if (NULL == (fp = fopen(rule_file_name, "r"))) {
    fprintf(stderr, "ERROR: can't open the rule file.\n");
    exit(1);
  }

  _n = 0;
  { /* count the number of rules */
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while (-1 != (read = getline(&line, &len, fp))) ++_n;
  }
  
  char SA[33], DA[33], PROT[9];
  unsigned SPL, SPH, DPL, DPH;

  rule* rulelist = (rule*)malloc(_n*sizeof(rule));
  unsigned i;
  rewind(fp);
  for (i = 0; EOF != fscanf(fp,"%s %s %u-%u %u-%u %s",SA,DA,&SPL,&SPH,&DPL,&DPH,PROT); ++i) {
    /* printf("%s %s %u : %u %u : %u %s\n", SA, DA, SPL, SPH, DPL, DPH, PROT); */
    rulelist[i].sa = (char*)malloc(33*sizeof(char));
    rulelist[i].da = (char*)malloc(33*sizeof(char));
    rulelist[i].prot = (char*)malloc(9*sizeof(char));
    strcpy(rulelist[i].sa, SA);
    strcpy(rulelist[i].da, DA);
    strcpy(rulelist[i].prot, PROT);
    rulelist[i].sp = range_to_01m_strings(SPL,SPH,LOW,HIGH);
    rulelist[i].dp = range_to_01m_strings(DPL,DPH,LOW,HIGH);
  }
  fclose(fp);
  
  return rulelist;
}

void free_rule_list(rule* rulelist) {
  unsigned i;
  for (i = 0; i < _n; ++i) {
    free(rulelist[i].sa);
    free(rulelist[i].da);
    free(rulelist[i].prot);
    string_list_clear(rulelist[i].sp);
    string_list_clear(rulelist[i].dp);
  }
  free(rulelist);
}

char** read_header_list(char* header_file_name) {
  FILE *fp;
  if (NULL == (fp = fopen(header_file_name, "r"))) {
    fprintf(stderr, "ERROR: can't open the header file.\n");
    exit(1);
  }

  _hn = 0;
  { /* count the number of rules */
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while (-1 != (read = getline(&line, &len, fp))) ++_hn;
  }

  char** headerlist = (char**)malloc(_hn*sizeof(char*));
  unsigned i;
  rewind(fp);
  
  char SA[33], DA[33], SP[17], DP[17], PROT[9];
  for (i = 0; EOF != fscanf(fp,"%s %s %s %s %s",SA,DA,SP,DP,PROT); ++i) {
    headerlist[i] = (char*)malloc((HEADER_LENGTH+1)*sizeof(char));
    unsigned j;
    for (j = 0; j < 32; ++j) {
      headerlist[i][31-j] = SA[j]; /* reverse the string of SA */
      headerlist[i][32+j] = DA[j];
    }
    for (j = 0; j < 16; ++j) {
      headerlist[i][64+j] = SP[j];
      headerlist[i][80+j] = DP[j];
    }
    for (j = 0; j < 8; ++j) { headerlist[i][96+j] = PROT[j]; }
  }
  fclose(fp);
  
  return headerlist;
}

void free_header_list(char** headerlist) {
  unsigned i;
  for (i = 0; i < _hn; ++i) { free(headerlist[i]); }
  free(headerlist);
}
