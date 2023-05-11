// Huffman Coding in C

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 50

typedef struct MinHNode {
  char item;
  unsigned freq;
  struct MinHNode *left, *right;
} MinHNode;

typedef struct MinHeap {
  unsigned size;
  unsigned capacity;
  MinHNode **array;
} MinHeap;

// Print the array
void printArr(int arr[], int n) {
  int i;
  for (i = 0; i < n; ++i)
    printf("%d", arr[i]);
  printf("\n");
}

// Create nodes
MinHNode *newNode(char item, unsigned freq) {
  MinHNode *temp = (MinHNode *)malloc(sizeof(MinHNode));

  temp->left = temp->right = NULL;
  temp->item = item;
  temp->freq = freq;

  return temp;
}

// Create min heap
MinHeap *createMinH(unsigned capacity) {
  MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));

  minHeap->size = 0;

  minHeap->capacity = capacity;

  minHeap->array = (MinHNode **)malloc(minHeap->capacity * sizeof(MinHNode *));
  return minHeap;
}

// Function to swap
void swapMinHNode(MinHNode **a, MinHNode **b) {
  MinHNode *t = *a;
  *a = *b;
  *b = t;
}

// Heapify
void minHeapify(MinHeap *minHeap, int idx) {
  int s = idx;
  int l = 2 * idx + 1;
  int r = 2 * idx + 2;

  if (l < minHeap->size && minHeap->array[l]->freq < minHeap->array[s]->freq)
    s = l;

  if (r < minHeap->size && minHeap->array[r]->freq < minHeap->array[s]->freq)
    s = r;

  if (s != idx) {
    swapMinHNode(&minHeap->array[s], &minHeap->array[idx]);
    minHeapify(minHeap, s);
  }
}

// Check if size if 1
int checkSizeOne(MinHeap *minHeap) {
  return (minHeap->size == 1);
}

// Extract min
MinHNode *extractMin(MinHeap *minHeap) {
  MinHNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];

  --minHeap->size;
  minHeapify(minHeap, 0);

  return temp;
}

// Insertion function
void insertMinHeap(MinHeap *minHeap, MinHNode *node) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = node;
}

void buildMinHeap(MinHeap *minHeap) {
  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    minHeapify(minHeap, i);
}

int isLeaf(MinHNode *root) {
  return !(root->left) && !(root->right);
}

MinHeap *createAndBuildMinHeap(char item[], int freq[], int size) {
  MinHeap *minHeap = createMinH(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(item[i], freq[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}

MinHNode *buildHuffmanTree(char item[], int freq[], int size) {
  MinHNode *left, *right, *top;
  MinHeap *minHeap = createAndBuildMinHeap(item, freq, size);

  while (!checkSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = newNode('$', left->freq + right->freq);

    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

void printHCodes(MinHNode *root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    printHCodes(root->left, arr, top + 1);
  }
  if (root->right) {
    arr[top] = 1;
    printHCodes(root->right, arr, top + 1);
  }
  if (isLeaf(root)) {
    printf("  %c   | ", root->item);
    printArr(arr, top);
  }
}

// Wrapper function
void HuffmanCodes(char item[], int freq[], int size) {
  MinHNode *root = buildHuffmanTree(item, freq, size);

  int arr[MAX_TREE_HT], top = 0;

  printHCodes(root, arr, top);
}

int main() {
  char arr[] = {'A', 'B', 'C', 'D'};
  int freq[] = {5, 1, 6, 3};

  int size = sizeof(arr) / sizeof(arr[0]);

  printf(" Char | Huffman code ");
  printf("\n--------------------\n");

  HuffmanCodes(arr, freq, size);
}
