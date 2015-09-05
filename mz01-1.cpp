int findmax(int* array, const int count) {
  int maximum = 0;
  for (int i = 0; i < count; ++i) {
    if (array[i] > array[maximum]) {
      maximum = i;
    }
  }
  return maximum;
}
