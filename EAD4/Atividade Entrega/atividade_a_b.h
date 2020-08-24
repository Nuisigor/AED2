int pai(int n);

int esq(int n);

int dir(int n);

void troca(int *v, int i, int j);

//------------------------- FP MAXIMO -------------------------

void maxHeapify(int *v, int i, int th);

int fp_inicio(int *fp, int n);

int fp_remover_maximo(int *fp, int n);

int fp_inserir(int *fp, int n, int valor);


//------------------------- FP MINIMO -------------------------


int fp_min_inserir(int *fp, int n, int valor);

void minHeapify(int *fp, int n, int th);

int fp_remover_minimo(int *fp, int n);

void buildMinHeap(int *v, int n);


//------------------------- HEAP SORT -------------------------
void buildMaxHeap(int *v, int n);

void HeapSort(int *v, int n);