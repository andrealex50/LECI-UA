from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding

def rsa_decryption():

    file_encrypted = input("Name of the encrypted file: ")
    file_decrypted = input("Name of the file to save the decrypted content: ")
    file_PrivateKey = input("Enter file with private key: ")

    # Read the encrypted data from the file
    with open(file_encrypted, 'rb') as f:
        encrypted_data = f.read()

    # Load the private key from the provided file
    with open(file_PrivateKey, 'rb') as f:
        private_key = serialization.load_pem_private_key(f.read(), password=None)

    # RSA key size (e.g., 1024 bits = 128 bytes)
    key_size = private_key.key_size // 8  # Size in bytes

    decrypted_data = b''

    # Decrypt the file in chunks corresponding to the key size
    for i in range(0, len(encrypted_data), key_size):
        encrypted_chunk = encrypted_data[i:i+key_size]
        decrypted_chunk = private_key.decrypt(
            encrypted_chunk,
            padding.PKCS1v15()
        )
        decrypted_data += decrypted_chunk
    
    # Save the decrypted data to a new file
    with open(file_decrypted, 'wb') as f:
        f.write(decrypted_data)


if __name__ == "__main__":
    rsa_decryption()