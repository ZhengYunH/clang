// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512vl -target-feature +avx512vbmi2 -emit-llvm -o - -Wall -Werror | FileCheck %s

#include <immintrin.h>

__m128i test_mm_mask_compress_epi16(__m128i __S, __mmask8 __U, __m128i __D) {
  // CHECK-LABEL: @test_mm_mask_compress_epi16
  // CHECK: @llvm.x86.avx512.mask.compress.w.128
  return _mm_mask_compress_epi16(__S, __U, __D);
}

__m128i test_mm_maskz_compress_epi16(__mmask8 __U, __m128i __D) {
  // CHECK-LABEL: @test_mm_maskz_compress_epi16
  // CHECK: @llvm.x86.avx512.mask.compress.w.128
  return _mm_maskz_compress_epi16(__U, __D);
}

__m128i test_mm_mask_compress_epi8(__m128i __S, __mmask16 __U, __m128i __D) {
  // CHECK-LABEL: @test_mm_mask_compress_epi8
  // CHECK: @llvm.x86.avx512.mask.compress.b.128
  return _mm_mask_compress_epi8(__S, __U, __D);
}

__m128i test_mm_maskz_compress_epi8(__mmask16 __U, __m128i __D) {
  // CHECK-LABEL: @test_mm_maskz_compress_epi8
  // CHECK: @llvm.x86.avx512.mask.compress.b.128
  return _mm_maskz_compress_epi8(__U, __D);
}

void test_mm_mask_compressstoreu_epi16(void *__P, __mmask8 __U, __m128i __D) {
  // CHECK-LABEL: @test_mm_mask_compressstoreu_epi16
  // CHECK: @llvm.x86.avx512.mask.compress.store.w.128
  _mm_mask_compressstoreu_epi16(__P, __U, __D);
}

void test_mm_mask_compressstoreu_epi8(void *__P, __mmask16 __U, __m128i __D) {
  // CHECK-LABEL: @test_mm_mask_compressstoreu_epi8
  // CHECK: @llvm.x86.avx512.mask.compress.store.b.128
  _mm_mask_compressstoreu_epi8(__P, __U, __D);
}

__m128i test_mm_mask_expand_epi16(__m128i __S, __mmask8 __U, __m128i __D) {
  // CHECK-LABEL: @test_mm_mask_expand_epi16
  // CHECK: @llvm.x86.avx512.mask.expand.w.128
  return _mm_mask_expand_epi16(__S, __U, __D);
}

__m128i test_mm_maskz_expand_epi16(__mmask8 __U, __m128i __D) {
  // CHECK-LABEL: @test_mm_maskz_expand_epi16
  // CHECK: @llvm.x86.avx512.mask.expand.w.128
  return _mm_maskz_expand_epi16(__U, __D);
}

__m128i test_mm_mask_expand_epi8(__m128i __S, __mmask16 __U, __m128i __D) {
  // CHECK-LABEL: @test_mm_mask_expand_epi8
  // CHECK: @llvm.x86.avx512.mask.expand.b.128
  return _mm_mask_expand_epi8(__S, __U, __D);
}

__m128i test_mm_maskz_expand_epi8(__mmask16 __U, __m128i __D) {
  // CHECK-LABEL: @test_mm_maskz_expand_epi8
  // CHECK: @llvm.x86.avx512.mask.expand.b.128
  return _mm_maskz_expand_epi8(__U, __D);
}

__m128i test_mm_mask_expandloadu_epi16(__m128i __S, __mmask8 __U, void const* __P) {
  // CHECK-LABEL: @test_mm_mask_expandloadu_epi16
  // CHECK: @llvm.x86.avx512.mask.expand.load.w.128
  return _mm_mask_expandloadu_epi16(__S, __U, __P);
}

