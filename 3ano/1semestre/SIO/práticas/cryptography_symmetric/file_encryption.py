import os
import sys
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes 
from cryptography.hazmat.primitives import padding

def encriptar(filename, output, algorithm):

    algorithm_name = algorithm.lower()
    if algorithm_name == "aes":
        iv = os.urandom(16)                # initialization vector
        cipher = Cipher(algorithms.AES(key), modes.CBC(iv))   # cifra
        encryptor = cipher.encryptor()   # encrypt a partir do objeto Cipher

        # padding
        padder = padding.PKCS7(algorithms.AES.block_size).padder()

    elif algorithm_name == "chacha":
        nonce = os.urandom(16)             # initialization vector
        algorithm = algorithms.ChaCha20(key, nonce)    # inicializa a cifra
        cipher = Cipher(algorithm, mode=None)  # criar um objeto da cifra
        encryptor = cipher.encryptor()  # encrypt a partir do objeto Cipher
    else:
        print("Não temos está esgotado \n")
        return


    # open file
    with open(filename, 'rb') as f:
        file = f.read()

    # write result
    # If AES, apply padding to the data
    if algorithm_name == "aes":     
        padded_data = padder.update(file) + padder.finalize()  # padding
        ciphertext = encryptor.update(padded_data) + encryptor.finalize()  # aplicar a encriptação em blocos de cifras
        with open(output, 'wb') as f_out:
            f_out.write(iv + ciphertext)
    elif algorithm_name == "chacha":
        # For ChaCha20, padding is not necessary
        ciphertext = encryptor.update(file) + encryptor.finalize()    # aplicar a encriptação em blocos de cifras
        with open(output, 'wb') as f_out:
            f_out.write(nonce + ciphertext)

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python file_encrytion.py <input_file> <output_file> <algorithm>")
    else:
        input_filename = sys.argv[1]
        output_filename = sys.argv[2]
        algoritmo = sys.argv[3]
        key = os.urandom(32)
        encriptar(input_filename, output_filename, algoritmo)
