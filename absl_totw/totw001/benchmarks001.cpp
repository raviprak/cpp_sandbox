#include <benchmark/benchmark.h>
#include <cstring>

///////////////////////////////////////////////////////////////////////////
// Benchmark single argument string_view(const char*) with double argument. 
///////////////////////////////////////////////////////////////////////////
static void BM_StringViewForConstCharOneArgument(benchmark::State& state) {
  const char* my_char_arr = "My precious const character array.";
  for(auto _: state) {
    std::string_view my_string_view(my_char_arr);
    benchmark::DoNotOptimize(my_string_view);
  }
}
BENCHMARK(BM_StringViewForConstCharOneArgument);

static void BM_StringViewForConstCharTwoArgument(benchmark::State& state) {
  const char* my_char_arr = "My precious const character array.";
  int length = strlen(my_char_arr);
  for(auto _: state) {
    std::string_view my_string_view(my_char_arr, length);
    benchmark::DoNotOptimize(my_string_view);
  }
}
BENCHMARK(BM_StringViewForConstCharTwoArgument);

// -------------------------------------------------------------------------------
// Benchmark                                     Time             CPU   Iterations
// -------------------------------------------------------------------------------
// BM_StringViewForConstCharOneArgument       4.38 ns         4.38 ns    159925915
// BM_StringViewForConstCharTwoArgument       1.49 ns         1.49 ns    468688912

//////////////////////////////////////////////////////
// Benchmark copying string_view vs passing const ref.
//////////////////////////////////////////////////////
void function_accepts_string_view_copy(std::string_view copy) {
  benchmark::DoNotOptimize(copy);
}

static void BM_StringViewPassByCopy(benchmark::State& state) {
  const char* my_char_arr = "My precious const character array.";
  int length = strlen(my_char_arr);
  std::string_view my_string_view(my_char_arr, length);
    for(auto _: state) {
    function_accepts_string_view_copy(my_string_view);
  }
}
BENCHMARK(BM_StringViewPassByCopy);

void function_accepts_string_view_reference(const std::string_view& reference) {
  benchmark::DoNotOptimize(reference);
}

static void BM_StringViewPassByReference(benchmark::State& state) {
  const char* my_char_arr = "My precious const character array.";
  int length = strlen(my_char_arr);
  std::string_view my_string_view(my_char_arr, length);
    for(auto _: state) {
    function_accepts_string_view_reference(my_string_view);
  }
}
BENCHMARK(BM_StringViewPassByReference);

// -------------------------------------------------------------------------------
// Benchmark                                     Time             CPU   Iterations
// -------------------------------------------------------------------------------
// BM_StringViewPassByCopy                    1.26 ns         1.26 ns    554824486
// BM_StringViewPassByReference               1.17 ns         1.17 ns    595781087



BENCHMARK_MAIN();