__m128i test_mm_maskz_expandloadu_epi16(__mmask8 __U, void const* __P) {
  // CHECK-LABEL: @test_mm_maskz_expandloadu_epi16
  // CHECK: @llvm.x86.avx512.mask.expand.load.w.128
  return _mm_maskz_expandloadu_epi16(__U, __P);
}

__m128i test_mm_mask_expandloadu_epi8(__m128i __S, __mmask16 __U, void const* __P) {
  // CHECK-LABEL: @test_mm_mask_expandloadu_epi8
  // CHECK: @llvm.x86.avx512.mask.expand.load.b.128
  return _mm_mask_expandloadu_epi8(__S, __U, __P);
}

__m128i test_mm_maskz_expandloadu_epi8(__mmask16 __U, void const* __P) {
  // CHECK-LABEL: @test_mm_maskz_expandloadu_epi8
  // CHECK: @llvm.x86.avx512.mask.expand.load.b.128
  return _mm_maskz_expandloadu_epi8(__U, __P);
}

__m256i test_mm256_mask_compress_epi16(__m256i __S, __mmask16 __U, __m256i __D) {
  // CHECK-LABEL: @test_mm256_mask_compress_epi16
  // CHECK: @llvm.x86.avx512.mask.compress.w.256
  return _mm256_mask_compress_epi16(__S, __U, __D);
}

__m256i test_mm256_maskz_compress_epi16(__mmask16 __U, __m256i __D) {
  // CHECK-LABEL: @test_mm256_maskz_compress_epi16
  // CHECK: @llvm.x86.avx512.mask.compress.w.256
  return _mm256_maskz_compress_epi16(__U, __D);
}

__m256i test_mm256_mask_compress_epi8(__m256i __S, __mmask32 __U, __m256i __D) {
  // CHECK-LABEL: @test_mm256_mask_compress_epi8
  // CHECK: @llvm.x86.avx512.mask.compress.b.256
  return _mm256_mask_compress_epi8(__S, __U, __D);
}

__m256i test_mm256_maskz_compress_epi8(__mmask32 __U, __m256i __D) {
  // CHECK-LABEL: @test_mm256_maskz_compress_epi8
  // CHECK: @llvm.x86.avx512.mask.compress.b.256
  return _mm256_maskz_compress_epi8(__U, __D);
}

void test_mm256_mask_compressstoreu_epi16(void *__P, __mmask16 __U, __m256i __D) {
  // CHECK-LABEL: @test_mm256_mask_compressstoreu_epi16
  // CHECK: @llvm.x86.avx512.mask.compress.store.w.256
  _mm256_mask_compressstoreu_epi16(__P, __U, __D);
}

void test_mm256_mask_compressstoreu_epi8(void *__P, __mmask32 __U, __m256i __D) {
  // CHECK-LABEL: @test_mm256_mask_compressstoreu_epi8
  // CHECK: @llvm.x86.avx512.mask.compress.store.b.256
  _mm256_mask_compressstoreu_epi8(__P, __U, __D);
}

__m256i test_mm256_mask_expand_epi16(__m256i __S, __mmask16 __U, __m256i __D) {
  // CHECK-LABEL: @test_mm256_mask_expand_epi16
  // CHECK: @llvm.x86.avx512.mask.expand.w.256
  return _mm256_mask_expand_epi16(__S, __U, __D);
}

__m256i test_mm256_maskz_expand_epi16(__mmask16 __U, __m256i __D) {
  // CHECK-LABEL: @test_mm256_maskz_expand_epi16
  // CHECK: @llvm.x86.avx512.mask.expand.w.256
  return _mm256_maskz_expand_epi16(__U, __D);
}

__m256i test_mm256_mask_expand_epi8(__m256i __S, __mmask32 __U, __m256i __D) {
  // CHECK-LABEL: @test_mm256_mask_expand_epi8
  // CHECK: @llvm.x86.avx512.mask.expand.b.256
  return _mm256_mask_expand_epi8(__S, __U, __D);
}

