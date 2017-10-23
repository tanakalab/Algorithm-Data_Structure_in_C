/* tools.c */

#include <tools.h>

/* LOW (=0) and HIGH (=65535) are predefined in the tool.h
     a-b  => 010101..10**, 111101..1111, ...
e.g. 3-17 => 0000000000000011,00000000000001**,0000000000001***,000000000001000*
   
*/
/* string_list* range_pair_to_01m_strings(unsigned a, unsigned b) { */
/*   string_list* L = (string_list*)malloc(sizeof(string_list)); */
  
/*   return L; //range_to_01ms_sub(a,b,LOW,HIGH); */
/* } */

string_list* range_to_01m_strings(unsigned a, unsigned b, unsigned low, unsigned high)
{
  unsigned m = (low+high-1)/2;
  unsigned n = (low+high+1)/2;
  // printf("a = %d, b = %d, low = %d, high = %d, m = %d, n = %d\n", a, b, low, high, m, n);

  if (a == low && b == high) 
    return int_pair_to_01m_string(a,b,BIT_LENGTH);
  else if (b <= m) 
    return range_to_01m_strings(a,b,low,m);
  else if (a <= m && n <= b)
    return string_lists_concat(range_to_01m_strings(a,m,low,m),range_to_01m_strings(n,b,n,high));
			       
  else 
    return range_to_01m_strings(a,b,n,high);

  return NULL;
}

string_list* int_pair_to_01m_string(unsigned a, unsigned b, unsigned w) {
  char* bin = (char*)malloc((w+1)*sizeof(char));

  double a1 = a, b1 = b, l;
  int d;
  l = log2(b1-a1+1);
  d = (int)l;

  // printf("a = %d, b = %d, d = %d\n", a, b, d);
  int i;
  for (i = w-1; i>=0; --i) {
    // printf("%d", (a >> i) & 1);
    // putchar(48+((a >> i) & 1));
    bin[w-i-1] = 48 + ((a>>i)&1);
  }
  bin[w] = '\0';

  for (i = 0; i < d; ++i) { bin[w-i-1] = '*'; }
  //putchar('\n');
  //printf("%s\n",bin);

  string_list* L = (string_list*)malloc(sizeof(string_list));
  string_list_insert(L, bin);
  free(bin);
  
  return L;
}
