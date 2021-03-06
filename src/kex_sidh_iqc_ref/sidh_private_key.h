#ifndef PRIVATE_KEY_H
#define PRIVATE_KEY_H

#include "sidh_elliptic_curve.h"
#include "sidh_public_param.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Representation of the private key in oqs_sidh_iqc_ref
 */
typedef struct {
	mpz_t m;
	mpz_t n;
} private_key_struct;

typedef private_key_struct private_key_t[1];

/**
 * Initializes the private-key.
 * @param private_key
 */
void oqs_sidh_iqc_ref_private_key_init(private_key_t private_key);

/**
 * Frees the memory allocated to the private-key.
 * @param private_key
 */
void oqs_sidh_iqc_ref_private_key_clear(private_key_t private_key);

/**
 * Generates the private-key. It is guaranteed that {@code private_key->m}
 * is comprime to {@code params->l}.
 * @param private_key
 * @param params
 */
void oqs_sidh_iqc_ref_private_key_generate(private_key_t private_key,
                                           const public_params_t params);

/**
 * Computes a generator for th kernel generated by {@code gen = m * P + n * Q}.
 * It is assumed that {@code m} is invertible modulo {@code le}.
 * @param gen
 * @param P one of the generators of the l^e torsion.
 * @param Q one of the generators of the l^e torsion.
 * @param private_key
 * @param le
 * @param E
 */
void oqs_sidh_iqc_ref_private_key_compute_kernel_gen(point_t gen,
                                                     const private_key_t private_key,
                                                     const point_t P,
                                                     const point_t Q,
                                                     const mpz_t le,
                                                     const elliptic_curve_t E);

/**
 * Converts a private-key to an array of bytes.
 * @param bytes
 * @param private_key
 * @param prime_size
 */
void oqs_sidh_iqc_ref_private_key_to_bytes(uint8_t *bytes,
                                           const private_key_t private_key,
                                           long prime_size);

/**
 * Converts an array of bytes to a private-key.
 * @param private_key
 * @param bytes
 * @param prime_size
 */
void oqs_sidh_iqc_ref_bytes_to_private_key(private_key_t private_key,
                                           const uint8_t *bytes,
                                           long prime_size);

/**
 * Prints {@code private_key} to the standard output.
 * @param private_key
 */
void oqs_sidh_iqc_ref_private_key_print(const private_key_t private_key);

#ifdef __cplusplus
}
#endif

#endif /* PRIVATE_KEY_H */