__m256i test_mm256_maskz_expand_epi8(__mmask32 __U, __m256i __D) {
  // CHECK-LABEL: @test_mm256_maskz_expand_epi8
  // CHECK: @llvm.x86.avx512.mask.expand.b.256
  return _mm256_maskz_expand_epi8(__U, __D);
}

__m256i test_mm256_mask_expandloadu_epi16(__m256i __S, __mmask16 __U, void const* __P) {
  // CHECK-LABEL: @test_mm256_mask_expandloadu_epi16
  // CHECK: @llvm.x86.avx512.mask.expand.load.w.256
  return _mm256_mask_expandloadu_epi16(__S, __U, __P);
}

__m256i test_mm256_maskz_expandloadu_epi16(__mmask16 __U, void const* __P) {
  // CHECK-LABEL: @test_mm256_maskz_expandloadu_epi16
  // CHECK: @llvm.x86.avx512.mask.expand.load.w.256
  return _mm256_maskz_expandloadu_epi16(__U, __P);
}

__m256i test_mm256_mask_expandloadu_epi8(__m256i __S, __mmask32 __U, void const* __P) {
  // CHECK-LABEL: @test_mm256_mask_expandloadu_epi8
  // CHECK: @llvm.x86.avx512.mask.expand.load.b.256
  return _mm256_mask_expandloadu_epi8(__S, __U, __P);
}

__m256i test_mm256_maskz_expandloadu_epi8(__mmask32 __U, void const* __P) {
  // CHECK-LABEL: @test_mm256_maskz_expandloadu_epi8
  // CHECK: @llvm.x86.avx512.mask.expand.load.b.256
  return _mm256_maskz_expandloadu_epi8(__U, __P);
}

__m256i test_mm256_mask_shldi_epi64(__m256i __S, __mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shldi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshld.q.256
  return _mm256_mask_shldi_epi64(__S, __U, __A, __B, 127);
}

__m256i test_mm256_maskz_shldi_epi64(__mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shldi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshld.q.256
  return _mm256_maskz_shldi_epi64(__U, __A, __B, 63);
}

__m256i test_mm256_shldi_epi64(__m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shldi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshld.q.256
  return _mm256_shldi_epi64(__A, __B, 31);
}

__m128i test_mm_mask_shldi_epi64(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shldi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshld.q.128
  return _mm_mask_shldi_epi64(__S, __U, __A, __B, 127);
}

__m128i test_mm_maskz_shldi_epi64(__mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shldi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshld.q.128
  return _mm_maskz_shldi_epi64(__U, __A, __B, 63);
}

__m128i test_mm_shldi_epi64(__m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shldi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshld.q.128
  return _mm_shldi_epi64(__A, __B, 31);
}

__m256i test_mm256_mask_shldi_epi32(__m256i __S, __mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shldi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshld.d.256
  return _mm256_mask_shldi_epi32(__S, __U, __A, __B, 127);
}

__m256i test_mm256_maskz_shldi_epi32(__mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shldi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshld.d.256
  return _mm256_maskz_shldi_epi32(__U, __A, __B, 63);
}

__m256i test_mm256_shldi_epi32(__m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shldi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshld.d.256
  return _mm256_shldi_epi32(__A, __B, 31);
}

__m128i test_mm_mask_shldi_epi32(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shldi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshld.d.128
  return _mm_mask_shldi_epi32(__S, __U, __A, __B, 127);
}

__m128i test_mm_maskz_shldi_epi32(__mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shldi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshld.d.128
  return _mm_maskz_shldi_epi32(__U, __A, __B, 63);
}

__m128i test_mm_shldi_epi32(__m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shldi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshld.d.128
  return _mm_shldi_epi32(__A, __B, 31);
}

__m256i test_mm256_mask_shldi_epi16(__m256i __S, __mmask16 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shldi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshld.w.256
  return _mm256_mask_shldi_epi16(__S, __U, __A, __B, 127);
}

