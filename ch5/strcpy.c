
/*strcpy: copy t to s*/
void strcpy(char *s,char *t){
  while((*s++=*t++))
    ;
}
