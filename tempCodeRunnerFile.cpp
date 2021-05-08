{
  int a, b;
  sscanf(cstr, "%d %d", &a, &b);
  int aux = *&a;
  a = *&b;
  b = aux;
 
  printf("%d %d\n", a, b);
  
  return std::make_tuple(a,b);
}