__m256i test_mm256_maskz_shldi_epi16(__mmask16 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shldi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshld.w.256
  return _mm256_maskz_shldi_epi16(__U, __A, __B, 63);
}

__m256i test_mm256_shldi_epi16(__m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shldi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshld.w.256
  return _mm256_shldi_epi16(__A, __B, 31);
}

__m128i test_mm_mask_shldi_epi16(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shldi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshld.w.128
  return _mm_mask_shldi_epi16(__S, __U, __A, __B, 127);
}

__m128i test_mm_maskz_shldi_epi16(__mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shldi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshld.w.128
  return _mm_maskz_shldi_epi16(__U, __A, __B, 63);
}

__m128i test_mm_shldi_epi16(__m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shldi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshld.w.128
  return _mm_shldi_epi16(__A, __B, 31);
}

__m256i test_mm256_mask_shrdi_epi64(__m256i __S, __mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shrdi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshrd.q.256
  return _mm256_mask_shrdi_epi64(__S, __U, __A, __B, 127);
}

__m256i test_mm256_maskz_shrdi_epi64(__mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shrdi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshrd.q.256
  return _mm256_maskz_shrdi_epi64(__U, __A, __B, 63);
}

__m256i test_mm256_shrdi_epi64(__m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shrdi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshrd.q.256
  return _mm256_shrdi_epi64(__A, __B, 31);
}

__m128i test_mm_mask_shrdi_epi64(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shrdi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshrd.q.128
  return _mm_mask_shrdi_epi64(__S, __U, __A, __B, 127);
}

__m128i test_mm_maskz_shrdi_epi64(__mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shrdi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshrd.q.128
  return _mm_maskz_shrdi_epi64(__U, __A, __B, 63);
}

__m128i test_mm_shrdi_epi64(__m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shrdi_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshrd.q.128
  return _mm_shrdi_epi64(__A, __B, 31);
}

__m256i test_mm256_mask_shrdi_epi32(__m256i __S, __mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shrdi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshrd.d.256
  return _mm256_mask_shrdi_epi32(__S, __U, __A, __B, 127);
}

__m256i test_mm256_maskz_shrdi_epi32(__mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shrdi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshrd.d.256
  return _mm256_maskz_shrdi_epi32(__U, __A, __B, 63);
}

__m256i test_mm256_shrdi_epi32(__m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shrdi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshrd.d.256
  return _mm256_shrdi_epi32(__A, __B, 31);
}

__m128i test_mm_mask_shrdi_epi32(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shrdi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshrd.d.128
  return _mm_mask_shrdi_epi32(__S, __U, __A, __B, 127);
}

__m128i test_mm_maskz_shrdi_epi32(__mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shrdi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshrd.d.128
  return _mm_maskz_shrdi_epi32(__U, __A, __B, 63);
}

__m128i test_mm_shrdi_epi32(__m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shrdi_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshrd.d.128
  return _mm_shrdi_epi32(__A, __B, 31);
}

__m256i test_mm256_mask_shrdi_epi16(__m256i __S, __mmask16 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shrdi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshrd.w.256
  return _mm256_mask_shrdi_epi16(__S, __U, __A, __B, 127);
}

__m256i test_mm256_maskz_shrdi_epi16(__mmask16 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shrdi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshrd.w.256
  return _mm256_maskz_shrdi_epi16(__U, __A, __B, 63);
}

__m256i test_mm256_shrdi_epi16(__m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shrdi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshrd.w.256
  return _mm256_shrdi_epi16(__A, __B, 31);
}

__m128i test_mm_mask_shrdi_epi16(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shrdi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshrd.w.128
  return _mm_mask_shrdi_epi16(__S, __U, __A, __B, 127);
}

__m128i test_mm_maskz_shrdi_epi16(__mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shrdi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshrd.w.128
  return _mm_maskz_shrdi_epi16(__U, __A, __B, 63);
}

