from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding

def rsa_encryption():
    
    file_toEncrypt = input("Enter file to encrypt: ")
    file_PublicKey = input("Enter file with public key: ")
    file_encrypted = input("Name for the encrypted file: ")

    # Read the data from the file to be encrypted
    with open(file_toEncrypt, 'rb') as f:
        data = f.read()

    # Load the public key from the provided file
    with open(file_PublicKey, 'rb') as f:
        public_key = serialization.load_pem_public_key(f.read())

    # RSA key size (e.g., 1024 bits = 128 bytes) minus padding overhead (11 bytes)
    key_size = public_key.key_size // 8  # Size in bytes
    chunk_size = key_size - 11  # For PKCS#1 v1.5 padding, subtract 11 bytes

    encrypted_data = b''

    # Encrypt the file in chunks to handle size limitations
    for i in range(0, len(data), chunk_size):
        chunk = data[i:i+chunk_size]
        encrypted_chunk = public_key.encrypt(
            chunk,
            padding.PKCS1v15()
        )
        encrypted_data += encrypted_chunk

    # Save the encrypted data to a new file
    with open(file_encrypted, 'wb') as f:
        f.write(encrypted_data)

if __name__ == "__main__":
    rsa_encryption()