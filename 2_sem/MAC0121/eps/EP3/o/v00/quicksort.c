static int separa (float v[], int inicio, int fim) {
   float c = v[inicio];
   int i = inicio+1, j = fim;
   float temp;
   while (i <= j) {
      if (v[i] <= c) ++i;
      else if (c < v[j]) --j; 
      else {
         temp = v[i], v[i] = v[j], v[j] = temp;
         ++i; --j;
      }
   }
   v[inicio] = v[j];
   v[j] = c;
   return j; 
}

void quicksort (float v[], int inicio, int fim) {
   int pivo;
   if (inicio < fim) { 
      pivo = separa (v, inicio, fim); 
      quicksort (v, inicio, pivo-1);
      quicksort (v, pivo+1, fim);
   }
}