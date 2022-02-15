// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#include <stdint.h>
namespace onnxruntime {
namespace contrib {
namespace cuda {

void LaunchAddProbsKernel(float* log_probs,
                          float* cum_log_probs,
                          const int batch_size,
                          const int num_beams,
                          const int vocab_size,
                          cudaStream_t stream);

template <typename T>
void LaunchUpdateKernel(T* log_probs,
                        T* cum_log_probs,
                        bool* finished,
                        int* sequence_length,
                        int* parent_ids,
                        int* word_ids,
                        int* output_ids,
                        int batch_size,
                        int num_beams,
                        int vocab_size,
                        int eos_token_id,
                        cudaStream_t stream);

template <typename T>
void LaunchVocabMaskKernel(
    T* log_probs,
    const int* vocab_mask,
    int batch_size,
    int num_beams,
    int vocab_size,
    cudaStream_t stream);

void LaunchInitKernel(
    float* beam_scores,
    int batch_size,
    int num_beams,
    cudaStream_t stream);

void LaunchNextTokenKernel(const int64_t* next_token_indices,
                           int64_t* next_indices,
                           int64_t* next_tokens,
                           int batch_size,
                           int top_k,
                           int vocab_size,
                           cudaStream_t stream);

template <typename T>
void LaunchUpdateKernel(const T* old_mask_data,
                        T* mask_data,
                        int64_t* next_positions,
                        int batch_beam_size,
                        int current_length,
                        cudaStream_t stream);

}  // namespace cuda
}  // namespace contrib
}  // namespace onnxruntime
