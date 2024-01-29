#include <benchmark/benchmark.h>
#include <absl/strings/str_cat.h>

/////////////////////////////////////////////////////////////
// Benchmark absl::StrCat() against std::string::operator+().
/////////////////////////////////////////////////////////////
static void BM_StrAppendOperatorThreeStrings(benchmark::State &state)
{
    std::string str1 = "My favorite first string.";
    std::string str2 = "My favorite second string.";
    std::string str3 = "My favorite third string.";
    // NOLINTNEXTLINE
    for (auto _ : state)
    {
        std::string str = str1 + str2 + str3;
        benchmark::DoNotOptimize(str);
    }
}
BENCHMARK(BM_StrAppendOperatorThreeStrings);

static void BM_StrCatThreeStrings(benchmark::State &state)
{
    std::string str1 = "My favorite first string.";
    std::string str2 = "My favorite second string.";
    std::string str3 = "My favorite third string.";
    // NOLINTNEXTLINE
    for (auto _ : state)
    {
        std::string str = absl::StrCat(str1, str2, str3);
        benchmark::DoNotOptimize(str);
    }
}
BENCHMARK(BM_StrCatThreeStrings);

// ---------------------------------------------------------------------------
// Benchmark                                 Time             CPU   Iterations
// ---------------------------------------------------------------------------
// BM_StrAppendOperatorThreeStrings       61.0 ns         61.0 ns     11485426
// BM_StrCatThreeStrings                  35.3 ns         35.2 ns     19756636

BENCHMARK_MAIN();