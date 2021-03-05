#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_min_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.min(sliced_mat, "row");
}
BENCHMARK(BM_min_row);

static void BM_min_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.min(sliced_mat, "column");
}
BENCHMARK(BM_min_column);

BENCHMARK_MAIN();