__m128i test_mm_shrdi_epi16(__m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shrdi_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshrd.w.128
  return _mm_shrdi_epi16(__A, __B, 31);
}

__m256i test_mm256_mask_shldv_epi64(__m256i __S, __mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shldv_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshldv.q.256
  return _mm256_mask_shldv_epi64(__S, __U, __A, __B);
}

__m256i test_mm256_maskz_shldv_epi64(__mmask8 __U, __m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shldv_epi64
  // CHECK: @llvm.x86.avx512.maskz.vpshldv.q.256
  return _mm256_maskz_shldv_epi64(__U, __S, __A, __B);
}

__m256i test_mm256_shldv_epi64(__m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shldv_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshldv.q.256
  return _mm256_shldv_epi64(__S, __A, __B);
}

__m128i test_mm_mask_shldv_epi64(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shldv_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshldv.q.128
  return _mm_mask_shldv_epi64(__S, __U, __A, __B);
}

__m128i test_mm_maskz_shldv_epi64(__mmask8 __U, __m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shldv_epi64
  // CHECK: @llvm.x86.avx512.maskz.vpshldv.q.128
  return _mm_maskz_shldv_epi64(__U, __S, __A, __B);
}

__m128i test_mm_shldv_epi64(__m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shldv_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshldv.q.128
  return _mm_shldv_epi64(__S, __A, __B);
}

__m256i test_mm256_mask_shldv_epi32(__m256i __S, __mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shldv_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshldv.d.256
  return _mm256_mask_shldv_epi32(__S, __U, __A, __B);
}

__m256i test_mm256_maskz_shldv_epi32(__mmask8 __U, __m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shldv_epi32
  // CHECK: @llvm.x86.avx512.maskz.vpshldv.d.256
  return _mm256_maskz_shldv_epi32(__U, __S, __A, __B);
}

__m256i test_mm256_shldv_epi32(__m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shldv_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshldv.d.256
  return _mm256_shldv_epi32(__S, __A, __B);
}

__m128i test_mm_mask_shldv_epi32(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shldv_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshldv.d.128
  return _mm_mask_shldv_epi32(__S, __U, __A, __B);
}

__m128i test_mm_maskz_shldv_epi32(__mmask8 __U, __m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shldv_epi32
  // CHECK: @llvm.x86.avx512.maskz.vpshldv.d.128
  return _mm_maskz_shldv_epi32(__U, __S, __A, __B);
}

__m128i test_mm_shldv_epi32(__m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shldv_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshldv.d.128
  return _mm_shldv_epi32(__S, __A, __B);
}

__m256i test_mm256_mask_shldv_epi16(__m256i __S, __mmask16 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shldv_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshldv.w.256
  return _mm256_mask_shldv_epi16(__S, __U, __A, __B);
}

__m256i test_mm256_maskz_shldv_epi16(__mmask16 __U, __m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shldv_epi16
  // CHECK: @llvm.x86.avx512.maskz.vpshldv.w.256
  return _mm256_maskz_shldv_epi16(__U, __S, __A, __B);
}

__m256i test_mm256_shldv_epi16(__m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shldv_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshldv.w.256
  return _mm256_shldv_epi16(__S, __A, __B);
}

__m128i test_mm_mask_shldv_epi16(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shldv_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshldv.w.128
  return _mm_mask_shldv_epi16(__S, __U, __A, __B);
}

__m128i test_mm_maskz_shldv_epi16(__mmask8 __U, __m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shldv_epi16
  // CHECK: @llvm.x86.avx512.maskz.vpshldv.w.128
  return _mm_maskz_shldv_epi16(__U, __S, __A, __B);
}

__m128i test_mm_shldv_epi16(__m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shldv_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshldv.w.128
  return _mm_shldv_epi16(__S, __A, __B);
}

__m256i test_mm256_mask_shrdv_epi64(__m256i __S, __mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shrdv_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.q.256
  return _mm256_mask_shrdv_epi64(__S, __U, __A, __B);
}

