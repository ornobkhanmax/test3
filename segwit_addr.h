#ifndef _SEGWIT_ADDR_H_
#define _SEGWIT_ADDR_H_ 1

#include <stdint.h>

/** Encode a SegWit address
 *
 *  Out: output:   Pointer to a buffer of size 73 + strlen(hrp) that will be
 *                 updated to contain the null-terminated address.
 *  In:  hrp:      Pointer to the null-terminated human readable part to use
 *                 (chain/network specific).
 *       ver:      Version of the witness program (between 0 and 16 inclusive).
 *       prog:     Data bytes for the witness program (between 2 and 40 bytes).
 *       prog_len: Number of data bytes in prog.
 *  Returns 1 if successful.
 */
int segwit_addr_encode(char *output, const char *hrp, int ver,
                       const uint8_t *prog, size_t prog_len);

/** Decode a SegWit address
 *
 *  Out: ver:      Pointer to an int that will be updated to contain the witness
 *                 program version (between 0 and 16 inclusive).
 *       prog:     Pointer to a buffer of size 40 that will be updated to
 *                 contain the witness program bytes.
 *       prog_len: Pointer to a size_t that will be updated to contain the
 * length of bytes in prog. hrp:      Pointer to the null-terminated human
 * readable part that is expected (chain/network specific). addr:     Pointer to
 * the null-terminated address. Returns 1 if successful.
 */
int segwit_addr_decode(int *ver, uint8_t *prog, size_t *prog_len,
                       const char *hrp, const char *addr);

/** Encode a Bech32 string
 *
 *  Out: output:  Pointer to a buffer of size strlen(hrp) + data_len + 8 that
 *                will be updated to contain the null-terminated Bech32 string.
 *  In: hrp :     Pointer to the null-terminated human readable part.
 *      data :    Pointer to an array of 5-bit values.
 *      data_len: Length of the data array.
 *  Returns 1 if successful.
 */
int bech32_encode(char *output, const char *hrp, const uint8_t *data,
                  size_t data_len);

/** Decode a Bech32 string
 *
 *  Out: hrp:      Pointer to a buffer of size strlen(input) - 6. Will be
 *                 updated to contain the null-terminated human readable part.
 *       data:     Pointer to a buffer of size strlen(input) - 8 that will
 *                 hold the encoded 5-bit data values.
 *       data_len: Pointer to a size_t that will be updated to be the number
 *                 of entries in data.
 *  In: input:     Pointer to a null-terminated Bech32 string.
 *  Returns 1 if succesful.
 */
int bech32_decode(char *hrp, uint8_t *data, size_t *data_len,
                  const char *input);

#endif
