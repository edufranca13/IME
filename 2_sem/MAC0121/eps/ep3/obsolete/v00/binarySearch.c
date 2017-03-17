int binarySearch(float v[], int inicio, int fim, float x){

        if (inicio > fim)
                return -1;
        else {
                int meio = (inicio+fim)/2;
                if (v[meio] == x)
                        return meio;
                else if (x > v[meio])
                        return binarySearch(v, meio+1, fim, x);
                else
                        return binarySearch(v, inicio, meio-1, x);
        }
}