__m256i test_mm256_maskz_shrdv_epi64(__mmask8 __U, __m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shrdv_epi64
  // CHECK: @llvm.x86.avx512.maskz.vpshrdv.q.256
  return _mm256_maskz_shrdv_epi64(__U, __S, __A, __B);
}

__m256i test_mm256_shrdv_epi64(__m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shrdv_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.q.256
  return _mm256_shrdv_epi64(__S, __A, __B);
}

__m128i test_mm_mask_shrdv_epi64(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shrdv_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.q.128
  return _mm_mask_shrdv_epi64(__S, __U, __A, __B);
}

__m128i test_mm_maskz_shrdv_epi64(__mmask8 __U, __m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shrdv_epi64
  // CHECK: @llvm.x86.avx512.maskz.vpshrdv.q.128
  return _mm_maskz_shrdv_epi64(__U, __S, __A, __B);
}

__m128i test_mm_shrdv_epi64(__m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shrdv_epi64
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.q.128
  return _mm_shrdv_epi64(__S, __A, __B);
}

__m256i test_mm256_mask_shrdv_epi32(__m256i __S, __mmask8 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shrdv_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.d.256
  return _mm256_mask_shrdv_epi32(__S, __U, __A, __B);
}

__m256i test_mm256_maskz_shrdv_epi32(__mmask8 __U, __m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shrdv_epi32
  // CHECK: @llvm.x86.avx512.maskz.vpshrdv.d.256
  return _mm256_maskz_shrdv_epi32(__U, __S, __A, __B);
}

__m256i test_mm256_shrdv_epi32(__m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shrdv_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.d.256
  return _mm256_shrdv_epi32(__S, __A, __B);
}

__m128i test_mm_mask_shrdv_epi32(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shrdv_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.d.128
  return _mm_mask_shrdv_epi32(__S, __U, __A, __B);
}

__m128i test_mm_maskz_shrdv_epi32(__mmask8 __U, __m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shrdv_epi32
  // CHECK: @llvm.x86.avx512.maskz.vpshrdv.d.128
  return _mm_maskz_shrdv_epi32(__U, __S, __A, __B);
}

__m128i test_mm_shrdv_epi32(__m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shrdv_epi32
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.d.128
  return _mm_shrdv_epi32(__S, __A, __B);
}

__m256i test_mm256_mask_shrdv_epi16(__m256i __S, __mmask16 __U, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_shrdv_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.w.256
  return _mm256_mask_shrdv_epi16(__S, __U, __A, __B);
}

__m256i test_mm256_maskz_shrdv_epi16(__mmask16 __U, __m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_shrdv_epi16
  // CHECK: @llvm.x86.avx512.maskz.vpshrdv.w.256
  return _mm256_maskz_shrdv_epi16(__U, __S, __A, __B);
}

__m256i test_mm256_shrdv_epi16(__m256i __S, __m256i __A, __m256i __B) {
  // CHECK-LABEL: @test_mm256_shrdv_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.w.256
  return _mm256_shrdv_epi16(__S, __A, __B);
}

__m128i test_mm_mask_shrdv_epi16(__m128i __S, __mmask8 __U, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_shrdv_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.w.128
  return _mm_mask_shrdv_epi16(__S, __U, __A, __B);
}

__m128i test_mm_maskz_shrdv_epi16(__mmask8 __U, __m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_shrdv_epi16
  // CHECK: @llvm.x86.avx512.maskz.vpshrdv.w.128
  return _mm_maskz_shrdv_epi16(__U, __S, __A, __B);
}

__m128i test_mm_shrdv_epi16(__m128i __S, __m128i __A, __m128i __B) {
  // CHECK-LABEL: @test_mm_shrdv_epi16
  // CHECK: @llvm.x86.avx512.mask.vpshrdv.w.128
  return _mm_shrdv_epi16(__S, __A, __B);
}

